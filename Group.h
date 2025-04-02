#pragma once
#include "Professor.h"
#include "Schedule.h"
#include "Course.h"
#include "List.h"
#include "Student.h"
#include "Constants.h"

class Group
{
private:
    /// @brief Period in which the group is taught
    std::string period;

    /// @brief Course taught in the group
    Course* course;

    /// @brief Group identifier
    std::string groupId;

    /// @brief Fixed number of students per group
    const int capacity = 30;

    /// @brief Number of students enrolled in the group
    int studentCount;

    /// @brief Schedule in which the group is taught
    Schedule* schedule;

    /// @brief Professor teaching the group
    Professor* professor;

    /// @brief List of students enrolled in the group
    List<Student>* students;
public:
    /// @brief Default constructor
    Group();

    /// @brief Constructor with parameters
    /// @param period Period in which the group is taught
    /// @param course Course taught in the group
    /// @param groupId Group identifier
    /// @param schedule Schedule in which the group is taught
    Group(std::string period, Course* course, std::string groupId, Schedule* schedule);

    /// @brief Constructor with parameters
    /// @param period Period in which the group is taught
    /// @param course Course taught in the group
    /// @param groupId Group identifier
    /// @param schedule Schedule in which the group is taught
    /// @param professor Professor teaching the group
    Group(std::string period, Course* course, std::string groupId, Schedule* schedule, Professor* professor);

    /// @brief Destructor
    virtual ~Group();

    /// @brief Gets the fixed number of students per group
    /// @return Fixed number of students per group
    int getCapacity() const;

    /// @brief Gets the period in which the group is taught
    /// @return Period in which the group is taught
    std::string getPeriod() const;

    /// @brief Gets the group identifier
    /// @return Group identifier
    std::string getId() const;

    /// @brief Gets the number of students enrolled in the group
    /// @return Number of students enrolled in the group
    int getStudentCount() const;

    /// @brief Gets the course taught in the group
    /// @return Course taught in the group
    Course* getCourse() const;

    /// @brief Gets the schedule in which the group is taught
    /// @return Schedule in which the group is taught
    Schedule* getSchedule() const;

    /// @brief Gets the professor teaching the group
    /// @return Professor teaching the group
    Professor* getProfessor() const;

    /// @brief Sets the period in which the group is taught
    /// @param period Period in which the group is taught
    void setPeriod(std::string period);

    /// @brief Sets the group identifier
    /// @param groupId Group identifier
    void setGroupId(std::string groupId);

    /// @brief Sets the number of students enrolled in the group
    /// @param studentCount Number of students enrolled in the group
    void setStudentCount(int studentCount);

    /// @brief Sets the course taught in the group
    /// @param course Course taught in the group
    void setCourse(Course* course);

    /// @brief Sets the schedule in which the group is taught
    /// @param schedule Schedule in which the group is taught
    void setSchedule(Schedule* schedule);

    /// @brief Sets the professor teaching the group
    /// @param professor Professor teaching the group
    /// @return True if set correctly, false otherwise
    bool setProfessor(Professor* professor);

    /// @brief Converts the group's information to a string
    std::string toString() const;

    /// @brief Inserts a student into the group's student list
    /// @param student Student to insert
    /// @return True if inserted correctly, false otherwise
    bool insertStudent(Student* student);

    /// @brief Removes a student from the group's student list
    /// @param id Identifier of the student to remove
    /// @return True if removed correctly, false otherwise
    bool removeStudent(std::string id);

    /// @brief Prints the information of the groups separated by period
    /// @param list List of Groups
    /// @return Information of the groups separated by period
    static std::string toStringPeriods(List<Group>* list);

    /// @brief Prints the basic information of the groups
    /// @param list List of Groups
    /// @return Basic information of the groups
    static std::string toStringBasic(List<Group>* list);

    /// @brief Prints the information of the groups without a professor
    /// @param list List of Groups
    /// @return Information of the groups without a professor
    static std::string groupsWithoutProfessor(List<Group>* list);

    /// @brief Prints the information of the groups with a professor
    /// @param list List of Groups
    /// @return Information of the groups with a professor
    static std::string groupsWithProfessor(List<Group>* list);

    /// @brief Saves the group's information to a file
    /// @param output Output stream where the information will be saved
    void save(std::ostream& output) const;

    /// @brief Reads the group's information from a file
    /// @param input Input stream from which the information will be read
    /// @return Read group
    static Group* read(std::istream& input);
};
