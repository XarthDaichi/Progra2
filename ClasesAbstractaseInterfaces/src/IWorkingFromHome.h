//
// Created by Xarthy on 0020 March 20, 2022.
//

#ifndef CLASESABSTRACTASEINTERFACES_IWORKINGFROMHOME_H
#define CLASESABSTRACTASEINTERFACES_IWORKINGFROMHOME_H


class IWorkingFromHome {
public:
    IWorkingFromHome();

    virtual ~IWorkingFromHome();

    virtual string returnHomAddress() const = 0;
};


#endif //CLASESABSTRACTASEINTERFACES_IWORKINGFROMHOME_H
