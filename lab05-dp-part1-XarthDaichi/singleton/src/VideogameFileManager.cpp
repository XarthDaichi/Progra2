//
// Created by Xarthy on 0021 May 21, 2022.
//

#include "VideogameFileManager.h"

VideogameFileManager::VideogameFileManager(const char c) : inputType(c) {
    videogames = new Container<Videogame>();
    clog << "Constructing VideogameFileManager" << endl;

    string name, company, priceStr;
    Videogame* videogame;

    string fileName = "../../db_videogames.";

    if (inputType == 'b') fileName += "dat";
    else fileName += "txt";

    ifstream in;
    in.open(fileName, ios::in | ios::binary);
    if(!in.is_open()) {
        throw invalid_argument(" Could not open file [" + fileName + "]");
    }

    if (inputType != 'b') getline(in, name, '\n');
    else in.seekg(0);

    while(in.good()) {
        videogame = new Videogame();
        if(inputType == 'b') read(in, *videogame);
        else {
            getline(in, name, ';');
            getline(in, company, ';');
            getline(in, priceStr, '\n');

            videogame->setName(name);
            videogame->setCompany(company);
            videogame->setPrice(stod(priceStr));
        }
        if(!videogame->getName().empty()) videogames->push(videogame);
    }

    in.close();
    clog << "Constructed VideogameFileManager" << endl;
}

VideogameFileManager::~VideogameFileManager() {
    clog << "Deconstructing VideogameFileManager" << endl;

    string fileNametxt = "../../db_videogames.txt", fileNamedat = "../../db_videogames.dat";
    ofstream outtxt, outdat;

    outtxt.open(fileNametxt, ios::trunc | ios::out);

    outtxt << "Name;Company;Price\n";

    for (auto * i : videogames->allObjects()) {
        outtxt << i->getName() << ';' << i->getCompany() << ';' << i->getPrice() << '\n';
    }
    outtxt.close();

    outdat.open(fileNamedat, ios::trunc | ios::out | ios::binary);

    for (auto * i : videogames->allObjects()) {
        write(outdat, *i);
     }

    outdat.close();

    clog << "Deconstructed VideogameFileManager" << endl;
}

Container<Videogame>* VideogameFileManager::getVideogames() {
    return videogames;
}

ostream& VideogameFileManager::write(ostream& out, const Videogame& videogame) {
    double price = videogame.getPrice();
    size_t lenN = videogame.getName().size();
    size_t lenC = videogame.getCompany().size();

    out.write((char*)&lenN, sizeof(lenN));
    out.write(videogame.getName().c_str(), lenN);
    out.write((char*)&lenC, sizeof(lenC));
    out.write(videogame.getCompany().c_str(), lenC);
    out.write((char*)(&price), sizeof(videogame.getPrice()));

    return out;
}

istream& VideogameFileManager::read(istream& in, Videogame& videogame) {
    size_t lenN = 0;
    size_t lenC = 0;
    double price = 0;

    in.read((char*)&lenN, sizeof(lenN));
    char* name = new char[lenN + 1];
    in.read(name, lenN);
    name[lenN] = '\0';
    videogame.setName(name);
    delete[] name;

    in.read((char*)&lenC, sizeof(lenC));
    char* company = new char[lenC + 1];
    in.read(company, lenC);
    company[lenC] = '\0';
    videogame.setCompany(company);
    delete[] company;

    in.read((char*)&price, sizeof(price));
    videogame.setPrice(price);

    return in;
}