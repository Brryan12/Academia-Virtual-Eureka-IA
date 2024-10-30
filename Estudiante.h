#pragma once
#include "Persona.h"
#include "ListaGrupos.h"
class ListaGrupos;	
class Estudiante : public Persona
{
private:
	std::string especialidad;
	ListaGrupos listaGrupo;
public:
	Estudiante() = default;
	Estudiante(std::string nombre, std::string cedula, std::string telefono, std::string email, std::string especialidad);
	virtual ~Estudiante();
	std::string getEspecialidad() const;
	void setEspecialidad(std::string especialidad);
	std::string toString() const override;
};

