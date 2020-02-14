#include "Libro.hpp"
#include <iostream>

void Libro::print(){
	std::cout << getTitulo() << " | " << getAutor() << " | " << getPrecio() << " | " << getEstado() << std::endl;
}
