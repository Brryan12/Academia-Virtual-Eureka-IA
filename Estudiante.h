#pragma once
#include "Constantes.h"
#include "Persona.h"
#include "Lista.h"

class Grupo;
class Estudiante : public Persona
{
private:
	std::string especialidad;
	Lista<Grupo>* listaGrupo;
public:
	Estudiante();
	Estudiante(std::string nombre, std::string cedula, std::string telefono, std::string email, std::string especialidad);
	virtual ~Estudiante();
	std::string getEspecialidad() const;
	Lista<Grupo>* getListaGrupo() const;
	void setEspecialidad(std::string especialidad);
	void setListaGrupo(Lista<Grupo>* listaGrupo);
	std::string toString() const override;
	bool insertarGrupo(Grupo* grupoAux);
	bool minimoDosGrupoPorPeriodo() const;
	double montoPagar() const;
	std::string infoCursos() const;
	bool eliminarGrupo(std::string id);
	void guardar(std::ostream& salida) const;
	static Estudiante* leer(std::istream& entrada);
};

