#pragma once
#include "Lista.h"
class Estudiante;
class ListaEst : public Lista<Estudiante>
{
public:
	ListaEst() = default;
	~ListaEst();
	Estudiante* buscar(int id);
};

