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
	std::string periodo;
	double precio;
	bool estado;
    Profesor* profAux=nullptr;
	Lista<Profesor>* listaProfesores = new Lista<Profesor>();
    Curso* cursoAux = nullptr;
	Lista<Curso>* listaCursos = new Lista<Curso>();
	Grupo* grupoAux = nullptr;
	Lista<Grupo>* listaGrupo = new Lista<Grupo>();

	Estudiante* estudianteAux = nullptr;
	Lista<Estudiante>* listaEstudiantes = new Lista<Estudiante>();

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
                    system(cls);
					cin.ignore();
                    std::cout << "(1) Ingresar Profesor" << std::endl;
                    std::cout << "Ingrese el nombre del profesor: "; getline(std::cin, nombre);
                    std::cout << "Nombre: " << nombre << std::endl;
                    std::cout << "Ingrese la cédula del profesor: "; std::cin >> id;
                    if (listaProfesores->buscarElemento(id)) {
                        std::cerr << "Error ya existe un profesor con esa cedula" << std::endl;
						system(pause);
						break;
                    }
                    std::cout << "Cedula: " << id << std::endl; cin.ignore();
                    std::cout << "Ingrese el teléfono del profesor: "; getline(std::cin, telefono);
                    std::cout << "Telefono: " << telefono << std::endl;
                    std::cout << "Ingrese el email del profesor: "; getline(std::cin, email);
                    std::cout << "Email: " << email << std::endl;
                    std::cout << "Ingrese el grado academico del profesor: "; getline(std::cin, gradoAcademico);
                    std::cout << "Grado Academico: " << gradoAcademico << std::endl;
                    if (nombre.empty() || id.empty() || telefono.empty() || email.empty() || gradoAcademico.empty()) {
                        std::endl(std::cout);
						std::cerr << "Error al ingresar los datos" << std::endl;
						std::cerr << "Hay datos vacios" << std::endl;
						system(pause);
						break;
                    }
                    profAux = new Profesor(nombre, id, telefono, email, gradoAcademico);
                    if (listaProfesores->insertar(profAux)) {
                        std::cout << "Profesor ingresado correctamente." << std::endl;
                    }
                    else {
                        std::cerr << "Error al ingresar el profesor." << std::endl;
                        system(pause);
                        break;
                    }
                    system(pause);
                    break;

                case 2:
                    system(cls);
                    cin.ignore();
                    std::cout << "(2) Ingresar Estudiante" << std::endl;
                    std::cout << "Ingrese el nombre del estudiante: "; getline(std::cin, nombre);
                    std::cout << "Nombre: " << nombre << std::endl; 
                    std::cout << "Ingrese la cédula del estudiante: "; std::cin >> id;
					if (listaEstudiantes->buscarElemento(id)) {
						std::cerr << "Error ya existe un estudiante con esa cedula" << std::endl;
						system(pause);
						break;
					}
                    std::cout << "Cedula: " << id << std::endl; cin.ignore();
                    std::cout << "Ingrese el teléfono del estudiante: "; getline(std::cin, telefono);
                    std::cout << "Telefono: " << telefono << std::endl;
                    std::cout << "Ingrese el email del estudiante: "; getline(std::cin, email);
                    std::cout << "Email: " << email << std::endl;
                    std::cout << "Ingrese la especialidad del estudiante: "; getline(std::cin, especialidad);
					std::cout << "Especialidad: " << especialidad << std::endl;
                    if (nombre.empty() || id.empty() || telefono.empty() || email.empty() || especialidad.empty()) {
                        std::endl(std::cout);
                        std::cerr << "Error al ingresar los datos" << std::endl;
                        std::cerr << "Hay datos vacios" << std::endl;
                        system(pause);
                        break;
                    }
					estudianteAux = new Estudiante(nombre, id, telefono, email, especialidad);
                    if (listaEstudiantes->insertar(estudianteAux)) {
                        std::cout << "Estudiante ingresado correctamente." << std::endl;
                    }
                    else {
                        std::cerr << "Error al ingresar el estudiante." << std::endl;
						system(pause);
                        break;
                    }
                    system(pause);
                    break;

                case 3:
                    system(cls);
					cin.ignore();
                    std::cout << "(3) Ingresar Curso" << std::endl;
					std::cout << "Ingrese el nombre del curso: "; getline(std::cin, nombre);
					std::cout << "Nombre: " << nombre << std::endl;
					std::cout << "Ingrese el id del curso: "; std::cin >> id;
					if (listaCursos->buscarElemento(id)) {
						std::cerr << "Error ya existe un curso con ese id" << std::endl;
						system(pause);
						break;
					}
					std::cout << "ID: " << id << std::endl; cin.ignore();
					std::cout << "Ingrese las horas del curso: "; getline(std::cin, horas);
					std::cout << "Horas: " << horas << std::endl;
					std::cout << "Ingrese el precio del curso: "; std::cin>>precio;
					std::cout << "Precio: " << precio << std::endl;
                    std::cout << "Ingrese 0 si el curso no esta activo " << std::endl;
                    std::cout << "Ingrese 1 si el curso esta activo " << std::endl;
					std::cout << "Ingrese el estado del curso: "; cin >> estado;
					if (estado != 0 && estado != 1) {
                        std::endl(std::cout);
						std::cerr << "Error al ingresar el estado del curso" << std::endl;
						system(pause);
						break;
					}
					else if (estado != 0) {
						std::cout << "Estado: Activo" << std::endl;
					}
					else {
						std::cout << "Estado: Inactivo" << std::endl;
					}
                    if (nombre.empty() || id.empty() || horas.empty()) {
                        std::endl(std::cout);
                        std::cerr << "Error al ingresar los datos" << std::endl;
                        std::cerr << "Hay datos vacios" << std::endl;
                        system(pause);
                        break;
                    }
					cursoAux = new Curso(nombre, id, horas, precio, estado);
                    if (listaCursos->insertar(cursoAux)) {
                        std::cout << "Curso ingresado correctamente." << std::endl;
                    }
                    else {
                        std::cerr << "Error al ingresar el curso." << std::endl;
                        system(pause);
                        break;
                    }
					system(pause);
                    break;

                case 4:
                    system(cls);
					cin.ignore(); 
					if (listaCursos->vacio()) {
						std::cerr << "Error no hay cursos registrados" << std::endl;
						system(pause);
						break;
					}
                    std::cout << "(4) Ingresar Grupo" << std::endl;
                    std::cout << "Los grupos tienen un cupo de 30 estudiantes\n";
                    for (int i = 0; i < CANTIDAD_PERIODOS; i++) {
                        std::cout << (i + 1) << ". " << periodos[i] << "\n";
                    }

                    std::cout << "Ingrese el numero del periodo: ";
                    std::cin >> pos;
                    if (pos < 1 || pos > CANTIDAD_PERIODOS) {
                        std::cerr << "Error el numero no es valido" << std::endl;
                        system(pause);
                        break;
                    }
                    periodo = periodos[pos - 1];
					std::cout << "Periodo seleccionado: " << periodo << std::endl;
					std::cout << "Cursos registrados: \n" << listaCursos->toString() << std::endl;
					std::cout << "Ingrese el id del curso: "; std::cin >> id;
                    if (listaCursos->buscarElemento(id)) 
						cursoAux = listaCursos->buscarElemento(id);
                    else {
                        std::cerr << "Error no hay curso con ese id" << std::endl;
						system(pause);
                        break;
                    }
                    std::cout << "Ingrese el id del grupo: "; std::cin >> id;
					if (listaGrupo->buscarElemento(id)) {
						std::cerr << "Error ya existe un grupo con ese id" << std::endl;
						system(pause);
						break;
					}
					std::cout << "ID: " << id << std::endl;
                    std::cout << "Ingrese el horario del grupo\n";
					std::cout << "Ingrese la hora de inicio: "; std::cin >> horaInicio;
                    std::cout << "Ingrese la hora de finalizacion: "; std::cin >> horaFinaliza;
					std::cout << "Hora de inicio: " << horaInicio << std::endl;
					std::cout << "Hora de finalizacion: " << horaFinaliza << std::endl;
                    for (int i = 0; i < CANTIDAD_DIAS; i++) {
                        std::cout << (i + 1) << ". " << dias[i] << "\n";
                    }

                    std::cout << "Ingrese el numero del primer dia: ";
                    std::cin >> pos;
                    if (pos < 1 || pos > CANTIDAD_DIAS) {
                        std::cerr << "Error el numero del dia no es valido" << std::endl;
						system(pause);
						break;
                    }
                    dia = dias[pos - 1];

                    std::cout << "Ingrese el numero del segundo dia: ";
                    std::cin >> pos;
                    
                     if (pos < 1 || pos > 5) {
                        std::cerr << "Error el numero del dia no es valido" << std::endl;
                        system(pause);
                        break;
                    }
                     if (dia2 == dia) {
                         std::cerr << "Error los dias no pueden ser iguales" << std::endl;
                         system(pause);
                         break;
                     }
					else
						dia2 = dias[pos - 1];

                    std::cout << "Dia 1 seleccionado: " << dia << std::endl;
                    std::cout << "Dia 2 seleccionado: " << dia2 << std::endl;
                    if (periodo.empty() || id.empty() || dia.empty() || dia2.empty()) {
                        std::endl(std::cout);
                        std::cerr << "Error al ingresar los datos" << std::endl;
                        std::cerr << "Hay datos vacios" << std::endl;
                        system(pause);
                        break;
                    }
					grupoAux = new Grupo(periodo, cursoAux, id, new Horario(horaInicio, horaFinaliza, dia, dia2));

                    system(pause);
                    break;

                case 5:
                    system(cls);
                    std::cout << "(5) Asignar Profesor a Grupo" << std::endl;
					if (listaProfesores->vacio() || listaGrupo->vacio()) {
						std::cerr << "Error no hay profesores o grupos registrados" << std::endl;
						system(pause);
						break;
					}
					std::cout << "Ingrese el id del profesor a asignar: "; std::cin >> id;
					if (listaProfesores->buscarElemento(id))
						profAux = listaProfesores->buscarElemento(id);
                    else {
                        std::cerr << "Error no hay profesor con ese id" << std::endl;
                        system(pause);
                        break;
                    }
					std::cout << "Ingrese el id del grupo: "; std::cin >> id;
					if (listaGrupo->buscarElemento(id))
						grupoAux = listaGrupo->buscarElemento(id);
					else {
						std::cerr << "Error no hay grupo con ese id" << std::endl;
                        system(pause);
                        break;
					}
                    if (!grupoAux->getProfesor() && profAux->getListaGrupo()->buscarElemento(id)!=grupoAux) {
                        if (grupoAux->setProfesor(profAux)) {
                            profAux->getListaGrupo()->insertar(grupoAux);
                            std::cout << "Profesor asignado correctamente." << std::endl;
                        }
                        else {
                            std::cerr << "Error al asignar el profesor." << std::endl;
                            system(pause);
                            break;
                        }
					}
					else {
						std::cerr << "El grupo ya tiene un profesor asignado o el profesor ya tiene ese grupo asignado." << std::endl;
						system(pause);
						break;
					}
                    system(pause);
                    break;

                case 0:
                    system(cls);
                    std::cout << "Regresando al Menu Principal..." << std::endl;
                    system(pause);
                    break;

                default:
                    system(cls);
                    std::cerr << "Opcion no valida. Intente de nuevo." << std::endl;
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
                    system(cls);
                    // Llamar a la función de matricular estudiante
                    std::cout << "(1) Matricular Estudiante" << std::endl;
					if (listaEstudiantes->vacio() || listaGrupo->vacio()) {
						std::cerr << "Error no hay estudiantes o grupos registrados" << std::endl;
						system(pause);
						break;
					}
					std::cout << "Ingrese el id del estudiante: "; std::cin >> id;
					if (listaEstudiantes->buscarElemento(id))
						estudianteAux = listaEstudiantes->buscarElemento(id);
                    else {
                        std::cerr << "Error no hay estudiante con ese id" << std::endl;
                        system(pause);
                        break;
                    }
					std::cout << "Ingrese el id del grupo: "; std::cin >> id;
					if (listaGrupo->buscarElemento(id))
						grupoAux = listaGrupo->buscarElemento(id);
					else {
						std::cerr << "Error no hay grupo con ese id" << std::endl;
						system(pause);
                        break;
					}
                    if (estudianteAux->insertarGrupo(grupoAux)) {
                        if (grupoAux->getCantidadEstudiantes() < 30) {
                            if (grupoAux->insertarEstudiante(id)) {
                                std::cout << "Estudiante matriculado correctamente." << std::endl;
							}
                            else {
                                std::cerr << "Error al matricular el estudiante." << std::endl;
                                system(pause);
                                break;
                            }
                        }
                        else {
                            std::cerr << "Error el grupo ya tiene 30 estudiantes" << std::endl;
                            system(pause);
                            break;
                        }
					}
					else {
						std::cerr << "Error el estudiante ya esta matriculado en un grupo" << std::endl;
						system(pause);
						break;
					}
                    system(pause);
                    break;

                case 2:
                    system(cls);
					std::cout << "(2) Desmatricular Estudiante" << std::endl;
                    if (listaEstudiantes->vacio() || listaGrupo->vacio()) {
                        std::cerr << "Error no hay estudiantes o grupos registrados" << std::endl;
                        system(pause);
                        break;
                    }
					std::cout << "Ingrese el id del estudiante: "; std::cin >> id;
					if (listaEstudiantes->buscarElemento(id))
						estudianteAux = listaEstudiantes->buscarElemento(id);
					else {
						std::cerr << "Error no hay estudiante con ese id" << std::endl;
						system(pause);
                        break;
					}
					std::cout << "Grupos del estudiante: \n" << estudianteAux->getListaGrupo()->toString() << std::endl;
					std::cout << "Ingrese el id del grupo: "; std::cin >> id;
					if (listaGrupo->buscarElemento(id))
						grupoAux = listaGrupo->buscarElemento(id);
					else {
						std::cerr << "Error no hay grupo con ese id" << std::endl;
						system(pause);
						break;
					}
                    if (estudianteAux->eliminarGrupo(grupoAux->getId())) {
                        if (grupoAux->eliminarEstudiante(id)) {
                            std::cout << "Estudiante desmatriculado correctamente." << std::endl;
                        }
                    }
                        else {
                            std::cerr << "Error al desmatricular el estudiante." << std::endl;
                            system(pause);
                            break;
                        }
                    system(pause);
                    break;

                case 0:
                    system(cls);
                    std::cout << "Regresando al Menu Principal..." << std::endl;
                    system(pause);
                    break;

                default:
                    system(cls);
                    std::cerr << "Opcion no valida. Intente de nuevo." << std::endl;
                    system(pause);
                    break;
                }
            } while (op2 != 0);
            break;

        case 3:
            do {
                system(cls);
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
                    system(cls);
                    std::cout << "(1) Informe Profesores Registrados" << std::endl;
                    if (!listaProfesores->vacio()) {
                        std::cout << listaProfesores->toString();
                    }
                    else {
                        std::cerr << "No hay profesores registrados" << std::endl;
                        system(pause);
                        break;
                    }

                    system(pause);
                    break;

                case 2:
                    system(cls);
                    std::cout << "(2) Informe Estudiantes Registrados" << std::endl;

                    if (!listaEstudiantes->vacio()) {
						std::cout << listaEstudiantes->toString();
					}
					else {
						std::cerr << "No hay estudiantes registrados" << std::endl;
						system(pause);
						break;
					}
                    system(pause);
                    break;
                case 3:
                    system(cls);
                    std::cout << "(3) Informe Cursos Matriculados por un Estudiante" << std::endl;
                    if (listaEstudiantes->vacio() || listaGrupo->vacio()) {
                        std::cerr << "No hay estudiantes ingresados o grupos ingresados" << std::endl;
                        system(pause);
                        break;
                    }
                    std::cout << "Ingrese el id del estudiante: "; std::cin >> id;
					if (listaEstudiantes->buscarElemento(id))
						estudianteAux = listaEstudiantes->buscarElemento(id);
					else {
						std::cerr << "Error no hay estudiante con ese id" << std::endl;
						system(pause);
						break;
					}
					std::cout << "Datos del estudiante: \n" << estudianteAux->toString() << std::endl;
					std::cout << "Grupos del estudiante: \n" << estudianteAux->getListaGrupo()->toStringBasico() << std::endl;
                    system(pause);
                    break;

                case 4:
                    system(cls);
                    std::cout << "(4) Informe Profesor Especifico" << std::endl;
                    if (listaProfesores->vacio()) {
                        std::cerr << "No hay profesores ingresados " << std::endl;
                        system(pause);
                        break;
                    }
                    std::cout << "Ingrese el id del profesor: "; std::cin >> id;
                    if (listaProfesores->buscarElemento(id))
                        profAux = listaProfesores->buscarElemento(id);
                    else {
                        std::cerr << "Error no hay profesor con ese id" << std::endl;
                        system(pause);
                        break;
                    }
                    std::cout << "Datos del profesor: \n" << profAux->toString() << std::endl;
                    std::cout << "Grupos del profesor: \n" << profAux->toStringPeriodo() << std::endl;
                    system(pause);
                    break;
                    system(pause);
                    break;

                case 5:
                    system(cls);
                    std::cout << "(5) Informe Periodos Habilitados para el Ano" << std::endl;
					if (!listaGrupo->vacio() && !listaCursos->vacio())
					grupoAux->toStringPeriodos(listaGrupo);
                    else {
                        std::cerr << "No hay grupos registrados o cursos registrados" << std::endl;
                        system(pause);
                        break;
                    }
                    system(pause);
                    break;

                case 6:
                    system(cls);
                    std::cout << "(6) Informe Grupo Especifico" << std::endl;
					if (listaGrupo->vacio() || listaCursos->vacio()) {
						std::cerr << "Error no hay grupos registrados o Cursos registrados" << std::endl;
						system(pause);
						break;
					}
					std::cout << "Ingrese el id del grupo: "; std::cin >> id;
					if (listaGrupo->buscarElemento(id))
						grupoAux = listaGrupo->buscarElemento(id);
					else {
						std::cerr << "Error no hay grupo con ese id" << std::endl;
                        system(pause);
						break;
					}
					std::cout << "Datos del grupo: \n" << grupoAux->toString() << std::endl;

                    system(pause);
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
            system(cls);
            // Llamar a la funcion de guardar los datos en archivos
            system(pause);
            break;

        case 5:
            system(cls);
            std::cout << "Saliendo del programa..." << std::endl;
            system(pause);
            break;

        default:
            system(cls);
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
            system(pause);
            break;
        }
    } while (op != 5);

    delete profAux;
    delete listaCursos;
    delete estudianteAux;
	delete listaEstudiantes;
	delete cursoAux;
	delete grupoAux;
	delete listaGrupo;
	return 0;
}