//
// Created by Xarthy on 0020 April 20, 2022.
//
#include "FileManager.h"
#include <stdexcept>
int main() {
    try {

        // geting from .csv
        FileManager filemanager;
        PersonManager personManager = filemanager.loadCSV("../../email.csv");

        // testing from .toString()
        std::cout << personManager.toString() << std::endl << std::endl << std::endl;


        // saving to a .dat
        filemanager.saveDAT("../../email.dat", personManager);

        // loading from a .dat
        personManager = filemanager.loadDAT("../../email.dat");
        std:: cout << personManager.toString() << std::endl;

    } catch (std::exception& ex) {
        std::cerr << ex.what() << '\n' << std::endl;
    }

    return 0;
}