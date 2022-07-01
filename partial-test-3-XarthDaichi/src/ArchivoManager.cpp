//
// Created by Maikol Guzman Alan on 6/20/22.
//

#include "ArchivoManager.h"

ArchivoManager::ArchivoManager() {}

ArchivoManager::~ArchivoManager() {

}

vector<Enfermedad> ArchivoManager::cargarEnfermedades(string fileName) {
    vector<Enfermedad> enfermedades;
    string myTextLine;

    // Read from the text file
    ifstream myReadFile(fileName);

    if (!myReadFile.is_open()) {
        throw invalid_argument("Could not open the file [" + fileName + "]");
    }

    // Use a while loop together with the getline() function to readByLine the file line by line
    int rowCont = 0;
    while (getline(myReadFile, myTextLine)) {
        if (rowCont > 0) {
            Enfermedad enfermedad;
            // esta instrucción sirve para limpiar el último caracter
            myTextLine.erase(std::remove(myTextLine.begin(), myTextLine.end(), '\r'), myTextLine.end());
            stringstream ss(myTextLine);
            int colCont = 0;
            while (ss.good()) {
                string substr;
                getline(ss, substr, ',');
                if (colCont == 0) enfermedad.setEnfermedad(substr);
                if (colCont == 1) enfermedad.setSecuencia(substr);

                colCont++;
            }
            enfermedades.push_back(enfermedad);
        }
        // Output the text from the file
        rowCont++;
    }

    // Close the file
    myReadFile.close();

    return enfermedades;
    // No funciona con MinGw pero si con Visual Studio
    //    string enfermedad, secuencia;
//    vector<Enfermedad> parsingInfo;
//    ifstream in;
//
//    in.open(fileName, ios::in);
//
//    if (!in.is_open()) {
//        throw invalid_argument("Could not open the file [" + fileName + "]");
//    }
//
//    getline(in, enfermedad, '\n');
//
//    while(in.good()) {
//        getline(in, enfermedad, ',');
//        getline(in, secuencia, '\n');
//        secuencia.erase(remove(secuencia.begin(), secuencia.end(), '\r'));
//
//        if (!enfermedad.empty()){
//            Enfermedad tempEnfermedad(enfermedad, secuencia);
//            parsingInfo.push_back(tempEnfermedad);
//        }
//    }
//
//    in.close();
//
//    return parsingInfo;
}

vector<Paciente> ArchivoManager::cargarPacientes(string fileName) {
    vector<Paciente> pacientes;
    string myTextLine;

    // Read from the text file
    ifstream myReadFile(fileName);

    if (!myReadFile.is_open()) {
        throw invalid_argument("Could not open the file [" + fileName + "]");
    }

    // Use a while loop together with the getline() function to readByLine the file line by line
    int rowCont = 0;
    while (getline(myReadFile, myTextLine)) {
        if (rowCont > 0) {
            Paciente paciente;
            // esta instrucción sirve para limpiar el último caracter
            myTextLine.erase(std::remove(myTextLine.begin(), myTextLine.end(), '\r'), myTextLine.end());
            stringstream ss(myTextLine);
            int colCont = 0;
            while (ss.good()) {
                string substr;
                getline(ss, substr, ',');
                if (colCont == 0) paciente.setId(substr);
                if (colCont == 1) paciente.setNombre(substr);
                if (colCont == 2) paciente.setTelefono(substr);
                if (colCont == 3) paciente.setCorreo(substr);
                if (colCont == 4) paciente.setSecuencia(substr);

                colCont++;
            }
            pacientes.push_back(paciente);
        }
        // Output the text from the file
        rowCont++;
    }

    // Close the file
    myReadFile.close();

    return pacientes;

    // No estaba sirviendo con Mingw pero si con Visual Studio
    //    string id, nombre, telefono, correo, secuencia, newline;
//    vector<Paciente> parsingInfo;
//    ifstream in;
//
//    in.open(fileName, ios::in);
//
//    if (!in.is_open()) {
//        throw invalid_argument("Could not open the file [" + fileName + "]");
//    }
//
//    getline(in,  newline, '\n');
//
//    while(in.good()) {
//        getline(in, id, ',');
//        getline(in, nombre, ',');
//        getline(in, telefono, ',');
//        getline(in, correo, ',');
//        getline(in, secuencia, '\n');
//        secuencia.erase(remove(secuencia.begin(), secuencia.end(), '\r'));
//
//        if (!id.empty()){
//            Paciente tempPaciente(id, nombre, telefono, correo, secuencia);
//            parsingInfo.push_back(tempPaciente);
//        }
////        getline(in, newline, '\n');
//    }
//
//    in.close();
//
//    return parsingInfo;
}
