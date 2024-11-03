#include "Horario.h"

std::string Horario::toStringDias()
{
	return std::string();
}

Horario::Horario(int horaInicio, int horaFinaliza,std::string dia1, std::string dia2): horaInicio(horaInicio),horaFinaliza(horaFinaliza), dia1(dia1), dia2(dia2){}

Horario::~Horario(){}

int Horario::getHoraInicio() const
{
	return horaInicio;
}

int Horario::getHoraFinaliza() const
{
	return horaFinaliza;
}

std::string Horario::getDia1() const
{
	return dia1;
}

std::string Horario::getDia2() const
{
	return dia2;
}

void Horario::setHoraInicio(int horaInicio)
{
	this->horaInicio = horaInicio;
}

void Horario::setHoraFinaliza(int horaFinaliza)
{
	this->horaFinaliza = horaFinaliza;
}

void Horario::setDia1(std::string dia1)
{
	this->dia1 = dia1;

}

void Horario::setDia2(std::string dia2)
{
	this->dia2 = dia2;
}

std::string Horario::toString() const
{
	std::stringstream s;
	s << "Hora de inicio: " << horaInicio << std::endl
		<< "Hora de finalizacion: " << horaFinaliza << std::endl
		<< "1° Dia: " << dia1 << std::endl
		<< "2° Dia: " << dia2 << std::endl;
	return s.str();
}
