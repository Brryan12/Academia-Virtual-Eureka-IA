#include "Person.h"

Person::Person() : name(""), id(""), phone(""), email("") {}

Person::Person(std::string name, std::string id, std::string phone, std::string email) : name(name), id(id), phone(phone), email(email) {}

Person::~Person()
{
}

std::string Person::getName() const
{
    return name;
}

std::string Person::getId() const
{
    return id;
}

std::string Person::getPhone() const
{
    return phone;
}

std::string Person::getEmail() const
{
    return email;
}

void Person::setName(std::string name)
{
    this->name = name;
}

void Person::setId(std::string id)
{
    this->id = id;
}

void Person::setPhone(std::string phone)
{
    this->phone = phone;
}

void Person::setEmail(std::string email)
{
    this->email = email;
}

std::string Person::toString() const
{
    std::stringstream s;
    s << "Name: " << name << std::endl
      << "ID: " << id << std::endl
      << "Phone: " << phone << std::endl
      << "Email: " << email << std::endl;
    return s.str();
}
