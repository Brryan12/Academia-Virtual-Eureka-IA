#pragma once
#include <iostream>

/// @brief Cantidad de periodos disponibles
constexpr int CANTIDAD_PERIODOS = 4;

/// @brief Cantidad de dias disponibles
constexpr int CANTIDAD_DIAS = 5;

/// @brief Nombre de los periodos respectivos
const std::string periodos[CANTIDAD_PERIODOS] = { "Periodo I", "Periodo II", "Periodo III", "Periodo IV" };

/// @brief Nombre de los dias trabajados
const std::string dias[CANTIDAD_DIAS] = { "Lunes", "Martes", "Miércoles", "Jueves", "Viernes" };

/// @brief Duracion de los periodos
const std::string duracion[CANTIDAD_PERIODOS] = { " de enero a marzo", " de a abril a junio", " de julio a setiembre", " de octubre a diciembre" };

/// @brief IVA actual
constexpr double IVA = 0.13;

/// @brief Constante para limpiar la pantalla y pausar si esta en windows o UNIX
#if defined(_WIN64) || defined(_WIN32)
#define cls "cls"
#define pause "pause"

#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#define cls "clear"
#define pause "read -n1 -r -p \"Press any key to continue...\""
#endif