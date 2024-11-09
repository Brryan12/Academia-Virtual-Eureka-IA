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
	Lista<Estudiante>* cargarEstudiantes();
	Lista<Profesor>* cargarProfesores();
	Lista<Curso>* cargarCursos();
	Lista<Grupo>* cargarGrupos();
};

