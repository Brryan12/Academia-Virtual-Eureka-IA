#pragma once
#include "Persona.h"
class Estudiante : public Persona
{
private:
	std::string especialidad;
public:
	Estudiante() = default;
	Estudiante(std::string nombre, std::string cedula, std::string telefono, std::string email, std::string especialidad);
	~Estudiante();
	std::string getEspecialidad() const;
	void setEspecialidad(std::string especialidad);
	std::string toString() const override;
};

