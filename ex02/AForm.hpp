#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <ostream>

typedef std::string string;
typedef std::exception exception;

class Bureaucrat;

class AForm {
private:
    const string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

protected:
    virtual void performAction() const = 0;

public:
    AForm();
    AForm(const string& name, int signGrade, int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& b);
    void execute(Bureaucrat const& executor) const;

    class GradeTooHighException : public exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif