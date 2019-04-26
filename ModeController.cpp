//
// Created by Sebastian on 23.04.2019.
//

#include <fstream>
#include "ModeController.h"
#include "YeetInterpreter.h"

int ModeController::fileMode(char *filePath) {
    int exitCode = 0; // Set by YeetInterpreter, changed from 0 when exiting
    YeetInterpreter interpreter = YeetInterpreter(&exitCode, 1024);
/*
    std::ifstream infile(filePath);
    std::string line;

    while(std::getline(infile, line) && exitCode == 0){
        interpreter.interpretLine(line);
    }
*/

    interpreter.interpretLine("yEEt");
    interpreter.interpretLine("yayEEt");

    return exitCode;

}

int ModeController::interactiveMode() {

}
