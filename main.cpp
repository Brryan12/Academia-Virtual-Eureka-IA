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
		std::cout << "1- Submen� Administraci�n" << std::endl;
		std::cout << "2- Submen� Matr�cula " << std::endl;
		std::cout << "3- Submen� B�squedas e Informes" << std::endl;
		std::cout << "4- - Guardar los Datos en Archivos " << std::endl;
		std::cout << "5- Salir" << std::endl;
		std::cout << "Seleccione una opci�n: "; std::cin >> op;
		switch (op)
		{
		case 1:
			// Llamar a la funci�n del submen� de administraci�n
			do {
				system(cls);
				std::endl(std::cout);
				std::cout << "(1) Ingresar Profesor" << std::endl;
				std::cout << "(2) Ingresar Estudiante" << std::endl;
				std::cout << "(3) Ingresar Bloque o Periodo" << std::endl;
				std::cout << "(4) Ingresar Curso" << std::endl;
				std::cout << "(5) Ingresar Grupo" << std::endl;
				std::cout << "(6) Asignar Profesor a Grupo" << std::endl;
				std::cout << "(0) Regresar al Men� Principal" << std::endl;
				std::cout << "Seleccione una opci�n: "; std::cin >> op1;

				switch (op1)
				{
				case 1:
					std::cout << "Ingrese los datos del profesor" << std::endl;
					std::cout << "Ingrese el nombre del profesor: "; getline(std::cin, nombre);
					std::cout << "Nombre: " << nombre << std::endl;
					std::cout << "Ingrese la c�dula del profesor: "; std::cin >> cedula;
					std::cout << "C�dula: " << cedula << std::endl;
					std::cout << "Ingrese el tel�fono del profesor: "; getline(std::cin, telefono);
					std::cout << "Tel�fono: " << telefono << std::endl;
					std::cout << "Ingrese el email del profesor: "; getline(std::cin,email);
					std::cout << "Email: " << email << std::endl;
					std::cout << "Ingrese el grado acad�mico del profesor: "; getline(std::cin, gradoAcademico);
					std::cout << "Grado Acad�mico: " << gradoAcademico << std::endl;
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
					// Llamar a la funci�n de ingresar estudiante
					break;

				case 3:
					// Llamar a la funci�n de ingresar bloque o periodo
					break;

				case 4:
					// Llamar a la funci�n de ingresar curso
					break;

				case 5:
					// Llamar a la funci�n de ingresar grupo
					break;

				case 6:
					// Llamar a la funci�n de asignar profesor a grupo
					break;

				case 0:
					system(cls);
					std::cout << "Regresando al Men� Principal..." << std::endl;
					system(pause);
					break;

				default:
					system(cls);
					std::cout << "Opci�n no v�lida. Intente de nuevo." << std::endl;
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
				std::cout << "(0) Regresar al men� Principal" << std::endl;
				std::cout << "Seleccione una opci�n: "; std::cin >> op2;
				switch (op2)
				{
				case 1:
					// Llamar a la funci�n de matricular estudiante
					break;

				case 2:
					// Llamar a la funci�n de desmatricular estudiante
					break;

				case 0:
					system(cls);
					std::cout << "Regresando al Men� Principal..." << std::endl;
					system(pause);
					break;

				default:
					system(cls);
					std::cout << "Opci�n no v�lida. Intente de nuevo." << std::endl;
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
				std::cout << "(5) Informe Periodos Habilitados para el A�o" << std::endl;
				std::cout << "(6) Informe Grupo Especifico" << std::endl;
				std::cout << "(0) Regresar al Men� Principal" << std::endl;				std::cout << "Seleccione una opci�n: "; std::cin >> op3;				switch (op3)				{				case 1:					// Llamar a la funci�n de informe de profesores registrados					break;				case 2:					// Llamar a la funci�n de informe de estudiantes registrados					break;				case 3:					// Llamar a la funci�n de informe de cursos matriculados por un estudiante					break;				case 4:					// Llamar a la funci�n de informe de profesor espec�fico					break;				case 5:					// Llamar a la funci�n de informe de periodos habilitados para el a�o					break;				case 6:					// Llamar a la funci�n de informe de grupo espec�fico					break;				case 0:					system(cls);					std::cout << "Regresando al Men� Principal..." << std::endl;					system(pause);					break;				default:					system(cls);					std::cout << "Opci�n no v�lida. Intente de nuevo." << std::endl;					system(pause);					break;				}			} while (op3 != 0);
		case 4:
			// Llamar a la funci�n de guardar los datos en archivos
			break;

		case 5:
			std::cout << "Saliendo del programa..." << std::endl;
			break;

		default:
			system(cls);
			std::cout << "Opci�n no v�lida. Intente de nuevo." << std::endl;
			system(pause);
			break;
		}
	} while (op != 5);
}