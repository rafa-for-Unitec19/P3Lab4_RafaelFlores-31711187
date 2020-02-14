#include <iostream>
#include "Libro.hpp"
#include "Usuario.hpp"

using namespace std;


Libro arrL[10];
Usuario arrU[10];
bool isAdmin = false;

int menu(){
	int op;
	cout << "\nEscoja la opcion que desee:"
		<< "\n\t1. Comprar Libro"
		<< "\n\t2. Buscar por Autor"
		<< "\n\t3. Buscar por Titulo"
		<< "\n\t4. Agregar dinero a mi cuenta"
		<< "\n\t5. Restablecer contraseña"
		<< "\n\t6. Borrar Cuenta"<< endl;
	cin >> op;
	return op;
}

int menuAdmin(){
	int op;
	cout << "\nIngrese la opcion administrador que desee:"
		<< "\n\t1. Agregar Libro"
		<< "\n\t2. Modificar Libro"
		<< "\n\t3. Eliminar Libro"
		<< "\n\t4. Borrar registro de libros" << endl;
	cin >> op;
	return op;
}

Usuario Login(){
	string usr, pass;
	cout <<	"Ingrese el Usuario" << endl;
	cin >> usr;
	cout << "Ingrese la Contraseña" << endl;
	cin >> pass;
	for (int i = 0; i < 10; i++){
		if ((arrU[i].getUsr() == usr) && (arrU[i].getPass() == pass)){
			cout << "Bienvenido " << arrU[i].getNombre() << endl;
			if(i == 0){
				cout << "Es admin " <<endl;
				isAdmin = true;
			}
			return arrU[i];
		}
	}
	Usuario def;
	return def;

}

Usuario menuLogin(bool &flag){
	Usuario act;
	while(true){
		int op;
		cout << "\nSeleccione la opcion que desea:"
			<< "\n\t1. Ingresar"
			<< "\n\t2. Registrarse" << endl;
		cin >> op;
		switch(op){
			case 1:
				cout << "Bienvenido al Log In" << endl;
				act =  Login();
				if (act.getNombre() == ""){
					cout << "No se encontro su usuario" << endl;
				}else{
					flag = true;
					return act;
				}		
				break;
			case 2:
				cout << "Bienvenido al Registro" << endl;
				break;
			default:
				cout << "La opcion es incorrecta" << endl;
		}
	}
}

void Agregar(){
	Libro l;
	cout << "Ingrese el nombre del libro: "<<endl;
	string t; cin >> t;
	l.setTitulo(t);
}

void selector(){
	bool salida = false, successLog = false;
	Usuario actual;
		while(!salida){
			actual = menuLogin(successLog);
		while(successLog){
			if (isAdmin){
				switch(menuAdmin()){
					case 1: 
						cout << "Agregar Libro" << endl;
						
						break;
					default:
							cout << "La opcion de admnistrador es incorrecta!!!" << endl;
				}
			}else{
				switch(menu()){
					default:
						cout << "La opcion es incorrecta";
				}
			}
		}
	}
}

int main(){
	arrU[0] = Usuario("n.duron", "sybase", "Nicolle Duron", 20, 1000);
	arrU[1] = Usuario("usr1", "pass1", "Rafael Flores", 21, 2000);
	selector();
	return 0;
}
