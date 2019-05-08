#ifndef METsNtuplizer_H
#define METsNtuplizer_H

#include "../interface/CandidateNtuplizer.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"
class TFormula;

class METsNtuplizer : public CandidateNtuplizer {

 public:
  METsNtuplizer( edm::EDGetTokenT<edm::View<pat::MET> > metmodifiedtoken,
		 edm::EDGetTokenT<edm::View<pat::MET> > metmodifiedPFtoken,
		 edm::EDGetTokenT<edm::View<pat::MET> > metpuppitoken,
		 edm::EDGetTokenT<edm::View<pat::MET> > metpuppiPFtoken,
		 NtupleBranches* nBranches,
		 std::map< std::string, bool>& runFlags);
  ~METsNtuplizer( void );

  void fillBranches( edm::Event const & event, const edm::EventSetup& iSetup );
  
 private:
  edm::EDGetTokenT<edm::View<pat::MET> > metmodifiedInputToken_;
  edm::EDGetTokenT<edm::View<pat::MET> > metmodifiedPFInputToken_;
  edm::EDGetTokenT<edm::View<pat::MET> > metpuppiInputToken_;
  edm::EDGetTokenT<edm::View<pat::MET> > metpuppiPFInputToken_;

  edm::Handle<edm::View<pat::MET> > METsmodified_;
  edm::Handle<edm::View<pat::MET> > METsmodifiedPF_;
  edm::Handle<edm::View<pat::MET> > METspuppi_;
  edm::Handle<edm::View<pat::MET> > METspuppiPF_;

};

#endif
