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

Lista<Grupo> Estudiante::agregarGrupo()
{
	return Lista<Grupo>();
}

std::string Estudiante::toString() const
{
	std::stringstream s;
	s << Persona::toString()
		<< "Especialidad: " << especialidad << std::endl;
	return s.str();
}