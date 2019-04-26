//
// Created by Sebastian on 23.04.2019.
//

#include <cstdio>
#include "Logger.h"

void Logger::log(char *msg) {
    std::printf("[LOG] %s\n");
}

void Logger::info(char *msg) {
    std::printf("[INFO] %s\n", msg);
}

void Logger::error(char *msg) {
    std::printf("[ERROR] %s\n", msg);
}
