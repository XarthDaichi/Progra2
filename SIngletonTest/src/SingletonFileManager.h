//
// Created by Xarthy on 0013 May 13, 2022.
//

#ifndef SINGLETONTEST_SINGLETONFILEMANAGER_H
#define SINGLETONTEST_SINGLETONFILEMANAGER_H
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
#endif //SINGLETONTEST_SINGLETONFILEMANAGER_H
