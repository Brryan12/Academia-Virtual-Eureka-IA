#include "Grupo.h"

Grupo::Grupo() : periodo(""), curso(nullptr), IdGrupo(""), cantidadEstudiantes(0), horario(nullptr), profesor(nullptr), estudiantes(nullptr) {}

Grupo::Grupo(std::string periodo, Curso* curso, std::string IdGrupo, Horario* horario) : periodo(periodo), curso(curso), IdGrupo(IdGrupo), cantidadEstudiantes(0), horario(horario), profesor(nullptr), estudiantes(new Lista<Estudiante>()) {}

Grupo::Grupo(std::string periodo, Curso* curso, std::string IdGrupo, Horario* horario, Profesor* profesor) : periodo(periodo), curso(curso), IdGrupo(IdGrupo), cantidadEstudiantes(0), horario(horario), profesor(profesor), estudiantes(new Lista<Estudiante>()) {}

Grupo::~Grupo()
{
	delete horario;
	estudiantes = nullptr;
	profesor = nullptr;
}
int Grupo::getCupo() const
{
	return cupo;
}
std::string Grupo::getPeriodo() const
{
	return periodo;
}

std::string Grupo::getId() const
{
	return IdGrupo;
}


int Grupo::getCantidadEstudiantes() const
{
	return cantidadEstudiantes;
}

Curso* Grupo::getCurso() const
{
	return curso;
}

Horario* Grupo::getHorario() const
{
	return horario;
}

Profesor* Grupo::getProfesor() const
{
	return profesor;
}

void Grupo::setPeriodo(std::string periodo)
{
	this->periodo = periodo;
}

void Grupo::setIdGrupo(std::string IdGrupo)
{
	this->IdGrupo = IdGrupo;
}

void Grupo::setCantidadEstudiantes(int cantidadEstudiantes)
{
	this->cantidadEstudiantes = cantidadEstudiantes;
}

void Grupo::setCurso(Curso* curso)
{
	this->curso = curso;
}

void Grupo::setHorario(Horario* horario)
{
	this->horario = horario;
}

bool Grupo::setProfesor(Profesor* profesor)
{
	this->profesor = profesor;
	return true;
}

std::string Grupo::toString() const
{
	std::stringstream s;

	s << "Periodo: " << periodo << std::endl
		<< this->curso->toString()
		<< "IdGrupo: " << IdGrupo << std::endl
		<< "Cupo: " << cupo << std::endl
		<< "Cantidad de Estudiantes: " << cantidadEstudiantes << std::endl
		<< "Horario: " << horario->toString() << std::endl;
	if (profesor != nullptr)
	{
		s << "Profesor: " << profesor->toString() << std::endl;
	}
	else
	{
		s << "Profesor: " << "No asignado" << std::endl;
	}
	s << "Estudiantes: " << std::endl;
	if (estudiantes != nullptr)
	{
		s << estudiantes->toString()<<std::endl;
	}
	else
	{
		s << "No hay estudiantes asignados" << std::endl;
	}
	return s.str();
}

bool Grupo::insertarEstudiante(Estudiante* estudiante) {
	if (cantidadEstudiantes < cupo) {
		// Verificamos si el estudiante ya está en el grupo para evitar duplicados
		if (estudiantes->buscarElemento(estudiante->getId()) == nullptr) {
			if (estudiantes->insertar(estudiante)) {
			cantidadEstudiantes++;
			return true;
			}
		}
		else {
			// El estudiante ya está en el grupo
			return false;
		}
	}
	// El grupo está lleno
	return false;
}


bool Grupo::eliminarEstudiante(std::string id) {
	if (cantidadEstudiantes > 0) {
		if (estudiantes->eliminar(id)) {  // Solo reducir cantidad si se eliminó exitosamente
			cantidadEstudiantes--;
			return true;
		}
	}
	return false;
}

