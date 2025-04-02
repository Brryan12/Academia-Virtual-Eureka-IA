#include "Schedule.h"

Schedule::Schedule() : startTime(0), endTime(0), day1(""), day2("") {}

Schedule::Schedule(int startTime, int endTime, std::string day1, std::string day2) : startTime(startTime), endTime(endTime), day1(day1), day2(day2) {}

Schedule::~Schedule() {}

int Schedule::getStartTime() const
{
    return startTime;
}

int Schedule::getEndTime() const
{
    return endTime;
}

std::string Schedule::getDay1() const
{
    return day1;
}

std::string Schedule::getDay2() const
{
    return day2;
}

void Schedule::setStartTime(int startTime)
{
    this->startTime = startTime;
}

void Schedule::setEndTime(int endTime)
{
    this->endTime = endTime;
}

void Schedule::setDay1(std::string day1)
{
    this->day1 = day1;
}

void Schedule::setDay2(std::string day2)
{
    this->day2 = day2;
}

bool Schedule::compareSchedules(Schedule* s)
{
    if (this->day1 == s->getDay1() || this->day2 == s->getDay2())
        return (this->endTime > s->getStartTime());

    return false;
}

void Schedule::save(std::ostream& output) const
{
    output << startTime << "\t"
           << endTime << "\t"
           << day1 << "\t"
           << day2 << "\n";
}

Schedule* Schedule::read(std::istream& input)
{
    std::string day1, day2, startTime, endTime;
    input >> startTime >> endTime >> day1 >> day2;
    if (std::stoi(startTime) < 0 || std::stoi(endTime) < 0)
    {
        return nullptr;
    }
    if (startTime.empty() && endTime.empty() && day1.empty() && day2.empty())
    {
        return nullptr;
    }
    return new Schedule(std::stoi(startTime), std::stoi(endTime), day1, day2);
}

std::string Schedule::toString() const
{
    std::stringstream s;
    s << "Start Time: " << startTime << std::endl
      << "End Time: " << endTime << std::endl
      << "1st Day: " << day1 << std::endl
      << "2nd Day: " << day2 << std::endl;
    return s.str();
}
