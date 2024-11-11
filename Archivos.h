#pragma once
#include "Lista.h"
#include "Grupo.h"	
#include "Estudiante.h"
class Archivos
{
private:
	/// @brief Archivo de entrada
	ifstream entrada;

	/// @brief Archivo de salida
	ofstream salida;
public:
	/// @brief Guardar los estudiantes en su respectivo documento
	/// @param listaEstudiantes Una lista de estudiantes
	void guardarEstudiantes(Lista<Estudiante>* listaEstudiantes);

	/// @brief Guardar los profesores en su respectivo documento
	/// @param listaProfesores Una lista de profesores
	void guardarProfesores(Lista<Profesor>* listaProfesores);

	/// @brief Guardar los cursos en su respectivo documento
	/// @param listaCursos Una lista de cursos
	void guardarCursos(Lista<Curso>* listaCursos);

	/// @brief Guardar los grupos en su respectivo documento
	/// @param listaGrupo Una lista de grupos
	void guardarGrupos(Lista<Grupo>* listaGrupo);

	/// @brief Cargar los estudiantes de su respectivo documento
	/// @return Una lista de estudiantes
	Lista<Estudiante>* cargarEstudiantes();

	/// @brief Cargar los profesores de su respectivo documento
	/// @return Una lista de profesores
	Lista<Profesor>* cargarProfesores();

	/// @brief Cargar los cursos de su respectivo documento
	/// @return Una lista de cursos
	Lista<Curso>* cargarCursos();

	/// @brief Cargar los grupos de su respectivo documento
	/// @return Una lista de grupos
	Lista<Grupo>* cargarGrupos();
};

