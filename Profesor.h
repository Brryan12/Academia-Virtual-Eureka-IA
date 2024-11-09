#pragma once
#include "Persona.h"
#include "Lista.h"

class Grupo;
class Profesor : public Persona
{
private:
	std::string gradoAcademico;
	Lista<Grupo>* listaGrupo;
public:
	Profesor();
	Profesor(std::string nombre, std::string cedula, std::string telefono, std::string email, std::string gradoAcademico);
	~Profesor();
	std::string getGradoAcademico() const;
	Lista<Grupo>* getListaGrupo() const;
	void setGradoAcademico(std::string gradoAcademico);
	std::string toString() const override;
	std::string toStringPeriodo() const;
	void guardar(std::ostream& salida) const override;
	static Profesor* leer(std::istream& entrada);
};

