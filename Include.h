#pragma once
#include "Menu.h"
#include "Constants.h"

/// @brief Function that displays the main menu of the program
void showMenu() {
    int op, op1, op2, op3;
    Files* files = new Files();
    List<Professor>* professorList = files->loadProfessors();
    List<Course>* courseList = files->loadCourses();
    List<Group>* groupList = files->loadGroups();
    List<Student>* studentList = files->loadStudents();
    do {
        op = Menu::mainMenu();
        switch (op)
        {
        case 1:
            do {
                op1 = Menu::administrationSubmenu();

                switch (op1)
                {
                case 1:
                    Menu::addProfessor(professorList);
                    break;

                case 2:
                    Menu::addStudent(studentList);
                    break;

                case 3:
                    Menu::addCourse(courseList);
                    break;

                case 4:
                    Menu::addGroup(groupList, courseList);
                    break;

                case 5:
                    Menu::assignProfessorToGroup(groupList, professorList);
                    break;

                case 0:
                    Menu::returnToMainMenu();
                    break;

                default:
                    Menu::defaultSwitch();
                    break;
                }
            } while (op1 != 0);
            break;

        case 2:
            do {
                op2 = Menu::enrollmentSubmenu();
                switch (op2)
                {
                case 1:
                    Menu::enrollStudent(groupList, studentList);
                    break;

                case 2:
                    Menu::unenrollStudent(groupList, studentList);
                    break;
                case 3:
                    Menu::generateInvoice(studentList);
                    break;
                case 0:
                    Menu::returnToMainMenu();
                    break;

                default:
                    Menu::defaultSwitch();
                    break;
                }
            } while (op2 != 0);
            break;

        case 3:
            do {
                op3 = Menu::searchAndReportsSubmenu();

                switch (op3)
                {
                case 1:
                    Menu::registeredProfessorsReport(professorList);
                    break;

                case 2:
                    Menu::registeredStudentsReport(studentList);
                    break;
                case 3:
                    Menu::coursesEnrolledByStudentReport(groupList, studentList);
                    break;

                case 4:
                    Menu::specificProfessorReport(professorList);
                    break;

                case 5:
                    Menu::enabledPeriodsForYearReport(groupList, courseList);
                    break;

                case 6:
                    Menu::specificGroupReport(groupList, courseList);
                    break;

                case 0:
                    Menu::returnToMainMenu();
                    break;

                default:
                    Menu::defaultSwitch();
                    break;
                }
            } while (op3 != 0);
            break;

        case 4:
            Menu::saveDataToFiles(professorList, studentList, courseList, groupList);
            break;

        case 5:
            system(cls);
            std::cout << "Exiting the program..." << std::endl;
            system(pause);
            break;

        default:
            Menu::defaultSwitch();
            break;
        }
    } while (op != 5);

    delete studentList;
    delete groupList;
    delete courseList;
    delete professorList;
    delete files;
}
