//
// Created by Maikol Guzman Alan on 5/17/22.
//

#ifndef PARTIAL_TEST_2_COLEGIADO_SERVICIO_H
#define PARTIAL_TEST_2_COLEGIADO_SERVICIO_H

#include <iostream>
using namespace std;

class Servicio {
public:
    Servicio();

    virtual ~Servicio();

    double obtenerPresupuesto(int codigo);

    int obtenerActividadPorAno(int codigo);

    int obtenerCantidadAsociados(int codigo);

};


#endif //PARTIAL_TEST_2_COLEGIADO_SERVICIO_H
