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
    std::string toString() const;
    bool guardarEnArchivo(const std::string& nombreArchivo) const;
    Datatype* leerDeArchivo(const std::string& nombreArchivo);
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
        actual->next = new Node(data, nullptr);
        return true;
    }
    return false;
}
template<typename Datatype>
inline std::string Lista<Datatype>::toString() const {
    Node* actual = primero;
    std::stringstream s;
    while (actual != nullptr)
    {
        s << actual->data->toString() << std::endl;
        actual = actual->next;
    }
    return s.str();
}

// Método para guardar en archivo
template<typename Datatype>
bool Lista<Datatype>::guardarEnArchivo(const std::string& nombreArchivo) const {
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        return false;
    }

    Node* actual = primero;
    while (actual != nullptr) {
        archivo << actual->data->toString() << std::endl;  // Convierte cada objeto a una línea
        actual = actual->next;
    }

    archivo.close();
    return true;
}

// Método para leer desde archivo
template<typename Datatype>
Datatype* Lista<Datatype>::leerDeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        return false;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        Datatype* nuevoDato = new Datatype();
        if (!nuevoDato->fromString(linea)) {  // Debes implementar fromString en cada clase
            delete nuevoDato;
            continue;
        }
        insertar(nuevoDato);
    }

    archivo.close();
    return true;
}