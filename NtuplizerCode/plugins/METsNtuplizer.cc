#include "../interface/METsNtuplizer.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "CommonTools/Utils/interface/StringCutObjectSelector.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"

METsNtuplizer::METsNtuplizer( edm::EDGetTokenT<edm::View<pat::MET> > metmodifiedtoken,
			      edm::EDGetTokenT<edm::View<pat::MET> > metmodifiedPFtoken,
			      edm::EDGetTokenT<edm::View<pat::MET> > metpuppitoken,
			      edm::EDGetTokenT<edm::View<pat::MET> > metpuppiPFtoken,
			      NtupleBranches* nBranches,
			      std::map< std::string, bool>& runFlags)
  : CandidateNtuplizer (nBranches)
  , metmodifiedInputToken_ (metmodifiedtoken)
  , metmodifiedPFInputToken_ (metmodifiedPFtoken)
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

  // MET without PF
  nBranches_ -> MET_rawet.push_back(metmodified.uncorPt());
  nBranches_ -> MET_rawphi.push_back(metmodified.uncorPhi());
  nBranches_ -> MET_rawsumEt.push_back(metmodified.uncorSumEt());

  nBranches_ -> MET_et.push_back(metmodified.pt());
  nBranches_ -> MET_px.push_back(metmodified.px());
  nBranches_ -> MET_py.push_back(metmodified.py());
  nBranches_ -> MET_phi.push_back(metmodified.phi());
  nBranches_ -> MET_sumEt.push_back(metmodified.sumEt());
  //-- PT --//
  nBranches_ -> MET_JetResUp_pt.push_back(metmodified.shiftedPt(pat::MET::JetResUp));
  nBranches_ -> MET_JetResDown_pt.push_back(metmodified.shiftedPt(pat::MET::JetResDown));
  nBranches_ -> MET_JetEnUp_pt.push_back(metmodified.shiftedPt(pat::MET::JetEnUp));
  nBranches_ -> MET_JetEnDown_pt.push_back(metmodified.shiftedPt(pat::MET::JetEnDown));
  nBranches_ -> MET_MuonEnUp_pt.push_back(metmodified.shiftedPt(pat::MET::MuonEnUp));
  nBranches_ -> MET_MuonEnDown_pt.push_back(metmodified.shiftedPt(pat::MET::MuonEnDown));
  nBranches_ -> MET_ElectronEnUp_pt.push_back(metmodified.shiftedPt(pat::MET::ElectronEnUp));
  nBranches_ -> MET_ElectronEnDown_pt.push_back(metmodified.shiftedPt(pat::MET::ElectronEnDown));
  nBranches_ -> MET_TauEnUp_pt.push_back(metmodified.shiftedPt(pat::MET::TauEnUp));
  nBranches_ -> MET_TauEnDown_pt.push_back(metmodified.shiftedPt(pat::MET::TauEnDown));
  nBranches_ -> MET_UnclusteredEnUp_pt.push_back(metmodified.shiftedPt(pat::MET::UnclusteredEnUp));
  nBranches_ -> MET_UnclusteredEnDown_pt.push_back(metmodified.shiftedPt(pat::MET::UnclusteredEnDown));
  nBranches_ -> MET_PhotonEnUp_pt.push_back(metmodified.shiftedPt(pat::MET::PhotonEnUp));
  nBranches_ -> MET_PhotonEnDown_pt.push_back(metmodified.shiftedPt(pat::MET::PhotonEnDown));
  nBranches_ -> MET_NoShift_pt.push_back(metmodified.shiftedPt(pat::MET::NoShift));
  //nBranches_ -> MET_JetResUpSmear_pt.push_back(metmodified.shiftedPt(pat::MET::JetResUpSmear));
  //nBranches_ -> MET_JetResDownSmear_pt.push_back(metmodified.shiftedPt(pat::MET::JetResDownSmear));
  //nBranches_ -> MET_METUncertaintySize_pt.push_back(metmodified.shiftedPt(pat::MET::METUncertaintySize));
  //nBranches_ -> MET_METUncertaintySize_pt.push_back(metmodified.shiftedPt(pat::MET::METFullUncertaintySize));
  //-- Px --//
  nBranches_ -> MET_JetResUp_px.push_back(metmodified.shiftedPx(pat::MET::JetResUp));
  nBranches_ -> MET_JetResDown_px.push_back(metmodified.shiftedPx(pat::MET::JetResDown));
  nBranches_ -> MET_JetEnUp_px.push_back(metmodified.shiftedPx(pat::MET::JetEnUp));
  nBranches_ -> MET_JetEnDown_px.push_back(metmodified.shiftedPx(pat::MET::JetEnDown));
  nBranches_ -> MET_MuonEnUp_px.push_back(metmodified.shiftedPx(pat::MET::MuonEnUp));
  nBranches_ -> MET_MuonEnDown_px.push_back(metmodified.shiftedPx(pat::MET::MuonEnDown));
  nBranches_ -> MET_ElectronEnUp_px.push_back(metmodified.shiftedPx(pat::MET::ElectronEnUp));
  nBranches_ -> MET_ElectronEnDown_px.push_back(metmodified.shiftedPx(pat::MET::ElectronEnDown));
  nBranches_ -> MET_TauEnUp_px.push_back(metmodified.shiftedPx(pat::MET::TauEnUp));
  nBranches_ -> MET_TauEnDown_px.push_back(metmodified.shiftedPx(pat::MET::TauEnDown));
  nBranches_ -> MET_UnclusteredEnUp_px.push_back(metmodified.shiftedPx(pat::MET::UnclusteredEnUp));
  nBranches_ -> MET_UnclusteredEnDown_px.push_back(metmodified.shiftedPx(pat::MET::UnclusteredEnDown));
  nBranches_ -> MET_PhotonEnUp_px.push_back(metmodified.shiftedPx(pat::MET::PhotonEnUp));
  nBranches_ -> MET_PhotonEnDown_px.push_back(metmodified.shiftedPx(pat::MET::PhotonEnDown));
  nBranches_ -> MET_NoShift_px.push_back(metmodified.shiftedPx(pat::MET::NoShift));
  //nBranches_ -> MET_JetResUpSmear_px.push_back(metmodified.shiftedPx(pat::MET::JetResUpSmear));
  //nBranches_ -> MET_JetResDownSmear_px.push_back(metmodified.shiftedPx(pat::MET::JetResDownSmear));
  //nBranches_ -> MET_METUncertaintySize_px.push_back(metmodified.shiftedPx(pat::MET::METUncertaintySize));
  //nBranches_ -> MET_METUncertaintySize_px.push_back(metmodified.shiftedPx(pat::MET::METFullUncertaintySize));
  //-- Py --//
  nBranches_ -> MET_JetResUp_py.push_back(metmodified.shiftedPy(pat::MET::JetResUp));
  nBranches_ -> MET_JetResDown_py.push_back(metmodified.shiftedPy(pat::MET::JetResDown));
  nBranches_ -> MET_JetEnUp_py.push_back(metmodified.shiftedPy(pat::MET::JetEnUp));
  nBranches_ -> MET_JetEnDown_py.push_back(metmodified.shiftedPy(pat::MET::JetEnDown));
  nBranches_ -> MET_MuonEnUp_py.push_back(metmodified.shiftedPy(pat::MET::MuonEnUp));
  nBranches_ -> MET_MuonEnDown_py.push_back(metmodified.shiftedPy(pat::MET::MuonEnDown));
  nBranches_ -> MET_ElectronEnUp_py.push_back(metmodified.shiftedPy(pat::MET::ElectronEnUp));
  nBranches_ -> MET_ElectronEnDown_py.push_back(metmodified.shiftedPy(pat::MET::ElectronEnDown));
  nBranches_ -> MET_TauEnUp_py.push_back(metmodified.shiftedPy(pat::MET::TauEnUp));
  nBranches_ -> MET_TauEnDown_py.push_back(metmodified.shiftedPy(pat::MET::TauEnDown));
  nBranches_ -> MET_UnclusteredEnUp_py.push_back(metmodified.shiftedPy(pat::MET::UnclusteredEnUp));
  nBranches_ -> MET_UnclusteredEnDown_py.push_back(metmodified.shiftedPy(pat::MET::UnclusteredEnDown));
  nBranches_ -> MET_PhotonEnUp_py.push_back(metmodified.shiftedPy(pat::MET::PhotonEnUp));
  nBranches_ -> MET_PhotonEnDown_py.push_back(metmodified.shiftedPy(pat::MET::PhotonEnDown));
  nBranches_ -> MET_NoShift_py.push_back(metmodified.shiftedPy(pat::MET::NoShift));
  //nBranches_ -> MET_JetResUpSmear_py.push_back(metmodified.shiftedPy(pat::MET::JetResUpSmear));
  //nBranches_ -> MET_JetResDownSmear_py.push_back(metmodified.shiftedPy(pat::MET::JetResDownSmear));
  //nBranches_ -> MET_METUncertaintySize_py.push_back(metmodified.shiftedPy(pat::MET::METUncertaintySize));
  //nBranches_ -> MET_METUncertaintySize_py.push_back(metmodified.shiftedPy(pat::MET::METFullUncertaintySize));
  //-- Phi --//
  nBranches_ -> MET_JetResUp_phi.push_back(metmodified.shiftedPhi(pat::MET::JetResUp));
  nBranches_ -> MET_JetResDown_phi.push_back(metmodified.shiftedPhi(pat::MET::JetResDown));
  nBranches_ -> MET_JetEnUp_phi.push_back(metmodified.shiftedPhi(pat::MET::JetEnUp));
  nBranches_ -> MET_JetEnDown_phi.push_back(metmodified.shiftedPhi(pat::MET::JetEnDown));
  nBranches_ -> MET_MuonEnUp_phi.push_back(metmodified.shiftedPhi(pat::MET::MuonEnUp));
  nBranches_ -> MET_MuonEnDown_phi.push_back(metmodified.shiftedPhi(pat::MET::MuonEnDown));
  nBranches_ -> MET_ElectronEnUp_phi.push_back(metmodified.shiftedPhi(pat::MET::ElectronEnUp));
  nBranches_ -> MET_ElectronEnDown_phi.push_back(metmodified.shiftedPhi(pat::MET::ElectronEnDown));
  nBranches_ -> MET_TauEnUp_phi.push_back(metmodified.shiftedPhi(pat::MET::TauEnUp));
  nBranches_ -> MET_TauEnDown_phi.push_back(metmodified.shiftedPhi(pat::MET::TauEnDown));
  nBranches_ -> MET_UnclusteredEnUp_phi.push_back(metmodified.shiftedPhi(pat::MET::UnclusteredEnUp));
  nBranches_ -> MET_UnclusteredEnDown_phi.push_back(metmodified.shiftedPhi(pat::MET::UnclusteredEnDown));
  nBranches_ -> MET_PhotonEnUp_phi.push_back(metmodified.shiftedPhi(pat::MET::PhotonEnUp));
  nBranches_ -> MET_PhotonEnDown_phi.push_back(metmodified.shiftedPhi(pat::MET::PhotonEnDown));
  nBranches_ -> MET_NoShift_phi.push_back(metmodified.shiftedPhi(pat::MET::NoShift));
  //nBranches_ -> MET_JetResUpSmear_phi.push_back(metmodified.shiftedPhi(pat::MET::JetResUpSmear));
  //nBranches_ -> MET_JetResDownSmear_phi.push_back(metmodified.shiftedPhi(pat::MET::JetResDownSmear));
  //nBranches_ -> MET_METUncertaintySize_phi.push_back(metmodified.shiftedPhi(pat::MET::METUncertaintySize));
  //nBranches_ -> MET_METUncertaintySize_phi.push_back(metmodified.shiftedPhi(pat::MET::METFullUncertaintySize));
  //-- SumEt --//
  nBranches_ -> MET_JetResUp_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::JetResUp));
  nBranches_ -> MET_JetResDown_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::JetResDown));
  nBranches_ -> MET_JetEnUp_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::JetEnUp));
  nBranches_ -> MET_JetEnDown_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::JetEnDown));
  nBranches_ -> MET_MuonEnUp_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::MuonEnUp));
  nBranches_ -> MET_MuonEnDown_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::MuonEnDown));
  nBranches_ -> MET_ElectronEnUp_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::ElectronEnUp));
  nBranches_ -> MET_ElectronEnDown_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::ElectronEnDown));
  nBranches_ -> MET_TauEnUp_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::TauEnUp));
  nBranches_ -> MET_TauEnDown_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::TauEnDown));
  nBranches_ -> MET_UnclusteredEnUp_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::UnclusteredEnUp));
  nBranches_ -> MET_UnclusteredEnDown_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::UnclusteredEnDown));
  nBranches_ -> MET_PhotonEnUp_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::PhotonEnUp));
  nBranches_ -> MET_PhotonEnDown_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::PhotonEnDown));
  nBranches_ -> MET_NoShift_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::NoShift));
  //nBranches_ -> MET_JetResUpSmear_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::JetResUpSmear));
  //nBranches_ -> MET_JetResDownSmear_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::JetResDownSmear));
  //nBranches_ -> MET_METUncertaintySize_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::METUncertaintySize));
  //nBranches_ -> MET_METUncertaintySize_sumEt.push_back(metmodified.shiftedSumEt(pat::MET::METFullUncertaintySize));
  
  //************************************************************************
  // MET with PF
  nBranches_ -> METPF_rawet.push_back(metmodifiedPF.uncorPt());
  nBranches_ -> METPF_rawphi.push_back(metmodifiedPF.uncorPhi());
  nBranches_ -> METPF_rawsumEt.push_back(metmodifiedPF.uncorSumEt());

  nBranches_ -> METPF_et.push_back(metmodifiedPF.pt());
  nBranches_ -> METPF_px.push_back(metmodifiedPF.px());
  nBranches_ -> METPF_py.push_back(metmodifiedPF.py());
  nBranches_ -> METPF_phi.push_back(metmodifiedPF.phi());
  nBranches_ -> METPF_sumEt.push_back(metmodifiedPF.sumEt());
  //-- PT --//
  
  nBranches_ -> METPF_JetResUp_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::JetResUp));
  nBranches_ -> METPF_JetResDown_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::JetResDown));
  nBranches_ -> METPF_JetEnUp_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::JetEnUp));
  nBranches_ -> METPF_JetEnDown_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::JetEnDown));
  nBranches_ -> METPF_MuonEnUp_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::MuonEnUp));
  nBranches_ -> METPF_MuonEnDown_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::MuonEnDown));
  nBranches_ -> METPF_ElectronEnUp_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::ElectronEnUp));
  nBranches_ -> METPF_ElectronEnDown_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::ElectronEnDown));
  nBranches_ -> METPF_TauEnUp_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::TauEnUp));
  nBranches_ -> METPF_TauEnDown_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::TauEnDown));
  nBranches_ -> METPF_UnclusteredEnUp_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPF_UnclusteredEnDown_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPF_PhotonEnUp_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::PhotonEnUp));
  nBranches_ -> METPF_PhotonEnDown_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::PhotonEnDown));
  nBranches_ -> METPF_NoShift_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::NoShift));
  //nBranches_ -> METPF_JetResUpSmear_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::JetResUpSmear));
  //nBranches_ -> METPF_JetResDownSmear_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::JetResDownSmear));
  //nBranches_ -> METPF_METUncertaintySize_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::METUncertaintySize));
  //nBranches_ -> METPF_METUncertaintySize_pt.push_back(metmodifiedPF.shiftedPt(pat::MET::METFullUncertaintySize));
  //-- Px --//
  nBranches_ -> METPF_JetResUp_px.push_back(metmodifiedPF.shiftedPx(pat::MET::JetResUp));
  nBranches_ -> METPF_JetResDown_px.push_back(metmodifiedPF.shiftedPx(pat::MET::JetResDown));
  nBranches_ -> METPF_JetEnUp_px.push_back(metmodifiedPF.shiftedPx(pat::MET::JetEnUp));
  nBranches_ -> METPF_JetEnDown_px.push_back(metmodifiedPF.shiftedPx(pat::MET::JetEnDown));
  nBranches_ -> METPF_MuonEnUp_px.push_back(metmodifiedPF.shiftedPx(pat::MET::MuonEnUp));
  nBranches_ -> METPF_MuonEnDown_px.push_back(metmodifiedPF.shiftedPx(pat::MET::MuonEnDown));
  nBranches_ -> METPF_ElectronEnUp_px.push_back(metmodifiedPF.shiftedPx(pat::MET::ElectronEnUp));
  nBranches_ -> METPF_ElectronEnDown_px.push_back(metmodifiedPF.shiftedPx(pat::MET::ElectronEnDown));
  nBranches_ -> METPF_TauEnUp_px.push_back(metmodifiedPF.shiftedPx(pat::MET::TauEnUp));
  nBranches_ -> METPF_TauEnDown_px.push_back(metmodifiedPF.shiftedPx(pat::MET::TauEnDown));
  nBranches_ -> METPF_UnclusteredEnUp_px.push_back(metmodifiedPF.shiftedPx(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPF_UnclusteredEnDown_px.push_back(metmodifiedPF.shiftedPx(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPF_PhotonEnUp_px.push_back(metmodifiedPF.shiftedPx(pat::MET::PhotonEnUp));
  nBranches_ -> METPF_PhotonEnDown_px.push_back(metmodifiedPF.shiftedPx(pat::MET::PhotonEnDown));
  nBranches_ -> METPF_NoShift_px.push_back(metmodifiedPF.shiftedPx(pat::MET::NoShift));
  //nBranches_ -> METPF_JetResUpSmear_px.push_back(metmodifiedPF.shiftedPx(pat::MET::JetResUpSmear));
  //nBranches_ -> METPF_JetResDownSmear_px.push_back(metmodifiedPF.shiftedPx(pat::MET::JetResDownSmear));
  //nBranches_ -> METPF_METUncertaintySize_px.push_back(metmodifiedPF.shiftedPx(pat::MET::METUncertaintySize));
  //nBranches_ -> METPF_METUncertaintySize_px.push_back(metmodifiedPF.shiftedPx(pat::MET::METFullUncertaintySize));
  //-- Py --//
  nBranches_ -> METPF_JetResUp_py.push_back(metmodifiedPF.shiftedPy(pat::MET::JetResUp));
  nBranches_ -> METPF_JetResDown_py.push_back(metmodifiedPF.shiftedPy(pat::MET::JetResDown));
  nBranches_ -> METPF_JetEnUp_py.push_back(metmodifiedPF.shiftedPy(pat::MET::JetEnUp));
  nBranches_ -> METPF_JetEnDown_py.push_back(metmodifiedPF.shiftedPy(pat::MET::JetEnDown));
  nBranches_ -> METPF_MuonEnUp_py.push_back(metmodifiedPF.shiftedPy(pat::MET::MuonEnUp));
  nBranches_ -> METPF_MuonEnDown_py.push_back(metmodifiedPF.shiftedPy(pat::MET::MuonEnDown));
  nBranches_ -> METPF_ElectronEnUp_py.push_back(metmodifiedPF.shiftedPy(pat::MET::ElectronEnUp));
  nBranches_ -> METPF_ElectronEnDown_py.push_back(metmodifiedPF.shiftedPy(pat::MET::ElectronEnDown));
  nBranches_ -> METPF_TauEnUp_py.push_back(metmodifiedPF.shiftedPy(pat::MET::TauEnUp));
  nBranches_ -> METPF_TauEnDown_py.push_back(metmodifiedPF.shiftedPy(pat::MET::TauEnDown));
  nBranches_ -> METPF_UnclusteredEnUp_py.push_back(metmodifiedPF.shiftedPy(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPF_UnclusteredEnDown_py.push_back(metmodifiedPF.shiftedPy(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPF_PhotonEnUp_py.push_back(metmodifiedPF.shiftedPy(pat::MET::PhotonEnUp));
  nBranches_ -> METPF_PhotonEnDown_py.push_back(metmodifiedPF.shiftedPy(pat::MET::PhotonEnDown));
  nBranches_ -> METPF_NoShift_py.push_back(metmodifiedPF.shiftedPy(pat::MET::NoShift));
  //nBranches_ -> METPF_JetResUpSmear_py.push_back(metmodifiedPF.shiftedPy(pat::MET::JetResUpSmear));
  //nBranches_ -> METPF_JetResDownSmear_py.push_back(metmodifiedPF.shiftedPy(pat::MET::JetResDownSmear));
  //nBranches_ -> METPF_METUncertaintySize_py.push_back(metmodifiedPF.shiftedPy(pat::MET::METUncertaintySize));
  //nBranches_ -> METPF_METUncertaintySize_py.push_back(metmodifiedPF.shiftedPy(pat::MET::METFullUncertaintySize));
  //-- Phi --//
  nBranches_ -> METPF_JetResUp_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::JetResUp));
  nBranches_ -> METPF_JetResDown_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::JetResDown));
  nBranches_ -> METPF_JetEnUp_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::JetEnUp));
  nBranches_ -> METPF_JetEnDown_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::JetEnDown));
  nBranches_ -> METPF_MuonEnUp_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::MuonEnUp));
  nBranches_ -> METPF_MuonEnDown_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::MuonEnDown));
  nBranches_ -> METPF_ElectronEnUp_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::ElectronEnUp));
  nBranches_ -> METPF_ElectronEnDown_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::ElectronEnDown));
  nBranches_ -> METPF_TauEnUp_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::TauEnUp));
  nBranches_ -> METPF_TauEnDown_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::TauEnDown));
  nBranches_ -> METPF_UnclusteredEnUp_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPF_UnclusteredEnDown_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPF_PhotonEnUp_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::PhotonEnUp));
  nBranches_ -> METPF_PhotonEnDown_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::PhotonEnDown));
  nBranches_ -> METPF_NoShift_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::NoShift));
  //nBranches_ -> METPF_JetResUpSmear_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::JetResUpSmear));
  //nBranches_ -> METPF_JetResDownSmear_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::JetResDownSmear));
  //nBranches_ -> METPF_METUncertaintySize_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::METUncertaintySize));
  //nBranches_ -> METPF_METUncertaintySize_phi.push_back(metmodifiedPF.shiftedPhi(pat::MET::METFullUncertaintySize));
  //-- SumEt --//
  nBranches_ -> METPF_JetResUp_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::JetResUp));
  nBranches_ -> METPF_JetResDown_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::JetResDown));
  nBranches_ -> METPF_JetEnUp_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::JetEnUp));
  nBranches_ -> METPF_JetEnDown_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::JetEnDown));
  nBranches_ -> METPF_MuonEnUp_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::MuonEnUp));
  nBranches_ -> METPF_MuonEnDown_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::MuonEnDown));
  nBranches_ -> METPF_ElectronEnUp_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::ElectronEnUp));
  nBranches_ -> METPF_ElectronEnDown_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::ElectronEnDown));
  nBranches_ -> METPF_TauEnUp_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::TauEnUp));
  nBranches_ -> METPF_TauEnDown_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::TauEnDown));
  nBranches_ -> METPF_UnclusteredEnUp_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPF_UnclusteredEnDown_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPF_PhotonEnUp_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::PhotonEnUp));
  nBranches_ -> METPF_PhotonEnDown_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::PhotonEnDown));
  nBranches_ -> METPF_NoShift_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::NoShift));
  //nBranches_ -> METPF_JetResUpSmear_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::JetResUpSmear));
  //nBranches_ -> METPF_JetResDownSmear_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::JetResDownSmear));
  //nBranches_ -> METPF_METUncertaintySize_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::METUncertaintySize));
  //nBranches_ -> METPF_METUncertaintySize_sumEt.push_back(metmodifiedPF.shiftedSumEt(pat::MET::METFullUncertaintySize));
  
  //*******************************************************************************************
  // MET Puppi without PF
  nBranches_ -> METPuppi_rawet.push_back(metpuppi.uncorPt());
  nBranches_ -> METPuppi_rawphi.push_back(metpuppi.uncorPhi());
  nBranches_ -> METPuppi_rawsumEt.push_back(metpuppi.uncorSumEt());

  nBranches_ -> METPuppi_et.push_back(metpuppi.pt());
  nBranches_ -> METPuppi_px.push_back(metpuppi.px());
  nBranches_ -> METPuppi_py.push_back(metpuppi.py());
  nBranches_ -> METPuppi_phi.push_back(metpuppi.phi());
  nBranches_ -> METPuppi_sumEt.push_back(metpuppi.sumEt());
  //-- PT --//
  nBranches_ -> METPuppi_JetResUp_pt.push_back(metpuppi.shiftedPt(pat::MET::JetResUp));
  nBranches_ -> METPuppi_JetResDown_pt.push_back(metpuppi.shiftedPt(pat::MET::JetResDown));
  nBranches_ -> METPuppi_JetEnUp_pt.push_back(metpuppi.shiftedPt(pat::MET::JetEnUp));
  nBranches_ -> METPuppi_JetEnDown_pt.push_back(metpuppi.shiftedPt(pat::MET::JetEnDown));
  nBranches_ -> METPuppi_MuonEnUp_pt.push_back(metpuppi.shiftedPt(pat::MET::MuonEnUp));
  nBranches_ -> METPuppi_MuonEnDown_pt.push_back(metpuppi.shiftedPt(pat::MET::MuonEnDown));
  nBranches_ -> METPuppi_ElectronEnUp_pt.push_back(metpuppi.shiftedPt(pat::MET::ElectronEnUp));
  nBranches_ -> METPuppi_ElectronEnDown_pt.push_back(metpuppi.shiftedPt(pat::MET::ElectronEnDown));
  nBranches_ -> METPuppi_TauEnUp_pt.push_back(metpuppi.shiftedPt(pat::MET::TauEnUp));
  nBranches_ -> METPuppi_TauEnDown_pt.push_back(metpuppi.shiftedPt(pat::MET::TauEnDown));
  nBranches_ -> METPuppi_UnclusteredEnUp_pt.push_back(metpuppi.shiftedPt(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPuppi_UnclusteredEnDown_pt.push_back(metpuppi.shiftedPt(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPuppi_PhotonEnUp_pt.push_back(metpuppi.shiftedPt(pat::MET::PhotonEnUp));
  nBranches_ -> METPuppi_PhotonEnDown_pt.push_back(metpuppi.shiftedPt(pat::MET::PhotonEnDown));
  nBranches_ -> METPuppi_NoShift_pt.push_back(metpuppi.shiftedPt(pat::MET::NoShift));
  //nBranches_ -> METPuppi_JetResUpSmear_pt.push_back(metpuppi.shiftedPt(pat::MET::JetResUpSmear));
  //nBranches_ -> METPuppi_JetResDownSmear_pt.push_back(metpuppi.shiftedPt(pat::MET::JetResDownSmear));
  //nBranches_ -> METPuppi_METUncertaintySize_pt.push_back(metpuppi.shiftedPt(pat::MET::METUncertaintySize));
  //nBranches_ -> METPuppi_METUncertaintySize_pt.push_back(metpuppi.shiftedPt(pat::MET::METFullUncertaintySize));
  //-- Px --//
  nBranches_ -> METPuppi_JetResUp_px.push_back(metpuppi.shiftedPx(pat::MET::JetResUp));
  nBranches_ -> METPuppi_JetResDown_px.push_back(metpuppi.shiftedPx(pat::MET::JetResDown));
  nBranches_ -> METPuppi_JetEnUp_px.push_back(metpuppi.shiftedPx(pat::MET::JetEnUp));
  nBranches_ -> METPuppi_JetEnDown_px.push_back(metpuppi.shiftedPx(pat::MET::JetEnDown));
  nBranches_ -> METPuppi_MuonEnUp_px.push_back(metpuppi.shiftedPx(pat::MET::MuonEnUp));
  nBranches_ -> METPuppi_MuonEnDown_px.push_back(metpuppi.shiftedPx(pat::MET::MuonEnDown));
  nBranches_ -> METPuppi_ElectronEnUp_px.push_back(metpuppi.shiftedPx(pat::MET::ElectronEnUp));
  nBranches_ -> METPuppi_ElectronEnDown_px.push_back(metpuppi.shiftedPx(pat::MET::ElectronEnDown));
  nBranches_ -> METPuppi_TauEnUp_px.push_back(metpuppi.shiftedPx(pat::MET::TauEnUp));
  nBranches_ -> METPuppi_TauEnDown_px.push_back(metpuppi.shiftedPx(pat::MET::TauEnDown));
  nBranches_ -> METPuppi_UnclusteredEnUp_px.push_back(metpuppi.shiftedPx(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPuppi_UnclusteredEnDown_px.push_back(metpuppi.shiftedPx(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPuppi_PhotonEnUp_px.push_back(metpuppi.shiftedPx(pat::MET::PhotonEnUp));
  nBranches_ -> METPuppi_PhotonEnDown_px.push_back(metpuppi.shiftedPx(pat::MET::PhotonEnDown));
  nBranches_ -> METPuppi_NoShift_px.push_back(metpuppi.shiftedPx(pat::MET::NoShift));
  //nBranches_ -> METPuppi_JetResUpSmear_px.push_back(metpuppi.shiftedPx(pat::MET::JetResUpSmear));
  //nBranches_ -> METPuppi_JetResDownSmear_px.push_back(metpuppi.shiftedPx(pat::MET::JetResDownSmear));
  //nBranches_ -> METPuppi_METUncertaintySize_px.push_back(metpuppi.shiftedPx(pat::MET::METUncertaintySize));
  //nBranches_ -> METPuppi_METUncertaintySize_px.push_back(metpuppi.shiftedPx(pat::MET::METFullUncertaintySize));
  //-- Py --//
  nBranches_ -> METPuppi_JetResUp_py.push_back(metpuppi.shiftedPy(pat::MET::JetResUp));
  nBranches_ -> METPuppi_JetResDown_py.push_back(metpuppi.shiftedPy(pat::MET::JetResDown));
  nBranches_ -> METPuppi_JetEnUp_py.push_back(metpuppi.shiftedPy(pat::MET::JetEnUp));
  nBranches_ -> METPuppi_JetEnDown_py.push_back(metpuppi.shiftedPy(pat::MET::JetEnDown));
  nBranches_ -> METPuppi_MuonEnUp_py.push_back(metpuppi.shiftedPy(pat::MET::MuonEnUp));
  nBranches_ -> METPuppi_MuonEnDown_py.push_back(metpuppi.shiftedPy(pat::MET::MuonEnDown));
  nBranches_ -> METPuppi_ElectronEnUp_py.push_back(metpuppi.shiftedPy(pat::MET::ElectronEnUp));
  nBranches_ -> METPuppi_ElectronEnDown_py.push_back(metpuppi.shiftedPy(pat::MET::ElectronEnDown));
  nBranches_ -> METPuppi_TauEnUp_py.push_back(metpuppi.shiftedPy(pat::MET::TauEnUp));
  nBranches_ -> METPuppi_TauEnDown_py.push_back(metpuppi.shiftedPy(pat::MET::TauEnDown));
  nBranches_ -> METPuppi_UnclusteredEnUp_py.push_back(metpuppi.shiftedPy(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPuppi_UnclusteredEnDown_py.push_back(metpuppi.shiftedPy(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPuppi_PhotonEnUp_py.push_back(metpuppi.shiftedPy(pat::MET::PhotonEnUp));
  nBranches_ -> METPuppi_PhotonEnDown_py.push_back(metpuppi.shiftedPy(pat::MET::PhotonEnDown));
  nBranches_ -> METPuppi_NoShift_py.push_back(metpuppi.shiftedPy(pat::MET::NoShift));
  //nBranches_ -> METPuppi_JetResUpSmear_py.push_back(metpuppi.shiftedPy(pat::MET::JetResUpSmear));
  //nBranches_ -> METPuppi_JetResDownSmear_py.push_back(metpuppi.shiftedPy(pat::MET::JetResDownSmear));
  //nBranches_ -> METPuppi_METUncertaintySize_py.push_back(metpuppi.shiftedPy(pat::MET::METUncertaintySize));
  //nBranches_ -> METPuppi_METUncertaintySize_py.push_back(metpuppi.shiftedPy(pat::MET::METFullUncertaintySize));
  //-- Phi --//
  nBranches_ -> METPuppi_JetResUp_phi.push_back(metpuppi.shiftedPhi(pat::MET::JetResUp));
  nBranches_ -> METPuppi_JetResDown_phi.push_back(metpuppi.shiftedPhi(pat::MET::JetResDown));
  nBranches_ -> METPuppi_JetEnUp_phi.push_back(metpuppi.shiftedPhi(pat::MET::JetEnUp));
  nBranches_ -> METPuppi_JetEnDown_phi.push_back(metpuppi.shiftedPhi(pat::MET::JetEnDown));
  nBranches_ -> METPuppi_MuonEnUp_phi.push_back(metpuppi.shiftedPhi(pat::MET::MuonEnUp));
  nBranches_ -> METPuppi_MuonEnDown_phi.push_back(metpuppi.shiftedPhi(pat::MET::MuonEnDown));
  nBranches_ -> METPuppi_ElectronEnUp_phi.push_back(metpuppi.shiftedPhi(pat::MET::ElectronEnUp));
  nBranches_ -> METPuppi_ElectronEnDown_phi.push_back(metpuppi.shiftedPhi(pat::MET::ElectronEnDown));
  nBranches_ -> METPuppi_TauEnUp_phi.push_back(metpuppi.shiftedPhi(pat::MET::TauEnUp));
  nBranches_ -> METPuppi_TauEnDown_phi.push_back(metpuppi.shiftedPhi(pat::MET::TauEnDown));
  nBranches_ -> METPuppi_UnclusteredEnUp_phi.push_back(metpuppi.shiftedPhi(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPuppi_UnclusteredEnDown_phi.push_back(metpuppi.shiftedPhi(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPuppi_PhotonEnUp_phi.push_back(metpuppi.shiftedPhi(pat::MET::PhotonEnUp));
  nBranches_ -> METPuppi_PhotonEnDown_phi.push_back(metpuppi.shiftedPhi(pat::MET::PhotonEnDown));
  nBranches_ -> METPuppi_NoShift_phi.push_back(metpuppi.shiftedPhi(pat::MET::NoShift));
  //nBranches_ -> METPuppi_JetResUpSmear_phi.push_back(metpuppi.shiftedPhi(pat::MET::JetResUpSmear));
  //nBranches_ -> METPuppi_JetResDownSmear_phi.push_back(metpuppi.shiftedPhi(pat::MET::JetResDownSmear));
  //nBranches_ -> METPuppi_METUncertaintySize_phi.push_back(metpuppi.shiftedPhi(pat::MET::METUncertaintySize));
  //nBranches_ -> METPuppi_METUncertaintySize_phi.push_back(metpuppi.shiftedPhi(pat::MET::METFullUncertaintySize));
  //-- SumEt --//
  nBranches_ -> METPuppi_JetResUp_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::JetResUp));
  nBranches_ -> METPuppi_JetResDown_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::JetResDown));
  nBranches_ -> METPuppi_JetEnUp_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::JetEnUp));
  nBranches_ -> METPuppi_JetEnDown_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::JetEnDown));
  nBranches_ -> METPuppi_MuonEnUp_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::MuonEnUp));
  nBranches_ -> METPuppi_MuonEnDown_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::MuonEnDown));
  nBranches_ -> METPuppi_ElectronEnUp_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::ElectronEnUp));
  nBranches_ -> METPuppi_ElectronEnDown_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::ElectronEnDown));
  nBranches_ -> METPuppi_TauEnUp_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::TauEnUp));
  nBranches_ -> METPuppi_TauEnDown_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::TauEnDown));
  nBranches_ -> METPuppi_UnclusteredEnUp_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPuppi_UnclusteredEnDown_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPuppi_PhotonEnUp_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::PhotonEnUp));
  nBranches_ -> METPuppi_PhotonEnDown_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::PhotonEnDown));
  nBranches_ -> METPuppi_NoShift_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::NoShift));
  //nBranches_ -> METPuppi_JetResUpSmear_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::JetResUpSmear));
  //nBranches_ -> METPuppi_JetResDownSmear_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::JetResDownSmear));
  //nBranches_ -> METPuppi_METUncertaintySize_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::METUncertaintySize));
  //nBranches_ -> METPuppi_METUncertaintySize_sumEt.push_back(metpuppi.shiftedSumEt(pat::MET::METFullUncertaintySize));
  
  //***********************************************************************************
  // MET Puppi with PF
  nBranches_ -> METPuppiPF_rawet.push_back(metpuppiPF.uncorPt());
  nBranches_ -> METPuppiPF_rawphi.push_back(metpuppiPF.uncorPhi());
  nBranches_ -> METPuppiPF_rawsumEt.push_back(metpuppiPF.uncorSumEt());

  nBranches_ -> METPuppiPF_et.push_back(metpuppiPF.pt());
  nBranches_ -> METPuppiPF_px.push_back(metpuppiPF.px());
  nBranches_ -> METPuppiPF_py.push_back(metpuppiPF.py());
  nBranches_ -> METPuppiPF_phi.push_back(metpuppiPF.phi());
  nBranches_ -> METPuppiPF_sumEt.push_back(metpuppiPF.sumEt());
  //-- PT --//
  nBranches_ -> METPuppiPF_JetResUp_pt.push_back(metpuppiPF.shiftedPt(pat::MET::JetResUp));
  nBranches_ -> METPuppiPF_JetResDown_pt.push_back(metpuppiPF.shiftedPt(pat::MET::JetResDown));
  nBranches_ -> METPuppiPF_JetEnUp_pt.push_back(metpuppiPF.shiftedPt(pat::MET::JetEnUp));
  nBranches_ -> METPuppiPF_JetEnDown_pt.push_back(metpuppiPF.shiftedPt(pat::MET::JetEnDown));
  nBranches_ -> METPuppiPF_MuonEnUp_pt.push_back(metpuppiPF.shiftedPt(pat::MET::MuonEnUp));
  nBranches_ -> METPuppiPF_MuonEnDown_pt.push_back(metpuppiPF.shiftedPt(pat::MET::MuonEnDown));
  nBranches_ -> METPuppiPF_ElectronEnUp_pt.push_back(metpuppiPF.shiftedPt(pat::MET::ElectronEnUp));
  nBranches_ -> METPuppiPF_ElectronEnDown_pt.push_back(metpuppiPF.shiftedPt(pat::MET::ElectronEnDown));
  nBranches_ -> METPuppiPF_TauEnUp_pt.push_back(metpuppiPF.shiftedPt(pat::MET::TauEnUp));
  nBranches_ -> METPuppiPF_TauEnDown_pt.push_back(metpuppiPF.shiftedPt(pat::MET::TauEnDown));
  nBranches_ -> METPuppiPF_UnclusteredEnUp_pt.push_back(metpuppiPF.shiftedPt(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPuppiPF_UnclusteredEnDown_pt.push_back(metpuppiPF.shiftedPt(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPuppiPF_PhotonEnUp_pt.push_back(metpuppiPF.shiftedPt(pat::MET::PhotonEnUp));
  nBranches_ -> METPuppiPF_PhotonEnDown_pt.push_back(metpuppiPF.shiftedPt(pat::MET::PhotonEnDown));
  nBranches_ -> METPuppiPF_NoShift_pt.push_back(metpuppiPF.shiftedPt(pat::MET::NoShift));
  //nBranches_ -> METPuppiPF_JetResUpSmear_pt.push_back(metpuppiPF.shiftedPt(pat::MET::JetResUpSmear));
  //nBranches_ -> METPuppiPF_JetResDownSmear_pt.push_back(metpuppiPF.shiftedPt(pat::MET::JetResDownSmear));
  //nBranches_ -> METPuppiPF_METUncertaintySize_pt.push_back(metpuppiPF.shiftedPt(pat::MET::METUncertaintySize));
  //nBranches_ -> METPuppiPF_METUncertaintySize_pt.push_back(metpuppiPF.shiftedPt(pat::MET::METFullUncertaintySize));
  //-- Px --//
  nBranches_ -> METPuppiPF_JetResUp_px.push_back(metpuppiPF.shiftedPx(pat::MET::JetResUp));
  nBranches_ -> METPuppiPF_JetResDown_px.push_back(metpuppiPF.shiftedPx(pat::MET::JetResDown));
  nBranches_ -> METPuppiPF_JetEnUp_px.push_back(metpuppiPF.shiftedPx(pat::MET::JetEnUp));
  nBranches_ -> METPuppiPF_JetEnDown_px.push_back(metpuppiPF.shiftedPx(pat::MET::JetEnDown));
  nBranches_ -> METPuppiPF_MuonEnUp_px.push_back(metpuppiPF.shiftedPx(pat::MET::MuonEnUp));
  nBranches_ -> METPuppiPF_MuonEnDown_px.push_back(metpuppiPF.shiftedPx(pat::MET::MuonEnDown));
  nBranches_ -> METPuppiPF_ElectronEnUp_px.push_back(metpuppiPF.shiftedPx(pat::MET::ElectronEnUp));
  nBranches_ -> METPuppiPF_ElectronEnDown_px.push_back(metpuppiPF.shiftedPx(pat::MET::ElectronEnDown));
  nBranches_ -> METPuppiPF_TauEnUp_px.push_back(metpuppiPF.shiftedPx(pat::MET::TauEnUp));
  nBranches_ -> METPuppiPF_TauEnDown_px.push_back(metpuppiPF.shiftedPx(pat::MET::TauEnDown));
  nBranches_ -> METPuppiPF_UnclusteredEnUp_px.push_back(metpuppiPF.shiftedPx(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPuppiPF_UnclusteredEnDown_px.push_back(metpuppiPF.shiftedPx(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPuppiPF_PhotonEnUp_px.push_back(metpuppiPF.shiftedPx(pat::MET::PhotonEnUp));
  nBranches_ -> METPuppiPF_PhotonEnDown_px.push_back(metpuppiPF.shiftedPx(pat::MET::PhotonEnDown));
  nBranches_ -> METPuppiPF_NoShift_px.push_back(metpuppiPF.shiftedPx(pat::MET::NoShift));
  //nBranches_ -> METPuppiPF_JetResUpSmear_px.push_back(metpuppiPF.shiftedPx(pat::MET::JetResUpSmear));
  //nBranches_ -> METPuppiPF_JetResDownSmear_px.push_back(metpuppiPF.shiftedPx(pat::MET::JetResDownSmear));
  //nBranches_ -> METPuppiPF_METUncertaintySize_px.push_back(metpuppiPF.shiftedPx(pat::MET::METUncertaintySize));
  //nBranches_ -> METPuppiPF_METUncertaintySize_px.push_back(metpuppiPF.shiftedPx(pat::MET::METFullUncertaintySize));
  //-- Py --//
  nBranches_ -> METPuppiPF_JetResUp_py.push_back(metpuppiPF.shiftedPy(pat::MET::JetResUp));
  nBranches_ -> METPuppiPF_JetResDown_py.push_back(metpuppiPF.shiftedPy(pat::MET::JetResDown));
  nBranches_ -> METPuppiPF_JetEnUp_py.push_back(metpuppiPF.shiftedPy(pat::MET::JetEnUp));
  nBranches_ -> METPuppiPF_JetEnDown_py.push_back(metpuppiPF.shiftedPy(pat::MET::JetEnDown));
  nBranches_ -> METPuppiPF_MuonEnUp_py.push_back(metpuppiPF.shiftedPy(pat::MET::MuonEnUp));
  nBranches_ -> METPuppiPF_MuonEnDown_py.push_back(metpuppiPF.shiftedPy(pat::MET::MuonEnDown));
  nBranches_ -> METPuppiPF_ElectronEnUp_py.push_back(metpuppiPF.shiftedPy(pat::MET::ElectronEnUp));
  nBranches_ -> METPuppiPF_ElectronEnDown_py.push_back(metpuppiPF.shiftedPy(pat::MET::ElectronEnDown));
  nBranches_ -> METPuppiPF_TauEnUp_py.push_back(metpuppiPF.shiftedPy(pat::MET::TauEnUp));
  nBranches_ -> METPuppiPF_TauEnDown_py.push_back(metpuppiPF.shiftedPy(pat::MET::TauEnDown));
  nBranches_ -> METPuppiPF_UnclusteredEnUp_py.push_back(metpuppiPF.shiftedPy(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPuppiPF_UnclusteredEnDown_py.push_back(metpuppiPF.shiftedPy(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPuppiPF_PhotonEnUp_py.push_back(metpuppiPF.shiftedPy(pat::MET::PhotonEnUp));
  nBranches_ -> METPuppiPF_PhotonEnDown_py.push_back(metpuppiPF.shiftedPy(pat::MET::PhotonEnDown));
  nBranches_ -> METPuppiPF_NoShift_py.push_back(metpuppiPF.shiftedPy(pat::MET::NoShift));
  //nBranches_ -> METPuppiPF_JetResUpSmear_py.push_back(metpuppiPF.shiftedPy(pat::MET::JetResUpSmear));
  //nBranches_ -> METPuppiPF_JetResDownSmear_py.push_back(metpuppiPF.shiftedPy(pat::MET::JetResDownSmear));
  //nBranches_ -> METPuppiPF_METUncertaintySize_py.push_back(metpuppiPF.shiftedPy(pat::MET::METUncertaintySize));
  //nBranches_ -> METPuppiPF_METUncertaintySize_py.push_back(metpuppiPF.shiftedPy(pat::MET::METFullUncertaintySize));
  //-- Phi --//
  nBranches_ -> METPuppiPF_JetResUp_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::JetResUp));
  nBranches_ -> METPuppiPF_JetResDown_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::JetResDown));
  nBranches_ -> METPuppiPF_JetEnUp_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::JetEnUp));
  nBranches_ -> METPuppiPF_JetEnDown_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::JetEnDown));
  nBranches_ -> METPuppiPF_MuonEnUp_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::MuonEnUp));
  nBranches_ -> METPuppiPF_MuonEnDown_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::MuonEnDown));
  nBranches_ -> METPuppiPF_ElectronEnUp_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::ElectronEnUp));
  nBranches_ -> METPuppiPF_ElectronEnDown_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::ElectronEnDown));
  nBranches_ -> METPuppiPF_TauEnUp_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::TauEnUp));
  nBranches_ -> METPuppiPF_TauEnDown_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::TauEnDown));
  nBranches_ -> METPuppiPF_UnclusteredEnUp_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPuppiPF_UnclusteredEnDown_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPuppiPF_PhotonEnUp_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::PhotonEnUp));
  nBranches_ -> METPuppiPF_PhotonEnDown_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::PhotonEnDown));
  nBranches_ -> METPuppiPF_NoShift_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::NoShift));
  //nBranches_ -> METPuppiPF_JetResUpSmear_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::JetResUpSmear));
  //nBranches_ -> METPuppiPF_JetResDownSmear_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::JetResDownSmear));
  //nBranches_ -> METPuppiPF_METUncertaintySize_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::METUncertaintySize));
  //nBranches_ -> METPuppiPF_METUncertaintySize_phi.push_back(metpuppiPF.shiftedPhi(pat::MET::METFullUncertaintySize));
  //-- SumEt --//
  nBranches_ -> METPuppiPF_JetResUp_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::JetResUp));
  nBranches_ -> METPuppiPF_JetResDown_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::JetResDown));
  nBranches_ -> METPuppiPF_JetEnUp_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::JetEnUp));
  nBranches_ -> METPuppiPF_JetEnDown_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::JetEnDown));
  nBranches_ -> METPuppiPF_MuonEnUp_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::MuonEnUp));
  nBranches_ -> METPuppiPF_MuonEnDown_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::MuonEnDown));
  nBranches_ -> METPuppiPF_ElectronEnUp_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::ElectronEnUp));
  nBranches_ -> METPuppiPF_ElectronEnDown_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::ElectronEnDown));
  nBranches_ -> METPuppiPF_TauEnUp_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::TauEnUp));
  nBranches_ -> METPuppiPF_TauEnDown_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::TauEnDown));
  nBranches_ -> METPuppiPF_UnclusteredEnUp_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::UnclusteredEnUp));
  nBranches_ -> METPuppiPF_UnclusteredEnDown_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::UnclusteredEnDown));
  nBranches_ -> METPuppiPF_PhotonEnUp_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::PhotonEnUp));
  nBranches_ -> METPuppiPF_PhotonEnDown_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::PhotonEnDown));
  nBranches_ -> METPuppiPF_NoShift_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::NoShift));
  //nBranches_ -> METPuppiPF_JetResUpSmear_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::JetResUpSmear));
  //nBranches_ -> METPuppiPF_JetResDownSmear_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::JetResDownSmear));
  //nBranches_ -> METPuppiPF_METUncertaintySize_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::METUncertaintySize));
  //nBranches_ -> METPuppiPF_METUncertaintySize_sumEt.push_back(metpuppiPF.shiftedSumEt(pat::MET::METFullUncertaintySize));
  

}
