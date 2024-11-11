#pragma once
#include <iostream>
#include <sstream>
class Persona{
protected:

	/// @brief Nombre de la persona
	std::string nombre;

	/// @brief Cedula de la persona
	std::string cedula;

	/// @brief Telefono de la persona
	std::string telefono;

	/// @brief Email de la persona
	std::string email;
public:

	/// @brief Constructor por defecto de la clase Persona
	Persona();

	/// @brief Constructor de la clase Persona
	/// @param nombre Nombre de la persona
	/// @param cedula Cedula de la persona
	/// @param telefono Telefono de la persona
	/// @param email Email de la persona
	Persona(std::string nombre, std::string cedula, std::string telefono, std::string email);

	/// @brief Destructor de la clase Persona
	virtual ~Persona();

	/// @brief Obtener el nombre de la persona
	/// @return Nombre de la persona
	std::string getNombre() const;

	/// @brief Obtener la cedula de la persona
	/// @return Cedula de la persona
	std::string getId() const;

	/// @brief Obtener el telefono de la persona
	/// @return Telefono de la persona
	std::string getTelefono() const;

	/// @brief Obtener el email de la persona
	/// @return Email de la persona
	std::string getEmail() const;

	/// @brief Establecer el nombre de la persona
	/// @param nombre Nombre de la persona
	void setNombre(std::string nombre);

	/// @brief Establecer la cedula de la persona
	/// @param cedula Cedula de la persona
	void setCedula(std::string cedula);

	/// @brief Establecer el telefono de la persona
	/// @param telefono Telefono de la persona
	void setTelefono(std::string telefono);

	/// @brief Establecer el email de la persona
	/// @param email Email de la persona
	void setEmail(std::string email);

	/// @brief Metodo que retorna un string con la informacion de la persona
	/// @return Informacion de la persona
	virtual std::string toString() const;
};

