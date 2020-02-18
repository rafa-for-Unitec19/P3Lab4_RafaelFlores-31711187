salida: main.o Libro.o Usuario.o
	g++ -o salida main.o Libro.o Usuario.o
	@./salida.out

main.o: main.cpp Libro.hpp Usuario.hpp
	g++ -c main.cpp

Libro.o: Libro.cpp Libro.hpp
	g++ -c Libro.cpp

Usuario.o: Usuario.cpp Usuario.hpp
	g++ -c Usuario.cpp

clean: 
	rm -f *.o salida core
