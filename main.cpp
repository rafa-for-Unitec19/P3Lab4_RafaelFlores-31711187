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
		if (arrL[i].getTitulo() != "" && arrL[i].getEstado()){
			cout << (i+1) << " -> " << arrL[i].getTitulo() << " | Precio -> " << arrL[i].getPrecio() << endl;
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
		<< "\n\t6. Borrar Cuenta"
		<< "\n\t7. Salir"<< endl;
	cin >> op;
	return op;
}

int menuAdmin(){
	int op;
	cout << "\nIngrese la opcion administrador que desee:"
		<< "\n\t1. Agregar Libro"
		<< "\n\t2. Modificar Libro"
		<< "\n\t3. Eliminar Libro"
		<< "\n\t4. Borrar registro de libros"
	        << "\n\t5. Salir"<< endl;
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
	bool salida = true;
	while(salida){
		int op;
		cout << "\nSeleccione la opcion que desea:"
			<< "\n\t1. Ingresar"
			<< "\n\t2. Registrarse" 
			<< "\n\t3. Salir"<< endl;
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
			case 3:
				salida = false;
				break;
			default:
				cout << "La opcion es incorrecta" << endl;
		}
	}
	return act;
}

void Agregar(int &ind){
	cin.ignore();
	Libro l;
	cout << "Ingrese el titulo del libro: " << endl;
	string t; getline(cin, t);
	l.setTitulo(t);
	cout << "Ingrese el nombre del autor" << endl;
	string a; cin >> a;
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
			break;
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
			if (actual.getNombre() == ""){
				salida = true;
			}
		while(successLog){
			if (isAdmin){
				switch(menuAdmin()){
					case 1: 
						cout << "Agregar Libro" << endl;
						if (tamLibro < 10){
							index = fillSpace(tamLibro);
							cout << "El Valor de Index es: "<< index << endl;
							if(index == tamLibro){
								Agregar(tamLibro);
							}else{
								Agregar(index);
							}
							imprimir(tamLibro);
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
							blank(tamLibro);
							tamLibro = 0;
						}
						break;
					case 5: 
						cout << "Saliendo de la cuenta" << endl;
						successLog = false;
						break;
					default:
							cout << "La opcion de admnistrador es incorrecta!!!" << endl;
				}
			}else{
				switch(menu()){
					case 1:{
							cout << "Compra un libro: " << endl;
							if (tamLibro != 0){
								imprimir(tamLibro);
								cout << "Que libro quiere comprar?" << endl;
								int comp; cin >> comp;
								if (comp > 0 && comp < tamLibro){
									if (actual.getDinero() < arrL[comp].getPrecio()){
										actual.setDinero(actual.getDinero() - arrL[comp].getPrecio());
										arrL[comp].setEstado(false);
										cout << "Ha comprado este libro!!!" << endl; 
										cout << "El saldo para " << actual.getNombre() << " es: " << actual.getDinero() << endl;
									}
								}
							}else{
								cout << "No hay libros para vender" << endl;
							}
						break;
					       }
					case 2:
					       cout << "Buscar por Titulo, Proximo Release" << endl;
					       break;
					case 3:
					       cout << "Buscar por Autor, Proximo Release" << endl;
					       break;
					case 4:{
							cout << "Agregar mas dinero a la cuenta" << endl;
							cout << "Ingrese cuanto desee añadir a su cuenta" << endl;
							int cant; cin >> cant;
							if(cant < 1){
								cout << "Tiene que agregar una cantidad positiva a la cuenta" << endl;
							}else{
								cout << "Actualmente tenia: " << actual.getDinero() << " dolares en su cuenta" << endl;
								actual.setDinero(cant + actual.getDinero());
							}	cout << "Ahora su cuenta tiene" << actual.getDinero() << "dolares en su cuenta" << endl;
						break;
					       }
					case 5:{
					       		cout << "Cambiar contraseña"
								<< "Ingrese su vieja contraseña: " << endl;
							string pss; cin >> pss;
							if (pss == actual.getPass()){
								cout << "Ingrese su nueva contraseña" << endl;
								cin >> pss;
								actual.setPass(pss);
								cout << "Se ha actualizado la contraseña" << endl;
							}
							break;
						}
					case 6:
						cout << "Borrando su cuenta..." << endl;
						actual.setUsr("");
						cout << "Volviendo al Login" << endl;
						successLog = false;
						break;
					case 7: 
						cout << "Saliendo de la cuenta..." << endl;
						successLog = false;
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
