#include "RobotomyRequestForm.hpp"
#include "CSharpStyle.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const string& t) : AForm("RobotomyRequestForm", 72, 45), target(t) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::performAction() const {
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }

    WriteLine("BZZZZZZZT... DRRRRRRRR...");
    if (std::rand() % 2 == 0) {
        WriteLine(target + " has been robotomized successfully");
    } else {
        WriteLine("Robotomy failed for " + target);
    }
}