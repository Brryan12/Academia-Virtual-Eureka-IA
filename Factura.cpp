#include "Factura.h"

Factura::Factura(Estudiante* estudiante): estudiante(estudiante){}

Factura::~Factura()
{
	delete estudiante;
}

double Factura::montoPagar()
{
	return estudiante->montoPagar() - this->descuento();
    
}

bool Factura::descuentoPeriodo()
{
    return estudiante->minimoDosGrupoPorPeriodo();
}

bool Factura::descuentoAnual()
{
    return estudiante->getListaGrupo()->cantidadElementos()>3 ;
}

double Factura::descuento()
{
	if (this->descuentoPeriodo() && this->descuentoAnual())
	{
		return estudiante->montoPagar()* 0.3625;
	}
	else if (this->descuentoPeriodo())
	{
		return estudiante->montoPagar() * 0.15;
	}
	else if (this->descuentoAnual())
	{
		return estudiante->montoPagar() * 0.25;
	}
	else
	{
		return 0.0;
	}
}

std::string Factura::factura()
{
	std::stringstream s;
	s << "Nombre: " << estudiante->getNombre() << std::endl;
	s << "Cedula: " << estudiante->getId() << std::endl;
	s << estudiante->infoCursos() << std::endl;
	s << "Subtotal: " << estudiante->montoPagar() << std::endl;
	s << "IVA: " << estudiante->montoPagar() * IVA << std::endl;
	s << "Descuento: " << this->descuento() << std::endl;
	s << "Descuentos aplicados: ";
	if (this->descuentoPeriodo())
	{
		s << "Descuento por tener mas de un grupo en un periodo" << std::endl;
	}
	if (this->descuentoAnual())
	{
		s << "Descuento por tener mas de 3 grupos en un anio" << std::endl;
	}
	s << "Total: " << this->montoPagar() << std::endl;

    return s.str();
}
