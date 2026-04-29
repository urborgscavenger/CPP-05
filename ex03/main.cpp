#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "CSharpStyle.hpp"

int main() {
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 130);
    Bureaucrat engineer("Engineer", 40);
    Bureaucrat intern("Intern", 150);

    WriteLine("=== Shrubbery tests ===");
    ShrubberyCreationForm shrub("home");
    intern.signForm(shrub);
    worker.signForm(shrub);
    intern.executeForm(shrub);
    worker.executeForm(shrub);

    WriteLine("");
    WriteLine("=== Robotomy tests ===");
    RobotomyRequestForm robot("Bender");
    worker.signForm(robot);
    engineer.signForm(robot);
    worker.executeForm(robot);
    engineer.executeForm(robot);
    boss.executeForm(robot);

    WriteLine("");
    WriteLine("=== Presidential tests ===");
    PresidentialPardonForm pardon("Ford Prefect");
    worker.signForm(pardon);
    boss.signForm(pardon);
    worker.executeForm(pardon);
    boss.executeForm(pardon);

    WriteLine("");
    WriteLine("=== Unsigned execute test ===");
    PresidentialPardonForm unsignedForm("Arthur Dent");
    boss.executeForm(unsignedForm);

    WriteLine("");
    WriteLine("=== Intern tests ===");
    Intern someRandomIntern;

    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf != NULL) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    AForm* shrubForm = someRandomIntern.makeForm("shrubbery creation", "garden");
    if (shrubForm != NULL) {
        boss.signForm(*shrubForm);
        boss.executeForm(*shrubForm);
        delete shrubForm;
    }

    AForm* pardonByIntern = someRandomIntern.makeForm("presidential pardon", "Trillian");
    if (pardonByIntern != NULL) {
        boss.signForm(*pardonByIntern);
        boss.executeForm(*pardonByIntern);
        delete pardonByIntern;
    }

    AForm* unknown = someRandomIntern.makeForm("coffee request", "office");
    if (unknown != NULL) {
        delete unknown;
    }

    return 0;
}