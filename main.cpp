#include "Include.h"

int main()
{
    int op, op1, op2, op3;
	Lista<Profesor>* listaProfesores = new Lista<Profesor>();
	Lista<Curso>* listaCursos = new Lista<Curso>();
	Lista<Grupo>* listaGrupo = new Lista<Grupo>();
	Lista<Estudiante>* listaEstudiantes = new Lista<Estudiante>();
    //Pruebas
	Estudiante* estudianteAux1 = new Estudiante("Juan", "123", "11-23", "adas@gmail.com", "Mate");
	Estudiante* estudianteAux2 = new Estudiante("Pedro", "124", "128-4", "das@gmail.com", "Medicina");
	Estudiante* estudianteAux3 = new Estudiante("Maria", "125", "125-5", "das@gmail.com", "Mota");
	Profesor* profAux1 = new Profesor("Juan", "123", "1245-3", "das@gmail.com", "Doctor");
	Profesor* profAux2 = new Profesor("Pedro", "124", "125-644", "das@gmail.com", "Maestro");
    Profesor* profAux3 = new Profesor("Maria", "125", "1744-25", "das@gmail.com", "Pedo");
	listaEstudiantes->insertar(estudianteAux1);
	listaEstudiantes->insertar(estudianteAux2);
	listaEstudiantes->insertar(estudianteAux3);
	listaProfesores->insertar(profAux1);
	listaProfesores->insertar(profAux2);
	listaProfesores->insertar(profAux3);
	Curso* cursoAux1 = new Curso("Mate", "123", "12", 100, true);
	Curso* cursoAux2 = new Curso("Fisica", "124", "12", 100, true);
	Curso* cursoAux3 = new Curso("Quimica", "125", "12", 100, true);
	listaCursos->insertar(cursoAux1);
	listaCursos->insertar(cursoAux2);
	listaCursos->insertar(cursoAux3);
	Grupo* grupoAux1 = new Grupo(periodos[0], cursoAux1, "123", new Horario(12, 14, "Lunes", "Miercoles"));
    Grupo* grupoAux11 = new Grupo(periodos[3], cursoAux1, "113", new Horario(12, 14, "Lunes", "Miercoles"));

	Grupo* grupoAux2 = new Grupo(periodos[0], cursoAux2, "124", new Horario(12, 14, "Martes", "Jueves"));
    Grupo* grupoAux22 = new Grupo(periodos[1], cursoAux3, "1232", new Horario(12, 14, "Martes", "Jueves"));

	Grupo* grupoAux3 = new Grupo(periodos[2], cursoAux3, "125", new Horario(12, 14, "Viernes", "Sabado"));
    Grupo* grupoAux33 = new Grupo(periodos[3], cursoAux3, "125745", new Horario(12, 14, "Viernes", "Sabado"));
	listaGrupo->insertar(grupoAux1);
	listaGrupo->insertar(grupoAux11);
	listaGrupo->insertar(grupoAux2);
	listaGrupo->insertar(grupoAux22);
	listaGrupo->insertar(grupoAux3);
	listaGrupo->insertar(grupoAux33);


    do {
		op= Menu::menuPrincipal();
        switch (op)
        {
        case 1:
            do {
				op1 = Menu::submenuAdministracion();

                switch (op1)
                {
                case 1:
                    Menu::ingresarProfesor(listaProfesores);
                    break;

                case 2:
                    Menu::ingresarEstudiante(listaEstudiantes);
                    break;

                case 3:
					Menu::ingresarCurso(listaCursos);
                    break;

                case 4:
					Menu::ingresarGrupo(listaGrupo, listaCursos);
                    break;

                case 5:
					Menu::asignarProfesorAGrupo(listaGrupo, listaProfesores);
                    break;

                case 0:
                    Menu::regresarMenuPrincipal();
                    break;

                default:
                    Menu::defaultSwitch();
                    break;
                }
            } while (op1 != 0);
            break;

        case 2:
            do {
				op2 = Menu::submenuMatricula();
                switch (op2)
                {
                case 1:
					Menu::matricularEstudiante(listaGrupo, listaEstudiantes);
                    break;

                case 2:
					Menu::desmatricularEstudiante(listaGrupo, listaEstudiantes);
                    break;
                case 3:
					Menu::generarFactura(listaEstudiantes);
                    break;
                case 0:
					Menu::regresarMenuPrincipal();
                    break;

                default:
                    Menu::defaultSwitch();
                    break;
                }
            } while (op2 != 0);
            break;

        case 3:
            do {
				op3 = Menu::submenuBusquedasEInformes();

                switch (op3)
                {
                case 1:
					Menu::informeProfesoresRegistrados(listaProfesores);
                    break;

                case 2:
					Menu::informeEstudiantesRegistrados(listaEstudiantes);
                    break;
                case 3:
					Menu::informeCursosMatriculadosPorEstudiante(listaGrupo,listaEstudiantes);
                    break;

                case 4:
					Menu::informeProfesorEspecifico(listaProfesores);
                    break;

                case 5:
					Menu::informePeriodosHabilitadosParaElAno(listaGrupo,listaCursos);
                    break;

                case 6:
					Menu::informeGrupoEspecifico(listaGrupo, listaCursos);
                    break;

                case 0:
                    Menu::regresarMenuPrincipal();
                    break;

                default:
					Menu::defaultSwitch();
                    break;
                }
            } while (op3 != 0);
            break;

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
            Menu::defaultSwitch();
            break;
        }
    } while (op != 5);

    delete listaCursos;
	delete listaEstudiantes;
	delete listaGrupo;
	delete listaProfesores;
	return 0;
}