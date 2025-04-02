#include "Course.h"

Course::Course() : name(""), id(""), hours(0), price(0), status(false) {}

Course::Course(string name, string id, int hours, double price, bool status) : name(name), id(id), hours(hours), price(price), status(status) {}

Course::~Course() {}

string Course::getName() const { return this->name; }

int Course::getHours() const { return this->hours; }

string Course::getId() const { return this->id; }

double Course::getPrice() const { return this->price; }

bool Course::getStatus() const { return this->status; }

void Course::setName(string name) { this->name = name; }

void Course::setHours(int hours) { this->hours = hours; }

void Course::setId(string id) { this->id = id; }

void Course::setPrice(double price) { this->price = price; }

void Course::setStatus(bool status) { this->status = status; }

void Course::save(std::ostream& output) const
{
    output << name << "\t"
           << id << "\t"
           << hours << "\t"
           << price << "\t"
           << status << "\n";
}

Course* Course::read(std::istream& input)
{
    string name, id, hours;
    string price;
    bool status;
    getline(input, name, '\t');
    getline(input, id, '\t');
    getline(input, hours, '\t');
    getline(input, price, '\t');
    input >> status;
    input.ignore();
    if (stoi(hours) < 1 || stod(price) < 1)
    {
        return nullptr;
    }
    if (name.empty() || id.empty() || hours.empty() || price.empty())
    {
        return nullptr;
    }
    if (status == 1)
        return new Course(name, id, stoi(hours), stod(price), true);
    else if (status == 0)
        return new Course(name, id, stoi(hours), stod(price), false);
}

string Course::toString() const
{
    stringstream s;

    s << "Course Name: " << this->name << endl
      << "Course ID: " << this->id << endl
      << "Course Hours: " << this->hours << endl
      << "Course Price: " << this->price << endl
      << "Course Status: " << this->status << endl;

    return s.str();
}
