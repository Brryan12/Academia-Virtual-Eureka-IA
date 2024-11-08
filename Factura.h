#pragma once
#include "Estudiante.h"
class Factura
{
private:
	Estudiante* estudiante;
public:
	Factura(Estudiante* estudiante);
	virtual ~Factura();
	double montoPagar();
	bool descuentoPeriodo();
	bool descuentoAnual();
	double descuento();
	std::string factura();
};

