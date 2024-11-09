#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

template <typename Datatype>
class Lista
{
private:
    struct Node
    {
        Node* next;
        Datatype* data;
        Node(Datatype* data, Node* next) : data(data), next(next) {}
    };
    Node* primero;
    Node* actual;
public:
	Lista() : primero(nullptr), actual(nullptr) {}
    virtual ~Lista();
    bool insertar(Datatype* data);
    bool eliminar(std::string id);
	Datatype* buscarElemento(std::string id);
    std::string toString() const;

	/// @brief Metodo que verifica si la lista esta vacia
	/// @return false si la lista no esta vacia, true si la lista esta vacia
	bool vacio() const { return primero == nullptr; }
	Node* getPrimero() const { return primero; }
	Node* getActual() const { return actual; }
	void setPrimero(Node* primero) { this->primero = primero; }
	int cantidadElementos() const {
		int cant = 0;
		Node* actual = primero;
		while (actual != nullptr) {
			cant++;
			actual = actual->next;
		}
		return cant;
	}
	void setActual(Node* actual) { this->actual = actual; }
    bool guardarEnArchivo(std::ostream& salida) const;
    //Datatype* leerDeArchivo(std::istream& entrada);
};

template<typename Datatype>
inline Lista<Datatype>::~Lista()
{
    Node* actual = primero;
    while (actual != nullptr)
    {
        primero = primero->next;
        delete actual->data;
        delete actual;
        actual = primero;
    }
}

template<typename Datatype>
inline bool Lista<Datatype>::insertar(Datatype* data)
{
    if (this->buscarElemento(data->getId()) != nullptr) {
        // Si el elemento ya existe, no se inserta y retorna false
        return false;
    }
    actual = new Node(data, nullptr);
    actual->next = primero;
    primero = actual;
    return true;
}
template<typename Datatype>
inline bool Lista<Datatype>::eliminar(std::string id)
{
    actual = primero;
    Node* anterior = nullptr;

    //lista vacia
    if (actual == nullptr) {
        return false;
    }

    //recorrer lista
    while (actual != nullptr && actual->data->getId() != id) {
        anterior = actual;
        actual = actual->next;
    }

    //Nunca encontro el nodo
    if (actual == nullptr) {
        return false;
    }

    //Caso si el primero es el que se quiere eliminar
    if (anterior == nullptr) {
        primero = actual->next;
    }

    //caso donde es x nodo
    else {
        anterior->next = actual->next;
    }
    delete actual;
    return true;
}

template<typename Datatype>
inline Datatype* Lista<Datatype>::buscarElemento(std::string id)
{
	actual = primero;
    if (actual == nullptr) {
        return nullptr;
    }
    while (actual != nullptr && actual->data->getId() != id) {
        actual=actual->next;
    }
	if (actual == nullptr) {
		return nullptr;
	}
    return actual->data;
}

template<typename Datatype>
inline std::string Lista<Datatype>::toString() const {
	std::stringstream ss;
	Node* actual = primero;
	while (actual != nullptr) {
		ss << actual->data->toString() << std::endl;
		actual = actual->next;
	}
	return ss.str();
}

// Método para guardar en archivo
template<typename Datatype>
bool Lista<Datatype>::guardarEnArchivo(std::ostream& salida) const {
    Node* actual = primero;
    while (actual != nullptr) {
        actual->data->guardar(salida);  
        actual = actual->next;
    }

    return true;
}
