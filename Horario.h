#pragma once
#include <iostream>
#include <sstream>

class Horario
{
private:

	/// @brief Hora de inicio de la clase
	int horaInicio;

	/// @brief Hora de finalizacion de la clase
	int horaFinaliza;

	/// @brief Dia de la semana en que se imparte la clase
	std::string dia1;

	/// @brief Dia de la semana en que se imparte la clase
	std::string dia2;
public:

	/// @brief Constructor por defecto de la clase Horario
	Horario();

	/// @brief Constructor de la clase Horario
	/// @param horaInicio Hora de inicio de la clase
	/// @param horaFinaliza Hora de finalizacion de la clase
	/// @param dia1 Dia de la semana en que se imparte la clase
	/// @param dia2 Dia de la semana en que se imparte la clase
	Horario(int horaInicio, int horaFinaliza, std::string dia1, std::string dia2 );

	/// @brief Destructor de la clase Horario
	~Horario();

	/// @brief Obtener la hora de inicio de la clase
	/// @return Hora de inicio de la clase
	int getHoraInicio() const;

	/// @brief Obtener la hora de finalizacion de la clase
	/// @return Hora de finalizacion de la clase
	int getHoraFinaliza() const;
	
	/// @brief Obtener el dia de la semana en que se imparte la clase
	/// @return Dia de la semana en que se imparte la clase
	std::string getDia1() const;

	/// @brief Obtener el dia de la semana en que se imparte la clase
	/// @return Dia de la semana en que se imparte la clase
	std::string getDia2() const;

	/// @brief Establecer la hora de inicio de la clase
	/// @param horaInicio Hora de inicio de la clase
	void setHoraInicio(int horaInicio);

	/// @brief Establecer la hora de finalizacion de la clase
	/// @param horaFinaliza Hora de finalizacion de la clase
	void setHoraFinaliza(int horaFinaliza);

	/// @brief Establecer el dia de la semana en que se imparte la clase
	/// @param dia1 Dia de la semana en que se imparte la clase
	void setDia1(std::string dia1);

	/// @brief Establecer el dia de la semana en que se imparte la clase
	/// @param dia2 Dia de la semana en que se imparte la clase
	void setDia2(std::string dia2);

	/// @brief Comparar si dos horarios chocan
	/// @param h Horario con el que se desea comparar
	/// @return false si no chocan y true si chocan
	bool compararHorarios(Horario* h);

	/// @brief Guarda la informacion del horario en un archivo
	/// @param salida Flujo de salida donde se guardara la informacion
	void guardar(std::ostream& salida) const;

	/// @brief Lee la informacion del horario de un archivo
	/// @param entrada Flujo de entrada de donde se leera la informacion
	static Horario* leer(std::istream& entrada);
	
	/// @brief Metodo que retorna un string con la informacion del horario
	/// @return string con la informacion del horario
	std::string toString() const;
};

