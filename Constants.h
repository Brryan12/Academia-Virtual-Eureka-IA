#pragma once
#include <iostream>

/// @brief Number of available periods
constexpr int NUMBER_OF_PERIODS = 4;

/// @brief Number of available days
constexpr int NUMBER_OF_DAYS = 5;

/// @brief Names of the respective periods
const std::string periods[NUMBER_OF_PERIODS] = { "Period I", "Period II", "Period III", "Period IV" };

/// @brief Names of the working days
const std::string days[NUMBER_OF_DAYS] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

/// @brief Duration of the periods
const std::string duration[NUMBER_OF_PERIODS] = { " from January to March", " from April to June", " from July to September", " from October to December" };

/// @brief Current VAT
constexpr double VAT = 0.13;

/// @brief Constant to clear the screen and pause if on Windows or UNIX
#if defined(_WIN64) || defined(_WIN32)
#define cls "cls"
#define pause "pause"

#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#define cls "clear"
#define pause "read -n1 -r -p \"Press any key to continue...\""
#endif
