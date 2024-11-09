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
		s << periodos[i] << duracion[i];
		this->listaGrupo->setActual(this->listaGrupo->getPrimero());
		while (this->listaGrupo->getActual() != nullptr) {
			if (this->listaGrupo->getActual()->data->getPeriodo() == periodos[i]) {
				s << this->listaGrupo->getActual()->data->getCurso() << std::endl
					<< this->listaGrupo->getActual()->data->getId() << std::endl;
			}
			this->listaGrupo->setActual(this->listaGrupo->getActual()->next);
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
