
#include "Servicio.h"

Servicio::Servicio() {}

Servicio::~Servicio() {

}

double Servicio::obtenerPresupuesto(int codigo) {
    switch(codigo) {
        case 15:
            return 33000000;
        case 52:
            return 39000000;
        case 55:
            return 15000000;
        case 39:
            return 14000000;
        case 33:
            return 25000000;
        case 43:
            return 60000000;
        case 37:
            return 15000000;
        default:
            return -1;
    }

}

int Servicio::obtenerActividadPorAno(int codigo) {
    switch(codigo) {
        case 15:
            return 30;
        case 52:
            return 35;
        case 55:
            return 16;
        case 39:
            return 11;
        case 33:
            return 23;
        case 43:
            return 42;
        case 37:
            return 18;
        default:
            return -1;
    }
}

int Servicio::obtenerCantidadAsociados(int codigo) {
    switch(codigo) {
        case 15:
            return 35;
        case 52:
            return 22;
        case 55:
            return 11;
        case 39:
            return 12;
        case 33:
            return 7;
        case 43:
            return 44;
        case 37:
            return 23;
        default:
            return -1;
    }
}