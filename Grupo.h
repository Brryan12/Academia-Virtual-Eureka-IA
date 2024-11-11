#pragma once
#include "Profesor.h"
#include "Horario.h"
#include "Curso.h"
#include "Lista.h"
#include "Estudiante.h"
#include "Constantes.h"
class Grupo
{
private:
	std::string periodo;
	Curso* curso;
	std::string IdGrupo;
	const int cupo=30;
	int cantidadEstudiantes;
	Horario *horario;
	Profesor* profesor;
	Lista<Estudiante>* estudiantes;
public:
	Grupo();
	Grupo(std::string periodo, Curso* curso, std::string IdGrupo, Horario* horario);
	Grupo(std::string periodo, Curso* curso, std::string IdGrupo, Horario* horario, Profesor* profesor);
	virtual ~Grupo();
	int getCupo() const;
	std::string getPeriodo() const;
	std::string getId() const;
	int getCantidadEstudiantes() const;
	Curso* getCurso() const;
	Horario* getHorario() const;
	Profesor* getProfesor() const;
	void setPeriodo(std::string periodo);
	void setIdGrupo(std::string IdGrupo);
	void setCantidadEstudiantes(int cantidadEstudiantes);
	void setCurso(Curso* curso);
	void setHorario(Horario* horario);
	bool setProfesor(Profesor* profesor);
	std::string toString() const;
	bool insertarEstudiante(Estudiante* estudiante);
	bool eliminarEstudiante(std::string id);
	static std::string toStringPeriodos(Lista<Grupo>* lista);
	static std::string toStringBasico(Lista<Grupo>* lista);
	static std::string GruposSinProfesor(Lista<Grupo>* lista);
	static std::string GruposConProfesor(Lista<Grupo>* lista);

	void guardar(std::ostream& salida) const;
	static Grupo* leer(std::istream& entrada);
};

