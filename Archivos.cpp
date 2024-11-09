#include "Archivos.h"

void Archivos::guardarEstudiantes(std::string nombreArchivo, Lista<Estudiante>* listaEstudiantes)
{
	salida.open("Estudiantes.txt");
    if (salida.good()) {

    }
}

void Archivos::guardarProfesores(Lista<Profesor>* listaProfesores)
{
}

void Archivos::guardarCursos(Lista<Curso>* listaCursos)
{
}

void Archivos::guardarGrupos(Lista<Grupo>* listaGrupo)
{
}

Lista<Estudiante>* Archivos::cargarEstudiantes(Lista<Estudiante>* listaEstudiantes)
{
    return nullptr;
}

Lista<Profesor>* Archivos::cargarProfesores(Lista<Profesor>* listaProfesores)
{
    return nullptr;
}

Lista<Curso>* Archivos::cargarCursos(Lista<Curso>* listaCursos)
{
    return nullptr;
}

Lista<Grupo>* Archivos::cargarGrupos(Lista<Grupo>* listaGrupo)
{
    return nullptr;
}
