#include <ParticleDetector.hh>
#include "SensitiveDetectorFactory.hh"
#include "G4SDManager.hh"
#include "Logger.hh"

G4VSensitiveDetector *SensitiveDetectorFactory::getSensitiveDetector(G4GDMLAuxListType::const_iterator vit) {
    auto name = (*vit).value;
    G4SDManager *fSDM = G4SDManager::GetSDMpointer();
    if (fSDM->FindSensitiveDetector(name)) {
        return fSDM->FindSensitiveDetector(name);
    }
    G4VSensitiveDetector *tempDetector;
    if (name == "particle"){
        tempDetector = new ParticleDetector(name, settings);
    }
    else{
        tempDetector = IDetectorFactory::getSensitiveDetector(vit);
    }


    fSDM->AddNewDetector(tempDetector);
    Logger::instance()->print("Create new detector: " + name);
    return tempDetector;
}

SensitiveDetectorFactory::SensitiveDetectorFactory(Settings *settings): settings(settings) {

}
