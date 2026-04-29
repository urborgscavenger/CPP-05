#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "CSharpStyle.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const string& n, int g) : name(n), grade(g) {
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1) throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150) throw GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(AForm& f) {
    try {
        f.beSigned(*this);
        WriteLine(name + " signed " + f.getName());
    } catch (exception& e) {
        WriteLine(name + " couldn’t sign " + f.getName() + " because " + e.what());
    }
}

void Bureaucrat::executeForm(AForm const& form) const {
    try {
        form.execute(*this);
        WriteLine(name + " executed " + form.getName());
    } catch (exception& e) {
        WriteLine(name + " couldn’t execute " + form.getName() + " because " + e.what());
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}