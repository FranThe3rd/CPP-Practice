#include <iostream>
using std::string;

class Employee {
private:
    string Name;
    string Company;
    int Age;
public:

// Setter and Getters
    void setName(string name) {
        Name = name;
    }
    string getName() {
        return Name;
    }

    void setCompany(string company) {
        Company = company;
    }

    string getCompany() {
        return Company;
    }

    void setAge(int age) {
        if (age >=18) {
            Age = age;

        }

    }

    int getAge() {
        return Age;
    }




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
    employee1.setAge(31);
    std::cout<<employee1.getName()<< " is " <<employee1.getAge()<< " years old";
}
