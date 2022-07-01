//
// Created by Xarthy on 0026 April 26, 2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_CONTAINER_H
#define PROGRA2_PROJECT_1_DELTA_CONTAINER_H

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<stdexcept>

template<class T>
class Container {
protected:
    std::vector<T*> vec;
public:
    void push(T* const &);
    void pop();
    T* top() const;
    bool empty() const {
        return vec.empty();
    }
    void insert(int position, T* const &elem);

    template<typename V>
    std::vector<T*> certainObjects(V &thing) const;

    std::vector<T*> allObjects() const;

    std::string toString() const;
};

template<class T>
void Container<T>::push(T* const &elem){
    vec.push_back(elem);
}

template<class T>
void Container<T>::pop() {
    if (vec.empty()) {
        throw std::out_of_range("Container<>::pop(): empty container");
    }

    vec.pop_back();
}

template<class T>
T* Container<T>::top() const {
    if (vec.empty()) {
        throw std::out_of_range("Container<>::top(): empty container");
    }

    return vec.back();
}

template<class T>
void Container<T>::insert(int position, T* const &elem) {
    auto iterator = vec.begin();
    if (vec.empty()) {
        vec.push_back(elem);
    } else {
        vec.insert(iterator + position, elem);
    }
}

template<class T>
template<typename V>
std::vector<T *> Container<T>::certainObjects(V &thing) const {
    std::vector<T *> newVector;
    std::stringstream searching;
    searching << thing;
    for (T * i : vec) {
        std::stringstream testing;
        testing << *i;
        if (testing.str().find(searching.str()) != std::string::npos) newVector.push_back(i);
        testing.str("");
    }
    return newVector;
}

template<class T>
std::vector<T *> Container<T>::allObjects() const {
    return vec;
}

template<class T>
std::string Container<T>::toString() const {
    std::stringstream s;
    for (T* i : vec) {
        s << i->toString();
    }
    return s.str();
};

/*
 */

#endif //PROGRA2_PROJECT_1_DELTA_CONTAINER_H
