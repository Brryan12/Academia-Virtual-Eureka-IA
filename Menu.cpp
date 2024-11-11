#include "Menu.h"

int Menu::menuPrincipal()
{
	int op;
    system(cls);
    std::endl(std::cout);
    std::cout << "----Menu Principal----" << std::endl;
    std::cout << "1- Submenu Administracion" << std::endl;
    std::cout << "2- Submenu Matricula " << std::endl;
    std::cout << "3- Submenu Busquedas e Informes" << std::endl;
   std::cout << "4- Guardar los Datos en Archivos " << std::endl;
    std::cout << "5- Salir" << std::endl;
    std::cout << "Seleccione una opcion: "; std::cin >> op;
	return op;
}

int Menu::submenuAdministracion()
{
	int op1;
    system(cls);
    std::endl(std::cout);
    std::cout << "(1) Ingresar Profesor" << std::endl;
    std::cout << "(2) Ingresar Estudiante" << std::endl;
    std::cout << "(3) Ingresar Curso" << std::endl;
    std::cout << "(4) Ingresar Grupo" << std::endl;
    std::cout << "(5) Asignar Profesor a Grupo" << std::endl;
    std::cout << "(0) Regresar al Menu Principal" << std::endl;
    std::cout << "Seleccione una opcion: "; std::cin >> op1;
	return op1;
}

int Menu::submenuMatricula()
{
    int op2;
    system(cls);
    std::endl(std::cout);
    std::cout << "(1) Matricular Estudiante" << std::endl;
    std::cout << "(2) Desmatricular Estudiante" << std::endl;
    std::cout << "(3) Generar Factura del pago del estudiante" << std::endl;
    std::cout << "(0) Regresar al menu Principal" << std::endl;
    std::cout << "Seleccione una opcion: "; std::cin >> op2;
	return op2;
}

int Menu::submenuBusquedasEInformes()
{
    int op3;
    system(cls);
    std::cout << "(1) Informe Profesores Registrados" << std::endl;
    std::cout << "(2) Informe Estudiantes Registrados" << std::endl;
    std::cout << "(3) Informe Cursos Matriculados por un Estudiante" << std::endl;
    std::cout << "(4) Informe Profesor Especifico" << std::endl;
    std::cout << "(5) Informe Periodos Habilitados para el Ano" << std::endl;
    std::cout << "(6) Informe Grupo Especifico" << std::endl;
    std::cout << "(0) Regresar al Menu Principal" << std::endl;
    std::cout << "Seleccione una opcion: "; std::cin >> op3;
	return op3;
}

void Menu::guardarLosDatosEnArchivos(Lista<Profesor>* listaProfesores, Lista<Estudiante>* listaEstudiantes, Lista<Curso>* listaCursos, Lista<Grupo>* listaGrupo)
{
    system(cls);
    Archivos* archivos = new Archivos();
    std::cout << "Guardando los datos en archivos..." << std::endl;
    archivos->guardarEstudiantes(listaEstudiantes);
    archivos->guardarProfesores(listaProfesores);
    archivos->guardarCursos(listaCursos);
    archivos->guardarGrupos(listaGrupo);
    std::cout << "Datos guardados en archivos" << std::endl;
    delete archivos;
    system(pause);
}

void Menu::defaultSwitch()
{
    system(cls);
    cout << "Opcion no valida. Intente de nuevo." << endl;
    system(pause);
}

void Menu::regresarMenuPrincipal()
{
    system(cls);
    std::cout << "Regresando al Menu Principal..." << std::endl;
    system(pause);
}

