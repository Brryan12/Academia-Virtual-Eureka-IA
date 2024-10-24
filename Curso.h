#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Curso {
protected:
	string nombre;
	string id;
	string horas;
	double precio;
	bool estado;
public:
	Curso();
	Curso(string nombre, string id, string horas, double precio, bool estado);
	virtual ~Curso();
	string getNombre();
	string gethora();
	string getid();
	double getprecio();
	bool getestado();
	void setNombre (string nombre);
	void sethora (string horas);
	void setid(string id);
	void setprecio(double precio);
	void setestado(bool estado);
	virtual string toString() const;
};
