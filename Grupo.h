#pragma once
#include "Profesor.h"
#include "Horario.h"
#include "Curso.h"
#include "ListaEst.h"
class ListaEst;
class Grupo
{
private:
	Curso* curso;
	int IdGrupo;
	const int cupo=30;	
	int cantidadEstudiantes;
	Profesor* profesor;
	Horario *horario;
	ListaEst estudiantes;
public:
	Grupo() = default;
	Grupo(Curso* curso, int IdGrupo, int cantidadEstudiantes, Horario* horario);
	virtual ~Grupo();
	int getIdGrupo() const;
	int getCantidadEstudiantes() const;
	Curso* getCurso() const;
	Horario* getHorario() const;
	Profesor* getProfesor() const;
	void setIdGrupo(int IdGrupo);
	void setCantidadEstudiantes(int cantidadEstudiantes);
	void setCurso(Curso* curso);
	void setHorario(Horario* horario);
	void setProfesor(Profesor* profesor);
	std::string toString() const;

};

