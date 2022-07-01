//
// Created by ribre on 15/06/2022.
//

#ifndef MY_PROJECT_NAME_ISUBJECT_H
#define MY_PROJECT_NAME_ISUBJECT_H
#include "IObserver.h"
class ISubject {
public:
    virtual bool registerObserver(IObserver *observer) = 0;
    virtual void removeObserver(IObserver *observer) = 0;
    virtual void notifyObservers() = 0;

    virtual ~ISubject() = default;
};
#endif //MY_PROJECT_NAME_ISUBJECT_H
