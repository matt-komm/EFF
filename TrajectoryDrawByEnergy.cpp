#include "TrajectoryDrawByEnergy.hpp"

#include "G4TrajectoryDrawerUtils.hh"
#include "G4VisTrajContext.hh"
#include "G4VTrajectory.hh"

TrajectoryDrawByEnergy::TrajectoryDrawByEnergy(const G4String& name, G4VisTrajContext* context)
  :G4VTrajectoryModel(name, context)
  ,fDefault(G4Colour::Grey())
{
  Set("gamma", "green");
  Set("e-", "blue");
  Set("e+", "blue");
  Set("pi+", "magenta");
  Set("pi-", "magenta");
  Set("proton", "red");
  Set("neutron", "yellow");
}

TrajectoryDrawByEnergy::~TrajectoryDrawByEnergy() {}

void
TrajectoryDrawByEnergy::Draw(const G4VTrajectory& object,
				   const G4int&,
				   const G4bool& visible) const
{
    Draw(object, visible);
}

void
TrajectoryDrawByEnergy::Draw(const G4VTrajectory& traj, const G4bool& visible) const
{
    G4Color pdgcolor(fDefault);
    G4String particle = traj.GetParticleName();
    
    fMap.GetColour(particle, pdgcolor);
    
    double energy = std::log(traj.GetInitialMomentum().mag()+1);
    if (traj.GetPDGEncoding()>30)
    {
        energy/=10.0;
    }
    std::cout<<particle<<": "<<energy<<std::endl;
    G4Color color(pdgcolor.GetRed()*energy,pdgcolor.GetGreen()*energy,pdgcolor.GetBlue()*energy,energy);
    
    G4VisTrajContext myContext(GetContext());

    myContext.SetLineColour(color);
    myContext.SetVisible(visible);

    //if (traj.GetPDGEncoding()<30)
    G4TrajectoryDrawerUtils::DrawLineAndPoints(traj, myContext);
}

void
TrajectoryDrawByEnergy::SetDefault(const G4String& colour)
{
  G4Colour myColour(G4Colour::White());      

  // Will not modify myColour if colour key does not exist  
  if (!G4Colour::GetColour(colour, myColour)) {
    G4ExceptionDescription ed;
    ed << "G4Colour with key "<<colour<<" does not exist ";
    G4Exception
      ("G4TrajectoryDrawByParticleID::SetDefault(const G4String& colour)",
       "modeling0124", JustWarning, ed);
  }

  SetDefault(myColour);
}

void
TrajectoryDrawByEnergy::SetDefault(const G4Colour& colour)
{
  fDefault = colour;
}

void
TrajectoryDrawByEnergy::Set(const G4String& particle, const G4String& colour)
{
  fMap.Set(particle, colour);
}

void
TrajectoryDrawByEnergy::Set(const G4String& particle, const G4Colour& colour)
{
  fMap[particle] = colour;
}

void
TrajectoryDrawByEnergy::Print(std::ostream& ostr) const
{
  ostr<<"TrajectoryDrawByEnergy model "<< Name() <<" colour scheme: "<<std::endl;
  
  ostr<<"Default colour: "<<fDefault<<G4endl;

  fMap.Print(ostr);

  ostr<<"Default configuration:"<<G4endl;
  GetContext().Print(G4cout);
}
