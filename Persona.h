#pragma once
#include <iostream>
#include <sstream>
class Persona{
protected:
	std::string nombre;
	std::string cedula;
	std::string telefono;
	std::string email;
public:
	Persona();
	Persona(std::string nombre, std::string cedula, std::string telefono, std::string email);
	virtual ~Persona();
	std::string getNombre();
	std::string getCedula();
	std::string getTelefono();
	std::string getEmail();
	void setNombre(std::string nombre);
	void setCedula(std::string cedula);
	void setTelefono(std::string telefono);
	void setEmail(std::string email);
	virtual std::string toString() const;
};

