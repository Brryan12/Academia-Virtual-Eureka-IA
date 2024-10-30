#include "Grupo.h"

Grupo::Grupo(Curso* curso, int IdGrupo, int cantidadEstudiantes, Horario* horario) : IdGrupo(IdGrupo), cantidadEstudiantes(cantidadEstudiantes), horario(horario), curso(curso){
	profesor = nullptr;
	Lista<Estudiante>* estudiantes = new Lista<Estudiante>();
}

Grupo::~Grupo()
{

	delete horario;
	delete curso;
	delete profesor;
	if (estudiantes != NULL)
		delete estudiantes;
}

int Grupo::getIdGrupo() const
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

void Grupo::setIdGrupo(int IdGrupo)
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
	s << "Estudiantes: " << std::endl;
	if (estudiantes != NULL)
	{
		s << estudiantes->toString()<<std::endl;
	}
	else
	{
		s << "No hay estudiantes" << std::endl;
	}
	return s.str();
}

bool Grupo::insertarEstudiante(Estudiante* estudiante)
{
	return false;
}

bool Grupo::eliminarEstudiante(Estudiante* estudiante)
{
	return false;
}

void Grupo::guardarConEstudiantes(std::ostream& salida) const
{
	salida << IdGrupo << "\t"
		<< cantidadEstudiantes << "\t"
		<< horario->toString() << "\t";
	if (profesor != nullptr)
	{
		salida << profesor->getNombre()  + " " + profesor->getCedula() << "\t";
	}
	else
	{
		salida << "No asignado" << std::endl;
	}
	if (estudiantes != NULL)
	{
		salida << estudiantes->guardarEnArchivo(salida) << std::endl;
	}
	else
	{
		salida << "No hay estudiantes" << std::endl;
	}
}

void Grupo::leerConEstudiantes(std::istream& entrada)
{
}
