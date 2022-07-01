//
// Created by Maikol Guzman Alan on 5/17/22.
//

#ifndef PARTIAL_TEST_2_COLEGIADO_REGION_H
#define PARTIAL_TEST_2_COLEGIADO_REGION_H

#include <iostream>
#include <sstream>
#include <string>
#include "Servicio.h"
using namespace std;

class Region {
protected:
    double presupuesto;
    int cantidadDeActividades;
    int cantidadDeAsociados;
public:

    Region();

    Region(double presupuesto, int cantidadDeActividades, int cantidadDeAsociados);

    virtual ~Region();

    double getPresupuesto() const;

    void setPresupuesto(double presupuesto);

    int getCantidadDeActividades() const;

    void setCantidadDeActividades(int cantidadDeActividades);

    int getCantidadDeAsociados() const;

    void setCantidadDeAsociados(int cantidadDeAsociados);

    friend ostream &operator<<(ostream &os, const Region &region);

    virtual int obtenerTotalCantActividades() const = 0;

    virtual double obtenerTotalPresupuesto() const = 0;

    virtual int obtenerTotalCantidadAsociados() const = 0;

    virtual string toString() const;
};


#endif //PARTIAL_TEST_2_COLEGIADO_REGION_H
