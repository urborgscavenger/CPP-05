#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <ostream>

typedef std::string string;

class Bureaucrat;

class Form {
private:
    const string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

public:
    Form();
    Form(const string& name, int signGrade, int execGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& b);

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif