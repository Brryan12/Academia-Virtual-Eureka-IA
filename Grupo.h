#pragma once
#include "Profesor.h"
#include "Horario.h"
class Grupo
{
private:
	int IdGrupo;
	int cupo;
	int cantidadEstudiantes;
	Profesor* profesor;
	Horario *horario;

public:
	Grupo() = default;
	Grupo(int IdGrupo, int cupo, int cantidadEstudiantes, Horario* horario);
	virtual ~Grupo();
	int getIdGrupo() const;
	int getCupo() const;
	int getCantidadEstudiantes() const;
	Horario* getHorario() const;
	Profesor* getProfesor() const;
	void setIdGrupo(int IdGrupo);
	void setCupo(int cupo);
	void setCantidadEstudiantes(int cantidadEstudiantes);
	void setHorario(Horario* horario);
	void setProfesor(Profesor* profesor);
	std::string toString() const;

};

