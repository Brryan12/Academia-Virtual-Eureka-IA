#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

template <typename Datatype>
class Lista
{
private:

	/// @brief Nodo de la lista
    struct Node
    {
		/// @brief  Dato almacenado en el nodo
        Datatype* data;

		/// @brief Puntero al siguiente nodo
        Node* next;

		/// @brief Constructor de la clase Node
		/// @param data Dato a almacenar en el nodo
		/// @param next Puntero al siguiente nodo
        Node(Datatype* data, Node* next) : data(data), next(next) {}
    };

	/// @brief Puntero al primer nodo de la lista
    Node* primero;

	/// @brief Puntero al nodo actual de la lista   
    Node* actual;
public:
	/// @brief Constructor de la clase Lista
	Lista() : primero(nullptr), actual(nullptr) {}

	/// @brief Destructor de la clase Lista
    virtual ~Lista();

	/// @brief Metodo para insertar un elemento en la lista
	/// @param data Dato a insertar en la lista
	/// @return false si el elemento ya existe, true si se inserto correctamente
    bool insertar(Datatype* data);

	/// @brief Metodo para eliminar un elemento de la lista
	/// @param id Identificador del elemento a eliminar
	/// @return false si el elemento no existe, true si se elimino correctamente
    bool eliminar(std::string id);

	/// @brief Metodo para buscar un elemento en la lista
	/// @param id Identificador del elemento a buscar
	/// @return Puntero al elemento si se encontro, nullptr si no se encontro
	Datatype* buscarElemento(std::string id);

	/// @brief Metodo para convertir la lista en un string
	/// @return String con los elementos de la lista
    std::string toString() const;

	/// @brief Metodo que verifica si la lista esta vacia
	/// @return false si la lista no esta vacia, true si la lista esta vacia
	bool vacio() const { return primero == nullptr; }

	/// @brief Metodo que retorna el primer nodo de la lista
	/// @return el primer nodo de la lista
	Node* getPrimero() const { return primero; }

	/// @brief Metodo que retorna el nodo actual de la lista
	/// @return el nodo actual de la lista
	Node* getActual() const { return actual; }

	/// @brief Metodo que setea el primer nodo de la lista
	/// @param primero Puntero al primer nodo de la lista
	void setPrimero(Node* primero) { this->primero = primero; }

	/// @brief Metodo que retorna la cantidad de elementos de la lista
	int cantidadElementos() const {
		int cant = 0;
		Node* actual = primero;
		while (actual != nullptr) {
			cant++;
			actual = actual->next;
		}
		return cant;
	}

	/// @brief Metodo que setea el nodo actual de la lista
	/// @param actual Puntero al nodo actual de la lista
	void setActual(Node* actual) { this->actual = actual; }

	/// @brief Metodo para guardar en archivo
	/// @param salida Flujo de salida
    bool guardarEnArchivo(std::ostream& salida) const;
};

template<typename Datatype>
inline Lista<Datatype>::~Lista() {
    Node* actual = primero;
    while (actual != nullptr) {
        Node* siguiente = actual->next; // Guardamos el siguiente nodo antes de eliminar el actual
        delete actual->data;            // Eliminamos el dato solo si estamos seguros de que Lista es el único dueño
        delete actual;                  // Eliminamos el nodo actual
        actual = siguiente;             // Pasamos al siguiente nodo
    }
    primero = nullptr; // Aseguramos que primero esté en nullptr al final
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
inline bool Lista<Datatype>::eliminar(std::string id) {
    actual = primero;
    Node* anterior = nullptr;

    // lista vacía
    if (actual == nullptr) {
        std::cout << "vacio" << std::endl;
        return false;

    }

    // recorrer lista
    while (actual != nullptr && actual->data->getId() != id) {
        anterior = actual;
        actual = actual->next;
    }

    // no encontró el nodo
    if (actual == nullptr) {
        std::cout << "no me encontre" << std::endl;
        return false;
    }

    // si el primero es el que se quiere eliminar
    if (anterior == nullptr) {
        primero = actual->next;
    }
    // si es otro nodo
    else {
        anterior->next = actual->next;
    }

    // liberar memoria y evitar referencias colgantes
    delete actual;
    actual = nullptr;

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
