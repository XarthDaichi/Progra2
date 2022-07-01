//
// Created by Xarthy on 0020 March 20, 2022.
//

#ifndef CLASESABSTRACTASEINTERFACES_IWORKINGFROMOFFICE_H
#define CLASESABSTRACTASEINTERFACES_IWORKINGFROMOFFICE_H
#include <iostream>

class IWorkingFromOffice {
public:
    IWorkingFromOffice();
    virtual ~IWorkingFromOffice();
    virtual string returnOfficeAddress() const = 0;
};


#endif //CLASESABSTRACTASEINTERFACES_IWORKINGFROMOFFICE_H
