#include <iostream>
#include <string>
#include "Profesor.h"
#include "Lista.h"
#if defined(_WIN64) || defined(_WIN32)
#define cls "cls"
#define pause "pause"
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#define cls "clear"
#define pause "read -n1 -r -p \"Press any key to continue...\""
#endif

int main()
{
    int op,op1,op2,op3;
	std::string nombre;
	std::string cedula;
	std::string telefono;
	std::string email; 
	std::string gradoAcademico;
	std::string especialidad;
	Profesor* profAux;
	Lista<Profesor> listaProfesores;

    do{
		system(cls);
		std::endl(std::cout);
		std::cout << "----Menu Principal----" << std::endl;
		std::cout << "1- Submenú Administración" << std::endl;
		std::cout << "2- Submenú Matrícula " << std::endl;
		std::cout << "3- Submenú Búsquedas e Informes" << std::endl;
		std::cout << "4- - Guardar los Datos en Archivos " << std::endl;
		std::cout << "5- Salir" << std::endl;
		std::cout << "Seleccione una opción: "; std::cin >> op;
		switch (op)
		{
		case 1:
			// Llamar a la función del submenú de administración
			do {
				system(cls);
				std::endl(std::cout);
				std::cout << "(1) Ingresar Profesor" << std::endl;
				std::cout << "(2) Ingresar Estudiante" << std::endl;
				std::cout << "(3) Ingresar Bloque o Periodo" << std::endl;
				std::cout << "(4) Ingresar Curso" << std::endl;
				std::cout << "(5) Ingresar Grupo" << std::endl;
				std::cout << "(6) Asignar Profesor a Grupo" << std::endl;
				std::cout << "(0) Regresar al Menú Principal" << std::endl;
				std::cout << "Seleccione una opción: "; std::cin >> op1;

				switch (op1)
				{
				case 1:
					std::cout << "Ingrese los datos del profesor" << std::endl;
					std::cout << "Ingrese el nombre del profesor: "; getline(std::cin, nombre);
					std::cout << "Nombre: " << nombre << std::endl;
					std::cout << "Ingrese la cédula del profesor: "; std::cin >> cedula;
					std::cout << "Cédula: " << cedula << std::endl;
					std::cout << "Ingrese el teléfono del profesor: "; getline(std::cin, telefono);
					std::cout << "Teléfono: " << telefono << std::endl;
					std::cout << "Ingrese el email del profesor: "; getline(std::cin,email);
					std::cout << "Email: " << email << std::endl;
					std::cout << "Ingrese el grado académico del profesor: "; getline(std::cin, gradoAcademico);
					std::cout << "Grado Académico: " << gradoAcademico << std::endl;
					profAux = new Profesor(nombre, cedula, telefono, email, gradoAcademico);
					if (listaProfesores.insertar(profAux)){
						std::cout << "Profesor ingresado correctamente." << std::endl;
					}else{
						std::cout << "Error al ingresar el profesor." << std::endl;
						break;
					}
					system(pause);
					break;

				case 2:
					// Llamar a la función de ingresar estudiante
					break;

				case 3:
					// Llamar a la función de ingresar bloque o periodo
					break;

				case 4:
					// Llamar a la función de ingresar curso
					break;

				case 5:
					// Llamar a la función de ingresar grupo
					break;

				case 6:
					// Llamar a la función de asignar profesor a grupo
					break;

				case 0:
					system(cls);
					std::cout << "Regresando al Menú Principal..." << std::endl;
					system(pause);
					break;

				default:
					system(cls);
					std::cout << "Opción no válida. Intente de nuevo." << std::endl;
					system(pause);
					break;
				}
			}while(op1!=0);
			break;

		case 2:
			do {
				system(cls);
				std::endl(std::cout);
				std::cout << "(1) Matricular Estudiante" << std::endl;
				std::cout << "(2) Desmatricular Estudiante" << std::endl;
				std::cout << "(0) Regresar al menú Principal" << std::endl;
				std::cout << "Seleccione una opción: "; std::cin >> op2;
				switch (op2)
				{
				case 1:
					// Llamar a la función de matricular estudiante
					break;

				case 2:
					// Llamar a la función de desmatricular estudiante
					break;

				case 0:
					system(cls);
					std::cout << "Regresando al Menú Principal..." << std::endl;
					system(pause);
					break;

				default:
					system(cls);
					std::cout << "Opción no válida. Intente de nuevo." << std::endl;
					system(pause);
					break;
				}
			} while (op2 != 0);
			break;

		case 3:
			do {				std::cout << "(1) Informe Profesores Registrados" << std::endl;
				std::cout << "(2) Informe Estudiantes Registrados" << std::endl;
				std::cout << "(3) Informe Cursos Matriculados por un Estudiante" << std::endl;
				std::cout << "(4) Informe Profesor Especifico" << std::endl;
				std::cout << "(5) Informe Periodos Habilitados para el Año" << std::endl;
				std::cout << "(6) Informe Grupo Especifico" << std::endl;
				std::cout << "(0) Regresar al Menú Principal" << std::endl;				std::cout << "Seleccione una opción: "; std::cin >> op3;				switch (op3)				{				case 1:					// Llamar a la función de informe de profesores registrados					break;				case 2:					// Llamar a la función de informe de estudiantes registrados					break;				case 3:					// Llamar a la función de informe de cursos matriculados por un estudiante					break;				case 4:					// Llamar a la función de informe de profesor específico					break;				case 5:					// Llamar a la función de informe de periodos habilitados para el año					break;				case 6:					// Llamar a la función de informe de grupo específico					break;				case 0:					system(cls);					std::cout << "Regresando al Menú Principal..." << std::endl;					system(pause);					break;				default:					system(cls);					std::cout << "Opción no válida. Intente de nuevo." << std::endl;					system(pause);					break;				}			} while (op3 != 0);
		case 4:
			// Llamar a la función de guardar los datos en archivos
			break;

		case 5:
			std::cout << "Saliendo del programa..." << std::endl;
			break;

		default:
			system(cls);
			std::cout << "Opción no válida. Intente de nuevo." << std::endl;
			system(pause);
			break;
		}
	} while (op != 5);
}