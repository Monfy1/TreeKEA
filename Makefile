OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#
# si se compila desde el linux de la FIB conviene usar g++-5 en lugar de g++
#
program.exe: program.o Almacen.o Sala.o Inventario.o
	g++ -o program.exe program.o Almacen.o Sala.o Inventario.o
#
program.o: program.cc Almacen.hh Inventario.hh
	g++ -c program.cc $(OPCIONS)
#
Almacen.o: Almacen.cc Almacen.hh Sala.hh
	g++ -c Almacen.cc $(OPCIONS)
#
Sala.o: Sala.cc Sala.hh
	g++ -c Sala.cc $(OPCIONS)
#
Inventario.o: Inventario.cc Inventario.hh
	g++ -c Inventario.cc $(OPCIONS)
#
tar: program.cc Almacen.cc Almacen.hh Sala.cc Sala.hh Inventario.cc Inventario.hh
	tar -cvf practica.tar program.cc Almacen.cc Almacen.hh Sala.cc Sala.hh Inventario.cc Inventario.hh Makefile
#
clean:
	rm *.o
	rm *.exe
