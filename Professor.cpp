#include "Professor.h"
#include "Group.h"

Professor::Professor() : Person(), academicDegree(""), groupList(nullptr) {}

Professor::Professor(std::string name, std::string id, std::string phone, std::string email, std::string academicDegree) : Person(name, id, phone, email), academicDegree(academicDegree), groupList(new List<Group>) {}

Professor::~Professor()
{
}

std::string Professor::getAcademicDegree() const
{
    return academicDegree;
}

List<Group>* Professor::getGroupList() const
{
    return groupList;
}

void Professor::setAcademicDegree(std::string academicDegree)
{
    this->academicDegree = academicDegree;
}

std::string Professor::toString() const
{
    std::stringstream s;
    s << Person::toString()
      << "Academic Degree: " << academicDegree << std::endl;
    return s.str();
}

std::string Professor::toStringPeriod() const
{
    std::stringstream s;
    for (int i = 0; i < NUMBER_OF_PERIODS; i++)
    {
        int counter = 0;
        s << periods[i] << duration[i] << std::endl;
        this->groupList->setCurrent(this->groupList->getFirst());
        while (this->groupList->getCurrent() != nullptr) {
            if (this->groupList->getCurrent()->data->getPeriod() == periods[i]) {
                s << "Course Name: "
                  << this->groupList->getCurrent()->data->getCourse()->getName() << std::endl
                  << "Course ID: "
                  << this->groupList->getCurrent()->data->getCourse()->getId() << std::endl
                  << "Group ID: "
                  << this->groupList->getCurrent()->data->getId() << std::endl;
                counter++;
            }
            this->groupList->setCurrent(this->groupList->getCurrent()->next);
        }
        if (counter == 0) {
            s << "\nNo groups found for the period " << periods[i] << std::endl;
        }
    }
    return s.str();
}

void Professor::save(std::ostream& output) const
{
    output << name << "\t"
           << id << "\t"
           << phone << "\t"
           << email << "\t"
           << academicDegree << "\n";
}

Professor* Professor::read(std::istream& input)
{
    Professor* professor = nullptr;
    std::string name, id, phone, email, academicDegree;
    if (input)
    {
        std::getline(input, name, '\t');
        std::getline(input, id, '\t');
        std::getline(input, phone, '\t');
        std::getline(input, email, '\t');
        std::getline(input, academicDegree, '\n');
    }
    if (!name.empty() && !id.empty() && !phone.empty() && !email.empty() && !academicDegree.empty()) {
        professor = new Professor(name, id, phone, email, academicDegree);
    }
    return professor;
}
