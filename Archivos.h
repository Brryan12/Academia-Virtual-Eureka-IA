#pragma once
#include "Lista.h"
#include "Grupo.h"	
#include "Estudiante.h"
class Archivos
{
private:
	ifstream entrada;
	ifstream entradaAux;
	ofstream salida;
	ofstream salidaAux;
public:
	void guardarEstudiantes(Lista<Estudiante>* listaEstudiantes);
	void guardarProfesores(Lista<Profesor>* listaProfesores);
	void guardarCursos(Lista<Curso>* listaCursos);
	void guardarGrupos(Lista<Grupo>* listaGrupo);
	Lista<Estudiante>* cargarEstudiantes(Lista<Estudiante>* listaEstudiantes);
	Lista<Profesor>* cargarProfesores(Lista<Profesor>* listaProfesores);
	Lista<Curso>* cargarCursos(Lista<Curso>* listaCursos);
	Lista<Grupo>* cargarGrupos(Lista<Grupo>* listaGrupo);
};

