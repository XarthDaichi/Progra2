//
// Created by Maikol Guzman Alan on 6/20/22.
//

#include "AnalisisBaseNitrogenada.h"

AnalisisBaseNitrogenada::AnalisisBaseNitrogenada() {}

AnalisisBaseNitrogenada::~AnalisisBaseNitrogenada() {

}

void AnalisisBaseNitrogenada::mostrarAnalisis(ostringstream &oss, vector<Enfermedad> enfermedades,
                                              vector<Paciente> pacientes) {
    for (auto i : pacientes) {
        oss << fixed << setprecision(6) << i.getNombre() << "[A-";
        oss << ((float)calcularRepeticiones("A", i.getSecuencia()) * 100/ (float)i.getSecuencia().length())<< "%,T-";
        oss << ((float)calcularRepeticiones("T", i.getSecuencia()) * 100/ (float)i.getSecuencia().length()) << "%,G-";
        oss << ((float)calcularRepeticiones("G", i.getSecuencia()) * 100/ (float)i.getSecuencia().length()) << "%,C-";
        oss << ((float)calcularRepeticiones("C", i.getSecuencia()) * 100/ (float)i.getSecuencia().length())<< "];";
    }
}

/**
* Algoritmo que permite determinar la repetición de una letra o conjunto de letras en un
* texto base. Ejemplo: textoBuscar: abc, textoBase: abcdewabc, retorna 2 coincidencias
* @param textoBuscar string que se busca en un texto base
* @param textoBase es el textoBase
* @return la cantidad de veces que se repite el textoBuscar
*/
int AnalisisBaseNitrogenada::calcularRepeticiones(const string& textoBuscar, const string& textoBase) {
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
