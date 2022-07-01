//
// Created by Maikol Guzman Alan on 4/8/22.
//

#ifndef PARTIAL_TEST_1_Q2_COLEGIADO_HUMANOIDE_H
#define PARTIAL_TEST_1_Q2_COLEGIADO_HUMANOIDE_H
#include "RoboCop.h"
#include "Guerrero.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <ostream>

class Humanoide : public RoboCop, public Guerrero {
private:
    double velocidad{};
public:
    Humanoide();

    Humanoide(const std::string &nombre, double nivelDeBateria, int numSensores, const std::string &numSerie,
              int nivelDeDano, int codigoDeArmadura, const std::string &color, double velocidad);

    virtual ~Humanoide();

    double getVelocidad() const;

    void setVelocidad(double velocidad);

    virtual int setValor(double x) = 0;

    virtual std::string toString() = 0;

    virtual std::string corre() const;

    friend std::ostream &operator<<(std::ostream &os, const Humanoide &humanoide);
};


#endif //PARTIAL_TEST_1_Q2_COLEGIADO_HUMANOIDE_H
