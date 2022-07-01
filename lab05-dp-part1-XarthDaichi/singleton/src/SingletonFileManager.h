//
// Created by Xarthy on 0021 May 21, 2022.
//

#ifndef SINGLETON_SINGLETONFILEMANAGER_H
#define SINGLETON_SINGLETONFILEMANAGER_H

#include "Container.h"
#include <fstream>

template<typename T>
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

#endif //SINGLETON_SINGLETONFILEMANAGER_H
