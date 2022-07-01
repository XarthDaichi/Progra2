//
// Created by ribre on 15/06/2022.
//

#ifndef MY_PROJECT_NAME_IOBSERVER_H
#define MY_PROJECT_NAME_IOBSERVER_H
#include <ostream>
#include <iostream>
#include "Set.h"
using namespace std;

class IObserver {
public:
    virtual void update(Set * stock, Set * catalog) = 0;

    virtual ~IObserver() = default;
};
#endif
