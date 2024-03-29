#ifndef EVENTACTION_H
#define EVENTACTION_H

#include "G4UserEventAction.hh"


class EventAction:
    public G4UserEventAction
{
    protected:
    public:
        EventAction();
        virtual ~EventAction();
        virtual void BeginOfEventAction (const G4Event *anEvent);
        virtual void EndOfEventAction(const G4Event* event);
};

#endif

