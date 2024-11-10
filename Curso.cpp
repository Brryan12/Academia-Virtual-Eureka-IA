#include "Curso.h"

Curso::Curso() : nombre(""), id(""), horas(""), precio(0), estado(false){}

Curso::Curso(string nombre, string id, string horas, double precio, bool estado): nombre(nombre), id(id), horas(horas), precio(precio), estado(estado){}
Curso::~Curso(){}
string Curso::getNombre() const  { return this->nombre; }
string Curso::getHoras() const { return this->horas; }
string Curso::getId() const { return this->id; }
double Curso::getPrecio() const { return this->precio; }
bool Curso::getEstado() const { return this->estado; }
void Curso::setNombre(string nombre) { this->nombre = nombre; }
void Curso::setHoras(string horas) { this->horas = horas; }
void Curso::setId(string id) { this->id = id; }
void Curso::setPrecio(double precio) { this->precio = precio; }
void Curso::setEstado(bool estado) { this->estado = estado; }
void Curso::guardar(std::ostream& salida) const
{
	salida << nombre << "\t"
		<< id << "\t"
		<< horas << "\t"
		<< precio << "\t"
		<< estado << "\n";
}
Curso* Curso::leer(std::istream& entrada)
{
	string nombre, id, horas;
	string precio;
	bool estado;
	getline(entrada, nombre, '\t');
	getline(entrada, id, '\t');
	getline(entrada, horas, '\t');
	getline(entrada, precio, '\t');
	entrada >> estado;
	entrada.ignore();
	if (nombre.empty() || id.empty() || horas.empty() || precio.empty())
	{
		return nullptr;
	}
	return new Curso(nombre, id, horas, stod(precio), estado);
}
string Curso::toString() const{
	stringstream s;

	s << "Nombre del curso: " << nombre << endl
		<< "Horas del curso: " << horas << endl
		<< "ID del Curso: " << id << endl
		<< "Precio del curso: " << precio << endl
		<< "Estado del curso: " << estado << endl;

	return s.str();

}