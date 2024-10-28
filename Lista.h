#pragma once
template <typename Datatype>
class Lista
{
private:
	struct Node
	{
		Node* next;
		Datatype* data;
	};
	Node* primero;
	Node* actual;
public:
	Lista() = default;
	virtual ~Lista();
	bool insertar(Datatype* data);
	bool eliminar(Datatype* data);
	Datatype* buscar(Datatype* data);

};

template<typename Datatype>
inline Lista<Datatype>::~Lista()
{
	Node* actual = primero;
	while (actual != nullptr)
	{
		primero = primero->next;
		delete actual;
		actual = primero;
	}
}

template<typename Datatype>
inline bool Lista<Datatype>::insertar(Datatype* data)
{
	actual = primero;
	if (primero == nullptr)
	{
		primero = new Node(data, nullptr);
		return true;
	}
	else
	{
		while (actual->next != nullptr)
		{
			actual = actual->next;
		}
		actual->next = new Node{ data, nullptr };
		return true;
	}
	return false;
}

template<typename Datatype>
inline bool Lista<Datatype>::eliminar(Datatype* data)
{
	//actual = primero;
	//node* anterior = nullptr;

	////lista vacia
	//if (actual == nullptr) {
	//	return false;
	//}

	////recorrer lista
	//while (actual != nullptr && actual->perso.getId() != id) {
	//	anterior = actual;
	//	actual = actual->next;
	//}

	////Nunca encontro el nodo
	//if (actual == nullptr) {
	//	return false;
	//}

	////Caso si el primero es el que se quiere eliminar
	//if (anterior == nullptr) {
	//	primero = actual->siguiente;
	//}

	////caso donde es x nodo
	//else {
	//	anterior->siguiente = actual->siguiente;
	//}
	//delete actual;
	//return true;
}

template<typename Datatype>
inline Datatype* Lista<Datatype>::buscar(Datatype* data)
{
	return nullptr;
}
