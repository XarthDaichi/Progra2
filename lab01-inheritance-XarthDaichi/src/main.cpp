#include "Derived1.h"
#include "Derived2.h"

// function main begins program execution
int main(int argc, char *argv[]) {
    std::cout << "Welcome to the UNA!" << std::endl;

    Derived1 derived1(3);
    derived1.do_something();

    Derived2 derived2(4);
    derived2.do_something();

    Derived1 derived3;
    derived3.setTest(1);

    Derived2 derived4;

    std::cout << "toString of derived1" << derived1 << std::endl;
    std::cout << "toString of derived2" << derived2 << std::endl;
    std::cout << "toString of derived3" << derived3 << std::endl;
    std::cout << "toString of derived4" << derived4 << std::endl;

    return 0;
}  // end function main