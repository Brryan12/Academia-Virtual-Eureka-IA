#pragma once
#include "Constants.h"
#include "Person.h"
#include "List.h"

class Group;
class Student : public Person
{
private:
    /// @brief Student's major
    std::string major;

    /// @brief List of groups the student is enrolled in
    List<Group>* groupList;
public:
    /// @brief Default constructor
    Student();

    /// @brief Constructor with parameters
    /// @param name Student's name
    /// @param id Student's ID
    /// @param phone Student's phone number
    /// @param email Student's email
    /// @param major Student's major
    /// @param groupList List of groups the student is enrolled in
    Student(std::string name, std::string id, std::string phone, std::string email, std::string major);

    /// @brief Destructor
    virtual ~Student();

    /// @brief Gets the student's major
    /// @return Student's major
    std::string getMajor() const;

    /// @brief Gets the list of groups the student is enrolled in
    /// @return List of groups the student is enrolled in
    List<Group>* getGroupList() const;

    /// @brief Sets the student's major
    /// @param major Student's major
    void setMajor(std::string major);

    /// @brief Sets the list of groups the student is enrolled in
    /// @param groupList List of groups the student is enrolled in
    void setGroupList(List<Group>* groupList);

    /// @brief Converts the student's information to a string
    /// @return Student's information in string format
    std::string toString() const override;

    /// @brief Inserts a group into the student's group list
    /// @param groupAux Group to insert
    /// @return True if inserted successfully, false otherwise
    bool insertGroup(Group* groupAux);

    /// @brief Checks if the student has the minimum number of groups per period for a discount
    /// @return True if the student has the minimum number of groups per period, false otherwise
    bool minimumTwoGroupsPerPeriod() const;

    /// @brief Gets the amount to be paid by the student
    /// @return Amount to be paid by the student
    double amountToPay() const;

    /// @brief Gets the information of the courses the student is enrolled in
    /// @return Information of the courses the student is enrolled in
    std::string courseInfo() const;

    /// @brief Removes a group from the student's group list
    /// @param id ID of the group to remove
    /// @return True if removed successfully, false otherwise
    bool removeGroup(std::string id);

    /// @brief Saves the student's information to a file
    /// @param output Output stream where the information will be saved
    void save(std::ostream& output) const;

    /// @brief Reads the student's information from a file
    /// @param input Input stream from which the information will be read
    /// @return Read student
    static Student* read(std::istream& input);
};
