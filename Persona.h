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
	Persona()=default;
	Persona(std::string nombre, std::string cedula, std::string telefono, std::string email);
	virtual ~Persona();
	std::string getNombre() const;
	std::string getCedula() const;
	std::string getTelefono() const;
	std::string getEmail() const;
	void setNombre(std::string nombre);
	void setCedula(std::string cedula);
	void setTelefono(std::string telefono);
	void setEmail(std::string email);
	virtual std::string toString() const;
};

