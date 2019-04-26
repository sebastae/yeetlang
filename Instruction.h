//
// Created by Sebastian on 26.04.2019.
//

#ifndef YEETLANG_INSTRUCTION_H
#define YEETLANG_INSTRUCTION_H


#include <vector>
#include "YeetParser.h"
#include "YeetEnv.h"

class Instruction {
public:
    virtual void execute(std::vector<IYeet> args, YeetEnv env) = 0;
};


#endif //YEETLANG_INSTRUCTION_H
