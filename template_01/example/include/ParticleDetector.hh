//
// Created by zelenyy on 03.02.2020.
//

#ifndef PHD_CODE_PARTICLEDETECTOR_HH
#define PHD_CODE_PARTICLEDETECTOR_HH


#include <G4VSensitiveDetector.hh>
#include "Settings.hh"
using namespace std;
class ParticleDetector : public G4VSensitiveDetector {
public:
    ParticleDetector(G4String name, Settings *settings) : G4VSensitiveDetector(name), settings(settings){};

    G4bool ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist) override{
        cout<<"Hit"<<endl;
    };

private:
    Settings *settings;
};


#endif //PHD_CODE_PARTICLEDETECTOR_HH
