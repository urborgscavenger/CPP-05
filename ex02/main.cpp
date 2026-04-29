#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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

    return 0;
}