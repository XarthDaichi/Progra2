//
// Created by Xarthy on 0020 April 20, 2022.
//

#ifndef LAB04_V2_DATAFLOW_XARTHDAICHI_OBJECT_H
#define LAB04_V2_DATAFLOW_XARTHDAICHI_OBJECT_H

#include<iostream>
#include<sstream>
#include<string>

class Object {
public:
    virtual std::string toString() const = 0;
};


#endif //LAB04_V2_DATAFLOW_XARTHDAICHI_OBJECT_H
