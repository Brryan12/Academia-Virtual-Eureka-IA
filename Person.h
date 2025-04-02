#pragma once
#include <iostream>
#include <sstream>

class Person {
protected:
    /// @brief Name of the person
    std::string name;

    /// @brief ID of the person
    std::string id;

    /// @brief Phone number of the person
    std::string phone;

    /// @brief Email of the person
    std::string email;
public:
    /// @brief Default constructor of the Person class
    Person();

    /// @brief Constructor of the Person class
    /// @param name Name of the person
    /// @param id ID of the person
    /// @param phone Phone number of the person
    /// @param email Email of the person
    Person(std::string name, std::string id, std::string phone, std::string email);

    /// @brief Destructor of the Person class
    virtual ~Person();

    /// @brief Get the name of the person
    /// @return Name of the person
    std::string getName() const;

    /// @brief Get the ID of the person
    /// @return ID of the person
    std::string getId() const;

    /// @brief Get the phone number of the person
    /// @return Phone number of the person
    std::string getPhone() const;

    /// @brief Get the email of the person
    /// @return Email of the person
    std::string getEmail() const;

    /// @brief Set the name of the person
    /// @param name Name of the person
    void setName(std::string name);

    /// @brief Set the ID of the person
    /// @param id ID of the person
    void setId(std::string id);

    /// @brief Set the phone number of the person
    /// @param phone Phone number of the person
    void setPhone(std::string phone);

    /// @brief Set the email of the person
    /// @param email Email of the person
    void setEmail(std::string email);

    /// @brief Method that returns a string with the person's information
    /// @return Person's information
    virtual std::string toString() const;
};