void Menu::ingresarProfesor(Lista<Profesor> * listaProfesores)
{
	std::string nombre, id, telefono, email, gradoAcademico;
	Profesor* profAux=nullptr;
    system(cls);
    cin.ignore();
    std::cout << "(1) Ingresar Profesor" << std::endl;
    std::cout << "Ingrese el nombre del profesor: "; getline(std::cin, nombre);
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Ingrese la cedula del profesor: "; std::cin >> id;
    if (listaProfesores->buscarElemento(id)) {
        std::cerr << "Error ya existe un profesor con esa cedula" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Cedula: " << id << std::endl; cin.ignore();
    std::cout << "Ingrese el telefono del profesor: "; getline(std::cin, telefono);
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
        return;
    }
    profAux = new Profesor(nombre, id, telefono, email, gradoAcademico);
    if (listaProfesores->insertar(profAux)) {
        std::cout << "Profesor ingresado correctamente." << std::endl;
    }
    else {
        std::cerr << "Error al ingresar el profesor." << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::ingresarEstudiante(Lista<Estudiante>* listaEstudiantes)
{
	std::string nombre, id, telefono, email, especialidad;
	Estudiante* estudianteAux = nullptr;
    system(cls);
    cin.ignore();
    std::cout << "(2) Ingresar Estudiante" << std::endl;
    std::cout << "Ingrese el nombre del estudiante: "; getline(std::cin, nombre);
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Ingrese la cédula del estudiante: "; std::cin >> id;
    if (listaEstudiantes->buscarElemento(id)) {
        std::cerr << "Error ya existe un estudiante con esa cedula" << std::endl;
        system(pause);
        return;
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
        return;
    }
    estudianteAux = new Estudiante(nombre, id, telefono, email, especialidad);
    if (listaEstudiantes->insertar(estudianteAux)) {
        std::cout << "Estudiante ingresado correctamente." << std::endl;
    }
    else {
        std::cerr << "Error al ingresar el estudiante." << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::ingresarCurso(Lista<Curso>* listaCursos)
{
	std::string nombre, id, horas;
	double precio;
	int estado;
	Curso* cursoAux = nullptr;

    system(cls);
    cin.ignore();
    std::cout << "(3) Ingresar Curso" << std::endl;
    std::cout << "Ingrese el nombre del curso: "; getline(std::cin, nombre);
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Ingrese el id del curso: "; std::cin >> id;
    if (listaCursos->buscarElemento(id)) {
        std::cerr << "Error ya existe un curso con ese id" << std::endl;
        system(pause);
        return;
    }
    std::cout << "ID: " << id << std::endl; cin.ignore();
    std::cout << "Ingrese las horas del curso: "; getline(std::cin, horas);
    std::cout << "Horas: " << horas << std::endl;
    std::cout << "Ingrese el precio del curso: "; std::cin >> precio;
    std::cout << "Precio: " << precio << std::endl;
    std::cout << "Ingrese 0 si el curso no esta activo " << std::endl;
    std::cout << "Ingrese 1 si el curso esta activo " << std::endl;
    std::cout << "Ingrese el estado del curso: "; cin >> estado;
    if (estado != 0 && estado != 1) {
        std::endl(std::cout);
        std::cerr << "Error al ingresar el estado del curso" << std::endl;
        system(pause);
        return;
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
        return;
    }
    cursoAux = new Curso(nombre, id, horas, precio, estado);
    if (listaCursos->insertar(cursoAux)) {
        std::cout << "Curso ingresado correctamente." << std::endl;
    }
    else {
        std::cerr << "Error al ingresar el curso." << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::ingresarGrupo(Lista<Grupo>* listaGrupo, Lista<Curso>* listaCursos)
{
	std::string periodo, id, dia, dia2;
	int pos, horaInicio, horaFinaliza;
	Curso* cursoAux = nullptr;
	Grupo* grupoAux = nullptr;
    system(cls);
    cin.ignore();
    if (listaCursos->vacio()) {
        std::cerr << "Error no hay cursos registrados" << std::endl;
        system(pause);
        return;
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
        return;
    }
    periodo = periodos[pos - 1];
    std::cout << "Periodo seleccionado: " << periodo << std::endl;
    std::cout << "Cursos registrados: \n" << listaCursos->toString() << std::endl;
    std::cout << "Ingrese el id del curso: "; std::cin >> id;
    if (listaCursos->buscarElemento(id)) {
        cursoAux = listaCursos->buscarElemento(id);
        if (cursoAux->getEstado() == false) {
            std::cerr << "El curso esta inactivo, no se puede crear grupo" << std::endl;
            system(pause);
            return;
        }
    }

    else {
        std::cerr << "Error no hay curso con ese id" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Ingrese el id del grupo: "; std::cin >> id;
    if (listaGrupo->buscarElemento(id)) {
        std::cerr << "Error ya existe un grupo con ese id" << std::endl;
        system(pause);
        return;
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
        return;
    }
    dia = dias[pos - 1];

    std::cout << "Ingrese el numero del segundo dia: ";
    std::cin >> pos;

    if (pos < 1 || pos > 5) {
        std::cerr << "Error el numero del dia no es valido" << std::endl;
        system(pause);
        return;
    }
    if (dia2 == dia) {
        std::cerr << "Error los dias no pueden ser iguales" << std::endl;
        system(pause);
        return;
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
        return;
    }
    grupoAux = new Grupo(periodo, cursoAux, id, new Horario(horaInicio, horaFinaliza, dia, dia2));
    if (listaGrupo->insertar(grupoAux)) {
        std::cout << "Grupo ingresado correctamente." << std::endl;
    }
    else {
        std::cerr << "Error al ingresar el grupo." << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::asignarProfesorAGrupo(Lista<Grupo>* listaGrupo, Lista<Profesor>* listaProfesores)
{
	std::string id;
	Profesor* profAux = nullptr;
	Grupo* grupoAux = nullptr;
    system(cls);
    std::cout << "(5) Asignar Profesor a Grupo" << std::endl;
    if (listaProfesores->vacio() || listaGrupo->vacio()) {
        std::cerr << "Error no hay profesores o grupos registrados" << std::endl;
        system(pause);
        return;
    }
	std::cout << listaProfesores->toString() << std::endl;
    std::cout << "Ingrese la cedula del profesor a asignar: "; std::cin >> id;
    if (listaProfesores->buscarElemento(id))
        profAux = listaProfesores->buscarElemento(id);
    else {
        std::cerr << "Error no hay profesor con esa cedula" << std::endl;
        system(pause);
        return;
    }
	std::cout << Grupo::GruposSinProfesor(listaGrupo) << std::endl;
    std::cout << "Ingrese el id del grupo: "; std::cin >> id;
    if (listaGrupo->buscarElemento(id))
        grupoAux = listaGrupo->buscarElemento(id);
    else {
        std::cerr << "Error no hay grupo con ese id" << std::endl;
        system(pause);
        return;
    }
    if (!grupoAux->getProfesor() && profAux->getListaGrupo()->buscarElemento(id) != grupoAux) {
        if (grupoAux->setProfesor(profAux)) {
            profAux->getListaGrupo()->insertar(grupoAux);
            std::cout << "Profesor asignado correctamente." << std::endl;
        }
        else {
            std::cerr << "Error al asignar el profesor." << std::endl;
            system(pause);
            return;
        }
    }
    else {
        std::cerr << "El grupo ya tiene un profesor asignado o el profesor ya tiene ese grupo asignado." << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::matricularEstudiante(Lista<Grupo>* listaGrupo, Lista<Estudiante>* listaEstudiantes)
{
	std::string id;
	Estudiante* estudianteAux = nullptr;
	Grupo* grupoAux = nullptr;
    system(cls);
    std::cout << "(1) Matricular Estudiante" << std::endl;
    if (listaEstudiantes->vacio() || listaGrupo->vacio()) {
        std::cerr << "Error no hay estudiantes o grupos registrados" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Estudiantes: \n" << listaEstudiantes->toString() << std::endl;
    std::cout << "Ingrese la cedula del estudiante: "; std::cin >> id;
    if (listaEstudiantes->buscarElemento(id))
        estudianteAux = listaEstudiantes->buscarElemento(id);
    else {
        std::cerr << "Error no hay estudiante con esa cedula" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Nombre del estudiante: " << estudianteAux->getNombre() << std::endl;
    std::cout << "Grupos: \n" << Grupo::GruposConProfesor(listaGrupo);
    std::cout << "Ingrese el id del grupo: "; std::cin >> id;
    if (listaGrupo->buscarElemento(id)) {
        grupoAux = listaGrupo->buscarElemento(id);
        if (!grupoAux->getProfesor()) {
            std::cerr << "Error el grupo no tiene profesor asignado" << std::endl;
        }
    }
    else {
        std::cerr << "Error no hay grupo con ese id" << std::endl;
        system(pause);
        return;
    }
    if (estudianteAux->insertarGrupo(grupoAux)) {
        if (grupoAux->getCantidadEstudiantes() < 30) {
            if (grupoAux->insertarEstudiante(estudianteAux)) {
                std::cout << "Estudiante matriculado correctamente Grupo." << std::endl;
            }
            else {
                std::cerr << "Error al matricular el estudiante." << std::endl;
                system(pause);
                return;
            }
        }
        else {
            std::cerr << "Error el grupo ya tiene 30 estudiantes" << std::endl;
            system(pause);
            return;
        }
        std::cout << "Estudiante matriculado correctamente estudiante." << std::endl;

    }
    else {
        std::cerr << "Error el estudiante ya esta matriculado en un grupo con este curso" << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::desmatricularEstudiante(Lista<Grupo>* listaGrupo, Lista<Estudiante>* listaEstudiantes)
{
	std::string id;
	Estudiante* estudianteAux = nullptr;
	Grupo* grupoAux = nullptr;
    system(cls);
    std::cout << "(2) Desmatricular Estudiante" << std::endl;
    if (listaEstudiantes->vacio() || listaGrupo->vacio()) {
        std::cerr << "Error no hay estudiantes o grupos registrados" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Estudiantes: \n" << listaEstudiantes->toString() << std::endl;
    std::cout << "Ingrese la cedula del estudiante: "; std::cin >> id;
    if (listaEstudiantes->buscarElemento(id))
        estudianteAux = listaEstudiantes->buscarElemento(id);
    else {
        std::cerr << "Error no hay estudiante con esa cedula" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Grupos del estudiante: \n" << estudianteAux->getListaGrupo()->toString() << std::endl;
    std::cout << "Ingrese el id del grupo: "; std::cin >> id;
    if (listaGrupo->buscarElemento(id))
        grupoAux = listaGrupo->buscarElemento(id);
    else {
        std::cerr << "Error no hay grupo con ese id" << std::endl;
        system(pause);
        return;
    }
    if (estudianteAux->eliminarGrupo(grupoAux->getId())) {
        std::cout << "Estudiante desmatriculado correctamente." << std::endl;
        if (grupoAux->eliminarEstudiante(estudianteAux->getId())) {
            std::cout << "Estudiante desmatriculado correctamente Grupo." << std::endl;
        }
        else {
            std::cerr << "Error al desmatricular el estudiante Grupo." << std::endl;
            system(pause);
            return;
        }
    }
    else {
        std::cerr << "Error al desmatricular el estudiante." << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::generarFactura(Lista<Estudiante>* listaEstudiantes)
{
	std::string id;
	Estudiante* estudianteAux = nullptr;
	Factura* facturaAux = nullptr;
	system(cls);
    std::cout << "(3) Generar Factura del pago del estudiante" << std::endl;
    std::cout << listaEstudiantes->toString() << endl;
    std::cout << "Ingrese la cedula del estudiante: "; std::cin >> id;
    if (listaEstudiantes->buscarElemento(id)) {
        estudianteAux = listaEstudiantes->buscarElemento(id);
        if (estudianteAux->getListaGrupo()->vacio()) {
            std::cerr << "Error el estudiante no esta matriculado en ningun grupo" << std::endl;
            system(pause);
            return;
        }
    }
    else {
        std::cerr << "Error no hay estudiante con esa cedula" << std::endl;
        system(pause);
        return;
    }
    facturaAux = new Factura(estudianteAux);
    std::cout << "Factura del estudiante: \n" << facturaAux->factura() << std::endl;

    system(pause);
}

void Menu::informeProfesoresRegistrados(Lista<Profesor>* listaProfesores)
{
    system(cls);
    std::cout << "(1) Informe Profesores Registrados" << std::endl;
    if (!listaProfesores->vacio()) {
        std::cout << listaProfesores->toString();
    }
    else {
        std::cerr << "No hay profesores registrados" << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::informeEstudiantesRegistrados(Lista<Estudiante>* listaEstudiantes)
{
    system(cls);
    std::cout << "(2) Informe Estudiantes Registrados" << std::endl;

    if (!listaEstudiantes->vacio()) {
        std::cout << listaEstudiantes->toString();
    }
    else {
        std::cerr << "No hay estudiantes registrados" << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::informeCursosMatriculadosPorEstudiante(Lista<Grupo>* listaGrupo, Lista<Estudiante>* listaEstudiantes)
{
	std::string id;
	Estudiante* estudianteAux = nullptr;

    system(cls);
    std::cout << "(3) Informe Cursos Matriculados por un Estudiante" << std::endl;
    if (listaEstudiantes->vacio() || listaGrupo->vacio()) {
        std::cerr << "No hay estudiantes ingresados o grupos ingresados" << std::endl;
        system(pause);
        return;
    }
    std::cout << listaEstudiantes->toString() << endl;
    std::cout << "Ingrese la cedula del estudiante: "; std::cin >> id;
    if (listaEstudiantes->buscarElemento(id))
        estudianteAux = listaEstudiantes->buscarElemento(id);
    else {
        std::cerr << "Error no hay estudiante con esa cedula" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Datos del estudiante: \n" << estudianteAux->toString() << std::endl;
    std::cout << "Grupos del estudiante: \n" << Grupo::toStringBasico(estudianteAux->getListaGrupo()) << std::endl;
    system(pause);
}

void Menu::informeProfesorEspecifico(Lista<Profesor>* listaProfesores)
{
	std::string id;
	Profesor* profAux = nullptr;
    system(cls);
    std::cout << "(4) Informe Profesor Especifico" << std::endl;
    if (listaProfesores->vacio()) {
        std::cerr << "No hay profesores ingresados " << std::endl;
        system(pause);
        return;
    }
    std::cout << listaProfesores->toString() << endl;
    std::cout << "Ingrese la cedula del profesor: "; std::cin >> id;
    if (listaProfesores->buscarElemento(id))
        profAux = listaProfesores->buscarElemento(id);
    else {
        std::cerr << "Error no hay profesor con esa cedula" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Datos del profesor: \n" << profAux->toString() << std::endl;
    std::cout << "Grupos del profesor: \n" << profAux->toStringPeriodo() << std::endl;
    system(pause);
    return;
    system(pause);
}

void Menu::informePeriodosHabilitadosParaElAno(Lista<Grupo>* listaGrupo, Lista<Curso>* listaCursos)
{
    system(cls);
    std::cout << "(5) Informe Periodos Habilitados para el Ano" << std::endl;
    if (!listaGrupo->vacio() && !listaCursos->vacio())
        std::cout<<Grupo::toStringPeriodos(listaGrupo)<<std::endl;
    else {
        std::cerr << "No hay grupos registrados o cursos registrados" << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::informeGrupoEspecifico(Lista<Grupo>* listaGrupo, Lista<Curso>* listaCursos)
{
	std::string id;
	Grupo* grupoAux=nullptr;
    system(cls);
    std::cout << "(6) Informe Grupo Especifico" << std::endl;
    if (listaGrupo->vacio() || listaCursos->vacio()) {
        std::cerr << "Error no hay grupos registrados o Cursos registrados" << std::endl;
        system(pause);
        return;
    }
    std::cout << listaGrupo->toString() << std::endl;
    std::cout << "Ingrese el id del grupo: "; std::cin >> id;
    if (listaGrupo->buscarElemento(id))
        grupoAux = listaGrupo->buscarElemento(id);
    else {
        std::cerr << "Error no hay grupo con ese id" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Datos del grupo: \n" << grupoAux->toString() << std::endl;

    system(pause);
}