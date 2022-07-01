//
// Created by Maikol Guzman Alan on 4/8/22.
//

#ifndef MY_PROJECT_NAME_POLICIA_H
#define MY_PROJECT_NAME_POLICIA_H
#include <iostream>


class Policia {
protected:
    std::string nombre;
public:
    Policia();

    Policia(const std::string &nombre);

    virtual ~Policia();

    const std::string &getNombre() const;
    void setNombre(const std::string &nombre);

    static std::string aprende();
    static std::string aplicaJusticia();
    static std::string ayuda();

    friend std::ostream &operator<<(std::ostream &os, const Policia &policia);
};


#endif //MY_PROJECT_NAME_POLICIA_H
