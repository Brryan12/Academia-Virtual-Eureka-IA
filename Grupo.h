#pragma once
#include "Profesor.h"
#include "Horario.h"
#include "Estudiante.h"
#include "Curso.h"
class Grupo
{
private:
	Curso* curso;
	int IdGrupo;
	int cupo;
	int cantidadEstudiantes;
	Profesor* profesor;
	Horario *horario;

	struct Node
	{
		Node* next;
		Estudiante* estudiante;
	};
	Node* primero;
	Node* actual;


public:
	Grupo() = default;
	Grupo(Curso* curso, int IdGrupo, int cupo, int cantidadEstudiantes, Horario* horario);
	virtual ~Grupo();
	int getIdGrupo() const;
	int getCupo() const;
	int getCantidadEstudiantes() const;
	Curso* getCurso() const;
	Horario* getHorario() const;
	Profesor* getProfesor() const;
	void setIdGrupo(int IdGrupo);
	void setCupo(int cupo);
	void setCantidadEstudiantes(int cantidadEstudiantes);
	void setCurso(Curso* curso);
	void setHorario(Horario* horario);
	void setProfesor(Profesor* profesor);
	std::string toString() const;

};

