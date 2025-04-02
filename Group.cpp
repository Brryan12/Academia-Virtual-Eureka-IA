#include "Group.h"

Group::Group() : period(""), course(nullptr), groupId(""), studentCount(0), schedule(nullptr), professor(nullptr), students(nullptr) {}

Group::Group(std::string period, Course* course, std::string groupId, Schedule* schedule) : period(period), course(course), groupId(groupId), studentCount(0), schedule(schedule), professor(nullptr), students(new List<Student>()) {}

Group::Group(std::string period, Course* course, std::string groupId, Schedule* schedule, Professor* professor) : period(period), course(course), groupId(groupId), studentCount(0), schedule(schedule), professor(professor), students(new List<Student>()) {}

Group::~Group()
{
    delete schedule;
    students = nullptr;
    professor = nullptr;
}

int Group::getCapacity() const
{
    return capacity;
}

std::string Group::getPeriod() const
{
    return period;
}

std::string Group::getId() const
{
    return groupId;
}

int Group::getStudentCount() const
{
    return studentCount;
}

Course* Group::getCourse() const
{
    return course;
}

Schedule* Group::getSchedule() const
{
    return schedule;
}

Professor* Group::getProfessor() const
{
    return professor;
}

void Group::setPeriod(std::string period)
{
    this->period = period;
}

void Group::setGroupId(std::string groupId)
{
    this->groupId = groupId;
}

void Group::setStudentCount(int studentCount)
{
    this->studentCount = studentCount;
}

void Group::setCourse(Course* course)
{
    this->course = course;
}

void Group::setSchedule(Schedule* schedule)
{
    this->schedule = schedule;
}

bool Group::setProfessor(Professor* professor)
{
    this->professor = professor;
    return true;
}

std::string Group::toString() const
{
    std::stringstream s;

    s << "Period: " << period << std::endl
      << this->course->toString()
      << "GroupId: " << groupId << std::endl
      << "Capacity: " << capacity << std::endl
      << "Student Count: " << studentCount << std::endl
      << "Schedule: " << schedule->toString() << std::endl;
    if (professor != nullptr)
    {
        s << "Professor: " << professor->toString() << std::endl;
    }
    else
    {
        s << "Professor: " << "Not assigned" << std::endl;
    }
    s << "Students: " << std::endl;
    if (students != nullptr)
    {
        s << students->toString() << std::endl;
    }
    else
    {
        s << "No students assigned" << std::endl;
    }
    return s.str();
}

bool Group::insertStudent(Student* student) {
    if (studentCount < capacity) {
        // Check if the student is already in the group to avoid duplicates
        if (students->searchElement(student->getId()) == nullptr) {
            if (students->insert(student)) {
                studentCount++;
                return true;
            }
        }
        else {
            // The student is already in the group
            return false;
        }
    }
    // The group is full
    return false;
}

bool Group::removeStudent(std::string id) {
    if (studentCount > 0) {
        if (students->remove(id)) {  // Only reduce count if successfully removed
            studentCount--;
            return true;
        }
    }
    return false;
}

std::string Group::toStringPeriods(List<Group>* list)
{
    std::stringstream s;
    for (int i = 0; i < NUMBER_OF_PERIODS; i++)
    {
        s << std::endl << periods[i] << duration[i] << std::endl;
        list->setCurrent(list->getFirst());

        // Check if there are elements in the list
        if (list->getFirst() == nullptr) {
            s << "No groups registered in the list." << std::endl;
            continue;  // Move to the next period if the list is empty
        }

        int groupCount = 0;  // Group count per period
        while (list->getCurrent() != nullptr) {
            if (list->getCurrent()->data->getPeriod() == periods[i]) {
                s << "------------------------------------------------------------\n";
                s << "Period: " << list->getCurrent()->data->getPeriod() << std::endl
                  << list->getCurrent()->data->getCourse()->toString()
                  << "GroupId: " << list->getCurrent()->data->getId() << std::endl
                  << "Capacity: " << list->getCurrent()->data->getCapacity() << std::endl
                  << "Student Count: " << list->getCurrent()->data->getStudentCount() << std::endl
                  << "Schedule: " << list->getCurrent()->data->getSchedule()->toString() << std::endl;
                if (list->getCurrent()->data->getProfessor() != nullptr)
                {
                    s << "Professor: " << list->getCurrent()->data->getProfessor()->toString() << std::endl;
                }
                else
                {
                    s << "Professor: " << "Not assigned" << std::endl;
                }
                groupCount++;
            }
            list->setCurrent(list->getCurrent()->next);
        }

        if (groupCount == 0) {
            s << "No groups found for the period " << periods[i] << std::endl;
        }
        s << "------------------------------------------------------------\n";
    }
    return s.str();
}

std::string Group::toStringBasic(List<Group>* list) {
    std::stringstream s;
    list->setCurrent(list->getFirst());
    while (list->getCurrent() != nullptr) {
        s << "Period: " << list->getCurrent()->data->getPeriod() << std::endl
          << list->getCurrent()->data->getCourse()->toString()
          << "GroupId: " << list->getCurrent()->data->getId() << std::endl
          << "Capacity: " << list->getCurrent()->data->getCapacity() << std::endl
          << "Student Count: " << list->getCurrent()->data->getStudentCount() << std::endl
          << "Schedule: " << list->getCurrent()->data->getSchedule()->toString() << std::endl;
        if (list->getCurrent()->data->getProfessor() != nullptr)
        {
            s << "Professor: " << list->getCurrent()->data->getProfessor()->toString() << std::endl;
        }
        else
        {
            s << "Professor: " << "Not assigned" << std::endl;
        }
        list->setCurrent(list->getCurrent()->next);
    }
    return s.str();
}

