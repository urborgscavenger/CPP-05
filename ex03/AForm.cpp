#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default Form"), isSigned(false), signGrade(150), execGrade(150) {}

AForm::AForm(const string& n, int sg, int eg) : name(n), isSigned(false), signGrade(sg), execGrade(eg) {
    if (signGrade < 1 || execGrade < 1) throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getSignGrade() const {
    return signGrade;
}

int AForm::getExecGrade() const {
    return execGrade;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= signGrade) {
        isSigned = true;
    } else {
        throw GradeTooLowException();
    }
}

void AForm::execute(Bureaucrat const& executor) const {
    if (!isSigned) throw FormNotSignedException();
    if (executor.getGrade() > execGrade) throw GradeTooLowException();
    performAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

ostream& operator<<(ostream& os, const AForm& f) {
    os << "Form " << f.getName() << ", signed? " << (f.getIsSigned() ? "yes" : "no")
       << ", sign grade: " << f.getSignGrade() << ", exec grade: " << f.getExecGrade();
    return os;
}