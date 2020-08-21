//
// Created by zelenyy on 8/10/20.
//

#ifndef THUNDERSTORM_SIMULATION_PUBLIC_MESSENGER_HH
#define THUNDERSTORM_SIMULATION_PUBLIC_MESSENGER_HH

#include "G4Server.hh"
#include "Settings.hh"
#include <G4UImessenger.hh>
#include <G4UIcmdWithAString.hh>
#include <G4UIcmdWithADoubleAndUnit.hh>
#include <G4UIcmdWithAnInteger.hh>
#include "G4UImessenger.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"

class Messenger : public ServerMessenger {
private:
    Settings* settings;
public:
    explicit Messenger(Settings* pSettings);

    void SetNewValue(G4UIcommand *command, G4String newValue) override;

    G4String GetCurrentValue(G4UIcommand *command) override;

private:
    G4UIcmdWithAString * physics;
    string physics_path = root_path + "physics";
};


#endif //THUNDERSTORM_SIMULATION_PUBLIC_MESSENGER_HH
