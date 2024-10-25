#include "Grupo.h"

Grupo::Grupo(int IdGrupo, int cupo, int cantidadEstudiantes, Horario* horario) : IdGrupo(IdGrupo), cupo(cupo), cantidadEstudiantes(cantidadEstudiantes), horario(horario) {}

Grupo::~Grupo()
{
}

int Grupo::getIdGrupo() const
{
	return IdGrupo;
}

int Grupo::getCupo() const
{
	return cupo;
}

int Grupo::getCantidadEstudiantes() const
{
	return cantidadEstudiantes;
}

Horario* Grupo::getHorario() const
{
	return horario;
}

Profesor* Grupo::getProfesor() const
{
	return profesor;
}

void Grupo::setIdGrupo(int IdGrupo)
{
	this->IdGrupo = IdGrupo;
}

void Grupo::setCupo(int cupo)
{
	this->cupo = cupo;
}

void Grupo::setCantidadEstudiantes(int cantidadEstudiantes)
{
	this->cantidadEstudiantes = cantidadEstudiantes;
}

void Grupo::setHorario(Horario* horario)
{
	this->horario = horario;
}

void Grupo::setProfesor(Profesor* profesor)
{
	this->profesor = profesor;

}

std::string Grupo::toString() const
{
	std::stringstream s;
	s << "IdGrupo: " << IdGrupo << std::endl
		<< "Cupo: " << cupo << std::endl
		<< "Cantidad de Estudiantes: " << cantidadEstudiantes << std::endl
		<< "Horario: " << horario << std::endl;
	if (profesor != nullptr)
	{
		s << "Profesor: " << profesor->getNombre() << std::endl;
	}
	else
	{
		s << "Profesor: " << "No asignado" << std::endl;
	}
	return s.str();
}