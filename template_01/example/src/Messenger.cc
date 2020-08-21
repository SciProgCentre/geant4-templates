//
// Created by zelenyy on 8/10/20.
//

#include <G4UIcmdWithABool.hh>
#include "Messenger.hh"

Messenger::Messenger(Settings *pSettings) : ServerMessenger(pSettings), settings(pSettings){
    physics = new G4UIcmdWithAString(physics_path.c_str(), this);
    physics->SetGuidance("Set using physics.");
    physics->SetParameterName("physics", true);
}

void Messenger::SetNewValue(G4UIcommand *command, G4String newValue) {
    if (command == physics){
        settings->physics = newValue;
    }
    else {
        ServerMessenger::SetNewValue(command, newValue);
    }

}

G4String Messenger::GetCurrentValue(G4UIcommand *command) {
    return ServerMessenger::GetCurrentValue(command);
}
