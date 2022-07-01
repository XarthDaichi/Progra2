//
// Created by Maikol Guzman Alan on 6/20/22.
//

#include "AnalisisEnfermedades.h"

AnalisisEnfermedades::AnalisisEnfermedades() {}

AnalisisEnfermedades::~AnalisisEnfermedades() {

}

void AnalisisEnfermedades::mostrarAnalisis(ostringstream &oss, vector<Enfermedad> enfermedades, vector<Paciente> pacientes) {
    for (auto i : enfermedades) {
        for (auto j : pacientes) {
            if (calcularRepeticiones(i.getSecuencia(), j.getSecuencia()) > 0) {
                oss << i.getEnfermedad() << ',';
                break;
            }
        }
    }
}

    /**
    * Algoritmo que permite determinar la repetición de una letra o conjunto de letras en un
    * texto base. Ejemplo: textoBuscar: abc, textoBase: abcdewabc, retorna 2 coincidencias
    * @param textoBuscar string que se busca en un texto base
    * @param textoBase es el textoBase
    * @return la cantidad de veces que se repite el textoBuscar
    */
int AnalisisEnfermedades::calcularRepeticiones(const string& textoBuscar, const string& textoBase) {
    int repeticiones = 0;
    unsigned long index = 0; // variable para la posición donde se encuentra la letra
    // El siguiente ciclo permite recorrer el string para identificar las veces que se
    // repite un carácter
    while ((index = textoBase.find(textoBuscar, index)) != std::string::npos) {
        index += textoBuscar.length();
        repeticiones++;
    }
    return repeticiones;
}

