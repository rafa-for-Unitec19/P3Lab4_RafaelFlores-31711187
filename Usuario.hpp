#include <iostream>

using namespace std;

class Usuario{
		string usr, pass, nombre;
		int edad;
		float dinero;
	public:
		Usuario();
		~Usuario();
		void setUsr(string u){this->usr = u;};
		void setPass(string p){this->pass = p;};
		void setNombre(string n){this->nombre = n;};
		void setEdad(int e){this->edad = e;};
		void setDinero(float d){this->dinero = d;};
		string getUsr() const {return usr;};
		string getPass() const {return pass;};
		string getNombre() const {return nombre;};
		int getEdad() const {return edad;};
		float getDinero() const {return dinero;};
		void print();
};
