//
// Created by Xarthy on 0016 April 16, 2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_SINGLETONFILEMANAGER_H
#define PROGRA2_PROJECT_1_DELTA_SINGLETONFILEMANAGER_H
#include "Container.h"
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


#endif //PROGRA2_PROJECT_1_DELTA_SINGLETONFILEMANAGER_H
