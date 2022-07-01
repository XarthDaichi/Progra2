//
// Created by Maikol Guzman Alan on 5/17/22.
//

#ifndef PARTIAL_TEST_2_COLEGIADO_GRUPO_H
#define PARTIAL_TEST_2_COLEGIADO_GRUPO_H

#include <ostream>
#include "Region.h"

class Grupo : public Region {
private:
    int codigo;
    string codigoGrupo;
    string nombreGrupo;
public:
    Grupo();

    Grupo(int codigo, const string &codigoGrupo, const string &nombreGrupo);

    virtual ~Grupo();

    int getCodigo() const;

    void setCodigo(int codigo);

    const string &getCodigoGrupo() const;

    void setCodigoGrupo(const string &codigoGrupo);

    const string &getNombreGrupo() const;

    void setNombreGrupo(const string &nombreGrupo);

    friend ostream &operator<<(ostream &os, const Grupo &grupo);

    int obtenerTotalCantActividades() const override;

    double obtenerTotalPresupuesto() const override;

    int obtenerTotalCantidadAsociados() const override;

    string toString() const override;
};


#endif //PARTIAL_TEST_2_COLEGIADO_GRUPO_H
