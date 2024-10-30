#include "Estudiante.h"

Estudiante::Estudiante(std::string nombre, std::string cedula, std::string telefono, std::string email, std::string especialidad) : Persona(nombre, cedula, telefono, email), especialidad(especialidad) {}

Estudiante::~Estudiante()
{
}

std::string Estudiante::getEspecialidad() const
{
	return especialidad;
}

void Estudiante::setEspecialidad(std::string especialidad)
{
	this->especialidad = especialidad;
}

std::string Estudiante::toString() const
{
	std::stringstream s;
	s << Persona::toString()
		<< "Especialidad: " << especialidad << std::endl;
	return s.str();
}

void Estudiante::guardar(std::ostream& salida) const 
{

}

Estudiante* Estudiante::leer(std::istream& entrada)
{
	std::string nombre, cedula, telefono, email, especialidad;
	getline(entrada, nombre, '\t');
	getline(entrada, cedula, '\t');
	getline(entrada, telefono, '\t');
	getline(entrada, email, '\t');
	getline(entrada, especialidad, '\n');
	if (nombre.empty() || cedula.empty() || telefono.empty() || email.empty() || especialidad.empty())
	{
		return nullptr;
	}
	return new Estudiante(nombre, cedula, telefono, email, especialidad);
}
