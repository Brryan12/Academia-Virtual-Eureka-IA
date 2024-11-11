#include "Horario.h"

Horario::Horario() : horaInicio(0), horaFinaliza(0), dia1(""), dia2("") {}

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

bool Horario::compararHorarios(Horario* h)
{
	if (this->dia1 == h->getDia1() || this->dia2 == h->getDia2())
		return (this->horaFinaliza > h->getHoraInicio());

	return false;
}

void Horario::guardar(std::ostream& salida) const
{
	salida << horaInicio << "\t"
		<< horaFinaliza << "\t"
		<< dia1 << "\t"
		<< dia2 << "\n";
}

Horario* Horario::leer(std::istream& entrada)
{
	std::string dia1, dia2, horaInicio, horaFinaliza;
	entrada >> horaInicio >> horaFinaliza >> dia1 >> dia2;
	if (std::stoi(horaInicio) < 0 || std::stoi(horaFinaliza) < 0)
	{
		return nullptr;
	}
	if (horaInicio.empty() && horaFinaliza.empty() && dia1.empty() && dia2.empty())
	{
		return nullptr;
	}
	return new Horario(std::stoi(horaInicio), std::stoi(horaFinaliza), dia1, dia2);
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
