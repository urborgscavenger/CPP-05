#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
private:
    typedef AForm* (*CreateFormFn)(const string& target);

    struct FormEntry {
        const char* name;
        CreateFormFn create;
    };

    static AForm* createShrubbery(const string& target);
    static AForm* createRobotomy(const string& target);
    static AForm* createPresidential(const string& target);

public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const string& formName, const string& target) const;
};

#endif