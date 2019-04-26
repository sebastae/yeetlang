//
// Created by Sebastian on 23.04.2019.
//

#ifndef YEETLANG_YEETINTERPRETER_H
#define YEETLANG_YEETINTERPRETER_H


#include <string>
#include "Instructions.h"

class YeetInterpreter {
    int* exitCode;
    YeetEnv env;
    std::vector<Instruction*> instructionList;

public:
    YeetInterpreter(int* ec, int memSize);
    int interpretLine(std::string line);
};


#endif //YEETLANG_YEETINTERPRETER_H
