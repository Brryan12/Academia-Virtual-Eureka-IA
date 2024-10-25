#include "Profesor.h"

Profesor::Profesor(std::string nombre, std::string cedula, std::string telefono, std::string email, std::string gradoAcademico) : Persona(nombre, cedula, telefono, email), gradoAcademico(gradoAcademico) {}

Profesor::~Profesor()
{
}

std::string Profesor::getGradoAcademico() const
{
	return gradoAcademico;
}

void Profesor::setGradoAcademico(std::string gradoAcademico)
{
	this->gradoAcademico = gradoAcademico;
}

std::string Profesor::toString() const
{
	std::stringstream s;
	s << Persona::toString()
		<< "Grado Academico: " << gradoAcademico << std::endl;
	return s.str();
}