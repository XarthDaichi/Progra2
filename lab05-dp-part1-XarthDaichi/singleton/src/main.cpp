//
// Created by Xarthy on 0017 May 17, 2022.
//

#include "VideogameFileManager.h"

void generateFiles() {
    Videogame v1("Star Wars Jedi: Fallen Order Deluxe Edition", "Respawn Entertainment", 39.990);
    Videogame v2("Hollow Knight", "Team Cherry", 15.99);

    ofstream out;
    out.open("../../db_videogames.txt", ios::out | ios::trunc);
    out << v1.getName() << ';' << v1.getCompany() << ';' << v1.getPrice() << '\n';
    out << v2.getName() << ';' << v2.getCompany() << ';' << v2.getPrice() << '\n';

    out.close();

    out.open("../../db_videogames.dat", ios::out | ios::trunc | ios::binary);
    VideogameFileManager::write(out,v1);
    VideogameFileManager::write(out, v2);
    out.close();
}

int main() {
    vector<Videogame*> vid = VideogameFileManager::getInstance().getVideogames()->allObjects();
    for (auto * i : vid) {
        cout << *i << endl;
    }
//    Videogame* v3 = new Videogame("Tomb Raider", "Crystal Dynamics", 14.99);
//    VideogameFileManager::getInstance().getVideogames()->push(v3);

    return 0;
}