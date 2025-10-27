#include <iostream>
using std::string;
using std::cout;
using std::endl;

// Base class
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

    void Introduce() {
        cout << "Name: " << Name << endl;
        cout << "Company: " << Company << endl;
        cout << "Age: " << Age << endl;
    }

    string getCompany() const {
        return Company;
    }
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
};

int main() {
    Developer d("Francisco", "UFC", 21, "C++");
    Teacher t("Alice", "High School", 35, "Math");

    d.Introduce();
    d.FixBug();

    cout << endl;

    t.Introduce();
    t.PrepareLesson();
}
