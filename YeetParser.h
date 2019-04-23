//
// Created by Sebastian on 23.04.2019.
//

#ifndef YEETLANG_YEETPARSER_H
#define YEETLANG_YEETPARSER_H

#include <string>

struct IYeet{
    bool address;
    int value;
};

class YeetParser {
    static bool isValidYeet(std::string* yeet);
public:
    static int parseYeet(std::string *yeet);
    static IYeet parseYeetStatement(std::string* yeet);

};


#endif //YEETLANG_YEETPARSER_H
