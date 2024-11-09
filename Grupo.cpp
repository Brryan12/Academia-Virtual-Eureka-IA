#include "Grupo.h"

Grupo::Grupo() : periodo(""), curso(nullptr), IdGrupo(""), cantidadEstudiantes(0), profesor(nullptr), horario(nullptr), estudiantes(nullptr) {}

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
		<< "Curso: " << curso->getNombre() << std::endl
		<< "Precio: " << curso->getPrecio() << std::endl
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

bool Grupo::insertarEstudiante(std::string id)
{
	Estudiante* estudiante = nullptr;
	if (cantidadEstudiantes < cupo)
	{
		estudiante=estudiantes->buscarElemento(id);
		if (estudiante == nullptr)
		{
			return false;
		}
		estudiantes->insertar(estudiante);
		cantidadEstudiantes++;
		return true;
	}
	return false;
}

bool Grupo::eliminarEstudiante(std::string id)
{
	if (cantidadEstudiantes > 0)
	{
		estudiantes->eliminar(id);
		cantidadEstudiantes--;
		return true;
	}
	return false;
}

std::string Grupo::toStringPeriodos(Lista<Grupo>* lista)
{
	std::stringstream s;
	for (int i = 0; i < CANTIDAD_PERIODOS; i++)
	{
		s << std::endl<<periodos[i] << duracion[i]<<std::endl;
		lista->setActual(lista->getPrimero());
		while (lista->getActual() != nullptr) {
			if (lista->getActual()->data->getPeriodo() == periodos[i]) {
				s << "------------------------------------------------------------\n";
				s<< lista->getActual()->data->getCurso()->toString() << std::endl
					<<"Id del grupo: " << lista->getActual()->data->getId() << std::endl;
			}
			lista->setActual(lista->getActual()->next);
		}
		s << "------------------------------------------------------------\n";

	}

	return s.str();
}
std::string Grupo::toStringBasico(Lista<Grupo>* lista){
	std::stringstream s;
	lista->setActual(lista->getPrimero());
	while (lista->getActual() != nullptr){
		s << "Periodo: " << lista->getActual()->data->getPeriodo() << std::endl
			<< "Curso: " << lista->getActual()->data->getCurso()->getNombre() << std::endl
			<< "Precio: " << lista->getActual()->data->getCurso()->getPrecio() << std::endl
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

std::string Grupo::GruposSinProfesor(Lista<Grupo>* lista){
	std::stringstream s;
	
	lista->setActual(lista->getPrimero());
	while (lista->getActual() != nullptr) {
		if (lista->getActual()->data->getProfesor() == nullptr)
		{
			s << "Periodo: " << lista->getActual()->data->getPeriodo() << std::endl
				<< "Curso: " << lista->getActual()->data->getCurso()->getNombre() << std::endl
				<< "Precio: " << lista->getActual()->data->getCurso()->getPrecio() << std::endl
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
				<< "Curso: " << lista->getActual()->data->getCurso()->getNombre() << std::endl
				<< "Precio: " << lista->getActual()->data->getCurso()->getPrecio() << std::endl
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
	salida << periodo << "\t"
		<< curso->getNombre() << "\t"
		<< curso->getId() << "\t"
		<< curso->getHoras() << "\t"
		<< curso->getPrecio() << "\t"
		<< curso->getEstado() << "\t"
		<< IdGrupo << "\t"
		<< horario->getHoraInicio() << "\t"
		<< horario->getHoraFinaliza() << "\t"
		<< horario->getDia1() << "\t";

	if (profesor != nullptr)
	{
		salida << horario->getDia2() << "\t"
			<< profesor->getNombre() << "\t"
			<< profesor->getId() << "\t"
			<< profesor->getTelefono() << "\t"
			<< profesor->getEmail() << "\t"
			<< profesor->getGradoAcademico() << "\n";
	}
	else
		salida << horario->getDia2() << "\n";
}

Grupo* Grupo::leer(std::istream& entrada)
{
	std::string periodo, nombreCurso, idCurso, IdGrupo, horasCurso, precioCurso, horaInicio, HoraFinal, dia1, dia2;
	bool estado;
	Profesor* profesor = nullptr;
	std::string nombre, cedula, telefono, email, gradoAcademico;
	Horario* horario = nullptr;
	Curso* curso = nullptr;
	getline(entrada, periodo, '\t');
	getline(entrada, nombreCurso, '\t');
	getline(entrada, idCurso, '\t');
	getline(entrada, horasCurso, '\t');
	getline(entrada, precioCurso, '\t');
	entrada >> estado;
	if (!nombreCurso.empty() && !idCurso.empty() && !horasCurso.empty() && !precioCurso.empty())
		curso = new Curso(nombreCurso, idCurso, horasCurso, std::stod(precioCurso), estado);
	else
		return nullptr;
	getline(entrada, IdGrupo, '\t');
	getline(entrada, horaInicio, '\t');
	getline(entrada, HoraFinal, '\t');
	getline(entrada, dia1, '\t');
	getline(entrada, dia2, '\n');
	if (!dia2.empty() && !dia1.empty() && !horaInicio.empty() && !HoraFinal.empty())
		horario = new Horario(std::stoi(horaInicio), std::stoi(HoraFinal), dia1, dia2);
	else
		return nullptr;
	getline(entrada, cedula, '\t');
	std::getline(entrada, nombre, '\t');
	std::getline(entrada, cedula, '\t');
	std::getline(entrada, telefono, '\t');
	std::getline(entrada, email, '\t');
	std::getline(entrada, gradoAcademico, '\n');
	if (!nombre.empty() && !cedula.empty() && !telefono.empty() && !email.empty() && !gradoAcademico.empty())
		profesor = new Profesor(nombre, cedula, telefono, email, gradoAcademico);
	else {
		entrada.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	if (!periodo.empty() && curso != nullptr && !IdGrupo.empty() && horario != nullptr) {
		if (profesor != nullptr) {
			return new Grupo(periodo, curso, IdGrupo, horario, profesor);
		}
		else {
			return new Grupo(periodo, curso, IdGrupo, horario);
		}
	}
	else {
		return nullptr;
	}
}
