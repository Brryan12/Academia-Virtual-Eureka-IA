#pragma once
#include "Person.h"
#include "List.h"

class Group;
class Professor : public Person
{
private:
    /// @brief Academic degree of the professor
    std::string academicDegree;

    /// @brief List of groups the professor teaches
    List<Group>* groupList;
public:
    /// @brief Default constructor
    Professor();

    /// @brief Constructor with parameters
    /// @param name Professor's name
    /// @param id Professor's ID
    /// @param phone Professor's phone number
    /// @param email Professor's email
    /// @param academicDegree Academic degree of the professor
    Professor(std::string name, std::string id, std::string phone, std::string email, std::string academicDegree);
    
    /// @brief Destructor
    ~Professor();

    /// @brief Gets the academic degree of the professor
    /// @return Academic degree of the professor
    std::string getAcademicDegree() const;

    /// @brief Gets the list of groups the professor teaches
    /// @return List of groups the professor teaches
    List<Group>* getGroupList() const;

    /// @brief Sets the academic degree of the professor
    /// @param academicDegree Academic degree of the professor
    void setAcademicDegree(std::string academicDegree);

    /// @brief Converts the professor's information to a string
    /// @return Professor's information in string format
    std::string toString() const override;

    /// @brief Converts the information of the courses the professor teaches in the periods to a string
    /// @return Information of the courses the professor teaches in the periods in string format
    std::string toStringPeriod() const;

    /// @brief Saves the professor's information to a file
    /// @param output Output stream where the information will be saved
    void save(std::ostream& output) const;

    /// @brief Reads the professor's information from a file
    /// @param input Input stream from which the information will be read
    static Professor* read(std::istream& input);
};
