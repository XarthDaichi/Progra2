//
// Created by Xarthy on 0009 April 09, 2022.
//

#include "Period.h"

Period::Period() {}

Period::~Period() {

}

int Period::getStartingHour() const {
    return startingHour;
}

void Period::setStartingHour(int startingHour) {
    Period::startingHour = startingHour;
}

int Period::getStartingMinute() const {
    return startingMinute;
}

void Period::setStartingMinute(int startingMinute) {
    Period::startingMinute = startingMinute;
}

int Period::getEndHour() const {
    return endHour;
}

void Period::setEndHour(int endHour) {
    Period::endHour = endHour;
}

int Period::getEndMinute() const {
    return endMinute;
}

void Period::setEndMinute(int endMinute) {
    Period::endMinute = endMinute;
}

const std::vector<std::string> &Period::getDays() const {
    return days;
}

void Period::setDays(const std::vector<std::string> &days) {
    Period::days = days;
}

std::ostream &operator<<(std::ostream &os, const Period &period) {
    os << static_cast<const Object &>(period) << " startingHour: " << period.startingHour << " startingMinute: "
       << period.startingMinute << " endHour: " << period.endHour << " endMinute: " << period.endMinute << " days: "
       << period.days;
    return os;
}
