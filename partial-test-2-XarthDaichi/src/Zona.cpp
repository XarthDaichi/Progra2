#include "Zona.h"

Zona::Zona() {}

Zona::Zona(Persona *coordinador, const string &nombreZona) : coordinador(coordinador), nombreZona(nombreZona) {
    presupuesto = obtenerTotalPresupuesto();
    cantidadDeActividades = obtenerTotalCantActividades();
    cantidadDeAsociados = obtenerTotalCantidadAsociados();
}

Zona::~Zona() {

}

Persona *Zona::getCoordinador() const {
    return coordinador;
}

void Zona::setCoordinador(Persona *coordinador) {
    Zona::coordinador = coordinador;
}

const string &Zona::getNombreZona() const {
    return nombreZona;
}

void Zona::setNombreZona(const string &nombreZona) {
    Zona::nombreZona = nombreZona;
}

const vector<Region*> &Zona::getZonaLista() const {
    return zonaLista;
}

void Zona::setZonaLista(const vector<Region*> &zonaLista) {
    Zona::zonaLista = zonaLista;
    presupuesto = obtenerTotalPresupuesto();
    cantidadDeActividades = obtenerTotalCantActividades();
    cantidadDeAsociados = obtenerTotalCantidadAsociados();
}

ostream &operator<<(ostream &os, const Zona &zona) {
    os << static_cast<const Region &>(zona) << " coordinador: " << *zona.coordinador << " nombreZona: "
       << zona.nombreZona;
    return os;
}

int Zona::obtenerTotalCantActividades() const {
    int suma = 0;
    for (auto i : zonaLista) {
        Zona *j = (Zona *) (i);
        if (!j) Grupo *j = (Grupo *) (i);
        suma += j->obtenerTotalCantActividades();
    }

    return suma;

    return suma;
}

double Zona::obtenerTotalPresupuesto() const {
    int suma = 0;
    for (auto i : zonaLista) {
        Zona *j = (Zona *) (i);
        if (!j) Grupo *j = (Grupo *) (i);
        suma += j->obtenerTotalPresupuesto();
    }

    return suma;
}

int Zona::obtenerTotalCantidadAsociados() const {
    int suma = 0;
    for (auto i : zonaLista) {
        Zona *j = (Zona *) (i);
        if (!j) Grupo *j = (Grupo *) (i);
        suma += j->obtenerTotalCantidadAsociados();
    }

    return suma;
}

string Zona::toString() const {
    stringstream s;
    s << (*this);
    return s.str();
}

void Zona::agregar(Region* region) {
    zonaLista.push_back(region);
    presupuesto = obtenerTotalPresupuesto();
    cantidadDeActividades = obtenerTotalCantActividades();
    cantidadDeAsociados = obtenerTotalCantidadAsociados();
}


