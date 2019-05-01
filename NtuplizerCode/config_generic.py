#### Process Initialization ####

import FWCore.ParameterSet.Config as cms

process = cms.Process("Ntuple")

process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.Geometry.GeometryRecoDB_cff")

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string("flatTuple.root")
                                   )

from Ntuplizer.NtuplizerCode.ntuplizerOptions_generic_cfi import config


#----- Config parser ------#

import FWCore.ParameterSet.VarParsing as VarParsing

options = VarParsing.VarParsing('analysis')

options.maxEvents = 100000

options.inputFiles = '' # add input file

options.parseArguments()

process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True),
    SkipEvent   = cms.untracked.vstring('ProductNotFound'),
    allowUnscheduled = cms.untracked.bool(True)
    )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( options.maxEvents) )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring( otpions.inputFiles),
                            )

print " process source filenames %s" %(process.source)

#--- Sequence settings ---#
#
####################

#--- Logger ---#
process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.MessageLogger.cerr.threshold = 'INFO'
process.MessageLogger.categories.append('Ntuple')
process.MessageLogger.cerr.INFO = cms.untracked.PSet(
    limit = cms.untracked.int32(1)
)

process.MessageLogger.cerr.FwkReport.reportEvery = 1000

#--- Define conditions ---#
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
from Configuration.AlCa.GlobalTag import GlobalTag

GT = ''
if config["RUNONMC"]: GT = '101X_upgrade2018_realistic_v7'
elif not config["RUNONMC"]: GT = '94X_dataRun2_ReReco_EOY17_v6'

print "******************** GLOBAL TAG ***************************"
print GT
print "***********************************************************"

process.GlobalTag = GlobalTag( process.GlobalTag, GT )


#--- Read JSON file for data ---#
if not( config["RUNONMC"] ) and config["USEJSON"]:
    
    import FWCore.PythonUtilities.LumiList as LumiList
    import FWCore.ParameterSet.Types as CfgTypes
    process.source.lumisToProcess = CfgTypes.untracked( CfgTypes.VLuminosityBlockTange() )
    myLumis = LumiList.LumiList( filename = config["JSONFILE"] ).getCMSSWString().split(',')
    process.source.lumisToprocess.extend(myLumis)


#--- Missing Energy Transverse MET ---#
from PhysicsTools.PatUtils.tools.runMETCorrectionsAndUncertainties import runMetCorAndUncFromMiniAOD

# Puppi
from PhysicsTools.PatAlgos.slimming.puppiForMET_cff import makePuppiesFromMiniAOD
makePuppiesFromMiniAOD(process, True)

#--- PF Objects are NOT used in Uncertainties ---#
# Default MET
runMetCorAndUncFromMiniAOD(
    process,
    isData = False,
    isPFUncertainties = False,
    postfix = "Modified"
)
# Puppi MET
runMETCorAndUncerFromMiniAOD(
    process,
    isData = False,
    isPFUncertainties = False,
    metType = "Puppi",
    jetFlavor = "AK4PFPuppi",
    postfix = "Puppi"
)

#--- PF Objects are BEING used in Uncertainties ---#
# Default MET
runMetCorAndUncFromMiniAOD(
    process,
    isData = False,
    isPFUncertainties = True,
    postfix = "ModifiedPF"
)
# Puppi MET
runMETCorAndUncFromMiniAOD(
    process,
    isData = False,
    isPFUncertainties = True,
    metType = "Puppi",
    jetFlavor = "AK4PFPuppi",
    postfix = "PuppiPF"
)

process.puppiNoLep.useExistingWeights = False
process.puppi.useExistingWeights = False


#================ NTUPLIZER ======================#
process.ntuplizer = cms.EDAnalyzer("Ntuplizer",
                                   runOnMC     = cms.bool(config["RUNONMC"]),
                                   doMissingEt = cms.bool(config["DOMISSINGET"]),
                                   met_modified = cms.InputTag("slimmedMETsModified"),
                                   met_modifiedPF = cms.InputTag("slimmedMETsModifiedPF"),
                                   met_puppi = cms.InputTag("slimmedMETsPuppi"),
                                   met_puppiPF = cms.InputTag("slimmedMETsPuppiPF")
                                   )

#--- Final Path ---#
process.p = cms.Path()

process.p += process.egmPhotonIDSequence
process.p += process.puppiMETSequence
process.p += process.fullPatMetSequencePuppiPF
process.p += process.fullPatMetSequenceModifiedPF
process.p += process.fullPatMetSequencePuppi
process.p += process.fullPatMetSequenceModified
process.p += process.ntuplizer
