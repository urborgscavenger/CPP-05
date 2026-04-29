#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <ostream>

typedef std::string string;
typedef std::exception exception;
typedef std::ostream ostream;

class AForm;

class Bureaucrat {
private:
    const string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(const string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& f);
    void executeForm(AForm const& form) const;

    class GradeTooHighException : public exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public exception {
    public:
        const char* what() const throw();
    };
};

ostream& operator<<(ostream& os, const Bureaucrat& b);

#endif