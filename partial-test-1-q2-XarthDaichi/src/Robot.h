//
// Created by Maikol Guzman Alan on 4/8/22.
//

#ifndef PARTIAL_TEST_1_Q2_COLEGIADO_ROBOT_H
#define PARTIAL_TEST_1_Q2_COLEGIADO_ROBOT_H
#include <iostream>

class Robot {
protected:
    double nivelDeBateria = 100;
    int numSensores = 2000;
public:
    Robot();

    Robot(double nivelDeBateria, int numSensores);

    virtual ~Robot();

    double getNivelDeBateria() const;

    void setNivelDeBateria(double nivelDeBateria);

    int getNumSensores() const;

    void setNumSensores(int numSensores);

    virtual std::string seConfigura();

    virtual std::string seRecarga();

    friend std::ostream &operator<<(std::ostream &os, const Robot &robot);
};

#endif //PARTIAL_TEST_1_Q2_COLEGIADO_ROBOT_H
