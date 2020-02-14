#include "Usuario.hpp"
#include <iostream>

void Usuario::print(){
	std::cout << getUsr() << " | " << getPass() << " | " << getNombre() << " | " << getEdad() << " | " << getDinero() << std::endl;
}
