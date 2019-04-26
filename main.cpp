#include <iostream>
#include "ModeController.h"
#include "YeetParser.h"
#include "Logger.h"

int main(int argc, char* argv[]) {

    if(argc == 0){
        // Run in interactive mode
        return ModeController::interactiveMode();
    } else {
        // Interpret file
        return ModeController::fileMode(argv[0]);
    }


    return 0;

}