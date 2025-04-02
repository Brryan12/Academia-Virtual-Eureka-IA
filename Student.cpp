#include "Student.h"
#include "Group.h"

Student::Student() : Person(), major(""), groupList(nullptr) {}

Student::Student(std::string name, std::string id, std::string phone, std::string email, std::string major) : Person(name, id, phone, email), major(major), groupList(new List<Group>) {}

Student::~Student()
{
    groupList = nullptr;
}

std::string Student::getMajor() const
{
    return major;
}

List<Group>* Student::getGroupList() const
{
    return groupList;
}

void Student::setMajor(std::string major)
{
    this->major = major;
}

void Student::setGroupList(List<Group>* groupList)
{
    this->groupList = groupList;
}

std::string Student::toString() const
{
    std::stringstream s;
    s << Person::toString()
      << "Major: " << major << std::endl;
    return s.str();
}

bool Student::insertGroup(Group* groupAux) {
    bool canInsert = true;
    auto currentGroup = groupList->getFirst(); // get first element

    while (currentGroup != nullptr) {
        auto groupCurrent = currentGroup->data;

        // Check for duplicate group
        if (groupCurrent->getId() == groupAux->getId()) {
            canInsert = false;
            break;
        }

        // Check for duplicate course and period
        if (groupCurrent->getCourse() == groupAux->getCourse() && groupCurrent->getPeriod() == groupAux->getPeriod()) {
            canInsert = false;
            break;
        }

        // Check for schedule conflict in the same period
        if (groupCurrent->getPeriod() == groupAux->getPeriod() &&
            groupCurrent->getSchedule()->compareSchedules(groupAux->getSchedule())) {
            canInsert = false;
            break;
        }

        currentGroup = currentGroup->next;
    }

    if (canInsert) {
        groupList->insert(groupAux);  // Insert group if no conflict
    }
    return canInsert;
}

bool Student::minimumTwoGroupsPerPeriod() const
{
    int count = 0;
    for (int i = 0; i < NUMBER_OF_PERIODS; i++) {
        this->groupList->setCurrent(this->groupList->getFirst());
        while (this->groupList->getCurrent() != nullptr)
        {
            if (this->groupList->getCurrent()->data->getPeriod() == periods[i]) {
                count++;
            }
            this->groupList->setCurrent(this->groupList->getCurrent()->next);
        }
        if (count > 1) {
            return true;
        }
    }
    return false;
}

double Student::amountToPay() const
{
    double amount = 0.0;
    this->groupList->setCurrent(this->groupList->getFirst());
    while (this->groupList->getCurrent() != nullptr)
    {
        amount += this->groupList->getCurrent()->data->getCourse()->getPrice();

        this->groupList->setCurrent(this->groupList->getCurrent()->next);
    }
    return amount;
}

std::string Student::courseInfo() const
{
    groupList->setCurrent(groupList->getFirst());
    std::stringstream s;
    while (groupList->getCurrent() != nullptr)
    {
        s << groupList->getCurrent()->data->getCourse()->getName() << std::endl;
        s << groupList->getCurrent()->data->getCourse()->getPrice() << std::endl;
        groupList->setCurrent(groupList->getCurrent()->next);
    }
    return s.str();
}

bool Student::removeGroup(std::string id)
{
    return this->groupList->remove(id);
}

void Student::save(std::ostream& output) const 
{
    output << name << "\t"
           << id << "\t"
           << phone << "\t"
           << email << "\t"
           << major << "\n";
}

Student* Student::read(std::istream& input)
{
    std::string name, id, phone, email, major;
    getline(input, name, '\t');
    getline(input, id, '\t');
    getline(input, phone, '\t');
    getline(input, email, '\t');
    getline(input, major, '\n');
    if (name.empty() || id.empty() || phone.empty() || email.empty() || major.empty())
    {
        return nullptr;
    }
    return new Student(name, id, phone, email, major);
}
