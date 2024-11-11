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
	Factura(Estudiante* estudiante);
	virtual ~Factura();
	double montoPagar();
	bool descuentoPeriodo();
	bool descuentoAnual();
	double descuento();
	std::string factura();
};

