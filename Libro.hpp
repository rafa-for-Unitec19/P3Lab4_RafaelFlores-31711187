#include <iostream>
#ifndef LIBRO_H
#define LIBRO_H

using namespace std;

class Libro{
		string titulo, autor;
		float precio;
		bool estado;
	public: 
		Libro(){};
		~Libro(){};
		void setTitulo(string t) {this->titulo = t;};
		void setAutor(string a){this->autor = a;};
		void setPrecio(float p){this->precio = p;};
		void setEstado(bool e){this->estado = e;};
		string getTitulo() const {return titulo;};
		string getAutor() const {return autor;};
		float getPrecio() const {return precio;};
		bool getEstado() const {return estado;};
		void print();		
};
#endif
