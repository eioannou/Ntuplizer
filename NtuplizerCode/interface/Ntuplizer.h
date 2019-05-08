#include <memory>
#include "DataFormats/METReco/interface/METCollection.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "../interface/NtupleBranches.h"

#include "FWCore/Framework/interface/ConsumesCollector.h"

class NtupleBranches;
class CandidateNtuplizer;

class Ntuplizer : public edm::EDAnalyzer {
 public:
  explicit Ntuplizer( const edm::ParameterSet&);
  ~Ntuplizer();

  static void fillDescriptions( edm::ConfigurationDescriptions& descriptions );

 private:
  virtual void beginJob() override;
  virtual void analyze( const edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;

  virtual void beginRun( edm::Run const&, edm::EventSetup const&) override;
  virtual void endRun( edm::Run const&, edm::EventSetup const&) override;
  virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
  virtual void endLuminosityBlock( edm::LuminosityBlock const &, edm::EventSetup const&) override;

  NtupleBranches* nBranches_;
  std::map<std::string, CandidateNtuplizer*> nTuplizers_;

  edm::EDGetTokenT<edm::View<pat::MET> > metmodifiedToken_;
  edm::EDGetTokenT<edm::View<pat::MET> > metmodifiedPFToken_;
  edm::EDGetTokenT<edm::View<pat::MET> > metpuppiToken_;
  edm::EDGetTokenT<edm::View<pat::MET> > metpuppiPFToken_;

};
