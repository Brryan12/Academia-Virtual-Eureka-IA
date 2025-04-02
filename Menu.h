#pragma once
#include "Group.h"
#include "List.h"
#include "Invoice.h"
#include "Files.h"

class Menu {
public:
    /// @brief Returns the selected option in the main menu
    /// @return selected option
    static int mainMenu();

    /// @brief Returns the selected option in the administration submenu
    /// @return selected option
    static int administrationSubmenu();

    /// @brief Returns the selected option in the enrollment submenu
    /// @return selected option
    static int enrollmentSubmenu();

    /// @brief Returns the selected option in the search and reports submenu
    /// @return selected option
    static int searchAndReportsSubmenu();

    /// @brief Method to save data to files
    /// @param professorList List of professors
    /// @param studentList List of students
    /// @param courseList List of courses
    /// @param groupList List of groups
    static void saveDataToFiles(List<Professor>* professorList, List<Student>* studentList, List<Course>* courseList, List<Group>* groupList);

    /// @brief Prints the default error message
    static void defaultSwitch();

    /// @brief Prints the return to main menu message
    static void returnToMainMenu();

    /// @brief Prints the menu to add a professor
    /// @param professorList list of professors
    static void addProfessor(List<Professor>* professorList);

    /// @brief Prints the menu to add a student
    /// @param studentList list of students
    static void addStudent(List<Student>* studentList);

    /// @brief Prints the menu to add a course
    /// @param courseList list of courses
    static void addCourse(List<Course>* courseList);

    /// @brief Prints the menu to add a group
    /// @param groupList list of groups
    /// @param courseList list of courses
    static void addGroup(List<Group>* groupList, List<Course>* courseList);

    /// @brief Prints the menu to assign a professor to a group
    /// @param groupList list of groups
    /// @param professorList list of professors
    static void assignProfessorToGroup(List<Group>* groupList, List<Professor>* professorList);

    /// @brief Prints the menu to enroll a student
    /// @param groupList list of groups
    /// @param studentList list of students
    static void enrollStudent(List<Group>* groupList, List<Student>* studentList);

    /// @brief Prints the menu to unenroll a student
    /// @param groupList list of groups
    /// @param studentList list of students
    static void unenrollStudent(List<Group>* groupList, List<Student>* studentList);

    /// @brief Prints the menu to generate an invoice
    /// @param studentList list of students
    static void generateInvoice(List<Student>* studentList);

    /// @brief Prints the report of all registered professors
    /// @param professorList list of professors
    static void registeredProfessorsReport(List<Professor>* professorList);

    /// @brief Prints the report of all registered students
    /// @param studentList list of students
    static void registeredStudentsReport(List<Student>* studentList);

    /// @brief Prints the report of the groups enrolled by a student
    /// @param groupList list of groups
    /// @param studentList list of students
    static void coursesEnrolledByStudentReport(List<Group>* groupList, List<Student>* studentList);

    /// @brief Prints the report of the groups assigned to a specific professor
    /// @param professorList list of professors
    static void specificProfessorReport(List<Professor>* professorList);

    /// @brief Prints the report of the groups by period
    /// @param groupList list of groups
    /// @param courseList list of courses
    static void enabledPeriodsForYearReport(List<Group>* groupList, List<Course>* courseList);

    /// @brief Prints the report of a specific group
    /// @param groupList list of groups
    /// @param courseList list of courses
    static void specificGroupReport(List<Group>* groupList, List<Course>* courseList);
};
