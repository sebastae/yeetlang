//
// Created by Sebastian on 26.04.2019.
//

#ifndef YEETLANG_INSTRUCTIONS_H
#define YEETLANG_INSTRUCTIONS_H

#include "Instruction.h"
#include "YeetEnv.h"

class ArithmeticAddInstruction : public Instruction{
public:
    void execute(std::vector<IYeet> args, YeetEnv env) override;
};

class ArithmeticSubtractInstruction : public Instruction{
public:
    void execute(std::vector<IYeet> args, YeetEnv env) override;
};

class SaveFromAccInstruction : public Instruction{
public:
    void execute(std::vector<IYeet> args, YeetEnv env) override;
};

class ReadToAccInstruction : public Instruction{
public:
    void execute(std::vector<IYeet> args, YeetEnv env) override;
};

class PushIntToPrintQueueInstruction : public Instruction{
public:
    void execute(std::vector<IYeet> args, YeetEnv env) override;
};
class PushCharToPrintQueueInstruction : public Instruction{
public:
    void execute(std::vector<IYeet> args, YeetEnv env) override;
};

class ClearPrintQueueInstruction : public Instruction{
public:
    void execute(std::vector<IYeet> args, YeetEnv env) override;
};

class PrintPrintQueueInstruction : public Instruction{
public:
    void execute(std::vector<IYeet> args, YeetEnv env) override;
};






#endif //YEETLANG_INSTRUCTIONS_H
