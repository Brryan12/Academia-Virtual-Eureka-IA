#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Curso {
private:
	string nombre;
	string id;
	string horas;
	double precio;
	bool estado;
public:
	Curso();
	Curso(string nombre, string id, string horas, double precio, bool estado);
	virtual ~Curso();
	string getNombre() const;
	string getHoras() const;
	string getId() const;
	double getPrecio() const;
	bool getEstado() const;
	void setNombre (string nombre);
	void setHoras (string horas);
	void setId(string id);
	void setPrecio(double precio);
	void setEstado(bool estado);
	void guardar(std::ostream& salida) const;
	static Curso* leer(std::istream& entrada);
	string toString() const;
};
