#ifndef METsNtuplizer_H
#define METsNtuplizer_H

#include "../interface/CandidateNtuplizer.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"
class TFormula;

class METsNtuplizer : public CandidateNtuplizer {

 public:
  METsNtuplizer( edm::EDGetTokenT<pat::METCollection> metmodifiedtoken,
		 edm::EDGetTokenT<pat::METCollection> metmodifiedPFtoken,
		 edm::EDGetTokenT<pat::METCollection> metpuppitoken,
		 edm::EDGetTokenT<pat::METCollection> metpuppiPFtoken,
		 NtupleBranches* nBranches,
		 std::map< std::string, bool>& runFlags);
  ~METsNtuplizer( void );

  void fillBranches( edm::Event const & event, const edm::EventSetup& iSetup );
  
 private:
  edm::EDGetTokenT<pat::METCollection> metmodifiedInputToken_;
  edm::EDGetTokenT<pat::METCollection> metmodifiedPFInputToken_;
  edm::EDGetTokenT<pat::METCollection> metpuppiInputToken_;
  edm::EDGetTokenT<pat::METCollection> metpuppiPFInputToken_;

  edm::Handle<pat::METCollection> METsmodified_;
  edm::Handle<pat::METCollection> METsmodifiedPF_;
  edm::Handle<pat::METCollection> METspuppi_;
  edm::Handle<pat::METCollection> METspuppiPF_;

};

#endif
