#include "../interface/Ntuplizer.h"
#include "../interface/CandidateNtuplizer.h"
#include "../interface/METsNtuplizer.h"

#include "FWCore/ParameterSet/interface/FileInPath.h"

Ntuplizer::Ntuplizer( const edm::ParameterSet& iConfig):

  metmodifiedToken_ (consumes<pat::METCollection>(iConfig.getParameter<edm::InputTag>("met_modified"))),
  metmodifiedPFToken_ (consumes<pat::METCollection>(iConfig.getParameter<edm::InputTag>("met_modifiedPF"))),
  metpuppiToken_ (consumes<pat::METCollection>(iConfig.getParameter<edm::InputTag>("met_puppi"))),
  metpuppiPFToken_ (consumes<pat::METCollection>(iConfig.getParameter<edm::InputTag>("met_puppiPF")))

{

  edm::Service<TFileService> fs;
  TTree* tree = fs->make<TTree>( "tree", "tree" );
  
  std::map< std::string, bool > runFlags;
  runFlags["runOnMC"] = iConfig.getParameter<bool>("runOnMC");
  runFlags["doMissingEt"] = iConfig.getParameter<bool>("doMissingEt");


  nBranches_ = new NtupleBranches( runFlags, tree );

  if (runFlags["doMissingEt"]) {
    //write here
    nTuplizers_["MET"] = new METsNtuplizer( metmodifiedToken_,
					    metmodifiedPFToken_,
					    metpuppiToken_,
					    metpuppiPFToken_,
					    nBranches_,
					    runFlags );

  }
}

/////////////////////////////////////////////////////////////////////////////////
Ntuplizer::~Ntuplizer()
{
  for(std::map<std::string,CandidateNtuplizer*>::iterator it = nTuplizers_.begin(); it != nTuplizers_.end(); ++it ) delete it->second;

  nTuplizers_.clear();
  
  delete nBranches_;
}

//////////////////////////////////////////////////////////////////////////////////
void Ntuplizer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup){
  
  nBranches_ -> reset();

  nBranches_ -> EVENT_event     = iEvent.id().event();
  nBranches_ -> EVENT_run       = iEvent.id().run();
  nBranches_ -> EVENT_lumiBlock = iEvent.id().luminosityBlock();

  for( std::map<std::string, CandidateNtuplizer*>::iterator it = nTuplizers_.begin(); it != nTuplizers_.end(); ++it ) (it->second) -> fillBranches( iEvent, iSetup );

  nBranches_ -> fillTree();
  nBranches_ -> reset();

}

//////////////////////////////////////////////////////////
void Ntuplizer::beginJob(){
}

//////////////////////////////////////////////////////////
void Ntuplizer::endJob(){
}

///////////////////////////////////////////////////////////////
void Ntuplizer::beginRun( edm::Run const&, edm::EventSetup const&){
}

////////////////////////////////////////////////////////////////
void Ntuplizer::endRun( edm::Run const&, edm::EventSetup const&){
}

///////////////////////////////////////////////////////////////
void Ntuplizer::beginLuminosityBlock( edm::LuminosityBlock const&, edm::EventSetup const&){
}

//////////////////////////////////////////////////////////////////////////
void Ntuplizer::endLuminosityBlock( edm::LuminosityBlock const&, edm::EventSetup const&){
}

///////////////////////////////////////////////////////////////////////
void Ntuplizer::fillDescriptions(edm::ConfigurationDescriptions& descriptions){

  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descripitons.addDefault(desc);
}

DEFINE_FWK_MODULE(Ntuplizer);
