#pragma once
#include "Student.h"

class Invoice
{
private:
    /// @brief Student for whom the invoice will be generated
    Student* student;
public:
    /// @brief Default constructor
    Invoice();

    /// @brief Constructor with parameters
    /// @param student Student for whom the invoice will be generated
    Invoice(Student* student);

    /// @brief Destructor
    virtual ~Invoice();

    /// @brief Calculates the amount to be paid by the student
    /// @return Amount to be paid by the student
    double calculateAmount();

    /// @brief Checks if the student has a discount for having more than a certain number of groups in a period
    /// @return true if the student has a discount, false otherwise
    bool periodDiscount();

    /// @brief Checks if the student has a discount for having a certain number of groups in a year
    /// @return true if the student has a discount, false otherwise
    bool annualDiscount();

    /// @brief Calculates the discount to be applied to the student
    /// @return Discount to be applied to the student
    double calculateDiscount();

    /// @brief Generates the student's invoice
    /// @return Student's invoice
    std::string generateInvoice();
};
