#include "Archivos.h"

void Archivos::guardarEstudiantes(Lista<Estudiante>* listaEstudiantes)
{
	salida.open("Estudiantes.txt");
    if (salida.good()) {
		listaEstudiantes->guardarEnArchivo(salida);
	}
	else {
		std::cerr << "Error al abrir el archivo" << endl;
		system(pause);
		return;
	}
	salida.close();
}

void Archivos::guardarProfesores(Lista<Profesor>* listaProfesores)
{
	salida.open("Profesores.txt");
	if (salida.good()) {
		listaProfesores->guardarEnArchivo(salida);
	}
	else {
		std::cerr << "Error al abrir el archivo" << endl;
		system(pause);
		return;
	}

	salida.close();
}

void Archivos::guardarCursos(Lista<Curso>* listaCursos)
{
	salida.open("Cursos.txt");
	if (salida.good()) {
		listaCursos->guardarEnArchivo(salida);
	}
	else {
		std::cerr << "Error al abrir el archivo" << endl;
		system(pause);
		return;
	}
	salida.close();
}

void Archivos::guardarGrupos(Lista<Grupo>* listaGrupo)
{
	salida.open("Grupos.txt");
	if (salida.good()) {
		listaGrupo->guardarEnArchivo(salida);
	}
	else {
		std::cerr << "Error al abrir el archivo" << endl;
		system(pause);
		return;
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
			estudiante=Estudiante::leer(entrada);
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
			profesor = Profesor::leer(entrada);
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
			curso = Curso::leer(entrada);
			if (curso != nullptr) {
				listaCursos->insertar(curso);
				curso = nullptr;
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
			grupo = Grupo::leer(entrada);
			if (grupo != nullptr) {
				listaGrupos->insertar(grupo);
				grupo = nullptr;
			}
		}
	}
	entrada.close();
	return listaGrupos;
}
