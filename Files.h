#pragma once
#include "List.h"
#include "Group.h"    
#include "Student.h"
class Files
{
private:
    /// @brief Input file
    ifstream input;

    /// @brief Output file
    ofstream output;
public:
    /// @brief Save students to their respective file
    /// @param studentList A list of students
    void saveStudents(List<Student>* studentList);

    /// @brief Save professors to their respective file
    /// @param professorList A list of professors
    void saveProfessors(List<Professor>* professorList);

    /// @brief Save courses to their respective file
    /// @param courseList A list of courses
    void saveCourses(List<Course>* courseList);

    /// @brief Save groups to their respective file
    /// @param groupList A list of groups
    void saveGroups(List<Group>* groupList);

    /// @brief Load students from their respective file
    /// @return A list of students
    List<Student>* loadStudents();

    /// @brief Load professors from their respective file
    /// @return A list of professors
    List<Professor>* loadProfessors();

    /// @brief Load courses from their respective file
    /// @return A list of courses
    List<Course>* loadCourses();

    /// @brief Load groups from their respective file
    /// @return A list of groups
    List<Group>* loadGroups();
};
