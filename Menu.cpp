#include "Menu.h"

int Menu::mainMenu()
{
    int op;
    system(cls);
    std::endl(std::cout);
    std::cout << "----Main Menu----" << std::endl;
    std::cout << "1- Administration Submenu" << std::endl;
    std::cout << "2- Enrollment Submenu" << std::endl;
    std::cout << "3- Search and Reports Submenu" << std::endl;
    std::cout << "4- Save Data to Files" << std::endl;
    std::cout << "5- Exit" << std::endl;
    std::cout << "Select an option: "; std::cin >> op;
    return op;
}

int Menu::administrationSubmenu()
{
    int op1;
    system(cls);
    std::endl(std::cout);
    std::cout << "(1) Add Professor" << std::endl;
    std::cout << "(2) Add Student" << std::endl;
    std::cout << "(3) Add Course" << std::endl;
    std::cout << "(4) Add Group" << std::endl;
    std::cout << "(5) Assign Professor to Group" << std::endl;
    std::cout << "(0) Return to Main Menu" << std::endl;
    std::cout << "Select an option: "; std::cin >> op1;
    return op1;
}

int Menu::enrollmentSubmenu()
{
    int op2;
    system(cls);
    std::endl(std::cout);
    std::cout << "(1) Enroll Student" << std::endl;
    std::cout << "(2) Unenroll Student" << std::endl;
    std::cout << "(3) Generate Student Payment Invoice" << std::endl;
    std::cout << "(0) Return to Main Menu" << std::endl;
    std::cout << "Select an option: "; std::cin >> op2;
    return op2;
}

int Menu::searchAndReportsSubmenu()
{
    int op3;
    system(cls);
    std::cout << "(1) Registered Professors Report" << std::endl;
    std::cout << "(2) Registered Students Report" << std::endl;
    std::cout << "(3) Courses Enrolled by a Student Report" << std::endl;
    std::cout << "(4) Specific Professor Report" << std::endl;
    std::cout << "(5) Enabled Periods for the Year Report" << std::endl;
    std::cout << "(6) Specific Group Report" << std::endl;
    std::cout << "(0) Return to Main Menu" << std::endl;
    std::cout << "Select an option: "; std::cin >> op3;
    return op3;
}

void Menu::saveDataToFiles(List<Professor>* professorList, List<Student>* studentList, List<Course>* courseList, List<Group>* groupList)
{
    system(cls);
    Files* files = new Files();
    std::cout << "Saving data to files..." << std::endl;
    files->saveStudents(studentList);
    files->saveProfessors(professorList);
    files->saveCourses(courseList);
    files->saveGroups(groupList);
    std::cout << "Data saved to files" << std::endl;
    delete files;
    system(pause);
}

void Menu::defaultSwitch()
{
    system(cls);
    std::cout << "Invalid option. Please try again." << std::endl;
    system(pause);
}

void Menu::returnToMainMenu()
{
    system(cls);
    std::cout << "Returning to Main Menu..." << std::endl;
    system(pause);
}

