#include <iostream>
using std::string;
using std::cout;
using std::endl;

// Base class (abstract)
class Employee {
protected:
    string Name;
    int Age;

private:
    string Company;

public:
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    // Common method
    void Introduce() {
        cout << "Name: " << Name << endl;
        cout << "Company: " << Company << endl;
        cout << "Age: " << Age << endl;
    }

    // Getter
    string getCompany() const {
        return Company;
    }

    // 🔹 Virtual function for polymorphism
    virtual void Work() = 0; // pure virtual -> makes Employee abstract
};

// Derived class
class Developer : public Employee {
public:
    string FavoriteLanguage;

    Developer(string name, string company, int age, string favLang)
        : Employee(name, company, age) {
        FavoriteLanguage = favLang;
    }

    void FixBug() {
        cout << Name << " fixed a bug using " << FavoriteLanguage
             << " at " << getCompany() << "!" << endl;
    }

    // Override the pure virtual function
    void Work() override {
        cout << Name << " is writing " << FavoriteLanguage << " code." << endl;
    }
};

// Another derived class
class Teacher : public Employee {
public:
    string Subject;

    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age) {
        Subject = subject;
    }

    void PrepareLesson() {
        cout << Name << " is preparing a " << Subject
             << " lesson for " << getCompany() << "." << endl;
    }

    // Override the pure virtual function
    void Work() override {
        cout << Name << " is teaching " << Subject << "." << endl;
    }
};

int main() {
    Developer d("Francisco", "UFC", 21, "C++");
    Teacher t("Alice", "High School", 35, "Math");

    // 🔹 Polymorphism in action
    Employee* e1 = &d;
    Employee* e2 = &t;

    e1->Work(); // calls Developer's version
    e2->Work(); // calls Teacher's version

    cout << endl;

    d.FixBug();
    t.PrepareLesson();
}
