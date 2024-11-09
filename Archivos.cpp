#include "Archivos.h"

void Archivos::guardarEstudiantes(Lista<Estudiante>* listaEstudiantes)
{
	salida.open("Estudiantes.txt");
    if (salida.good()) {
		listaEstudiantes->guardarEnArchivo(salida);
    }
	salida.close();
}

void Archivos::guardarProfesores(Lista<Profesor>* listaProfesores)
{
	salida.open("Profesores.txt");
	if (salida.good()) {
		listaProfesores->guardarEnArchivo(salida);
	}
	salida.close();
}

void Archivos::guardarCursos(Lista<Curso>* listaCursos)
{
	salida.open("Cursos.txt");
	if (salida.good()) {
		listaCursos->guardarEnArchivo(salida);
	}
	salida.close();
}

void Archivos::guardarGrupos(Lista<Grupo>* listaGrupo)
{
	salida.open("Grupos.txt");
	if (salida.good()) {
		listaGrupo->guardarEnArchivo(salida);
	}
	salida.close();
}

Lista<Estudiante>* Archivos::cargarEstudiantes()
{
	Lista<Estudiante>* listaEstudiantes = new Lista<Estudiante>();
	Estudiante* estudiante = nullptr;
	entrada.open("Estudiantes.txt");
	if (entrada.good()) {
		while (!entrada.eof()) {
			estudiante = new Estudiante();
			estudiante = estudiante->leer(entrada);
			if (estudiante != nullptr) {
				listaEstudiantes->insertar(estudiante);
			}
		}
	}
	entrada.close();
	return listaEstudiantes;
}

Lista<Profesor>* Archivos::cargarProfesores()
{
	Lista<Profesor>* listaProfesores = new Lista<Profesor>();
	Profesor* profesor = nullptr;
	entrada.open("Profesores.txt");
	if (entrada.good()) {
		while (!entrada.eof()) {
			profesor = new Profesor();
			profesor = profesor->leer(entrada);
			if (profesor != nullptr) {
				listaProfesores->insertar(profesor);
			}
		}
	}
	entrada.close();
	return listaProfesores;
}

Lista<Curso>* Archivos::cargarCursos()
{
	Lista<Curso>* listaCursos = new Lista<Curso>();
	Curso* curso = nullptr;
	entrada.open("Cursos.txt");
	if (entrada.good()) {
		while (!entrada.eof()) {
			curso = new Curso();
			curso = curso->leer(entrada);
			if (curso != nullptr) {
				listaCursos->insertar(curso);
			}
		}
	}
	entrada.close();
	return listaCursos;
}

Lista<Grupo>* Archivos::cargarGrupos()
{
	Lista<Grupo>* listaGrupos = new Lista<Grupo>();
	Grupo* grupo = nullptr;
	entrada.open("Grupos.txt");
	if (entrada.good()) {
		while (!entrada.eof()) {
			grupo = new Grupo();
			grupo = grupo->leer(entrada);
			if (grupo != nullptr) {
				listaGrupos->insertar(grupo);
			}
		}
	}
	entrada.close();
	return listaGrupos;
}
