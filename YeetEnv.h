//
// Created by Sebastian on 26.04.2019.
//

#ifndef YEETLANG_YEETENV_H
#define YEETLANG_YEETENV_H

#include <vector>

struct YeetCell{
    bool interpretAsCharacter;
    int value;
};

class YeetEnv {
    YeetCell acc;
    std::vector<YeetCell> printQueue;
    std::vector<YeetCell> memory;
public:
    YeetEnv(unsigned long long int size);

    YeetCell getMemory(int addr);
    void     setMemory(int addr, YeetCell cell);
    YeetCell getAcc();
    void     setAcc(YeetCell cell);
    void     pushPrint(YeetCell cell);
    void     printPrintQueue();
    void     clearPrint();
};


#endif //YEETLANG_YEETENV_H
