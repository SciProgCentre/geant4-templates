//
// Created by zelenyy on 14.01.2020.
//

#ifndef PHD_CODE_SETTINGS_HH
#define PHD_CODE_SETTINGS_HH

#include <G4Server.hh>
#include "G4SystemOfUnits.hh"
#include "ServerSettings.hh"

using namespace std;

class Settings : public ServerSettings {
public:
    string physics = "default";
};


#endif //PHD_CODE_SETTINGS_HH
