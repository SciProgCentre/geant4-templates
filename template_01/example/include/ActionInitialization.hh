//
// Created by zelenyy on 8/5/20.
//

#ifndef THUNDERSTORM_SIMULATION_PUBLIC_ACTIONINITIALIZATION_HH
#define THUNDERSTORM_SIMULATION_PUBLIC_ACTIONINITIALIZATION_HH

#include "G4VUserActionInitialization.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "Settings.hh"

class ActionInitialization : public G4VUserActionInitialization{
private:
    Settings* settings;
public:
    explicit ActionInitialization(Settings* settings) : settings(settings){

    }

    void Build() const override {
        auto gps = new GeneralParticleSource();
        SetUserAction(gps);
        auto runAction = new RunAction(settings);
        SetUserAction(runAction);
        auto eventAction = new EventAction(settings);
        SetUserAction(eventAction);
    }
};

#endif //THUNDERSTORM_SIMULATION_PUBLIC_ACTIONINITIALIZATION_HH
