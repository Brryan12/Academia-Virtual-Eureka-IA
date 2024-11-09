#pragma once
#include <iostream>
constexpr int CANTIDAD_PERIODOS = 4;
constexpr int CANTIDAD_DIAS = 5;
const std::string periodos[CANTIDAD_PERIODOS] = { "Periodo I", "Periodo II", "Periodo III", "Periodo IV" };
const std::string dias[CANTIDAD_DIAS] = { "Lunes", "Martes", "Miércoles", "Jueves", "Viernes" };
const std::string duracion[CANTIDAD_PERIODOS] = { " de enero a marzo", " de a abril a junio", " de julio a setiembre", " de octubre a diciembre" };
constexpr double IVA = 0.13;

#if defined(_WIN64) || defined(_WIN32)
#define cls "cls"
#define pause "pause"

#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#define cls "clear"
#define pause "read -n1 -r -p \"Press any key to continue...\""
#endif