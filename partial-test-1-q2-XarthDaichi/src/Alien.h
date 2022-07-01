//
// Created by Maikol Guzman Alan on 4/8/22.
//

#ifndef PARTIAL_TEST_1_Q2_COLEGIADO_ALIEN_H
#define PARTIAL_TEST_1_Q2_COLEGIADO_ALIEN_H

#include <ostream>
#include "Humanoide.h"

class Alien : public Humanoide {
private:
    double estatura{};
public:
    Alien();

    Alien(const std::string &nombre, double nivelDeBateria, int numSensores, const std::string &numSerie,
          int nivelDeDano, int codigoDeArmadura, const std::string &color, double velocidad, double estatura);

    virtual ~Alien();

    double getEstatura() const;

    void setEstatura(double estatura);

    int setValor(double x) override;

    friend std::ostream &operator<<(std::ostream &os, const Alien &alien);

    std::string toString() override;
};


#endif //PARTIAL_TEST_1_Q2_COLEGIADO_ALIEN_H
