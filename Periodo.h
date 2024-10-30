#pragma once
#include "Lista.h"
#include "Curso.h"
class Periodo
{
private:
	Periodo* vec[4];
	Lista<Curso>* cursos;
public:
	Periodo();
	Periodo(Lista<Curso>* cursos);
	virtual ~Periodo();
	Lista<Curso>* getCursos() const;
	void setCursos(Lista<Curso>* cursos);
	std::string toString() const;
	void guardar(std::ostream& salida) const;
	static Periodo* leer(std::istream& entrada);
};

