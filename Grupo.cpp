#include "Grupo.h"

Grupo::Grupo() : periodo(""), curso(nullptr), IdGrupo(""), cantidadEstudiantes(0), profesor(nullptr), horario(nullptr), estudiantes(nullptr) {}

Grupo::Grupo(std::string periodo, Curso* curso, std::string IdGrupo, Horario* horario) : periodo(periodo), curso(curso), IdGrupo(IdGrupo), cantidadEstudiantes(0), profesor(nullptr), horario(horario), estudiantes(new Lista<Estudiante>()) {}

Grupo::~Grupo()
{

	delete horario;
	delete curso;
	delete profesor;
	if (estudiantes != nullptr)
		delete estudiantes;
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

void Grupo::guardarConEstudiantes(std::ostream& salida) const
{

}

void Grupo::leerConEstudiantes(std::istream& entrada)
{
}

std::string Grupo::toStringPeriodos(Lista<Grupo>* lista) const
{
	std::stringstream s;
	for (int i = 0; i < CANTIDAD_PERIODOS; i++)
	{
		s << periodos[i] << duracion[i];
		lista->setActual(lista->getPrimero());
		while (lista->getActual() != nullptr) {
			if (lista->getActual()->data->getPeriodo() == periodos[i]) {
				s << lista->getActual()->data->getCurso() << std::endl
					<< lista->getActual()->data->getId() << std::endl;
			}
			lista->setActual(lista->getActual()->next);
		}
	}
	return s.str();
}
	std::string Grupo::toStringBasico() const {

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
		return s.str();
}