#include "Horario.h"

Horario::Horario(int horaInicio, int horaFinaliza,std::string dia): horaInicio(horaInicio),horaFinaliza(horaFinaliza), dia(dia){}

Horario::~Horario()
{
}

int Horario::getHoraInicio() const
{
	return horaInicio;
}

int Horario::getHoraFinaliza() const
{
	return horaFinaliza;
}

std::string Horario::getDia() const
{
	return dia;
}

void Horario::setHoraInicio(int horaInicio)
{
	this->horaInicio = horaInicio;
}

void Horario::setHoraFinaliza(int horaFinaliza)
{
	this->horaFinaliza = horaFinaliza;
}

void Horario::setDia(std::string dia)
{
	this->dia = dia;

}

std::string Horario::toString() const
{
	std::stringstream s;
	s << "Hora de inicio: " << horaInicio << std::endl
		<< "Hora de finalizacion: " << horaFinaliza << std::endl
		<< "Dia: " << dia << std::endl;
	return s.str();
}
