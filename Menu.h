#pragma once
#include "Grupo.h"
#include "Lista.h"
#include "Factura.h"
#include "Archivos.h"



class Menu {
public:

	/// @brief Retorna la opcion elegida en el menu principal
	/// @return opcion elegida
	static int menuPrincipal();

	/// @brief Retorna la opcion elegida en el submenu de administracion
	/// @return opcion elegida
	static int submenuAdministracion();

	/// @brief Retorna la opcion elegida en el submenu de matricula
	/// @return opcion elegida
	static int submenuMatricula();

	/// @brief Retorna la opcion elegida en el submenu de busquedas e informes
	/// @return opcion elegida
	static int submenuBusquedasEInformes();

	/// @brief Metodo para guardar los datos en archivos
	/// @param listaProfesores Lista de profesores
	/// @param listaEstudiantes Lista de estudiantes
	/// @param listaCursos Lista de cursos
	/// @param listaGrupo Lista de grupos
	static void guardarLosDatosEnArchivos(Lista<Profesor>* listaProfesores, Lista<Estudiante>* listaEstudiantes, Lista<Curso>* listaCursos, Lista<Grupo>* listaGrupo);

	/// @brief Imprime el mensaje de error por defecto
	static void defaultSwitch();

	/// @brief Imprime el mensaje de retorno al menu principal
	static void regresarMenuPrincipal();

	/// @brief Imprime le menu para ingresar un profesor
	/// @param listaProfesores lista de profesores
	static void ingresarProfesor(Lista<Profesor>* listaProfesores);

	/// @brief Imprime el menu para ingresar un estudiante
	/// @param listaEstudiantes lista de estudiantes
	static void ingresarEstudiante(Lista<Estudiante>* listaEstudiantes);

	/// @brief Imprime el menu para ingresar un curso
	/// @param listaCursos lista de cursos
	static void ingresarCurso(Lista<Curso>* listaCursos);

	/// @brief Imprime el menu para ingresar un grupo
	/// @param listaGrupo lista de grupos
	/// @param listaCursos lista de cursos
	static void ingresarGrupo(Lista<Grupo>* listaGrupo, Lista<Curso>* listaCursos);

	/// @brief Imprime el menu para asignar un profesor a un grupo
	/// @param listaGrupo lista de grupos
	/// @param listaProfesores lista de profesores
	static void asignarProfesorAGrupo(Lista<Grupo>* listaGrupo, Lista<Profesor>* listaProfesores);

	/// @brief Imprime el menu para matricular un estudiante
	/// @param listaGrupo lista de grupos
	/// @param listaEstudiantes lista de estudiantes
	static void matricularEstudiante(Lista<Grupo>* listaGrupo, Lista<Estudiante>* listaEstudiantes);

	/// @brief Imprime el menu para desmatricular un estudiante
	/// @param listaGrupo lista de grupos
	/// @param listaEstudiantes lista de estudiantes
	static void desmatricularEstudiante(Lista<Grupo>* listaGrupo, Lista<Estudiante>* listaEstudiantes);

	/// @brief Imprime el menu para generar una factura
	/// @param listaEstudiantes lista de estudiantes
	static void generarFactura(Lista<Estudiante>* listaEstudiantes);

	/// @brief Imprime el informe de todos los profesores en la lista
	/// @param listaProfesores lista de profesores
	static void informeProfesoresRegistrados(Lista<Profesor>* listaProfesores);

	/// @brief Imprime el informe de todos los estudiantes en la lista
	/// @param listaEstudiantes lista de estudiantes
	static void informeEstudiantesRegistrados(Lista<Estudiante>* listaEstudiantes);

	/// @brief Imprime el informe de los grupos matriculados por un estudiante
	/// @param listaGrupo lista de grupos
	/// @param listaEstudiantes lista de estudiantes
	static void informeCursosMatriculadosPorEstudiante(Lista<Grupo>* listaGrupo, Lista<Estudiante>* listaEstudiantes);

	/// @brief Imprime el informe de los grupos asignados a un profesor
	/// @param listaGrupo lista de grupos
	static void informeProfesorEspecifico(Lista<Profesor>* listaProfesores);

	/// @brief Imprime el informe de los grupos por periodo
	/// @param listaGrupo lista de grupos
	/// @param listaCursos lista de cursos
	static void informePeriodosHabilitadosParaElAno(Lista<Grupo>* listaGrupo, Lista<Curso>* listaCursos);

	/// @brief Imprime el informe de un grupo en espeficico
	/// @param listaGrupo lista de grupos
	static void informeGrupoEspecifico(Lista<Grupo>* listaGrupo, Lista<Curso>* listaCursos);
};