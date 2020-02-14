#include "Usuario.hpp"
#include <iostream>

Usuario::Usuario(string u, string p, string n, int e, float d): usr(u), pass(p), nombre(n), edad(e), dinero(d){}

void Usuario::print(){
	std::cout << getUsr() << " | " << getPass() << " | " << getNombre() << " | " << getEdad() << " | " << getDinero() << std::endl;
}
