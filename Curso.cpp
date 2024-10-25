#include "Curso.h"

Curso::Curso(string nombre, string id, string horas, double precio, bool estado): nombre(nombre), id(id), horas(horas), precio(precio), estado(estado){}
Curso::~Curso(){}
string Curso::getNombre() const  { return nombre; }
string Curso::getHoras() const { return horas; }
string Curso::getId() const { return id; }
double Curso::getPrecio() const { return precio; }
bool Curso::getEstado() const { return estado; }
void Curso::setNombre(string nombre) { nombre = nombre; }
void Curso::setHoras(string horas) { horas = horas; }
void Curso::setId(string id) { id = id; }
void Curso::setPrecio(double precio) { precio = precio; }
void Curso::setEstado(bool estado) { estado = estado; }
string Curso::toString() const{
	stringstream s;

	s << "Nombre del curso: " << nombre << endl
		<< "Hora del curso: " << horas << endl
		<< "ID del Curso: " << id << endl
		<< " Precio del curso: " << precio << endl
		<< "Estado del curso: " << estado << endl;

	return s.str();

}