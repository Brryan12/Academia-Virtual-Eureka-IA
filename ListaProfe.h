#pragma once
#include "Profesor.h"
#include "Lista.h"
class ListaProfe : public Lista<Profesor>
{
public:
	ListaProfe() = default;
	~ListaProfe();
	Profesor* buscar(int id);
};

