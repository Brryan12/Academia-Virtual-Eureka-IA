#pragma once
#include "Persona.h"
class Profesor : public Persona
{
private:
	std::string gradoAcademico;
public:
	Profesor();
	Profesor(std::string nombre, std::string cedula, std::string telefono, std::string email, std::string gradoAcademico);
	~Profesor();
	std::string getGradoAcademico() const;
	void setGradoAcademico(std::string gradoAcademico);
	std::string toString() const override;
};

