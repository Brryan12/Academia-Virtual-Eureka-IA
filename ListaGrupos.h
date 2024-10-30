#pragma once
#include "Lista.h"
#include "Grupo.h"

class Grupo;
class ListaGrupos : public Lista<Grupo>
{
public:
	ListaGrupos() = default;
	~ListaGrupos();
	bool agregarGrupo(Grupo* grupo);
	Grupo* buscar(int id);
};

