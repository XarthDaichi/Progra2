//
// Created by Maikol Guzman Alan on 4/8/22.
//

#ifndef PARTIAL_TEST_1_Q2_COLEGIADO_GUERRERO_H
#define PARTIAL_TEST_1_Q2_COLEGIADO_GUERRERO_H
#include <iostream>

class Guerrero {
private:
    std::string color = "Negro plateado";
public:
    Guerrero();

    Guerrero(const std::string &color);

    virtual ~Guerrero();

    const std::string &getColor() const;

    void setColor(const std::string &color);

    static std::string seDefiende();
    static std::string ataca();
    static std::string muere();

    friend std::ostream &operator<<(std::ostream &os, const Guerrero &guerrero);
};


#endif //PARTIAL_TEST_1_Q2_COLEGIADO_GUERRERO_H
