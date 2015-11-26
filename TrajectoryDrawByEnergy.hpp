#ifndef _TRAJECTORYDRAWBYENERGY_H_
#define _TRAJECTORYDRAWBYENERGY_H_

#include "G4VTrajectoryModel.hh"
#include "G4Colour.hh"
#include "G4ModelColourMap.hh"
#include "G4String.hh"
#include <map>

class TrajectoryDrawByEnergy:
    public G4VTrajectoryModel
{

    public: // With description

        TrajectoryDrawByEnergy(const G4String& name = "Unspecified", G4VisTrajContext* context=0);

        virtual ~TrajectoryDrawByEnergy();

        // Draw method
        virtual void Draw(const G4VTrajectory& trajectory, const G4int& i_mode = 0,
                const G4bool& visible = true) const;
        virtual void Draw(const G4VTrajectory& trajectory, 
                const G4bool& visible = true) const;

        virtual void Print(std::ostream& ostr) const;
        // Print configuration

        void SetDefault(const G4String&);
        void SetDefault(const G4Colour&);

        void Set(const G4String& particle, const G4String& colour);
        void Set(const G4String& particle, const G4Colour& colour);
        // Configuration functions

    private:

        // Data members
        G4ModelColourMap<G4String> fMap;
        G4Colour fDefault;

};

#endif
