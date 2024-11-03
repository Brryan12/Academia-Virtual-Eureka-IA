#include "Include.h"

int main()
{
    int op, op1, op2, op3;
    std::string nombre;
    std::string id;
    std::string telefono;
    std::string email;
    std::string gradoAcademico;
    std::string especialidad;
    std::string horas;
    int horaInicio;
	int horaFinaliza;
	int pos;
    std::string dia;
	std::string dia2;
    const std::string dias[5] = { "Lunes", "Martes", "Miércoles", "Jueves", "Viernes" };
	double precio;
	bool estado;
    int cant;
    Profesor* profAux=nullptr;
	Lista<Profesor>* listaProfesores = new Lista<Profesor>();
    Curso* cursoAux = nullptr;
	Lista<Curso>* listaCursos = new Lista<Curso>();
	Grupo* grupoAux = nullptr;
	Lista<Grupo>* listaGrupo = new Lista<Grupo>();
	Estudiante* estudianteAux = nullptr;
	Lista<Estudiante>* listaEstudiantes = new Lista<Estudiante>();
    //Profesor::Profesor(std::string nombre, std::string cedula, std::string telefono, std::string email, std::string gradoAcademico)
    Profesor* prof1 = new Profesor("Juan", "123456789", "1234567", "gaihfd@gmail.com", "Master");
	Profesor* prof2 = new Profesor("Pedro", "123456789", "1234567", "fsdfs@gmail.com", "Doctor");

	if(listaProfesores->insertar(prof1))
		cout << "Profesor ingresado correctamente" << endl;
	else
		cout << "Error al ingresar el profesor" << endl;

    if (listaProfesores->insertar(prof2))
        cout << "Profesor ingresado correctamente" << endl;
    else
        cout << "Error al ingresar el profesor" << endl;

	cout << listaProfesores->toString() << endl;
    do {
        system(cls);
        std::endl(std::cout);
        std::cout << "----Menu Principal----" << std::endl;
        std::cout << "1- Submenu Administración" << std::endl;
        std::cout << "2- Submenu Matricula " << std::endl;
        std::cout << "3- Submenu Busquedas e Informes" << std::endl;
        std::cout << "4- - Guardar los Datos en Archivos " << std::endl;
        std::cout << "5- Salir" << std::endl;
        std::cout << "Seleccione una opcion: "; std::cin >> op;
        switch (op)
        {
        case 1:
            // Llamar a la función del submenú de administración
            do {
                system(cls);
                std::endl(std::cout);
                std::cout << "(1) Ingresar Profesor" << std::endl;
                std::cout << "(2) Ingresar Estudiante" << std::endl;
                std::cout << "(3) Ingresar Curso" << std::endl;
                std::cout << "(4) Ingresar Grupo" << std::endl;
                std::cout << "(5) Asignar Profesor a Grupo" << std::endl;
                std::cout << "(0) Regresar al Menu Principal" << std::endl;
                std::cout << "Seleccione una opcion: "; std::cin >> op1;

                switch (op1)
                {
                case 1:
					cin.ignore();
                    std::cout << "Ingrese los datos del profesor" << std::endl;
                    std::cout << "Ingrese el nombre del profesor: "; getline(std::cin, nombre);
                    std::cout << "Nombre: " << nombre << std::endl;
                    std::cout << "Ingrese la cédula del profesor: "; std::cin >> id;
                    std::cout << "Cedula: " << id << std::endl; cin.ignore();
                    std::cout << "Ingrese el teléfono del profesor: "; getline(std::cin, telefono);
                    std::cout << "Telefono: " << telefono << std::endl;
                    std::cout << "Ingrese el email del profesor: "; getline(std::cin, email);
                    std::cout << "Email: " << email << std::endl;
                    std::cout << "Ingrese el grado academico del profesor: "; getline(std::cin, gradoAcademico);
                    std::cout << "Grado Academico: " << gradoAcademico << std::endl;
                    profAux = new Profesor(nombre, id, telefono, email, gradoAcademico);
                    if (listaProfesores->insertar(profAux)) {
                        std::cout << "Profesor ingresado correctamente." << std::endl;
                    }
                    else {
                        std::cout << "Error al ingresar el profesor." << std::endl;
                        break;
                    }
                    system(pause);
                    break;

                case 2:
                    cin.ignore();
                    std::cout << "Ingrese los datos del estudiante\n";
                    std::cout << "Ingrese el nombre del estudiante: "; getline(std::cin, nombre);
                    std::cout << "Nombre: " << nombre << std::endl; 
                    std::cout << "Ingrese la cédula del estudiante: "; std::cin >> id;
                    std::cout << "Cedula: " << id << std::endl; cin.ignore();
                    std::cout << "Ingrese el teléfono del estudiante: "; getline(std::cin, telefono);
                    std::cout << "Telefono: " << telefono << std::endl;
                    std::cout << "Ingrese el email del estudiante: "; getline(std::cin, email);
                    std::cout << "Email: " << email << std::endl;
                    std::cout << "Ingrese la especialidad del estudiante: "; getline(std::cin, especialidad);
					std::cout << "Especialidad: " << especialidad << std::endl;
					estudianteAux = new Estudiante(nombre, id, telefono, email, especialidad);
                    if (listaEstudiantes->insertar(estudianteAux)) {
                        std::cout << "Estudiante ingresado correctamente." << std::endl;
                    }
                    else {
                        std::cout << "Error al ingresar el estudiante." << std::endl;
                        break;
                    }
                    break;

                case 3:
                    // Llamar a la función de ingresar curso
					cin.ignore();
					std::cout << "Ingrese los datos del curso\n";
					std::cout << "Ingrese el nombre del curso: "; getline(std::cin, nombre);
					std::cout << "Nombre: " << nombre << std::endl;
					std::cout << "Ingrese el id del curso: "; std::cin >> id;
					std::cout << "ID: " << id << std::endl; cin.ignore();
					std::cout << "Ingrese las horas del curso: "; getline(std::cin, horas);
					std::cout << "Horas: " << horas << std::endl;
					std::cout << "Ingrese el precio del curso: "; std::cin>>precio;
					std::cout << "Precio: " << precio << std::endl;
                    std::cout << "Ingrese 0 si el curso no esta activo " << std::endl;
                    std::cout << "Ingrese 1 si el curso esta activo " << std::endl;
					std::cout << "Ingrese el estado del curso: "; cin >> estado;
					if (estado != 0 && estado != 1) {
						std::cout << "Error al ingresar el estado del curso" << std::endl;
						break;
					}
					else if (estado != 0) {
						std::cout << "Estado: Activo" << std::endl;
					}
					else {
						std::cout << "Estado: Inactivo" << std::endl;
					}
					cursoAux = new Curso(nombre, id, horas, precio, estado);
                    if (listaCursos->insertar(cursoAux)) {
                        std::cout << "Curso ingresado correctamente." << std::endl;
                    }
                    else {
                        std::cout << "Error al ingresar el curso." << std::endl;
                        break;
                    }
					system(pause);
                    break;

                case 4:
                    // Llamar a la función de ingresar grupo
					cin.ignore(); //(Periodo * periodo, Curso * curso, std::string IdGrupo, int cantidadEstudiantes, Horario * horario)
					std::cout << "Ingrese los datos del grupo\n";
                    //periodo
					std::cout << "Ingrese el id del curso: "; std::cin >> id;
                    if (listaCursos->buscarElemento(id)) 
						cursoAux = listaCursos->buscarElemento(id);
                    else {
                        std::cout << "Error no hay curso con ese id" << std::endl;
                        break;
                    }
                    std::cout << "Ingrese el id del grupo: "; std::cin >> id;
					std::cout << "ID: " << id << std::endl;
					std::cout << "Ingrese la cantidad de estudiantes: "; std::cin >> id;
					std::cout << "Cantidad de estudiantes: " << id << std::endl;
                    std::cout << "Ingrese el horario del grupo\n";
					std::cout << "Ingrese la hora de inicio: "; std::cin >> horaInicio;
                    std::cout << "Ingrese la hora de finalizacion: "; std::cin >> horaFinaliza;
					std::cout << "Hora de inicio: " << horaInicio << std::endl;
					std::cout << "Hora de finalizacion: " << horaFinaliza << std::endl;
                    for (int i = 0; i < 5; i++) {
                        std::cout << (i + 1) << ". " << dias[i] << "\n";
                    }

                    std::cout << "Ingrese el numero del primer daa: ";
                    std::cin >> pos;
                    dia = dias[pos - 1];

                    std::cout << "Ingrese el numero del segundo dia: ";
                    std::cin >> pos;
                    dia2 = dias[pos - 1];

                    std::cout << "Dia 1 seleccionado: " << dia << std::endl;
                    std::cout << "Dia 2 seleccionado: " << dia2 << std::endl;

					grupoAux = new Grupo(nullptr, cursoAux, id, cant, new Horario(horaInicio, horaFinaliza, dia, dia2));


                    break;

                case 5:
                    // Llamar a la función de asignar profesor a grupo

                    break;

                case 0:
                    system(cls);
                    std::cout << "Regresando al Menu Principal..." << std::endl;
                    system(pause);
                    break;

                default:
                    system(cls);
                    std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
                    system(pause);
                    break;
                }
            } while (op1 != 0);
            break;

        case 2:
            do {
                system(cls);
                std::endl(std::cout);
                std::cout << "(1) Matricular Estudiante" << std::endl;
                std::cout << "(2) Desmatricular Estudiante" << std::endl;
                std::cout << "(0) Regresar al menu Principal" << std::endl;
                std::cout << "Seleccione una opcion: "; std::cin >> op2;
                switch (op2)
                {
                case 1:
                    // Llamar a la función de matricular estudiante
                    break;

                case 2:
                    // Llamar a la función de desmatricular estudiante
					//listaGrupo->eliminarEstudiante(id); //
					//Estudiante->ListaGrupo->EliminarGrupo(id); //
					//ListaGrupo->setCupo(--) //
                    break;

                case 0:
                    system(cls);
                    std::cout << "Regresando al Menu Principal..." << std::endl;
                    system(pause);
                    break;

                default:
                    system(cls);
                    std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
                    system(pause);
                    break;
                }
            } while (op2 != 0);
            break;

        case 3:
            do {
                std::cout << "(1) Informe Profesores Registrados" << std::endl;
                std::cout << "(2) Informe Estudiantes Registrados" << std::endl;
                std::cout << "(3) Informe Cursos Matriculados por un Estudiante" << std::endl;
                std::cout << "(4) Informe Profesor Especifico" << std::endl;
                std::cout << "(5) Informe Periodos Habilitados para el Ano" << std::endl;
                std::cout << "(6) Informe Grupo Especifico" << std::endl;
                std::cout << "(0) Regresar al Menu Principal" << std::endl;
                std::cout << "Seleccione una opcion: "; std::cin >> op3;

                switch (op3)
                {
                case 1:
                    // Llamar a la función de informe de profesores registrados
                    break;

                case 2:
                    // Llamar a la función de informe de estudiantes registrados
                    break;

                case 3:
                    // Llamar a la función de informe de cursos matriculados por un estudiante
                    break;

                case 4:
                    // Llamar a la función de informe de profesor específico
                    break;

                case 5:
                    // Llamar a la función de informe de periodos habilitados para el año
                    break;

                case 6:
                    // Llamar a la función de informe de grupo específico
                    break;

                case 0:
                    system(cls);
                    std::cout << "Regresando al Menu Principal..." << std::endl;
                    system(pause);
                    break;

                default:
                    system(cls);
                    std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
                    system(pause);
                    break;
                }
            } while (op3 != 0);
            break; // Falta este break para cerrar el case 3

        case 4:
            // Llamar a la funcion de guardar los datos en archivos
            break;

        case 5:
            std::cout << "Saliendo del programa..." << std::endl;
            break;

        default:
            system(cls);
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
            system(pause);
            break;
        }
    } while (op != 5);
}