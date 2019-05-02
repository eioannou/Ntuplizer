#include <memory>
#include "DataFormats/METReco/interface/METCollection.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilsAlgos/interface/TFileService.h"

#include "../interface/NtupleBranches.h"

#include "FWCore/Framewrok/interface/ConsumesCollector.h"

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
  virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventStup const&) override;
  virtual void endLuminosityBlock( edm::LuminosityBlock const &, edm::EventSetup const&) override;

  NtupleBranches* nBranches_;
  std::map<std::string, CandidateNtuplizer*> nTupplizers_;

  edm::EDGetTokenT<pat::METCollection> metmodifiedToken_;
  edm::EDGetTokenT<pat::METCollection> metmodifiedPFToken_;
  edm::EDGetTokenT<pat::METCollection> metpuppiToken_;
  edm::EDGetTokenT<pat::METCollection> metpuppiPFToken_;

};
