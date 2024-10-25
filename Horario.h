#pragma once
#include <iostream>
#include <sstream>
class Horario
{
private:
	int horaInicio;
	int horaFinaliza;
	std::string dia;
public:
	Horario() = default;
	Horario(int horaInicio, int horaFinaliza, std::string dia);
	~Horario();
	int getHoraInicio() const;
	int getHoraFinaliza() const;
	std::string getDia() const;
	void setHoraInicio(int horaInicio);
	void setHoraFinaliza(int horaFinaliza);
	void setDia(std::string dia);
	std::string toString() const;
};

