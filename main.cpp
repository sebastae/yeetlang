#include "ModeController.h"

int main(int argc, char* argv[]) {

    if(argc == 0){
        // Run in interactive mode
        return ModeController::interactiveMode();
    } else {
        // Interpret file
        return ModeController::fileMode(argv[0]);
    }

}