void Menu::addProfessor(List<Professor>* professorList)
{
    std::string name, id, phone, email, academicDegree;
    Professor* profAux = nullptr;
    system(cls);
    std::cin.ignore();
    std::cout << "(1) Add Professor" << std::endl;
    std::cout << "Enter the professor's name: "; getline(std::cin, name);
    std::cout << "Name: " << name << std::endl;
    if (name.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Enter the professor's ID: "; std::cin >> id;
    if (professorList->searchElement(id)) {
        std::cerr << "Error, a professor with that ID already exists" << std::endl;
        system(pause);
        return;
    }
    std::cout << "ID: " << id << std::endl; std::cin.ignore();
    std::cout << "Enter the professor's phone number: "; getline(std::cin, phone);
    if (phone.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "Enter the professor's email: "; getline(std::cin, email);
    if (email.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Email: " << email << std::endl;
    std::cout << "Enter the professor's academic degree: "; getline(std::cin, academicDegree);
    std::cout << "Academic Degree: " << academicDegree << std::endl;
    if (name.empty() || id.empty() || phone.empty() || email.empty() || academicDegree.empty()) {
        std::endl(std::cout);
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    profAux = new Professor(name, id, phone, email, academicDegree);
    if (professorList->insert(profAux)) {
        std::cout << "Professor added successfully." << std::endl;
    }
    else {
        std::cerr << "Error adding the professor." << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::addStudent(List<Student>* studentList)
{
    std::string name, id, phone, email, major;
    Student* studentAux = nullptr;
    system(cls);
    std::cin.ignore();
    std::cout << "(2) Add Student" << std::endl;
    std::cout << "Enter the student's name: "; getline(std::cin, name);
    if (name.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Name: " << name << std::endl;
    std::cout << "Enter the student's ID: "; std::cin >> id;
    if (studentList->searchElement(id)) {
        std::cerr << "Error, a student with that ID already exists" << std::endl;
        system(pause);
        return;
    }
    std::cout << "ID: " << id << std::endl; std::cin.ignore();
    std::cout << "Enter the student's phone number: "; getline(std::cin, phone);
    if (phone.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "Enter the student's email: "; getline(std::cin, email);
    if (email.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Email: " << email << std::endl;
    std::cout << "Enter the student's major: "; getline(std::cin, major);
    std::cout << "Major: " << major << std::endl;
    if (name.empty() || id.empty() || phone.empty() || email.empty() || major.empty()) {
        std::endl(std::cout);
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    studentAux = new Student(name, id, phone, email, major);
    if (studentList->insert(studentAux)) {
        std::cout << "Student added successfully." << std::endl;
    }
    else {
        std::cerr << "Error adding the student." << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::addCourse(List<Course>* courseList)
{
    std::string name, id;
    int hours;
    double price;
    int status;
    Course* courseAux = nullptr;

    system(cls);
    std::cin.ignore();
    std::cout << "(3) Add Course" << std::endl;
    std::cout << "Enter the course name: "; getline(std::cin, name);
    if (name.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Name: " << name << std::endl;
    std::cout << "Enter the course ID: "; std::cin >> id;
    if (courseList->searchElement(id)) {
        std::cerr << "Error, a course with that ID already exists" << std::endl;
        system(pause);
        return;
    }
    std::cout << "ID: " << id << std::endl; std::cin.ignore();
    std::cout << "Enter the course hours: "; std::cin >> hours;
    if (hours < 1) {
        std::cerr << "Error entering the course hours" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Hours: " << hours << std::endl;
    std::cout << "Enter the course price: "; std::cin >> price;
    if (price < 1) {
        std::cerr << "Error entering the course price" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Price: " << price << std::endl;
    std::cout << "Enter 0 if the course is not active" << std::endl;
    std::cout << "Enter 1 if the course is active" << std::endl;
    std::cout << "Enter the course status: "; std::cin >> status;
    if (status != 0 && status != 1) {
        std::endl(std::cout);
        std::cerr << "Error entering the course status" << std::endl;
        system(pause);
        return;
    }
    else if (status != 0) {
        std::cout << "Status: Active" << std::endl;
    }
    else {
        std::cout << "Status: Inactive" << std::endl;
    }
    if (name.empty() || id.empty()) {
        std::endl(std::cout);
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    courseAux = new Course(name, id, hours, price, status);
    if (courseList->insert(courseAux)) {
        std::cout << "Course added successfully." << std::endl;
    }
    else {
        std::cerr << "Error adding the course." << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::addGroup(List<Group>* groupList, List<Course>* courseList)
{
    std::string period, id, day, day2;
    int pos, startTime, endTime;
    Course* courseAux = nullptr;
    Group* groupAux = nullptr;
    system(cls);
    std::cin.ignore();
    if (courseList->isEmpty()) {
        std::cerr << "Error, no courses registered" << std::endl;
        system(pause);
        return;
    }
    std::cout << "(4) Add Group" << std::endl;
    std::cout << "Groups have a capacity of 30 students\n";
    for (int i = 0; i < NUMBER_OF_PERIODS; i++) {
        std::cout << (i + 1) << ". " << periods[i] << "\n";
    }

    std::cout << "Enter the period number: ";
    std::cin >> pos;
    if (pos < 1 || pos > NUMBER_OF_PERIODS) {
        std::cerr << "Error, the number is not valid" << std::endl;
        system(pause);
        return;
    }
    period = periods[pos - 1];
    std::cout << "Selected period: " << period << std::endl;
    std::cout << "Registered courses: \n" << courseList->toString() << std::endl;
    std::cout << "Enter the course ID: "; std::cin >> id;
    if (id.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    if (courseList->searchElement(id)) {
        courseAux = courseList->searchElement(id);
        if (courseAux->getStatus() == false) {
            std::cerr << "The course is inactive, cannot create group" << std::endl;
            system(pause);
            return;
        }
    }
    else {
        std::cerr << "Error, no course with that ID" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Enter the group ID: "; std::cin >> id;
    if (id.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    if (groupList->searchElement(id)) {
        std::cerr << "Error, a group with that ID already exists" << std::endl;
        system(pause);
        return;
    }
    std::cout << "ID: " << id << std::endl;
    std::cout << "Enter the group schedule\n";
    std::cout << "Schedules are from 0 to 23\n";
    std::cout << "Enter the start time: "; std::cin >> startTime;
    if (startTime < 0 || startTime > 23) {
        std::cerr << "Error, the time is not valid" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Enter the end time: "; std::cin >> endTime;
    if (endTime < 0 || endTime > 23) {
        std::cerr << "Error, the time is not valid" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Start time: " << startTime << std::endl;
    std::cout << "End time: " << endTime << std::endl;
    for (int i = 0; i < NUMBER_OF_DAYS; i++) {
        std::cout << (i + 1) << ". " << days[i] << "\n";
    }

    std::cout << "Enter the number of the first day: ";
    std::cin >> pos;
    if (pos < 1 || pos > NUMBER_OF_DAYS) {
        std::cerr << "Error, the day number is not valid" << std::endl;
        system(pause);
        return;
    }
    day = days[pos - 1];

    std::cout << "Enter the number of the second day: ";
    std::cin >> pos;

    if (pos < 1 || pos > 5) {
        std::cerr << "Error, the day number is not valid" << std::endl;
        system(pause);
        return;
    }

    day2 = days[pos - 1];

    if (day2 == day) {
        std::cerr << "Error, the days cannot be the same" << std::endl;
        system(pause);
        return;
    }

    std::cout << "Selected day 1: " << day << std::endl;
    std::cout << "Selected day 2: " << day2 << std::endl;
    if (period.empty() || id.empty() || day.empty() || day2.empty()) {
        std::endl(std::cout);
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    groupAux = new Group(period, courseAux, id, new Schedule(startTime, endTime, day, day2));
    if (groupList->insert(groupAux)) {
        std::cout << "Group added successfully." << std::endl;
    }
    else {
        std::cerr << "Error adding the group." << std::endl;
        system(pause);
        return;
    }
    system(pause);
}
void Menu::assignProfessorToGroup(List<Group>* groupList, List<Professor>* professorList)
{
    std::string id;
    Professor* profAux = nullptr;
    Group* groupAux = nullptr;
    system(cls);
    std::cout << "(5) Assign Professor to Group" << std::endl;
    if (professorList->isEmpty() || groupList->isEmpty()) {
        std::cerr << "Error, no professors or groups registered" << std::endl;
        system(pause);
        return;
    }
    std::cout << professorList->toString() << std::endl;
    std::cout << "Enter the professor's ID to assign: "; std::cin >> id;
    if (id.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    if (professorList->searchElement(id))
        profAux = professorList->searchElement(id);
    else {
        std::cerr << "Error, no professor with that ID" << std::endl;
        system(pause);
        return;
    }
    std::cout << Group::groupsWithoutProfessor(groupList) << std::endl;
    std::cout << "Enter the group ID: "; std::cin >> id;
    if (id.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    if (groupList->searchElement(id))
        groupAux = groupList->searchElement(id);
    else {
        std::cerr << "Error, no group with that ID" << std::endl;
        system(pause);
        return;
    }
    if (!groupAux->getProfessor() && profAux->getGroupList()->searchElement(id) != groupAux) {
        if (groupAux->setProfessor(profAux)) {
            profAux->getGroupList()->insert(groupAux);
            std::cout << "Professor assigned successfully." << std::endl;
        }
        else {
            std::cerr << "Error assigning the professor." << std::endl;
            system(pause);
            return;
        }
    }
    else {
        std::cerr << "The group already has a professor assigned or the professor already has that group assigned." << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::enrollStudent(List<Group>* groupList, List<Student>* studentList)
{
    std::string id;
    Student* studentAux = nullptr;
    Group* groupAux = nullptr;
    system(cls);
    std::cout << "(1) Enroll Student" << std::endl;
    if (studentList->isEmpty() || groupList->isEmpty()) {
        std::cerr << "Error, no students or groups registered" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Students: \n" << studentList->toString() << std::endl;
    std::cout << "Enter the student's ID: "; std::cin >> id;
    if (id.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    if (studentList->searchElement(id))
        studentAux = studentList->searchElement(id);
    else {
        std::cerr << "Error, no student with that ID" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Student's name: " << studentAux->getName() << std::endl;
    std::cout << "Groups: \n" << Group::groupsWithProfessor(groupList);
    std::cout << "Enter the group ID: "; std::cin >> id;
    if (groupList->searchElement(id)) {
        groupAux = groupList->searchElement(id);
        if (!groupAux->getProfessor()) {
            std::cerr << "Error, the group has no assigned professor" << std::endl;
        }
    }
    else {
        std::cerr << "Error, no group with that ID" << std::endl;
        system(pause);
        return;
    }
    if (studentAux->insertGroup(groupAux)) {
        if (groupAux->getStudentCount() < 30) {
            if (groupAux->insertStudent(studentAux)) {
                std::cout << "Student successfully enrolled in the group." << std::endl;
            }
            else {
                std::cerr << "Error enrolling the student." << std::endl;
                system(pause);
                return;
            }
        }
        else {
            std::cerr << "Error, the group already has 30 students" << std::endl;
            system(pause);
            return;
        }
        std::cout << "Student successfully enrolled." << std::endl;
    }
    else {
        std::cerr << "Error, the student is already enrolled in a group with this course" << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::unenrollStudent(List<Group>* groupList, List<Student>* studentList)
{
    std::string id;
    Student* studentAux = nullptr;
    Group* groupAux = nullptr;
    system(cls);
    std::cout << "(2) Unenroll Student" << std::endl;
    if (studentList->isEmpty() || groupList->isEmpty()) {
        std::cerr << "Error, no students or groups registered" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Students: \n" << studentList->toString() << std::endl;
    std::cout << "Enter the student's ID: "; std::cin >> id;
    if (id.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    if (studentList->searchElement(id))
        studentAux = studentList->searchElement(id);
    else {
        std::cerr << "Error, no student with that ID" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Student's groups: \n" << studentAux->getGroupList()->toString() << std::endl;
    std::cout << "Enter the group ID: "; std::cin >> id;
    if (groupList->searchElement(id))
        groupAux = groupList->searchElement(id);
    else {
        std::cerr << "Error, no group with that ID" << std::endl;
        system(pause);
        return;
    }
    if (studentAux->removeGroup(groupAux->getId())) {
        std::cout << "Student successfully unenrolled." << std::endl;
        if (groupAux->removeStudent(studentAux->getId())) {
            std::cout << "Student successfully unenrolled from the group." << std::endl;
        }
        else {
            std::cerr << "Error unenrolling the student from the group." << std::endl;
            system(pause);
            return;
        }
    }
    else {
        std::cerr << "Error unenrolling the student." << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::generateInvoice(List<Student>* studentList)
{
    std::string id;
    Student* studentAux = nullptr;
    Invoice* invoiceAux = nullptr;
    system(cls);
    std::cout << "(3) Generate Student Payment Invoice" << std::endl;
    std::cout << studentList->toString() << std::endl;
    std::cout << "Enter the student's ID: "; std::cin >> id;
    if (id.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    if (studentList->searchElement(id)) {
        studentAux = studentList->searchElement(id);
        if (studentAux->getGroupList()->isEmpty()) {
            std::cerr << "Error, the student is not enrolled in any group" << std::endl;
            system(pause);
            return;
        }
    }
    else {
        std::cerr << "Error, no student with that ID" << std::endl;
        system(pause);
        return;
    }
    invoiceAux = new Invoice(studentAux);
    std::cout << "Student's invoice: \n" << invoiceAux->generateInvoice() << std::endl;

    system(pause);
}

void Menu::registeredProfessorsReport(List<Professor>* professorList)
{
    system(cls);
    std::cout << "(1) Registered Professors Report" << std::endl;
    if (!professorList->isEmpty()) {
        std::cout << professorList->toString();
    }
    else {
        std::cerr << "No professors registered" << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::registeredStudentsReport(List<Student>* studentList)
{
    system(cls);
    std::cout << "(2) Registered Students Report" << std::endl;

    if (!studentList->isEmpty()) {
        std::cout << studentList->toString();
    }
    else {
        std::cerr << "No students registered" << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::coursesEnrolledByStudentReport(List<Group>* groupList, List<Student>* studentList)
{
    std::string id;
    Student* studentAux = nullptr;

    system(cls);
    std::cout << "(3) Courses Enrolled by a Student Report" << std::endl;
    if (studentList->isEmpty() || groupList->isEmpty()) {
        std::cerr << "No students or groups registered" << std::endl;
        system(pause);
        return;
    }
    std::cout << studentList->toString() << std::endl;
    std::cout << "Enter the student's ID: "; std::cin >> id;
    if (studentList->searchElement(id))
        studentAux = studentList->searchElement(id);
    else {
        std::cerr << "Error, no student with that ID" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Student's data: \n" << studentAux->toString() << std::endl;
    std::cout << "Student's groups: \n" << Group::toStringBasic(studentAux->getGroupList()) << std::endl;
    system(pause);
}

void Menu::specificProfessorReport(List<Professor>* professorList)
{
    std::string id;
    Professor* profAux = nullptr;
    system(cls);
    std::cout << "(4) Specific Professor Report" << std::endl;
    if (professorList->isEmpty()) {
        std::cerr << "No professors registered" << std::endl;
        system(pause);
        return;
    }
    std::cout << professorList->toString() << std::endl;
    std::cout << "Enter the professor's ID: "; std::cin >> id;
    if (id.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    if (professorList->searchElement(id))
        profAux = professorList->searchElement(id);
    else {
        std::cerr << "Error, no professor with that ID" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Professor's data: \n" << profAux->toString() << std::endl;
    std::cout << "Professor's groups: \n" << profAux->toStringPeriod() << std::endl;
    system(pause);
    return;
    system(pause);
}

void Menu::enabledPeriodsForYearReport(List<Group>* groupList, List<Course>* courseList)
{
    system(cls);
    std::cout << "(5) Enabled Periods for the Year Report" << std::endl;
    if (!groupList->isEmpty() && !courseList->isEmpty())
        std::cout << Group::toStringPeriods(groupList) << std::endl;
    else {
        std::cerr << "No groups or courses registered" << std::endl;
        system(pause);
        return;
    }
    system(pause);
}

void Menu::specificGroupReport(List<Group>* groupList, List<Course>* courseList)
{
    std::string id;
    Group* groupAux = nullptr;
    system(cls);
    std::cout << "(6) Specific Group Report" << std::endl;
    if (groupList->isEmpty() || courseList->isEmpty()) {
        std::cerr << "Error, no groups or courses registered" << std::endl;
        system(pause);
        return;
    }
    std::cout << groupList->toString() << std::endl;
    std::cout << "Enter the group ID: "; std::cin >> id;
    if (id.empty()) {
        std::cerr << "Error entering data" << std::endl;
        std::cerr << "There are empty fields" << std::endl;
        system(pause);
        return;
    }
    if (groupList->searchElement(id))
        groupAux = groupList->searchElement(id);
    else {
        std::cerr << "Error, no group with that ID" << std::endl;
        system(pause);
        return;
    }
    std::cout << "Group's data: \n" << groupAux->toString() << std::endl;

    system(pause);
}