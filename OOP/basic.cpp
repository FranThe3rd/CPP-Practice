#include <iostream>
using std::string;

class Employee {
public: // Access Modifier

//Attributes
    string Name;
    string Company;
    int Age;


    void Introduction() { //void method
        std::cout<<"Name - " << Name << std::endl;
        std::cout<<"Company - " << Company << std::endl;
        std::cout<<"Age - " << Age << std::endl;

    }

public:

Employee() { // Default Constructor

}
Employee(string name, string company, int age) { // Modified Contrustor
    Name = name;
    Company = company;
    Age = age;
}

};


int main() {

    Employee employee1 = Employee("Francisco","UFC",21);
    employee1.Introduction();
    Employee employee2 = Employee("John","Gay",21);
    employee2.Introduction();
    return  0;
}
