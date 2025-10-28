#include <iostream>
#include <string>
using namespace std;



/**
 A reference in C++ is an alias for an existing variable — it doesn’t create a new copy but directly refers to the same memory location.
 Changing the reference changes the original variable, and unlike pointers, a reference can’t be reassigned once it’s set.
 */

int main() {
    int age = 25;         // Original variable
    int newAge = 30;      // Another variable

    int& refAge = age;    // Reference is another name for 'age'
    cout << "Reference to age: " << refAge << endl;  // prints 25

    refAge = 40;          // changes 'age' directly through the reference
    cout << "New age after refAge = 40: " << age << endl; // prints 40

    // ❌ References cannot be changed to refer to something else
    refAge = newAge;      // Only copies the value (does NOT rebind reference)
    cout << "After refAge = newAge, age becomes: " << age << endl; // prints 30
    cout << "newAge is still: " << newAge << endl; // prints 30

    // -----------------------------
    // 🧩 SUMMARY OUTPUT
    // -----------------------------
    cout << "\nFinal values:" << endl;
    cout << "age: " << age << endl;
    cout << "newAge: " << newAge << endl;
    cout << "refAge (alias to age): " << refAge << endl;

    return 0;
}