std::string Grupo::toStringPeriodos(Lista<Grupo>* lista)
{
	std::stringstream s;
	for (int i = 0; i < CANTIDAD_PERIODOS; i++)
	{
		s << std::endl << periodos[i] << duracion[i] << std::endl;
		lista->setActual(lista->getPrimero());

		// Verificación de la existencia de elementos en la lista
		if (lista->getPrimero() == nullptr) {
			s << "No hay grupos registrados en la lista." << std::endl;
			continue;  // Pasa al siguiente periodo si la lista está vacía
		}

		int contadorGrupos = 0;  // Contador de grupos por periodo
		while (lista->getActual() != nullptr) {
			if (lista->getActual()->data->getPeriodo() == periodos[i]) {
				s << "------------------------------------------------------------\n";
				s << "Periodo: " << lista->getActual()->data->getPeriodo() << std::endl
					<< lista->getActual()->data->getCurso()->toString()
					<< "IdGrupo: " << lista->getActual()->data->getId() << std::endl
					<< "Cupo: " << lista->getActual()->data->getCupo() << std::endl
					<< "Cantidad de Estudiantes: " << lista->getActual()->data->getCantidadEstudiantes() << std::endl
					<< "Horario: " << lista->getActual()->data->getHorario()->toString() << std::endl;
				if (lista->getActual()->data->getProfesor() != nullptr)
				{
					s << "Profesor: " << lista->getActual()->data->getProfesor()->toString() << std::endl;
				}
				else
				{
					s << "Profesor: " << "No asignado" << std::endl;
				}
				contadorGrupos++;
			}
			lista->setActual(lista->getActual()->next);
		}

		if (contadorGrupos == 0) {
			s << "No se encontraron grupos para el periodo " << periodos[i] << std::endl;
		}
		s << "------------------------------------------------------------\n";
	}
	return s.str();
}

std::string Grupo::toStringBasico(Lista<Grupo>* lista) {
	std::stringstream s;
	lista->setActual(lista->getPrimero());
	while (lista->getActual() != nullptr) {
		s << "Periodo: " << lista->getActual()->data->getPeriodo() << std::endl
			<< lista->getActual()->data->getCurso()->toString()
			<< "IdGrupo: " << lista->getActual()->data->getId() << std::endl
			<< "Cupo: " << lista->getActual()->data->getCupo() << std::endl
			<< "Cantidad de Estudiantes: " << lista->getActual()->data->getCantidadEstudiantes() << std::endl
			<< "Horario: " << lista->getActual()->data->getHorario()->toString() << std::endl;
		if (lista->getActual()->data->getProfesor() != nullptr)
		{
			s << "Profesor: " << lista->getActual()->data->getProfesor()->toString() << std::endl;
		}
		else
		{
			s << "Profesor: " << "No asignado" << std::endl;
		}
	}
	return s.str();
}

std::string Grupo::GruposSinProfesor(Lista<Grupo>* lista) {
	std::stringstream s;

	lista->setActual(lista->getPrimero());
	while (lista->getActual() != nullptr) {
		if (lista->getActual()->data->getProfesor() == nullptr)
		{
			s << "Periodo: " << lista->getActual()->data->getPeriodo() << std::endl
				<< lista->getActual()->data->getCurso()->toString()
				<< "IdGrupo: " << lista->getActual()->data->getId() << std::endl
				<< "Cupo: " << lista->getActual()->data->getCupo() << std::endl
				<< "Cantidad de Estudiantes: " << lista->getActual()->data->getCantidadEstudiantes() << std::endl
				<< "Horario: " << lista->getActual()->data->getHorario()->toString() << std::endl;
		}
		lista->setActual(lista->getActual()->next);
	}
	return s.str();
}

