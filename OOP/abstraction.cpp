#include <iostream>
using std::string;


class AbstractEmployee { // Abstract Class
    virtual void AskForPromotion()=0; // Abstract method, any class that inherits this class must implement this method.
};

class Employee:AbstractEmployee { //Notice now its inheriting the AbstractEmployee Class
private:
    string Name;
    string Company;
    int Age;
public:

 void AskForPromotion() { // Using the abstract method that is required
    if(Age>30) {
        std::cout<<Name<< " got promoted!" << std::endl;
    }
    else {
        std::cout<<Name<< " sorry you are not going to get promoted..." << std::endl;

    }
 }

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




    void Introduction() {
        std::cout<<"Name - " << Name << std::endl;
        std::cout<<"Company - " << Company << std::endl;
        std::cout<<"Age - " << Age << std::endl;

    }

public:

    Employee() {

    }
    Employee(string name, string company, int age) { // Modified Contrustor
        Name = name;
        Company = company;
        Age = age;
    }

    };


int main() {

    Employee employee1 = Employee("Francisco","UFC",21);
    Employee employee2 = Employee("Bob","NFL",35);

    employee1.AskForPromotion(); // Use case of using Abstract Method
    employee2.AskForPromotion();

}
