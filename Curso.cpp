#include "Curso.h"

Curso::Curso() : nombre(""), id(""), horas(0), precio(0), estado(false){}

Curso::Curso(string nombre, string id, int horas, double precio, bool estado): nombre(nombre), id(id), horas(horas), precio(precio), estado(estado){}
Curso::~Curso(){}
string Curso::getNombre() const  { return this->nombre; }
int Curso::getHoras() const { return this->horas; }
string Curso::getId() const { return this->id; }
double Curso::getPrecio() const { return this->precio; }
bool Curso::getEstado() const { return this->estado; }
void Curso::setNombre(string nombre) { this->nombre = nombre; }
void Curso::setHoras(int horas) { this->horas = horas; }
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
	string nombre, id,horas;
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
	return new Curso(nombre, id, stoi(horas), stod(precio), estado);
}
string Curso::toString() const{
	stringstream s;

	s << "Nombre del curso: " << this->nombre << endl
		<< "ID del Curso: " << this->id << endl
		<< "Horas del curso: " << this->horas << endl
		<< "Precio del curso: " << this->precio << endl
		<< "Estado del curso: " << this->estado << endl;

	return s.str();

}