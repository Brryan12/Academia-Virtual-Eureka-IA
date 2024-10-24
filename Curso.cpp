#include "Curso.h"
#include <iostream>
#include <sstream>
using namespace std;

Curso::Curso() {}

Curso::Curso(string n, string id2, string h, double p, bool e): nombre(n), id(id2), horas(h), precio(p), estado(e){}
Curso::~Curso(){}
string Curso::getNombre() { return nombre; }
string Curso::gethora() { return horas; }
string Curso::getid() { return id; }
double Curso::getprecio() { return precio; }
bool Curso::getestado() { return estado; }
void Curso::setNombre(string n) { nombre = n; }
void Curso::sethora(string h) { horas = h; }
void Curso::setid(string id2) { id = id2; }
void Curso::setprecio(double p) { precio = p; }
void Curso::setestado(bool e) { estado = e; }
string Curso::toString() const{
	stringstream s;

	s << "Nombre del curso: " << nombre<<endl;
	s << "Hora del curso: " << horas << endl;
	s << "ID del Curso: " << id << endl;
	s << " Precio del curso: " << precio<< endl;
	s << "Estado del curso: " << estado << endl;

	return s.str();



}