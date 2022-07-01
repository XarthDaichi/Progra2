//
// Created by Maikol Guzman Alan on 5/17/22.
//

#ifndef PARTIAL_TEST_2_COLEGIADO_ZONA_H
#define PARTIAL_TEST_2_COLEGIADO_ZONA_H

#include "Region.h"
#include "Persona.h"
#include "Grupo.h"
#include <vector>
#include <ostream>

class Zona : public Region {
private:
    Persona *coordinador;
    string nombreZona;
    vector<Region*> zonaLista;

public:
    Zona();

    Zona(Persona *coordinador, const string &nombreZona);

    virtual ~Zona();

    Persona *getCoordinador() const;

    void setCoordinador(Persona *coordinador);

    const string &getNombreZona() const;

    void setNombreZona(const string &nombreZona);

    const vector<Region*> &getZonaLista() const;

    void setZonaLista(const vector<Region*> &zonaLista);

    void agregar(Region* region);

    int obtenerTotalCantActividades() const override;

    double obtenerTotalPresupuesto() const override;

    int obtenerTotalCantidadAsociados() const override;

    string toString() const override;

    friend ostream &operator<<(ostream &os, const Zona &zona);
};

#endif //PARTIAL_TEST_2_COLEGIADO_ZONA_H
