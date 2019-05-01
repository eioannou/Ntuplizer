#ifndef NtupleBranches_H
#define NtupleBranches_H

#include <DataFormats/PatCandidates/interface/MET.h>
#include "DataFormats/FWLite/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "FWCore/Framework/interface/Event.h"
#include "TMatrixD.h"
#include "TMatrix.h"

#include "TTree.h"
#include "TLorentzVector.h"

class NtupleBranches {

 public:
  NtupleBranches( std::map< std::string, bool>& runFlags, TTree* tree = 0);
  ~NtupleBranches( void );

  void branch( std::map< std::string, bool >& runFlags );
  void getEventByLabels( edm::EventBase const & event );
  void reset( void );
  void fillTree( void ){ tree_ -> Fill(); };

  /*-------------- Event infos ---------------------------*/
  int EVENT_event;
  int EVENT_run;
  int EVENT_lumiBlock;

  /*-------------- MET -------------------------------------*/
  // MET Modified without PF
  std::vector<float> METraw_pt;
  std::vector<float> METraw_phi;
  std::vector<float> METraw_sumEt;
  std::vector<float> MET_pt;
  std::vector<float> MET_phi;
  std::vector<float> MET_sumEt;
  //--------------------------------------
  std::vector<float> MET_JetResUp_pt;
  std::vector<float> MET_JetResDown_pt;
  std::vector<float> MET_JetEnUp_pt;
  std::vector<float> MET_JetEnDown_pt;
  std::vector<float> MET_MuonEnUp_pt;
  std::vector<float> MET_MuonEnDown_pt;
  std::vector<float> MET_ElectronEnUp_pt;
  std::vector<float> MET_ElectronEnDown_pt;
  std::vector<float> MET_TauEnUp_pt;
  std::vector<float> MET_TauEnDown_pt;
  std::vector<float> MET_UnclusteredEnUp_pt;
  std::vector<float> MET_UnclusteredEnDown_pt;
  std::vector<float> MET_PhotonEnUp_pt;
  std::vector<float> MET_PhotonEnDown_pt;
  std::vector<float> MET_NoShift_pt;
  std::vector<float> MET_METUncertaintySize_pt;
  std::vector<float> MET_JetResUpSmear_pt;
  std::vector<float> MET_JetResDownSmear_pt;
  std::vector<float> MET_METFullUncertaintySize_pt;
  //----------------------------------------------------
  std::vector<float> MET_JetResUp_phi;
  std::vector<float> MET_JetResDown_phi;
  std::vector<float> MET_JetEnUp_phi;
  std::vector<float> MET_JetEnDown_phi;
  std::vector<float> MET_MuonEnUp_phi;
  std::vector<float> MET_MuonEnDown_phi;
  std::vector<float> MET_ElectronEnUp_phi;
  std::vector<float> MET_ElectronEnDown_phi;
  std::vector<float> MET_TauEnUp_phi;
  std::vector<float> MET_TauEnDown_phi;
  std::vector<float> MET_UnclusteredEnUp_phi;
  std::vector<float> MET_UnclusteredEnDown_phi;
  std::vector<float> MET_PhotonEnUp_phi;
  std::vector<float> MET_PhotonEnDown_phi;
  std::vector<float> MET_NoShift_phi;
  std::vector<float> MET_METUncertaintySize_phi;
  std::vector<float> MET_JetResUpSmear_phi;
  std::vector<float> MET_JetResDownSmear_phi;
  std::vector<float> MET_METFullUncertaintySize_phi;
  //------------------------------------------------------
  std::vector<float> MET_JetResUp_sumEt;
  std::vector<float> MET_JetResDown_sumEt;
  std::vector<float> MET_JetEnUp_sumEt;
  std::vector<float> MET_JetEnDown_sumEt;
  std::vector<float> MET_MuonEnUp_sumEt;
  std::vector<float> MET_MuonEnDown_sumEt;
  std::vector<float> MET_ElectronEnUp_sumEt;
  std::vector<float> MET_ElectronEnDown_sumEt;
  std::vector<float> MET_TauEnUp_sumEt;
  std::vector<float> MET_TauEnDown_sumEt;
  std::vector<float> MET_UnclusteredEnUp_sumEt;
  std::vector<float> MET_UnclusteredEnDown_sumEt;
  std::vector<float> MET_PhotonEnUp_sumEt;
  std::vector<float> MET_PhotonEnDown_sumEt;
  std::vector<float> MET_NoShift_sumEt;
  std::vector<float> MET_METUncertaintySize_sumEt;
  std::vector<float> MET_JetResUpSmear_sumEt;
  std::vector<float> MET_JetResDownSmear_sumEt;
  std::vector<float> MET_METFullUncertaintySize_sumEt;
  //-------------------------------------------------------
  // MET Modified with PF
  std::vector<float> METPFraw_pt;
  std::vector<float> METPFraw_phi;
  std::vector<float> METPFraw_sumEt;
  std::vector<float> METPF_pt;
  std::vector<float> METPF_phi;
  std::vector<float> METPF_sumEt;
  //--------------------------------------
  std::vector<float> METPF_JetResUp_pt;
  std::vector<float> METPF_JetResDown_pt;
  std::vector<float> METPF_JetEnUp_pt;
  std::vector<float> METPF_JetEnDown_pt;
  std::vector<float> METPF_MuonEnUp_pt;
  std::vector<float> METPF_MuonEnDown_pt;
  std::vector<float> METPF_ElectronEnUp_pt;
  std::vector<float> METPF_ElectronEnDown_pt;
  std::vector<float> METPF_TauEnUp_pt;
  std::vector<float> METPF_TauEnDown_pt;
  std::vector<float> METPF_UnclusteredEnUp_pt;
  std::vector<float> METPF_UnclusteredEnDown_pt;
  std::vector<float> METPF_PhotonEnUp_pt;
  std::vector<float> METPF_PhotonEnDown_pt;
  std::vector<float> METPF_NoShift_pt;
  std::vector<float> METPF_METUncertaintySize_pt;
  std::vector<float> METPF_JetResUpSmear_pt;
  std::vector<float> METPF_JetResDownSmear_pt;
  std::vector<float> METPF_METFullUncertaintySize_pt;
  //----------------------------------------------------
  std::vector<float> METPF_JetResUp_phi;
  std::vector<float> METPF_JetResDown_phi;
  std::vector<float> METPF_JetEnUp_phi;
  std::vector<float> METPF_JetEnDown_phi;
  std::vector<float> METPF_MuonEnUp_phi;
  std::vector<float> METPF_MuonEnDown_phi;
  std::vector<float> METPF_ElectronEnUp_phi;
  std::vector<float> METPF_ElectronEnDown_phi;
  std::vector<float> METPF_TauEnUp_phi;
  std::vector<float> METPF_TauEnDown_phi;
  std::vector<float> METPF_UnclusteredEnUp_phi;
  std::vector<float> METPF_UnclusteredEnDown_phi;
  std::vector<float> METPF_PhotonEnUp_phi;
  std::vector<float> METPF_PhotonEnDown_phi;
  std::vector<float> METPF_NoShift_phi;
  std::vector<float> METPF_METUncertaintySize_phi;
  std::vector<float> METPF_JetResUpSmear_phi;
  std::vector<float> METPF_JetResDownSmear_phi;
  std::vector<float> METPF_METFullUncertaintySize_phi;
  //------------------------------------------------------
  std::vector<float> METPF_JetResUp_sumEt;
  std::vector<float> METPF_JetResDown_sumEt;
  std::vector<float> METPF_JetEnUp_sumEt;
  std::vector<float> METPF_JetEnDown_sumEt;
  std::vector<float> METPF_MuonEnUp_sumEt;
  std::vector<float> METPF_MuonEnDown_sumEt;
  std::vector<float> METPF_ElectronEnUp_sumEt;
  std::vector<float> METPF_ElectronEnDown_sumEt;
  std::vector<float> METPF_TauEnUp_sumEt;
  std::vector<float> METPF_TauEnDown_sumEt;
  std::vector<float> METPF_UnclusteredEnUp_sumEt;
  std::vector<float> METPF_UnclusteredEnDown_sumEt;
  std::vector<float> METPF_PhotonEnUp_sumEt;
  std::vector<float> METPF_PhotonEnDown_sumEt;
  std::vector<float> METPF_NoShift_sumEt;
  std::vector<float> METPF_METUncertaintySize_sumEt;
  std::vector<float> METPF_JetResUpSmear_sumEt;
  std::vector<float> METPF_JetResDownSmear_sumEt;
  std::vector<float> METPF_METFullUncertaintySize_sumEt;
  //--------------------------------------------------------------
  // MET Puppi without PF
  std::vector<float> METPuppiraw_pt;
  std::vector<float> METPuppiraw_phi;
  std::vector<float> METPuppiraw_sumEt;
  std::vector<float> METPuppi_pt;
  std::vector<float> METPuppi_phi;
  std::vector<float> METPuppi_sumEt;
  //--------------------------------------
  std::vector<float> METPuppi_JetResUp_pt;
  std::vector<float> METPuppi_JetResDown_pt;
  std::vector<float> METPuppi_JetEnUp_pt;
  std::vector<float> METPuppi_JetEnDown_pt;
  std::vector<float> METPuppi_MuonEnUp_pt;
  std::vector<float> METPuppi_MuonEnDown_pt;
  std::vector<float> METPuppi_ElectronEnUp_pt;
  std::vector<float> METPuppi_ElectronEnDown_pt;
  std::vector<float> METPuppi_TauEnUp_pt;
  std::vector<float> METPuppi_TauEnDown_pt;
  std::vector<float> METPuppi_UnclusteredEnUp_pt;
  std::vector<float> METPuppi_UnclusteredEnDown_pt;
  std::vector<float> METPuppi_PhotonEnUp_pt;
  std::vector<float> METPuppi_PhotonEnDown_pt;
  std::vector<float> METPuppi_NoShift_pt;
  std::vector<float> METPuppi_METUncertaintySize_pt;
  std::vector<float> METPuppi_JetResUpSmear_pt;
  std::vector<float> METPuppi_JetResDownSmear_pt;
  std::vector<float> METPuppi_METFullUncertaintySize_pt;
  //----------------------------------------------------
  std::vector<float> METPuppi_JetResUp_phi;
  std::vector<float> METPuppi_JetResDown_phi;
  std::vector<float> METPuppi_JetEnUp_phi;
  std::vector<float> METPuppi_JetEnDown_phi;
  std::vector<float> METPuppi_MuonEnUp_phi;
  std::vector<float> METPuppi_MuonEnDown_phi;
  std::vector<float> METPuppi_ElectronEnUp_phi;
  std::vector<float> METPuppi_ElectronEnDown_phi;
  std::vector<float> METPuppi_TauEnUp_phi;
  std::vector<float> METPuppi_TauEnDown_phi;
  std::vector<float> METPuppi_UnclusteredEnUp_phi;
  std::vector<float> METPuppi_UnclusteredEnDown_phi;
  std::vector<float> METPuppi_PhotonEnUp_phi;
  std::vector<float> METPuppi_PhotonEnDown_phi;
  std::vector<float> METPuppi_NoShift_phi;
  std::vector<float> METPuppi_METUncertaintySize_phi;
  std::vector<float> METPuppi_JetResUpSmear_phi;
  std::vector<float> METPuppi_JetResDownSmear_phi;
  std::vector<float> METPuppi_METFullUncertaintySize_phi;
  //------------------------------------------------------
  std::vector<float> METPuppi_JetResUp_sumEt;
  std::vector<float> METPuppi_JetResDown_sumEt;
  std::vector<float> METPuppi_JetEnUp_sumEt;
  std::vector<float> METPuppi_JetEnDown_sumEt;
  std::vector<float> METPuppi_MuonEnUp_sumEt;
  std::vector<float> METPuppi_MuonEnDown_sumEt;
  std::vector<float> METPuppi_ElectronEnUp_sumEt;
  std::vector<float> METPuppi_ElectronEnDown_sumEt;
  std::vector<float> METPuppi_TauEnUp_sumEt;
  std::vector<float> METPuppi_TauEnDown_sumEt;
  std::vector<float> METPuppi_UnclusteredEnUp_sumEt;
  std::vector<float> METPuppi_UnclusteredEnDown_sumEt;
  std::vector<float> METPuppi_PhotonEnUp_sumEt;
  std::vector<float> METPuppi_PhotonEnDown_sumEt;
  std::vector<float> METPuppi_NoShift_sumEt;
  std::vector<float> METPuppi_METUncertaintySize_sumEt;
  std::vector<float> METPuppi_JetResUpSmear_sumEt;
  std::vector<float> METPuppi_JetResDownSmear_sumEt;
  std::vector<float> METPuppi_METFullUncertaintySize_sumEt;
  //------------------------------------------------------------
  // MET Puppi with PF
  std::vector<float> METPuppiPFraw_pt;
  std::vector<float> METPuppiPFraw_phi;
  std::vector<float> METPuppiPFraw_sumEt;
  std::vector<float> METPuppiPF_pt;
  std::vector<float> METPuppiPF_phi;
  std::vector<float> METPuppiPF_sumEt;
  //--------------------------------------
  std::vector<float> METPuppiPF_JetResUp_pt;
  std::vector<float> METPuppiPF_JetResDown_pt;
  std::vector<float> METPuppiPF_JetEnUp_pt;
  std::vector<float> METPuppiPF_JetEnDown_pt;
  std::vector<float> METPuppiPF_MuonEnUp_pt;
  std::vector<float> METPuppiPF_MuonEnDown_pt;
  std::vector<float> METPuppiPF_ElectronEnUp_pt;
  std::vector<float> METPuppiPF_ElectronEnDown_pt;
  std::vector<float> METPuppiPF_TauEnUp_pt;
  std::vector<float> METPuppiPF_TauEnDown_pt;
  std::vector<float> METPuppiPF_UnclusteredEnUp_pt;
  std::vector<float> METPuppiPF_UnclusteredEnDown_pt;
  std::vector<float> METPuppiPF_PhotonEnUp_pt;
  std::vector<float> METPuppiPF_PhotonEnDown_pt;
  std::vector<float> METPuppiPF_NoShift_pt;
  std::vector<float> METPuppiPF_METUncertaintySize_pt;
  std::vector<float> METPuppiPF_JetResUpSmear_pt;
  std::vector<float> METPuppiPF_JetResDownSmear_pt;
  std::vector<float> METPuppiPF_METFullUncertaintySize_pt;
  //----------------------------------------------------
  std::vector<float> METPuppiPF_JetResUp_phi;
  std::vector<float> METPuppiPF_JetResDown_phi;
  std::vector<float> METPuppiPF_JetEnUp_phi;
  std::vector<float> METPuppiPF_JetEnDown_phi;
  std::vector<float> METPuppiPF_MuonEnUp_phi;
  std::vector<float> METPuppiPF_MuonEnDown_phi;
  std::vector<float> METPuppiPF_ElectronEnUp_phi;
  std::vector<float> METPuppiPF_ElectronEnDown_phi;
  std::vector<float> METPuppiPF_TauEnUp_phi;
  std::vector<float> METPuppiPF_TauEnDown_phi;
  std::vector<float> METPuppiPF_UnclusteredEnUp_phi;
  std::vector<float> METPuppiPF_UnclusteredEnDown_phi;
  std::vector<float> METPuppiPF_PhotonEnUp_phi;
  std::vector<float> METPuppiPF_PhotonEnDown_phi;
  std::vector<float> METPuppiPF_NoShift_phi;
  std::vector<float> METPuppiPF_METUncertaintySize_phi;
  std::vector<float> METPuppiPF_JetResUpSmear_phi;
  std::vector<float> METPuppiPF_JetResDownSmear_phi;
  std::vector<float> METPuppiPF_METFullUncertaintySize_phi;
  //------------------------------------------------------
  std::vector<float> METPuppiPF_JetResUp_sumEt;
  std::vector<float> METPuppiPF_JetResDown_sumEt;
  std::vector<float> METPuppiPF_JetEnUp_sumEt;
  std::vector<float> METPuppiPF_JetEnDown_sumEt;
  std::vector<float> METPuppiPF_MuonEnUp_sumEt;
  std::vector<float> METPuppiPF_MuonEnDown_sumEt;
  std::vector<float> METPuppiPF_ElectronEnUp_sumEt;
  std::vector<float> METPuppiPF_ElectronEnDown_sumEt;
  std::vector<float> METPuppiPF_TauEnUp_sumEt;
  std::vector<float> METPuppiPF_TauEnDown_sumEt;
  std::vector<float> METPuppiPF_UnclusteredEnUp_sumEt;
  std::vector<float> METPuppiPF_UnclusteredEnDown_sumEt;
  std::vector<float> METPuppiPF_PhotonEnUp_sumEt;
  std::vector<float> METPuppiPF_PhotonEnDown_sumEt;
  std::vector<float> METPuppiPF_NoShift_sumEt;
  std::vector<float> METPuppiPF_METUncertaintySize_sumEt;
  std::vector<float> METPuppiPF_JetResUpSmear_sumEt;
  std::vector<float> METPuppiPF_JetResDownSmear_sumEt;
  std::vector<float> METPuppiPF_METFullUncertaintySize_sumEt;

 private:
  TTree* tree_;

};

#endif
