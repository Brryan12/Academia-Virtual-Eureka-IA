#pragma once
#include <iostream>
#include <sstream>

class Schedule
{
private:
    /// @brief Start time of the class
    int startTime;

    /// @brief End time of the class
    int endTime;

    /// @brief Day of the week the class is held
    std::string day1;

    /// @brief Day of the week the class is held
    std::string day2;
public:
    /// @brief Default constructor of the Schedule class
    Schedule();

    /// @brief Constructor of the Schedule class
    /// @param startTime Start time of the class
    /// @param endTime End time of the class
    /// @param day1 Day of the week the class is held
    /// @param day2 Day of the week the class is held
    Schedule(int startTime, int endTime, std::string day1, std::string day2);

    /// @brief Destructor of the Schedule class
    ~Schedule();

    /// @brief Get the start time of the class
    /// @return Start time of the class
    int getStartTime() const;

    /// @brief Get the end time of the class
    /// @return End time of the class
    int getEndTime() const;
    
    /// @brief Get the day of the week the class is held
    /// @return Day of the week the class is held
    std::string getDay1() const;

    /// @brief Get the day of the week the class is held
    /// @return Day of the week the class is held
    std::string getDay2() const;

    /// @brief Set the start time of the class
    /// @param startTime Start time of the class
    void setStartTime(int startTime);

    /// @brief Set the end time of the class
    /// @param endTime End time of the class
    void setEndTime(int endTime);

    /// @brief Set the day of the week the class is held
    /// @param day1 Day of the week the class is held
    void setDay1(std::string day1);

    /// @brief Set the day of the week the class is held
    /// @param day2 Day of the week the class is held
    void setDay2(std::string day2);

    /// @brief Compare if two schedules conflict
    /// @param s Schedule to compare with
    /// @return false if they do not conflict, true if they conflict
    bool compareSchedules(Schedule* s);

    /// @brief Save the schedule information to a file
    /// @param output Output stream where the information will be saved
    void save(std::ostream& output) const;

    /// @brief Read the schedule information from a file
    /// @param input Input stream from which the information will be read
    static Schedule* read(std::istream& input);
    
    /// @brief Method that returns a string with the schedule information
    /// @return string with the schedule information
    std::string toString() const;
};
