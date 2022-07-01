//
// Created by Xarthy on 0021 May 21, 2022.
//

#ifndef SINGLETON_VIDEOGAMEFILEMANAGER_H
#define SINGLETON_VIDEOGAMEFILEMANAGER_H

#include "SingletonFileManager.h"
#include "Videogame.h"

class VideogameFileManager final : public SingletonFileManager<VideogameFileManager> {
private:
    Container<Videogame>* videogames;
    char inputType;
public:
    VideogameFileManager(const char c);
    virtual ~VideogameFileManager();

    Container<Videogame>* getVideogames();

    static ostream& write(ostream& out, const Videogame& videogame);
    static istream& read(istream& in, Videogame& videogame);
};


#endif //SINGLETON_VIDEOGAMEFILEMANAGER_H
