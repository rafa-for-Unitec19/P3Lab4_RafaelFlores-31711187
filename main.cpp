#include <iostream>
#include "Libro.hpp"
#include "Usuario.hpp"

using namespace std;


Libro arrL[10];
Usuario arrU[10];
bool isAdmin = false;

void imprimir(int ind){
	cout << "A continuacion se listan los libros existentes" << endl;
	for (int i = 0; i < ind; i++){
		if (arrL[i].getTitulo() != ""){
			cout << (i+1) << " -> " << arrL[i].getTitulo() << " Precio -> " << arrL[i].getPrecio() << endl;
		}
	}
}

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

void Agregar(int &ind){
	cin.ignore();
	Libro l;
	cout << "Ingrese el titulo del libro: " << endl;
	string t; getline(cin, t);
	l.setTitulo(t);
	cout << "Ingrese el nombre del autor" << endl;
	string a; getline(cin, a);
	cin.ignore();
	l.setAutor(a);
	cin.get();
	while(true){
		cout << "Ingrese el precio del libro"<< endl;
		float p; cin >> p;
		if (p > 0) { l.setPrecio(p);break; 
		}else{ cout << "El precio no puede ser negativo" << endl;}
	}
	l.setEstado(true);
	arrL[ind] = l;
	ind++;
}

void Eliminar(int ind){
	int op;
	while(true){
		cout << "Ingrese el indice del libro que desee eliminar: "<< endl;
		cin >> op;
		if (op > 0 && op < ind){
			arrL[op].setTitulo("");
		}else{
			cout << "No existe ese libro!!!!" << endl;
		}
	}
}

int fillSpace(int ind){
	for(int i=0; i < ind; i++){
		if (arrL[i].getTitulo() == ""){
			return i;
		}
	}
	return ind;
}

void blank(int ind){
	for(int i = 0; i < ind; i++){
		arrL[i].setTitulo("");
	}
}

void selector(){
	bool salida = false, successLog = false;
	int tamLibro = 0;
	int tamUsr = 2, index = tamLibro;
	Usuario actual;
		while(!salida){
			actual = menuLogin(successLog);
		while(successLog){
			if (isAdmin){
				switch(menuAdmin()){
					case 1: 
						cout << "Agregar Libro" << endl;
						if (tamLibro < 10){
							index = fillSpace();
							if(index == tamLibro){
								Agregar(tamLibro);
							}else{
								Agregar(index);
								imprimir(tamLibro);
							}
						}else{
							cout << "Ya no puede crear mas libros" << endl;
						}
						break;
					case 2:
						if (tamLibro == 0){
							cout << "No puede Modificar libros si no hay ninguno!!" << endl;
						}else{
							imprimir(tamLibro);
						}
						break;
					case 3:
						if (tamLibro == 0){
							cout << "No se puede eliminar un elemento si no ha libros para eliminar" << endl;
						}else{
							imprimir(tamLibro);
							Eliminar(tamLibro);
							cout << "Ingrese el archivo que quiera eliminar:" << endl;
							
						}
						break;
					case 4:
						if (tamLibro == 0){
							cout << "El arreglo esta vacio!!!" << endl;
						}else{
							tamLibro = 0;
							blank(tamLibro);
						}
						break;
					default:
							cout << "La opcion de admnistrador es incorrecta!!!" << endl;
				}
			}else{
				switch(menu()){
					default:
						cout << "La opcion es incorrecta" << endl;
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
