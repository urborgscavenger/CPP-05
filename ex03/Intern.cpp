#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "CSharpStyle.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(const string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const string& formName, const string& target) const {
    static const FormEntry forms[] = {
        {"shrubbery creation", &Intern::createShrubbery},
        {"robotomy request", &Intern::createRobotomy},
        {"presidential pardon", &Intern::createPresidential}
    };

    const int count = sizeof(forms) / sizeof(forms[0]);
    for (int i = 0; i < count; i++) {
        if (formName == forms[i].name) {
            WriteLine("Intern creates " + formName);
            return forms[i].create(target);
        }
    }

    WriteLine("Intern couldn't create unknown form: " + formName);
    return NULL;
}