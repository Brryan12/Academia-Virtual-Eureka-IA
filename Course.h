#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Course {
private:
    /// @brief Name of the course
    string name;

    /// @brief Identifier of the course
    string id;

    /// @brief Hours of the course
    int hours;

    /// @brief Price of the course
    double price;

    /// @brief Status of the course
    bool status;
public:
    /// @brief Default constructor
    Course();

    /// @brief Constructor with parameters
    Course(string name, string id, int hours, double price, bool status);

    /// @brief Destructor
    virtual ~Course();

    /// @brief Returns the name of the course
    /// @return Name of the course
    string getName() const;

    /// @brief Returns the hours of the course
    /// @return Hours of the course
    int getHours() const;

    /// @brief Returns the identifier of the course
    /// @return Identifier of the course
    string getId() const;

    /// @brief Returns the price of the course
    /// @return Price of the course
    double getPrice() const;

    /// @brief Returns the status of the course
    /// @return Status of the course
    bool getStatus() const;

    /// @brief Sets the name of the course
    /// @param name Name of the course
    void setName(string name);

    /// @brief Sets the hours of the course
    /// @param hours Hours of the course
    void setHours(int hours);

    /// @brief Sets the identifier of the course
    /// @param id Identifier of the course
    void setId(string id);

    /// @brief Sets the price of the course
    /// @param price Price of the course
    void setPrice(double price);

    /// @brief Sets the status of the course
    /// @param status Status of the course
    void setStatus(bool status);

    /// @brief Saves the course data to a file
    /// @param output File where the information will be saved
    void save(std::ostream& output) const;

    /// @brief Reads the course data from a file
    /// @param input File from which the data will be read
    /// @return Read course
    static Course* read(std::istream& input);

    /// @brief Returns the course data as a string
    /// @return Course data
    string toString() const;
};
