//
// Created by Xarthy on 0009 April 09, 2022.
//

#ifndef LAB03_UML_RELATIONSHIPS_XARTHDAICHI_PERIOD_H
#define LAB03_UML_RELATIONSHIPS_XARTHDAICHI_PERIOD_H

#include <ostream>
#include "Object.h"

class Period : public Object {
private:
    int startingHour;
    int startingMinute;
    int endHour;
    int endMinute;
    vector<std::string> days;
public:
    Period();

    virtual ~Period();

    int getStartingHour() const;

    void setStartingHour(int startingHour);

    int getStartingMinute() const;

    void setStartingMinute(int startingMinute);

    int getEndHour() const;

    void setEndHour(int endHour);

    int getEndMinute() const;

    void setEndMinute(int endMinute);

    const std::vector<std::string> &getDays() const;

    void setDays(const std::vector<std::string> &days);

    friend std::ostream &operator<<(std::ostream &os, const Period &period);
};


#endif //LAB03_UML_RELATIONSHIPS_XARTHDAICHI_PERIOD_H
