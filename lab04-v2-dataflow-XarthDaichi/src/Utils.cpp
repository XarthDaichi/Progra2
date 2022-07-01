//
// Created by Xarthy on 0021 April 21, 2022.
//

#include "Utils.h"

int Utils::strToInt(const std::string &s) {
    std::stringstream r(s);
    int v;
    r >> v;
    return v;
}