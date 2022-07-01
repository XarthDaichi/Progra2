//
// Created by Maikol Guzman Alan on 4/8/22.
//

#ifndef PARTIAL_TEST_1_Q2_COLEGIADO_PREDATOR_H
#define PARTIAL_TEST_1_Q2_COLEGIADO_PREDATOR_H
#include "Humanoide.h"


class Predator : public Humanoide {
private:
    double peso{};
public:
    Predator();

    Predator(const std::string &nombre, double nivelDeBateria, int numSensores, const std::string &numSerie,
             int nivelDeDano, int codigoDeArmadura, const std::string &color, double velocidad, double peso);

    virtual ~Predator();

    double getPeso() const;

    void setPeso(double peso);

    int setValor(double x);

    std::string toString() override;
};


#endif //PARTIAL_TEST_1_Q2_COLEGIADO_PREDATOR_H
