#pragma once
#include "Menu.h"
#include "Constantes.h"

/// @brief Funcion que muestra el menu principal del programa
void mostrarMenu() {
    int op, op1, op2, op3;
    Archivos* archivos = new Archivos();
    Lista<Profesor>* listaProfesores = archivos->cargarProfesores();
    Lista<Curso>* listaCursos = archivos->cargarCursos();
    Lista<Grupo>* listaGrupo = archivos->cargarGrupos();
    Lista<Estudiante>* listaEstudiantes = archivos->cargarEstudiantes();
    do {
        op = Menu::menuPrincipal();
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
                    Menu::informeCursosMatriculadosPorEstudiante(listaGrupo, listaEstudiantes);
                    break;

                case 4:
                    Menu::informeProfesorEspecifico(listaProfesores);
                    break;

                case 5:
                    Menu::informePeriodosHabilitadosParaElAno(listaGrupo, listaCursos);
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
            Menu::guardarLosDatosEnArchivos(listaProfesores, listaEstudiantes, listaCursos, listaGrupo);
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

    delete listaEstudiantes;
    delete listaGrupo;
    delete listaCursos;
    delete listaProfesores;
    delete archivos;
}