#pragma once
#include "Grupo.h"
#include "Factura.h"

#if defined(_WIN64) || defined(_WIN32)
#define cls "cls"
#define pause "pause"

#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#define cls "clear"
#define pause "read -n1 -r -p \"Press any key to continue...\""
#endif

class Menu {
public:
	static int menuPrincipal();
	static int submenuAdministracion();
	static int submenuMatricula();
	static int submenuBusquedasEInformes();
	static void  guardarLosDatosEnArchivos();
	static void defaultSwitch();
	static void regresarMenuPrincipal();
	static void ingresarProfesor(Lista<Profesor>* listaProfesores);
	static void ingresarEstudiante(Lista<Estudiante>* listaEstudiantes);
	static void ingresarCurso(Lista<Curso>* listaCursos);
	static void ingresarGrupo(Lista<Grupo>* listaGrupo, Lista<Curso>* listaCursos);
	static void asignarProfesorAGrupo(Lista<Grupo>* listaGrupo, Lista<Profesor>* listaProfesores);
	static void matricularEstudiante(Lista<Grupo>* listaGrupo, Lista<Estudiante>* listaEstudiantes);
	static void desmatricularEstudiante(Lista<Grupo>* listaGrupo, Lista<Estudiante>* listaEstudiantes);
	static void generarFactura(Lista<Estudiante>* listaEstudiantes);
	static void informeProfesoresRegistrados(Lista<Profesor>* listaProfesores);
	static void informeEstudiantesRegistrados(Lista<Estudiante>* listaEstudiantes);
	static void informeCursosMatriculadosPorEstudiante(Lista<Grupo>* listaGrupo, Lista<Estudiante>* listaEstudiantes);
	static void informeProfesorEspecifico(Lista<Profesor>* listaProfesores);
	static void informePeriodosHabilitadosParaElAno(Lista<Grupo>* listaGrupo, Lista<Curso>* listaCursos);
	static void informeGrupoEspecifico(Lista<Grupo>* listaGrupo, Lista<Curso>* listaCursos);
};