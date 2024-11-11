#pragma once
#include "Constantes.h"
#include "Persona.h"
#include "Lista.h"

class Grupo;
class Estudiante : public Persona
{
private:
	/// @brief Especialidad del estudiante
	std::string especialidad;

	/// @brief Lista de grupos en los que esta inscrito el estudiante
	Lista<Grupo>* listaGrupo;
public:
	/// @brief Constructor por defecto
	Estudiante();

	/// @brief Constructor con parametros
	/// @param nombre Nombre del estudiante
	/// @param cedula Cedula del estudiante
	/// @param telefono Telefono del estudiante
	/// @param email Email del estudiante
	/// @param especialidad Especialidad del estudiante
	/// @param listaGrupo Lista de grupos en los que esta inscrito el estudiante
	Estudiante(std::string nombre, std::string cedula, std::string telefono, std::string email, std::string especialidad);

	/// @brief Destructor
	virtual ~Estudiante();

	/// @brief Obtiene la especialidad del estudiante
	/// @return Especialidad del estudiante
	std::string getEspecialidad() const;

	/// @brief Obtiene la lista de grupos en los que esta inscrito el estudiante
	/// @return Lista de grupos en los que esta inscrito el estudiante
	Lista<Grupo>* getListaGrupo() const;

	/// @brief Establece la especialidad del estudiante
	/// @param especialidad Especialidad del estudiante
	void setEspecialidad(std::string especialidad);

	/// @brief Establece la lista de grupos en los que esta inscrito el estudiante
	/// @param listaGrupo Lista de grupos en los que esta inscrito el estudiante
	void setListaGrupo(Lista<Grupo>* listaGrupo);

	/// @brief Convierte la informacion del estudiante en un string
	/// @return Informacion del estudiante en formato string
	std::string toString() const override;

	/// @brief Inserta un grupo en la lista de grupos del estudiante
	/// @param grupoAux Grupo a insertar
	/// @return True si se inserto correctamente, false en caso contrario
	bool insertarGrupo(Grupo* grupoAux);

	/// @brief Verifica si el estudiante tiene el minimo de grupos por periodo para el descuento
	/// @return True si tiene el minimo de grupos por periodo, false en caso contrario
	bool minimoDosGrupoPorPeriodo() const;

	/// @brief Obtiene el monto a pagar por el estudiante
	/// @return Monto a pagar por el estudiante
	double montoPagar() const;

	/// @brief Obtiene la informacion de los cursos en los que esta inscrito el estudiante
	/// @return Informacion de los cursos en los que esta inscrito el estudiante
	std::string infoCursos() const;

	/// @brief Elimina un grupo de la lista de grupos del estudiante
	/// @param id ID del grupo a eliminar
	/// @return True si se elimino correctamente, false en caso contrario
	bool eliminarGrupo(std::string id);

	/// @brief Guarda la informacion del estudiante en un archivo
	/// @param salida Flujo de salida donde se guardara la informacion
	void guardar(std::ostream& salida) const;

	/// @brief Lee la informacion del estudiante de un archivo
	/// @param entrada Flujo de entrada de donde se leera la informacion
	/// @return Estudiante leido
	static Estudiante* leer(std::istream& entrada);
};

