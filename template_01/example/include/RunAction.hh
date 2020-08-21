//
// Created by zelenyy on 8/14/20.
//

#ifndef THUNDERSTORM_SIMULATION_PUBLIC_RUNACTION_HH
#define THUNDERSTORM_SIMULATION_PUBLIC_RUNACTION_HH

#include "G4UserRunAction.hh"
#include "Logger.hh"
#include "Settings.hh"

class RunAction : public G4UserRunAction{
private:
    Settings* settings;
public:

    RunAction(Settings* settings) : settings(settings){};

    void BeginOfRunAction(const G4Run *aRun) override;

    void EndOfRunAction(const G4Run *aRun) override;

};

void RunAction::BeginOfRunAction(const G4Run *aRun) {
    G4UserRunAction::BeginOfRunAction(aRun);
    Logger::instance()->print("Start run.");
}

void RunAction::EndOfRunAction(const G4Run *aRun) {
    G4UserRunAction::EndOfRunAction(aRun);
}

#endif //THUNDERSTORM_SIMULATION_PUBLIC_RUNACTION_HH
