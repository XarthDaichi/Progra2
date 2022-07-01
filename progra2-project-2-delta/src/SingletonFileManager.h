//
// Created by Xarthy on 0020 June 20, 2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_SINGLETONFILEMANAGER_H
#define PROGRA_PROJECT_2_DELTA_SINGLETONFILEMANAGER_H
#include "Container.h"
//#include <../lib/nlohmann/json.hpp>
#include <fstream>

template <typename T>
class SingletonFileManager {
protected:
    SingletonFileManager() {};
public:
    SingletonFileManager(SingletonFileManager const &) = delete;
    SingletonFileManager &operator = (SingletonFileManager const &) = delete;

    static T& getInstance(const char c = 'b') {
        static T singletonFileManager(c);
        return singletonFileManager;
    }
};


#endif //PROGRA_PROJECT_2_DELTA_SINGLETONFILEMANAGER_H
