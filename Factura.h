#pragma once
#include "Estudiante.h"
class Factura
{
private:
	/// @brief Estudiante al que se le va a generar la factura
	Estudiante* estudiante;
public:
	/// @brief Constructor por defecto
	Factura();

	/// @brief Constructor con parametros
	/// @param estudiante Estudiante al que se le va a generar la factura
	Factura(Estudiante* estudiante);

	/// @brief Destructor
	virtual ~Factura();

	/// @brief Calcula el monto a pagar por el estudiante
	/// @return Monto a pagar por el estudiante
	double montoPagar();

	/// @brief Verifica si el estudiante tiene descuento por tener mas de x grupos en un periodo
	/// @return true si tiene descuento, false si no tiene descuento
	bool descuentoPeriodo();

	/// @brief Verifica si el estudiante tiene descuento por tener x cantidad de grupos en un anio
	/// @return true si tiene descuento, false si no tiene descuento
	bool descuentoAnual();

	/// @brief Calcula el descuento que se le va a aplicar al estudiante
	/// @return Descuento a aplicar al estudiante
	double descuento();

	/// @brief Genera la factura del estudiante
	/// @return Factura del estudiante
	std::string factura();
};

