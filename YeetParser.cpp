//
// Created by Sebastian on 23.04.2019.
//

#include <cmath>
#include <stdexcept>
#include "YeetParser.h"

bool YeetParser::isValidYeet(std::string *yeet) {
    return (yeet->length()> 2) && (std::tolower(yeet->at(0)) == 'y') && (std::tolower(yeet->at(yeet->length()-1)) == 't');
}

int YeetParser::parseYeet(std::string *yeet) {
    if(isValidYeet(yeet)){
        std::string estr = yeet->substr(1, yeet->length()-2);
        int val = 0;
        for(int i = (int)estr.length()-1; i >= 0; i--){
            if(estr.at(i) == 'E') val += (int) pow(2, estr.length()-i-1);
            else if(estr.at(i) == 'e') val += 0;
            else val *= -1;
        }
        return val;
    } else{
        throw std::runtime_error("Invalid yeet");
    }
}

IYeet YeetParser::parseYeetStatement(std::string *yeet) {
    try {
        if (yeet->find("ya") == 0) {
            std::string yeetOnly = yeet->substr(2);
            return {true, parseYeet(&yeetOnly)};
        } else {
            return {false, parseYeet(yeet)};
        }
    } catch (const std::runtime_error& e){
        throw e;
    }
}
