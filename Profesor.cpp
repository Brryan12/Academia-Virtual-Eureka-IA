#include "Profesor.h"
#include "Grupo.h"

Profesor::Profesor() : Persona(), gradoAcademico(""), listaGrupo(nullptr) {}

Profesor::Profesor(std::string nombre, std::string cedula, std::string telefono, std::string email, std::string gradoAcademico) : Persona(nombre, cedula, telefono, email), gradoAcademico(gradoAcademico), listaGrupo(new Lista<Grupo>) {}

Profesor::~Profesor()
{
}

std::string Profesor::getGradoAcademico() const
{
	return gradoAcademico;
}
Lista<Grupo>* Profesor::getListaGrupo() const
{
	return listaGrupo;
}

void Profesor::setGradoAcademico(std::string gradoAcademico)
{
	this->gradoAcademico = gradoAcademico;
}

std::string Profesor::toString() const
{
	std::stringstream s;
	s << Persona::toString()
		<< "Grado Academico: " << gradoAcademico << std::endl;
	return s.str();
}

std::string Profesor::toStringPeriodo() const
{
	std::stringstream s;
	for (int i = 0; i < CANTIDAD_PERIODOS; i++)
	{
		int contador = 0;
		s << periodos[i] << duracion[i]<<std::endl;
		this->listaGrupo->setActual(this->listaGrupo->getPrimero());
		while (this->listaGrupo->getActual() != nullptr) {
			if (this->listaGrupo->getActual()->data->getPeriodo() == periodos[i]) {

				s << "Nombre del curso:"
					<< this->listaGrupo->getActual()->data->getCurso()->getNombre() << std::endl
					<< "ID del curso: "
					<< this->listaGrupo->getActual()->data->getCurso()->getId() << std::endl
					<< "ID del grupo: "
					<< this->listaGrupo->getActual()->data->getId() << std::endl;
				contador++;
			}
			this->listaGrupo->setActual(this->listaGrupo->getActual()->next);
		}
		if (contador == 0) {
			s << "\nNo se encontraron grupos para el periodo " << periodos[i] << std::endl;

		}
	}
	return s.str();
}

void Profesor::guardar(std::ostream& salida) const
{
	salida << nombre << "\t"
		<< cedula << "\t"
		<< telefono << "\t"
		<< email << "\t"
		<< gradoAcademico << "\n";
}

Profesor* Profesor::leer(std::istream& entrada)
{
	Profesor* profesor = nullptr;
	std::string nombre, cedula, telefono, email, gradoAcademico;
	if (entrada)
	{
		std::getline(entrada, nombre, '\t');
		std::getline(entrada, cedula, '\t');
		std::getline(entrada, telefono, '\t');
		std::getline(entrada, email, '\t');
		std::getline(entrada, gradoAcademico, '\n');
	}
	if (!nombre.empty() && !cedula.empty() && !telefono.empty() && !email.empty() && !gradoAcademico.empty()){
		profesor = new Profesor(nombre, cedula, telefono, email, gradoAcademico);
	}
	return profesor;
}
