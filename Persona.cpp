#include "Persona.h"

Persona::Persona() : nombre(""), cedula(""), telefono(""), email(""){}

Persona::Persona(std::string nombre, std::string cedula, std::string telefono, std::string email): nombre(nombre), cedula(cedula), telefono(telefono), email(email){}

Persona::~Persona()
{
}

std::string Persona::getNombre() const
{
    return nombre;
}

std::string Persona::getId() const
{
    return cedula;
}

std::string Persona::getTelefono() const
{
    return telefono;
}

std::string Persona::getEmail() const
{
    return email;
}

void Persona::setNombre(std::string nombre)
{
	this->nombre = nombre;
}

void Persona::setCedula(std::string cedula)
{
	this->cedula = cedula;
}

void Persona::setTelefono(std::string telefono)
{
	this->telefono = telefono;
}

void Persona::setEmail(std::string email)
{
	this->email = email;

}

std::string Persona::toString() const
{
	std::stringstream s;
	s << "Nombre: " << nombre << std::endl
		<< "Cedula: " << cedula << std::endl
		<< "Telefono: " << telefono << std::endl
		<< "Email: " << email << std::endl;
    return s.str();
}
