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
public:
	Horario();
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

	/// @brief Comparar si dos horarios chocan
	/// @param h Horario con el que se desea comparar
	/// @return false si no chocan y true si chocan
	bool compararHorarios(Horario* h);
	void guardar(std::ostream& salida) const;
	static Horario* leer(std::istream& entrada);
	std::string toString() const;
};

