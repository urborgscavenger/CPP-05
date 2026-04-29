#include "Bureaucrat.hpp"
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
        std::stringstream ss;
        ss << "Exception: " << e.what();
        WriteLine(ss.str());
    }

    try {
        Bureaucrat b2("Jeff2", 150);
        std::stringstream ss;
        ss << b2;
        WriteLine(ss.str());
        b2.decrementGrade();
    } catch (exception& e) {
        std::stringstream ss;
        ss << "Exception: " << e.what();
        WriteLine(ss.str());
    }

    try {
        Bureaucrat b3("Jeff3", 0);
    } catch (exception& e) {
        std::stringstream ss;
        ss << "Exception: " << e.what();
        WriteLine(ss.str());
    }

    try {
        Bureaucrat b4("Jeff4", 151); 
    } catch (exception& e) {
        std::stringstream ss;
        ss << "Exception: " << e.what();
        WriteLine(ss.str());
    }

    Bureaucrat b5("Jeff5", 50);
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

    return 0;
}