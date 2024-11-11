#pragma once
#include "Persona.h"
#include "Lista.h"

class Grupo;
class Profesor : public Persona
{
private:

	/// @brief Grado academico del profesor
	std::string gradoAcademico;

	/// @brief Lista de grupos en los que el profesor es profesor
	Lista<Grupo>* listaGrupo;
public:

	/// @brief Constructor por defecto
	Profesor();

	/// @brief Constructor con parametros
	/// @param nombre Nombre del profesor
	/// @param cedula Cedula del profesor
	/// @param telefono Telefono del profesor
	/// @param email Email del profesor
	/// @param gradoAcademico Grado academico del profesor
	Profesor(std::string nombre, std::string cedula, std::string telefono, std::string email, std::string gradoAcademico);
	
	/// @brief Destructor
	~Profesor();

	/// @brief Obtiene el grado academico del profesor
	/// @return Grado academico del profesor
	std::string getGradoAcademico() const;

	/// @brief Obtiene la lista de grupos en los que el profesor es profesor
	/// @return Lista de grupos en los que el profesor es profesor
	Lista<Grupo>* getListaGrupo() const;

	/// @brief Establece el grado academico del profesor
	/// @param gradoAcademico Grado academico del profesor
	void setGradoAcademico(std::string gradoAcademico);

	/// @brief Convierte la informacion del profesor en un string
	/// @return Informacion del profesor en formato string
	std::string toString() const override;

	/// @brief Convierte la informacion de los cursos que el profesor da en los periodos en un string
	/// @return Informacion de los cursos que el profesor da en los periodos en formato string
	std::string toStringPeriodo() const;

	/// @brief Guarda la informacion del profesor en un archivo
	/// @param salida Flujo de salida donde se guardara la informacion
	void guardar(std::ostream& salida) const;

	/// @brief Lee la informacion del profesor de un archivo
	/// @param entrada Flujo de entrada de donde se leera la informacion
	static Profesor* leer(std::istream& entrada);
};