std::string Group::groupsWithoutProfessor(List<Group>* list) {
    std::stringstream s;

    list->setCurrent(list->getFirst());
    while (list->getCurrent() != nullptr) {
        if (list->getCurrent()->data->getProfessor() == nullptr)
        {
            s << "Period: " << list->getCurrent()->data->getPeriod() << std::endl
              << list->getCurrent()->data->getCourse()->toString()
              << "GroupId: " << list->getCurrent()->data->getId() << std::endl
              << "Capacity: " << list->getCurrent()->data->getCapacity() << std::endl
              << "Student Count: " << list->getCurrent()->data->getStudentCount() << std::endl
              << "Schedule: " << list->getCurrent()->data->getSchedule()->toString() << std::endl;
        }
        list->setCurrent(list->getCurrent()->next);
    }
    return s.str();
}

std::string Group::groupsWithProfessor(List<Group>* list) {
    std::stringstream s;
    list->setCurrent(list->getFirst());
    while (list->getCurrent() != nullptr) {
        if (list->getCurrent()->data->getProfessor() != nullptr)
        {
            s << "Period: " << list->getCurrent()->data->getPeriod() << std::endl
              << list->getCurrent()->data->getCourse()->toString()
              << "GroupId: " << list->getCurrent()->data->getId() << std::endl
              << "Capacity: " << list->getCurrent()->data->getCapacity() << std::endl
              << "Student Count: " << list->getCurrent()->data->getStudentCount() << std::endl
              << "Schedule: " << list->getCurrent()->data->getSchedule()->toString() << std::endl
              << "Professor: " << list->getCurrent()->data->getProfessor()->toString() << std::endl;
        }
        list->setCurrent(list->getCurrent()->next);
    }
    return s.str();
}

void Group::save(std::ostream& output) const
{
    // Write the group data
    output << period << "\t"
           << course->getName() << "\t"
           << course->getId() << "\t"
           << course->getHours() << "\t"
           << course->getPrice() << "\t"
           << course->getStatus() << "\t"
           << groupId << "\t";
    if (professor != nullptr)
    {
        output << professor->getName() << "\t"
               << professor->getId() << "\t"
               << professor->getPhone() << "\t"
               << professor->getEmail() << "\t"
               << professor->getAcademicDegree() << "\t"
               << schedule->getStartTime() << "\t"
               << schedule->getEndTime() << "\t"
               << schedule->getDay1() << "\t"
               << schedule->getDay2() << "\n";
    }
    else {
        output << "\t" << "\t" << "\t" << "\t" << "\t" 
               << schedule->getStartTime() << "\t"
               << schedule->getEndTime() << "\t"
               << schedule->getDay1() << "\t"
               << schedule->getDay2() << "\n";
    }
}

Group* Group::read(std::istream& input)
{
    std::string period, courseName, courseId, groupId, courseHours, coursePrice, startTime, endTime, day1, day2;
    bool status;
    Professor* professor = nullptr;
    std::string name, id, phone, email, academicDegree;
    Schedule* schedule = nullptr;
    Course* course = nullptr;

    // Read the group data
    std::getline(input, period, '\t');
    std::getline(input, courseName, '\t');
    std::getline(input, courseId, '\t');
    std::getline(input, courseHours, '\t');
    std::getline(input, coursePrice, '\t');
    input >> status;  // Read status as boolean
    input.ignore();    // Ignore the newline following the status

    // Validate the course
    if (stoi(courseHours) < 1 || stod(coursePrice) < 1) {
        return nullptr;
    }
    if (!courseName.empty() && !courseId.empty() && !courseHours.empty() && !coursePrice.empty()) {
        course = new Course(courseName, courseId, stoi(courseHours), std::stod(coursePrice), status);
    } else {
        return nullptr;
    }
    std::getline(input, groupId, '\t');
    std::getline(input, name, '\t');
    std::getline(input, id, '\t');  // This seems to be a duplicate read error
    std::getline(input, phone, '\t');
    std::getline(input, email, '\t');
    std::getline(input, academicDegree, '\t');

    // Validate the professor
    if (!name.empty() && !id.empty() && !phone.empty() && !email.empty() && !academicDegree.empty()) {
        professor = new Professor(name, id, phone, email, academicDegree);
    }

    // Read the schedule
    std::getline(input, startTime, '\t');
    std::getline(input, endTime, '\t');
    std::getline(input, day1, '\t');
    std::getline(input, day2, '\n');

    // Validate the schedule
    if (std::stoi(startTime) < 0 || std::stoi(startTime) > 23 || (stoi(endTime) < 0 || stoi(endTime) > 23))
    {
        return nullptr;
    }
    if (!startTime.empty() && !endTime.empty() && !day1.empty() && !day2.empty()) {
        schedule = new Schedule(std::stoi(startTime), std::stoi(endTime), day1, day2);
    } else {
        return nullptr;
    }

    // Create and return the Group
    if (!period.empty() && course != nullptr && !groupId.empty() && schedule != nullptr) {
        if (professor != nullptr) {
            return new Group(period, course, groupId, schedule, professor);
        } else {
            return new Group(period, course, groupId, schedule);
        }
    } else {
        return nullptr;
    }
}
