#include "EventAction.hpp"
#include "G4EventManager.hh"
#include "G4Event.hh"
#include "G4HCtable.hh"
#include "G4VHitsCollection.hh"
#include "G4HCofThisEvent.hh"


#include <iostream>

EventAction::EventAction():
    G4UserEventAction()
{

}

EventAction::~EventAction()
{
}

void EventAction::BeginOfEventAction(const G4Event *anEvent)
{
    std::cout<<"begin event action"<<std::endl;
}
void EventAction::EndOfEventAction(const G4Event* event)
{
    std::cout<<"end event action"<<std::endl;
    //G4UserEventAction::fpEventManager->KeepTheCurrentEvent();
    //std::cout<<"end of event"<<std::endl;
    //std::cout<<"----------------"<<std::endl;
    //G4HCofThisEvent* hitcollections = event->GetHCofThisEvent();
    //std::cout<<"hit collections: "<<hitcollections->GetNumberOfCollections()<<std::endl;
    
    /*
    for (int icollection = 0; icollection<hitcollections->GetNumberOfCollections(); ++icollection)
    {
        
        //std::cout<<"  ->  hit collection: "<<icollection<<std::endl;
        G4VHitsCollection* hitCollection = hitcollections->GetHC(icollection);
        //std::cout<<"  ->    ->  name: "<<hitCollection->GetName()<<std::endl;
        //std::cout<<"  ->    ->  sdname: "<<hitCollection->GetSDname()<<std::endl;
        //std::cout<<"  ->    ->  hits: "<<hitCollection->GetSize()<<std::endl;
        
        
    }
    try
    {
        
        
    }
    catch (std::string s)
    {
        std::cout<<s<<std::endl;
        
    }
    */
}


