#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Curso {
private:
	/// @brief Nombre del curso
	string nombre;

	/// @brief Identificador del curso
	string id;

	/// @brief Horas del curso
	int horas;

	/// @brief Precio del curso
	double precio;

	/// @brief Estado del curso
	bool estado;
public:
	/// @brief Constructor por defecto
	Curso();

	/// @brief Constructor con parametros
	Curso(string nombre, string id, int horas, double precio, bool estado);

	/// @brief Destructor
	virtual ~Curso();

	/// @brief Devuelve el nombre del curso
	/// @return Nombre del curso
	string getNombre() const;

	/// @brief Devuelve las horas del curso
	/// @return Horas del curso
	int getHoras() const;

	/// @brief Devuelve el identificador del curso
	/// @return Identificador del curso
	string getId() const;

	/// @brief Devuelve el precio del curso
	/// @return Precio del curso
	double getPrecio() const;

	/// @brief Devuelve el estado del curso
	/// @return Estado del curso
	bool getEstado() const;

	/// @brief Establece el nombre del curso
	/// @param nombre Nombre del curso
	void setNombre (string nombre);

	/// @brief Establece las horas del curso
	/// @param horas Horas del curso
	void setHoras (int horas);

	/// @brief Establece el identificador del curso
	/// @param id Identificador del curso
	void setId(string id);

	/// @brief Establece el precio del curso
	/// @param precio Precio del curso
	void setPrecio(double precio);

	/// @brief Establece el estado del curso
	/// @param estado Estado del curso
	void setEstado(bool estado);

	/// @brief Guarda los datos del curso en un archivo
	/// @param salida Archivo donde se guardara la informacion
	void guardar(std::ostream& salida) const;

	/// @brief Lee los datos de un curso de un archivo
	/// @param entrada Archivo del que se leeran los datos
	/// @return Curso leido
	static Curso* leer(std::istream& entrada);

	/// @brief Devuelve los datos del curso en forma de string
	/// @return Datos del curso
	string toString() const;
};
