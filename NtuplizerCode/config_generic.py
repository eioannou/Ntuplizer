#### Process Initialization ####

import FWCore.ParameterSet.Config as cms

process = cms.Process("Ntuple")

process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.Geometry.GeometryRecoDB_cff")

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string("flatTuple.root")
                                   )

from Ntuplizer.NtuplizerCode.ntuplizerOptions_generic_cfi import config
