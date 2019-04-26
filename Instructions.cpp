//
// Created by Sebastian on 26.04.2019.
//

#include <stdexcept>
#include "Instructions.h"


void ArithmeticAddInstruction::execute(std::vector<IYeet> args, YeetEnv env) {
    if(args.size() != 2){
        throw std::runtime_error("Unexpected number of arguments, expected 2 IYeet arguments");
    } else{
        IYeet aYeet = args.at(0);
        IYeet bYeet = args.at(1);

        int a = aYeet.address ? env.getMemory(aYeet.value).value : aYeet.value;
        int b = bYeet.address ? env.getMemory(bYeet.value).value : bYeet.value;

        env.setAcc({false, a+b});
    }
}

void ArithmeticSubtractInstruction::execute(std::vector<IYeet> args, YeetEnv env) {
    if(args.size() != 2){
        throw std::runtime_error("Unexpected number of arguments, expected 2 IYeet arguments");
    } else {
        IYeet aYeet = args.at(0);
        IYeet bYeet = args.at(1);

        int a = aYeet.address ? env.getMemory(aYeet.value).value : aYeet.value;
        int b = bYeet.address ? env.getMemory(bYeet.value).value : bYeet.value;

        env.setAcc({false, a-b});
    }
}

void SaveFromAccInstruction::execute(std::vector<IYeet> args, YeetEnv env) {
    if(args.size() != 1){
        throw std::runtime_error("Unexpected number of arguments, expected 1 IYeet arguments");
    } else{
        env.setMemory(args.at(0).value, env.getAcc());
    }
}

void ReadToAccInstruction::execute(std::vector<IYeet> args, YeetEnv env) {
    if(args.size() != 1){
        throw std::runtime_error("Unexpected number of arguments, expected 1 IYeet arguments");
    } else{
        env.setAcc(env.getMemory(args.at(0).value));
    }
}

void PushIntToPrintQueueInstruction::execute(std::vector<IYeet> args, YeetEnv env) {
    if(args.size() == 1){
        IYeet yeet = args.at(0);
        int val = yeet.address ? env.getMemory(yeet.value).value : yeet.value;

        env.pushPrint({false, val});

    } else {
        throw std::runtime_error("Unexpected number of arguments, expected 1 IYeet arguments");
    }
}

void PushCharToPrintQueueInstruction::execute(std::vector<IYeet> args, YeetEnv env) {
    if(args.size() == 1){
        IYeet yeet = args.at(0);
        int val = yeet.address ? env.getMemory(yeet.value).value : yeet.value;

        env.pushPrint({true, val});

    } else {
        throw std::runtime_error("Unexpected number of arguments, expected 1 IYeet arguments");
    }
}

void ClearPrintQueueInstruction::execute(std::vector<IYeet> args, YeetEnv env) {
    if(args.size() == 0){
        env.clearPrint();
    } else {
        throw std::runtime_error("Unexpected number of arguments, expected 0 IYeet arguments");
    }
}

void PrintPrintQueueInstruction::execute(std::vector<IYeet> args, YeetEnv env) {
    if(args.size() == 0){
        env.printPrintQueue();
    } else {
        throw std::runtime_error("Unexpected number of arguments, expected 0 IYeet arguments");
    }
}

