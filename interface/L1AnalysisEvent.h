#ifndef __L1Analysis_L1AnalysisEvent_H__
#define __L1Analysis_L1AnalysisEvent_H__

//-------------------------------------------------------------------------------
// Created 06/01/2010 - A.C. Le Bihan
// 
// 
// Original code : UserCode/L1TriggerDPG/L1NtupleProducer
//-------------------------------------------------------------------------------

#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "FWCore/Common/interface/TriggerNames.h"

#include "PhysicsTools/Utilities/interface/LumiReWeighting.h"

#include "L1AnalysisEventDataFormat.h"

#include <string>

namespace L1Analysis
{
  class L1AnalysisEvent 
  {
  public:
    L1AnalysisEvent(std::string puMCFile, 
		    std::string puMCHist, 
		    std::string puDataFile, 
		    std::string puDataHist);
    ~L1AnalysisEvent();
    
    //void Print(std::ostream &os = std::cout) const;
    void Set(const edm::Event& e, const edm::InputTag& hlt_);
    void Reset() {event_.Reset();}
    L1AnalysisEventDataFormat * getData() {return &event_;}

    // ---- General L1AnalysisEvent information.
    
  private :
    bool fillHLT_;
    bool doPUWeights_;

    edm::LumiReWeighting lumiWeights_;
  
    L1Analysis::L1AnalysisEventDataFormat event_;
    
  }; 
}
#endif


