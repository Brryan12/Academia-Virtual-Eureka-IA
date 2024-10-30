#include "ListaGrupos.h"

ListaGrupos::~ListaGrupos()
{
}

Grupo* ListaGrupos::buscar(int id)
{
	actual = primero;
	while (actual != nullptr)
	{
		if (actual->data->getIdGrupo()==id)
		{
			return actual->data;
		}
		actual = actual->next;
	}
	return nullptr;
}

bool ListaGrupos::agregarGrupo(Grupo* grupo)
{
	actual = primero;
	if (primero == nullptr) //Si la lista esta vacia, inserta el grupo
	{
		this->insertar(grupo);
		return true;
	}
	else {
		while (actual != nullptr)
		{
			if (actual->data->getCurso()->getId() == grupo->getCurso()->getId())
			{
				return false;
			}
			actual = actual->next;
		}
		this->insertar(grupo);
		return true;
	}
    return false;
}
