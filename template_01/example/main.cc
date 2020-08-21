#include <Messenger.hh>
#include "Settings.hh"
//Mandatory user option
#include "ActionInitialization.hh"
#include "PhysicsList.hh"
//Factory
#include "SensitiveDetectorFactory.hh"
#include "IFieldFactory.hh"

#include "G4Server.hh"

int main(int argc, char **argv) {

//    GeometryType type = GeometryType::gdml;
//    type = GeometryType ::gdml;

    auto logger = Logger::instance();
    logger->print("Number of arguments: " + to_string(argc));
    for (int i = 0; i < argc; ++i) {
        logger->print(string("Argument number ") + to_string(i) + ": " + argv[i]);
    }

    // Create server and settings
    auto settings = new Settings();
    settings->argc = argc;
    settings->argv = argv;
    auto messenger = new Messenger(settings);
    auto g4Server = new G4Server(messenger, settings);


    // Select input
    istream *setup_in = &std::cin;
    istream *mainloop_in = &std::cin;

    vector<fstream*> open_files;
    if (argc > 1) {
            string filename = argv[1];
            fstream *fin = new fstream;
            fin->open(filename);
            open_files.push_back(fin);
            setup_in = fin;
            mainloop_in = fin;
    }

    // Run server
    g4Server->setup(*setup_in);
    if (g4Server->massWorld == nullptr) {
        // If don't use GDML file
        // Create custom geometry here
//        MyConstruction *construction = new MyConstruction();
//        g4Server->runManager->SetUserInitialization(construction);
    } else {
        g4Server->massWorld->setDetectorFactory(new SensitiveDetectorFactory(settings));

        g4Server->massWorld->setFieldFactory(new IFieldFactory);
    }


    auto physList = new PhysicsList(settings->physics);
    g4Server->runManager->SetUserInitialization(physList);
    auto actionInit = new ActionInitialization(settings);
    g4Server->runManager->SetUserInitialization(actionInit);

    g4Server->mainloop(*mainloop_in);
    g4Server->stop();
    for ( auto &&fin : open_files){
        fin->close();
    }
    return 0;
}




