#include "Files.h"

void Files::saveStudents(List<Student>* studentList)
{
    output.open("Files/Students.txt");
    if (output.good()) {
        studentList->saveToFile(output);
    }
    else {
        std::cerr << "Error opening the file" << std::endl;
        system(pause);
        return;
    }
    output.close();
}

void Files::saveProfessors(List<Professor>* professorList)
{
    output.open("Files/Professors.txt");
    if (output.good()) {
        professorList->saveToFile(output);
    }
    else {
        std::cerr << "Error opening the file" << std::endl;
        system(pause);
        return;
    }
    output.close();
}

void Files::saveCourses(List<Course>* courseList)
{
    output.open("Files/Courses.txt");
    if (output.good()) {
        courseList->saveToFile(output);
    }
    else {
        std::cerr << "Error opening the file" << std::endl;
        system(pause);
        return;
    }
    output.close();
}

void Files::saveGroups(List<Group>* groupList)
{
    output.open("Files/Groups.txt");
    if (output.good()) {
        groupList->saveToFile(output);
    }
    else {
        std::cerr << "Error opening the file" << std::endl;
        system(pause);
        return;
    }
    output.close();
}

List<Student>* Files::loadStudents()
{
    List<Student>* studentList = new List<Student>();
    Student* student = nullptr;
    input.open("Files/Students.txt");
    if (input.good()) {
        while (!input.eof()) {
            student = Student::read(input);
            if (student != nullptr) {
                studentList->insert(student);
            }
        }
    }
    input.close();
    return studentList;
}

List<Professor>* Files::loadProfessors()
{
    List<Professor>* professorList = new List<Professor>();
    Professor* professor = nullptr;
    input.open("Files/Professors.txt");
    if (input.good()) {
        while (!input.eof()) {
            professor = Professor::read(input);
            if (professor != nullptr) {
                professorList->insert(professor);
            }
        }
    }
    input.close();
    return professorList;
}

List<Course>* Files::loadCourses()
{
    List<Course>* courseList = new List<Course>();
    Course* course = nullptr;
    input.open("Files/Courses.txt");
    if (input.good()) {
        while (!input.eof()) {
            course = Course::read(input);
            if (course != nullptr) {
                courseList->insert(course);
                course = nullptr;
            }
        }
    }
    input.close();
    return courseList;
}

List<Group>* Files::loadGroups()
{
    List<Group>* groupList = new List<Group>();
    Group* group = nullptr;
    input.open("Files/Groups.txt");
    if (input.good()) {
        while (!input.eof()) {
            group = Group::read(input);
            if (group != nullptr) {
                groupList->insert(group);
                group = nullptr;
            }
        }
    }
    input.close();
    return groupList;
}
