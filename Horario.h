#pragma once
#include <iostream>
#include <sstream>

class Horario
{
private:
	int horaInicio;
	int horaFinaliza;
	std::string dia1;
	std::string dia2;
	
	static std::string toStringDias();
public:
	Horario() = default;
	Horario(int horaInicio, int horaFinaliza, std::string dia1, std::string dia2 );
	~Horario();
	int getHoraInicio() const;
	int getHoraFinaliza() const;
	std::string getDia1() const;
	std::string getDia2() const;
	void setHoraInicio(int horaInicio);
	void setHoraFinaliza(int horaFinaliza);
	void setDia1(std::string dia1);
	void setDia2(std::string dia2);

	std::string toString() const;
};

