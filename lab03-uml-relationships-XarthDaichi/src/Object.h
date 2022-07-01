//
// Created by Xarthy on 0009 April 09, 2022.
//

#ifndef LAB03_UML_RELATIONSHIPS_XARTHDAICHI_OBJECT_H
#define LAB03_UML_RELATIONSHIPS_XARTHDAICHI_OBJECT_H
#include <iostream>
#include <vector>

class Object {
protected:
public:
    Object();

    virtual ~Object();

    friend std::ostream &operator<<(std::ostream &os, const Object &object);
};


#endif //LAB03_UML_RELATIONSHIPS_XARTHDAICHI_OBJECT_H
