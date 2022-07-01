
#include "Grupo.h"

Grupo::Grupo() {}

Grupo::Grupo(int codigo, const string &codigoGrupo, const string &nombreGrupo) : codigo(codigo),
                                                                                 codigoGrupo(codigoGrupo),
                                                                                 nombreGrupo(nombreGrupo) {
    presupuesto = obtenerTotalPresupuesto();
    cantidadDeActividades = obtenerTotalCantActividades();
    cantidadDeAsociados = obtenerTotalCantidadAsociados();
}

Grupo::~Grupo() {

}

int Grupo::getCodigo() const {
    return codigo;
}

void Grupo::setCodigo(int codigo) {
    Grupo::codigo = codigo;
    presupuesto = obtenerTotalPresupuesto();
    cantidadDeActividades = obtenerTotalCantActividades();
    cantidadDeAsociados = obtenerTotalCantidadAsociados();
}

const string &Grupo::getCodigoGrupo() const {
    return codigoGrupo;
}

void Grupo::setCodigoGrupo(const string &codigoGrupo) {
    Grupo::codigoGrupo = codigoGrupo;
}

const string &Grupo::getNombreGrupo() const {
    return nombreGrupo;
}

void Grupo::setNombreGrupo(const string &nombreGrupo) {
    Grupo::nombreGrupo = nombreGrupo;
}

int Grupo::obtenerTotalCantActividades() const {
    Servicio servicio;
    return servicio.obtenerActividadPorAno(codigo);
}

double Grupo::obtenerTotalPresupuesto() const {
    Servicio servicio;
    return servicio.obtenerPresupuesto(codigo);
}

int Grupo::obtenerTotalCantidadAsociados() const {
    Servicio servicio;
    return servicio.obtenerCantidadAsociados(codigo);
}

ostream &operator<<(ostream &os, const Grupo &grupo) {
    stringstream sstream;
    sstream.setf(ios::fixed);
    sstream.precision(0);
    sstream << grupo.presupuesto;
    os << "presupuesto: " << sstream.str() << " cantidadDeActividades: " << grupo.cantidadDeActividades
       << " cantidadDeAsociados: " << grupo.cantidadDeAsociados << " codigo: " << grupo.codigo << " codigoGrupo: " << grupo.codigoGrupo
       << " nombreGrupo: " << grupo.nombreGrupo;
    return os;
}

string Grupo::toString() const {
    stringstream s;
    stringstream sstream;
    sstream.setf(ios::fixed);
    sstream.precision(0);
    sstream << presupuesto;

    s << "presupuesto: " << sstream.str() << " cantidadDeActividades: " << cantidadDeActividades
      << " cantidadDeAsociados: " << cantidadDeAsociados << " codigo: " << codigo << " codigoGrupo: " << codigoGrupo
      << " nombreGrupo: " << nombreGrupo;
    return s.str();
}
