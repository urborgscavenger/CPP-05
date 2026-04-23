#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default Form"), isSigned(false), signGrade(150), execGrade(150) {}

Form::Form(const string& n, int sg, int eg) : name(n), isSigned(false), signGrade(sg), execGrade(eg) {
    if (signGrade < 1 || execGrade < 1) throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150) throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form() {}

const string& Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getSignGrade() const {
    return signGrade;
}

int Form::getExecGrade() const {
    return execGrade;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= signGrade) {
        isSigned = true;
    } else {
        throw GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form " << f.getName() << ", signed? " << (f.getIsSigned() ? "yes" : "no") << ", sign grade: " << f.getSignGrade() << ", exec grade: " << f.getExecGrade();
    return os;
}