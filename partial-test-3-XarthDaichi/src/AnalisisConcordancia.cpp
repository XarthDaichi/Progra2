//
// Created by Maikol Guzman Alan on 6/20/22.
//

#include "AnalisisConcordancia.h"

AnalisisConcordancia::AnalisisConcordancia() {}

AnalisisConcordancia::~AnalisisConcordancia() {

}

void
AnalisisConcordancia::mostrarAnalisis(ostringstream &oss, vector<Enfermedad> enfermedades, vector<Paciente> pacientes) {
    int counter = 0;
    for (auto i : enfermedades) {
        for (auto j : pacientes) {
            counter = calcularRepeticiones(i.getSecuencia(), j.getSecuencia());
            if (counter == 2) oss << j.getId() << '-' << j.getNombre() << '-' << j.getCorreo() << " [" << i.getEnfermedad() << "-MEDIA];";
            else if (counter >= 3) oss << j.getId() << '-' << j.getNombre() << '-' << j.getCorreo() << " [" << i.getEnfermedad() << "-ALTA];";
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
int AnalisisConcordancia::calcularRepeticiones(const string& textoBuscar, const string& textoBase) {
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
