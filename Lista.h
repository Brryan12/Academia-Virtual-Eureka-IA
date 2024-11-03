#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

template <typename Datatype>
class Lista
{
protected:
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
    bool yaExisteElemento(std::string id);
	Datatype* buscarElemento(std::string id);
    std::string toString() const;
    bool guardarEnArchivo(std::ostream& salida) const;
    Datatype* leerDeArchivo(std::istream& entrada);
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
		if (this->yaExisteElemento(data->getId()) == false){
            actual->next = new Node(data, nullptr);
            return true;
        }
    }
    return false;
}
template<typename Datatype>
inline bool Lista<Datatype>::yaExisteElemento(std::string id)
{
    actual = primero;
    while (actual != nullptr) {
        if (actual->data->getId() == id) {
            return true;
        }
		actual = actual->next;
    }
    return false;
}
template<typename Datatype>
inline Datatype* Lista<Datatype>::buscarElemento(std::string id)
{
	actual = primero;
	if (!yaExisteElemento(id)) {
		return nullptr;
	}
	while (actual != nullptr) {
		if (actual->data->getId() == id) {
			return actual->data;
		}
		actual = actual->next;
	}
    return nullptr;
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
    if (!salida) {
        return false;
    }

    Node* actual = primero;
    while (actual != nullptr) {
        salida << actual->data->toString() << std::endl;  // Convierte cada objeto a una línea
        actual = actual->next;
    }

    return true;
}

// Método para leer desde archivo
template<typename Datatype>
Datatype* Lista<Datatype>::leerDeArchivo(std::istream& entrada) {
    if (!entrada) {
        std::cerr << "Error al abrir archivo de lectura" << std::endl;
        return nullptr;
    }

    std::string linea;
    while (std::getline(entrada, linea)) {
        Datatype* nuevoDato = new Datatype();
        if (!nuevoDato->fromString(linea)) {  // Debes implementar fromString en cada clase
            delete nuevoDato;
            continue;
        }
        insertar(nuevoDato);
    }


}