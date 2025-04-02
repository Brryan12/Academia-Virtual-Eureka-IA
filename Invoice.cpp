#include "Invoice.h"

Invoice::Invoice() : student(nullptr) {}

Invoice::Invoice(Student* student) : student(student) {}

Invoice::~Invoice()
{
    delete student;
}

double Invoice::calculateAmount()
{
    return student->amountToPay() - this->calculateDiscount();
}

bool Invoice::periodDiscount()
{
    return student->minimumTwoGroupsPerPeriod();
}

bool Invoice::annualDiscount()
{
    return student->getGroupList()->elementCount() > 3;
}

double Invoice::calculateDiscount()
{
    if (this->periodDiscount() && this->annualDiscount())
    {
        return student->amountToPay() * 0.3625;
    }
    else if (this->periodDiscount())
    {
        return student->amountToPay() * 0.15;
    }
    else if (this->annualDiscount())
    {
        return student->amountToPay() * 0.25;
    }
    else
    {
        return 0.0;
    }
}

std::string Invoice::generateInvoice()
{
    std::stringstream s;
    s << "Name: " << student->getName() << std::endl;
    s << "ID: " << student->getId() << std::endl;
    s << student->courseInfo() << std::endl;
    s << "Subtotal: " << student->amountToPay() << std::endl;
    s << "VAT: " << student->amountToPay() * VAT << std::endl;
    s << "Discount: " << this->calculateDiscount() << std::endl;
    s << "Applied Discounts: " << std::endl;
    if (this->periodDiscount())
    {
        s << "Discount for having more than one group in a period" << std::endl;
    }
    if (this->annualDiscount())
    {
        s << "Discount for having more than 3 groups in a year" << std::endl;
    }
    s << "Total: " << this->calculateAmount() << std::endl;

    return s.str();
}
