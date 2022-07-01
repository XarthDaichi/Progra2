//
// Created by Maikol Guzman Alan on 4/8/22.
//

#ifndef PARTIAL_TEST_1_Q2_COLEGIADO_HUMANOIDEMANAGER_H
#define PARTIAL_TEST_1_Q2_COLEGIADO_HUMANOIDEMANAGER_H
#include "Humanoide.h"
#include "Alien.h"
#include "Predator.h"
#include <vector>

class HumanoideManager {
private:
    std::vector<Humanoide *> humanoideLista;
public:
    HumanoideManager() = default;

    HumanoideManager(std::vector<Humanoide *> &humanoideLista);

    virtual ~HumanoideManager();

    std::vector<Humanoide *> getHumanoideLista() const;

    void setHumanoideLista(std::vector<Humanoide *> &humanoideLista);

    void ingresaHumanoide(Humanoide* humanoide);
    std::string retornaSoloAliens();
    std::string retornaTodos();
};


#endif //PARTIAL_TEST_1_Q2_COLEGIADO_HUMANOIDEMANAGER_H
