#include "DetectorConstruction.hpp"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"

DetectorConstruction::DetectorConstruction():  
    experimentalHall_log(0),
    calorimeterBlock_log(0),
    experimentalHall_phys(0),
    calorimeterBlock_phys(0)
{
}

DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{

  //------------------------------------------------------ materials

  G4double a;  // atomic mass
  G4double z;  // atomic number
  G4double density;

  G4Material* Ar = 
  new G4Material("ArgonGas", z= 18., a= 39.95*g/mole, density= 1.782*mg/cm3);

  G4Material* Pb = 
  new G4Material("Lead", z= 82., a= 207.19*g/mole, density= 11.35*g/cm3);

  //------------------------------------------------------ volumes

  //------------------------------ experimental hall (world volume)
  //------------------------------ beam line along x axis

  G4double expHall_x = 3.0*m;
  G4double expHall_y = 1.0*m;
  G4double expHall_z = 1.0*m;
  G4Box* experimentalHall_box = new G4Box("expHall_box",expHall_x,expHall_y,expHall_z);
  experimentalHall_log = new G4LogicalVolume(experimentalHall_box,Ar,"expHall_log",0,0,0);
  experimentalHall_phys = new G4PVPlacement(0,G4ThreeVector(),experimentalHall_log,"expHall",0,false,0);

  //------------------------------ a calorimeter block

  G4double block_x = 1.0*m;
  G4double block_y = 1.0*m;
  G4double block_z = 1.0*m;
  G4Box* calorimeterBlock_box = new G4Box("calBlock_box",block_x,block_y,block_z);
  calorimeterBlock_log = new G4LogicalVolume(calorimeterBlock_box,Pb,"caloBlock_log",0,0,0);
  G4double blockPos_x = 2*block_x+0.0*m;
  G4double blockPos_y = 0.0*m;
  G4double blockPos_z = 0.0*m;
  calorimeterBlock_phys = new G4PVPlacement(0,G4ThreeVector(blockPos_x,blockPos_y,blockPos_z),calorimeterBlock_log,"caloBlock",experimentalHall_log,false,0);

  return experimentalHall_phys;
}

