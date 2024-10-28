#pragma once
#include "Persona.h"
#include "Grupo.h"
#include "Lista.h"
class Estudiante : public Persona
{
private:
	std::string especialidad;
	Lista<Grupo> listaGrupo;
public:
	Estudiante() = default;
	Estudiante(std::string nombre, std::string cedula, std::string telefono, std::string email, std::string especialidad);
	~Estudiante();
	std::string getEspecialidad() const;
	void setEspecialidad(std::string especialidad);
	Lista<Grupo> agregarGrupo();
	std::string toString() const override;
};

