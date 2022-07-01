//
// Created by Xarthy on 0021 May 21, 2022.
//

#ifndef SINGLETON_CONTAINER_H
#define SINGLETON_CONTAINER_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

template<class T>
class Container {
protected:
    vector<T*> vec;
public:
    void push(T* const &);
    void pop();
    T* top() const;
    bool empty() const;
    void insert(int position, T* const &elem);

    template<typename V>
    vector<T*> certainObjects(V &thing) const;

    vector<T*> allObjects() const;

    string toString() const;
};

template<class T>
void Container<T>::push(T* const &elem) {
    vec.push_back(elem);
}

template<class T>
void Container<T>::pop() {
    if (vec.empty()) {
        throw out_of_range("Container<>::pop(): empty container");
    }

    vec.pop_back();
}

template<class T>
T* Container<T>::top() const {
    if (vec.empty()) {
        throw out_of_range("Container<>::top(): empty container");
    }

    return vec.back();
}

template<class T>
bool Container<T>::empty() const {
    return vec.empty();
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
vector<T *> Container<T>::certainObjects(V &thing) const {
    vector<T *> newVector;
    stringstream searching;
    searching << thing;
    for (T * i : vec) {
        stringstream testing;
        testing << *i;
        if (testing.str().find(searching.str()) != string::npos) newVector.push_back(i);
        testing.str("");
    }
    return newVector;
}

template<class T>
vector<T*> Container<T>::allObjects() const {
    return vec;
}

template<class T>
string Container<T>::toString() const {
    stringstream s;
    for (T* i : vec) {
        s << *i;
    }
    return s.str();
}

#endif //SINGLETON_CONTAINER_H
