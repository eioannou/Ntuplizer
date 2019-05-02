#include "../interface/METsNtuplizer.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "CommonTools/Utils/interface/StringCutObjectSelector.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"

METsNtuplizer::METsNtuplizer( edm::EDGetTokenT<pat::METCollection> metmodifiedtoken,
			      edm::EDGetTokenT<pat::METCollection> metmodifiedPFtoken,
			      edm::EDGetTokenT<pat::METCollection> metpuppitoken,
			      edm::EDGetTokenT<pat::METCollection> metpuppiPFtoken,
			      NtupleBranches* nBranches,
			      std::map< std::string, bool>& runFlags)
  : CandidateNtuplizer (nBranches)
  , metmodifiedInputToken_ (metmodifiedtoken),
  , metmodifedPFInputToken_ (metmodifiedPFtoken)
  , metpuppiInputToken_ (metpuppitoken)
  , metpuppiPFInputToken_ (metpuppiPFtoken)
{
}

METsNtuplizer::~METsNtuplizer( void )
{

}

void METsNtuplizer::fillBranches( edm::Event const & event, const edm::EventSetup& iSetup ){

  // MET without PF
  event.getByToken(metmodifiedInputToken_, METsmodified_ );
  const pat::MET &metmodified = METsmodified_ -> front();

  // MET with PF
  event.getByToken(metmodifiedPFInputToken_, METsmodifiedPF_);
  const pat::MET &metmodifiedPF = METsmodifiedPF_ -> front();

  // MET Puppi without PF
  event.getByToken(metpuppiInputToken_, METspuppi_);
  const pat::MET &metpuppi = METspuppi_ -> front();
  
  // MET Puppi with PF
  event.getByToken(metpuppiPFInputToken_, METspuppiPF_);
  const pat::MET &metpuppiPF = METspuppiPF_ -> front();

  nBranches_ -> METraw_pt.push_back(metmodified.uncorPt());
  nBranches_ -> METraw_phi.push_back(metmodified.uncorPhi());
  nBranches_ -> METraw_sumEt.push_back(metmodified.uncorSumEt());

  nBranches_ -> MET_pt.push_back(metmodified.pt());
  nBranches_ -> MET_px.push_back(metmodified.px());
  nBranches_ -> MET_py.push_back(metmodified.py());
  nBranches_ -> MET_phi.push_back(metmodified.phi());
  nBranches_ -> MET_sumEt.push_back(metmodified.sumEt());

  nBranches_ -> MET_JetResUp_pt.push_back(metmodified.shiftedPt(pat::MET::JetResUp));
  nBranches_ -> MET_JetResDown_pt.push_back(metmodified.shiftedPt(pat::MET::JetResDown));
