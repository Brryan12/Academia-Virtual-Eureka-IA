#include "Estudiante.h"
#include "Grupo.h"

Estudiante::Estudiante() : Persona(), especialidad(""), listaGrupo(nullptr) {}

Estudiante::Estudiante(std::string nombre, std::string cedula, std::string telefono, std::string email, std::string especialidad) : Persona(nombre, cedula, telefono, email), especialidad(especialidad), listaGrupo(new Lista<Grupo>) {}

Estudiante::~Estudiante()
{
	if (listaGrupo != nullptr)
		delete listaGrupo;
}

std::string Estudiante::getEspecialidad() const
{
	return especialidad;
}

Lista<Grupo>* Estudiante::getListaGrupo() const
{
	return listaGrupo;
}

void Estudiante::setEspecialidad(std::string especialidad)
{
	this->especialidad = especialidad;
}

void Estudiante::setListaGrupo(Lista<Grupo>* listaGrupo)
{
	this->listaGrupo = listaGrupo;
}

std::string Estudiante::toString() const
{
	std::stringstream s;
	s << Persona::toString()
		<< "Especialidad: " << especialidad << std::endl;
	return s.str();
}

bool Estudiante::insertarGrupo(Grupo* grupoAux)
{
	bool puedeInsertar = true;
	this->listaGrupo->setActual(listaGrupo->getPrimero());
	while (this->listaGrupo->getActual() != nullptr)
	{
		if (this->getListaGrupo()->getActual()->data->getId() == grupoAux->getId()) {
			puedeInsertar = false;
			break;
		}
		if (this->listaGrupo->getActual()->data->getCurso() == grupoAux->getCurso()) {
			if (this->listaGrupo->getActual()->data->getPeriodo() == grupoAux->getPeriodo()) {
				puedeInsertar = false;
				break;
			}
		}
		else if (this->listaGrupo->getActual()->data->getPeriodo() == grupoAux->getPeriodo() 
			&& this->getListaGrupo()->getActual()->data->getHorario()->compararHorarios(grupoAux->getHorario())) {
			puedeInsertar = false;
			break;
		}
		this->getListaGrupo()->setActual(this->getListaGrupo()->getActual()->next);
	}
	return puedeInsertar;
}

bool Estudiante::eliminarGrupo(std::string id)
{
	return this->listaGrupo->eliminar(id);
}

void Estudiante::guardar(std::ostream& salida) const 
{

}

Estudiante* Estudiante::leer(std::istream& entrada)
{
	std::string nombre, cedula, telefono, email, especialidad;
	getline(entrada, nombre, '\t');
	getline(entrada, cedula, '\t');
	getline(entrada, telefono, '\t');
	getline(entrada, email, '\t');
	getline(entrada, especialidad, '\n');
	if (nombre.empty() || cedula.empty() || telefono.empty() || email.empty() || especialidad.empty())
	{
		return nullptr;
	}
	return new Estudiante(nombre, cedula, telefono, email, especialidad);
}