std::string Grupo::GruposConProfesor(Lista<Grupo>* lista) {
	std::stringstream s;
	lista->setActual(lista->getPrimero());
	while (lista->getActual() != nullptr) {
		if (lista->getActual()->data->getProfesor() != nullptr)
		{
			s << "Periodo: " << lista->getActual()->data->getPeriodo() << std::endl
				<< lista->getActual()->data->getCurso()->toString()
				<< "IdGrupo: " << lista->getActual()->data->getId() << std::endl
				<< "Cupo: " << lista->getActual()->data->getCupo() << std::endl
				<< "Cantidad de Estudiantes: " << lista->getActual()->data->getCantidadEstudiantes() << std::endl
				<< "Horario: " << lista->getActual()->data->getHorario()->toString() << std::endl
				<< "Profesor: " << lista->getActual()->data->getProfesor()->toString() << std::endl;
		}
		lista->setActual(lista->getActual()->next);
	}
	return s.str();
}
void Grupo::guardar(std::ostream& salida) const
{
	// Escribir los datos del grupo
	salida << periodo << "\t"
		<< curso->getNombre() << "\t"
		<< curso->getId() << "\t"
		<< curso->getHoras() << "\t"
		<< curso->getPrecio() << "\t"
		<< curso->getEstado() << "\t"
		<< IdGrupo << "\t";
	if (profesor != nullptr)
	{
		salida << profesor->getNombre() << "\t"
			<< profesor->getId() << "\t"
			<< profesor->getTelefono() << "\t"
			<< profesor->getEmail() << "\t"
			<< profesor->getGradoAcademico() << "\t"
			<< horario->getHoraInicio() << "\t"
			<< horario->getHoraFinaliza() << "\t"
			<< horario->getDia1() << "\t"
			<< horario->getDia2() << "\n";
	}
	else {
		salida<<"\t" << "\t" << "\t" << "\t" << "\t" 
			<< horario->getHoraInicio() << "\t"
			<< horario->getHoraFinaliza() << "\t"
			<< horario->getDia1() << "\t"
			<< horario->getDia2() << "\n";
	}
}

Grupo* Grupo::leer(std::istream& entrada)
{
    std::string periodo, nombreCurso, idCurso, IdGrupo, horasCurso, precioCurso, horaInicio, horaFinal, dia1, dia2;
    bool estado;
    Profesor* profesor = nullptr;
    std::string nombre, cedula, telefono, email, gradoAcademico;
    Horario* horario = nullptr;
    Curso* curso = nullptr;

    // Leer los datos del grupo
    std::getline(entrada, periodo, '\t');
    std::getline(entrada, nombreCurso, '\t');
    std::getline(entrada, idCurso, '\t');
    std::getline(entrada, horasCurso, '\t');
    std::getline(entrada, precioCurso, '\t');
    entrada >> estado;  // Leer estado como booleano
    entrada.ignore();    // Ignorar el salto de línea que sigue al estado

    // Validación del curso
	if (stoi(horasCurso) < 1 || stod(precioCurso) < 1) {
		return nullptr;
	}
    if (!nombreCurso.empty() && !idCurso.empty() && !horasCurso.empty() && !precioCurso.empty()) {
            curso = new Curso(nombreCurso, idCurso, stoi(horasCurso), std::stod(precioCurso), estado);
    } else {
        return nullptr;
    }
    std::getline(entrada, IdGrupo, '\t');
    std::getline(entrada, nombre, '\t');
    std::getline(entrada, cedula, '\t');  // Parece ser un error de lectura duplicada
    std::getline(entrada, telefono, '\t');
    std::getline(entrada, email, '\t');
    std::getline(entrada, gradoAcademico, '\t');

    // Validación del profesor
    if (!nombre.empty() && !cedula.empty() && !telefono.empty() && !email.empty() && !gradoAcademico.empty()) {
        profesor = new Profesor(nombre, cedula, telefono, email, gradoAcademico);
    }

    // Leer el horario
    std::getline(entrada, horaInicio, '\t');
    std::getline(entrada, horaFinal, '\t');
    std::getline(entrada, dia1, '\t');
    std::getline(entrada, dia2, '\n');

    // Validación del horario
	if (std::stoi(horaInicio) < 0 || std::stoi(horaInicio) >23 || (stoi(horaFinal) < 0 || stoi(horaFinal) > 23))
	{
		return nullptr;
	}
    if (!horaInicio.empty() && !horaFinal.empty() && !dia1.empty() && !dia2.empty()) {
            horario = new Horario(std::stoi(horaInicio), std::stoi(horaFinal), dia1, dia2);

    } else {
        return nullptr;
    }

    // Crear y retornar el Grupo
    if (!periodo.empty() && curso != nullptr && !IdGrupo.empty() && horario != nullptr) {
        if (profesor != nullptr) {
            return new Grupo(periodo, curso, IdGrupo, horario, profesor);
        } else {
            return new Grupo(periodo, curso, IdGrupo, horario);
        }
    } else {
        return nullptr;
    }
}