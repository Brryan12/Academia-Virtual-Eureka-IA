#pragma once
#include "Profesor.h"
#include "Horario.h"
#include "Curso.h"
#include "Lista.h"
#include "Periodo.h"
#include "Estudiante.h"
class Grupo
{
private:
	Periodo* periodo;
	Curso* curso;
	std::string IdGrupo;
	const int cupo=30;	
	int cantidadEstudiantes;
	Profesor* profesor;
	Horario *horario;
	Lista<Estudiante>* estudiantes;
public:
	Grupo();
	Grupo(Periodo* periodo, Curso* curso, std::string IdGrupo, int cantidadEstudiantes, Horario* horario);
	virtual ~Grupo();
	std::string getId() const;
	int getCantidadEstudiantes() const;
	Curso* getCurso() const;
	Horario* getHorario() const;
	Profesor* getProfesor() const;
	void setIdGrupo(std::string IdGrupo);
	void setCantidadEstudiantes(int cantidadEstudiantes);
	void setCurso(Curso* curso);
	void setHorario(Horario* horario);
	void setProfesor(Profesor* profesor);
	std::string toString() const;
	bool insertarEstudiante(Estudiante* estudiante);
	bool eliminarEstudiante(Estudiante* estudiante);
	void guardarConEstudiantes(std::ostream& salida) const;
	void leerConEstudiantes(std::istream& entrada);

};

