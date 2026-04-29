#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "CSharpStyle.hpp"
#include <sstream>

int main() {
    try {
        Bureaucrat b1("Jeff", 1);
        std::stringstream ss;
        ss << b1;
        WriteLine(ss.str());
        b1.incrementGrade();
    } catch (exception& e) {
        WriteLine("Exception: " + string(e.what()));
    }

    try {
        Bureaucrat b2("Jeff2", 150);
        std::stringstream ss;
        ss << b2;
        WriteLine(ss.str());
        b2.decrementGrade(); 
    } catch (exception& e) {
        WriteLine("Exception: " + string(e.what()));
    }

    try {
        Bureaucrat b3("Jeff3", 0); 
    } catch (exception& e) {
        WriteLine("Exception: " + string(e.what()));
    }

    try {
        Bureaucrat b4("Alice", 151);
    } catch (exception& e) {
        WriteLine("Exception: " + string(e.what()));
    }

    Bureaucrat b5("Charlie", 50);
    std::stringstream ss5;
    ss5 << b5;
    WriteLine(ss5.str());
    b5.incrementGrade();
    std::stringstream ss5a;
    ss5a << b5;
    WriteLine(ss5a.str());
    b5.decrementGrade();
    std::stringstream ss5b;
    ss5b << b5;
    WriteLine(ss5b.str());

    Bureaucrat b6 = b5;
    std::stringstream ss6;
    ss6 << b6;
    WriteLine(ss6.str());

    Bureaucrat b7;
    b7 = b5;
    std::stringstream ss7;
    ss7 << b7;
    WriteLine(ss7.str());

    try {
        Form f1("Form A", 50, 25);
        std::stringstream ssf1;
        ssf1 << f1;
        WriteLine(ssf1.str());

        Bureaucrat signer("Signer", 40);
        signer.signForm(f1);
        std::stringstream ssf1a;
        ssf1a << f1;
        WriteLine(ssf1a.str());

        Bureaucrat lowSigner("LowSigner", 60);
        lowSigner.signForm(f1);

        Form f2("Form B", 30, 20);
        lowSigner.signForm(f2); 
        std::stringstream ssf2;
        ssf2 << f2;
        WriteLine(ssf2.str());

    } catch (exception& e) {
        WriteLine("Exception: " + string(e.what()));
    }

    try {
        Form f3("Invalid Form", 0, 25);
    } catch (exception& e) {
        WriteLine("Exception: " + string(e.what()));
    }

    try {
        Form f4("Invalid Form2", 25, 151);
    } catch (exception& e) {
        WriteLine("Exception: " + string(e.what()));
    }

    return 0;
}