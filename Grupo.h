#pragma once
#include "Profesor.h"
#include "Horario.h"
#include "Curso.h"
#include "Estudiante.h"
class Grupo
{
private:
	Curso* curso;
	int IdGrupo;
	const int cupo=30;	
	int cantidadEstudiantes;
	Profesor* profesor;
	Horario *horario;
	Lista<Estudiante>* estudiantes;
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
	bool insertarEstudiante(Estudiante* estudiante);
	bool eliminarEstudiante(Estudiante* estudiante);
	void guardarConEstudiantes(std::ostream& salida) const;
	void leerConEstudiantes(std::istream& entrada);

};

