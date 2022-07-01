//
// Created by Maikol Guzman Alan on 4/8/22.
//

#ifndef PARTIAL_TEST_1_Q2_COLEGIADO_ROBOCOP_H
#define PARTIAL_TEST_1_Q2_COLEGIADO_ROBOCOP_H

#include <ostream>
#include "Robot.h"
#include "Policia.h"
#include "Armadura.h"

class RoboCop : public Policia, public Robot {
private:
    std::string numSerie;
    int nivelDeDano{};
    int codigoDeArmadura{};
public:
    RoboCop();

    RoboCop(const std::string &nombre, double nivelDeBateria, int numSensores, const std::string &numSerie,
            int nivelDeDano, int codigoDeArmadura);

    virtual ~RoboCop();

    static std::string dispara();
    static std::string detiene();

    const std::string &getNumSerie() const;

    void setNumSerie(const std::string &numSerie);

    int getNivelDeDano() const;

    void setNivelDeDano(int nivelDeDano);

    int getCodigoDeArmadura() const;

    void setCodigoDeArmadura(int codigoDeArmadura);

    std::string tipoDeMetal() const;

    int nivelDeResistencia() const;

    double valorEnDolares() const;

    friend std::ostream &operator<<(std::ostream &os, const RoboCop &cop);

    std::string seConfigura() override {
        return "El Robot se Autoconfigura";
    }

    std::string seRecarga() override {
        return "El Robot se Auto Recarga a: 100.000000";
    }
};


#endif //PARTIAL_TEST_1_Q2_COLEGIADO_ROBOCOP_H
