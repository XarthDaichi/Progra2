
#include "Region.h"

Region::Region() {}

Region::Region(double presupuesto, int cantidadDeActividades, int cantidadDeAsociados) : presupuesto(presupuesto),
                                                                                         cantidadDeActividades(
                                                                                                 cantidadDeActividades),
                                                                                         cantidadDeAsociados(
                                                                                                 cantidadDeAsociados) {}

Region::~Region() {

}

double Region::getPresupuesto() const {
    return presupuesto;
}

void Region::setPresupuesto(double presupuesto) {
    Region::presupuesto = presupuesto;
}

int Region::getCantidadDeActividades() const {
    return cantidadDeActividades;
}

void Region::setCantidadDeActividades(int cantidadDeActividades) {
    Region::cantidadDeActividades = cantidadDeActividades;
}

int Region::getCantidadDeAsociados() const {
    return cantidadDeAsociados;
}

void Region::setCantidadDeAsociados(int cantidadDeAsociados) {
    Region::cantidadDeAsociados = cantidadDeAsociados;
}

string Region::toString() const {
    stringstream s;
    s << (*this);
    return s.str();
}

ostream &operator<<(ostream &os, const Region &region) {
    stringstream sstream;
    sstream.setf(ios::fixed);
    sstream.precision(0);
    sstream << region.presupuesto;
    os << "presupuesto: " << sstream.str() << " cantidadDeActividades: " << region.cantidadDeActividades
       << " cantidadDeAsociados: " << region.cantidadDeAsociados;
    return os;
}

