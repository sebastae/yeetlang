//
// Created by Sebastian on 26.04.2019.
//

#include <iostream>
#include "YeetEnv.h"
#include "YeetParser.h"

YeetEnv::YeetEnv(unsigned long long int size){
    memory = std::vector<YeetCell>(size);
}

YeetCell YeetEnv::getMemory(int addr) {
    return memory.at((unsigned long long int)(addr));
}

void YeetEnv::setMemory(int addr, YeetCell cell) {
    memory[addr] = cell;
}

YeetCell YeetEnv::getAcc() {
    return acc;
}

void YeetEnv::setAcc(YeetCell cell) {
    acc = cell;
}

void YeetEnv::pushPrint(YeetCell cell) {
    printQueue.push_back(cell);
}

void YeetEnv::printPrintQueue() {
    for(auto &it : printQueue){
        std::cout << it.interpretAsCharacter ? (char) it.value : it.value;
    }
    std::cout << std::endl;
    clearPrint();
}

void YeetEnv::clearPrint() {
    printQueue.clear();
};
