//
// Created by ribre on 26/04/2022.
//

#include "CapacityManager.h"

int CapacityManager::capacity(const std::string& type) {
    if (type == "Buseta") return 40;
    if (type == "Coaster") return 27;
    if (type == "Hiace") return 12;
    if (type == "H1") return 6;
    return -1;
}