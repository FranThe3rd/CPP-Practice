#include <iostream>


// Pointers - a variable that stores a memeory adress of another variable
//            sometimes it's easier to work with an address.



int main() {

    // * dereference operator
    // & address-of operator
    std::cout << std::endl << "String Example: " << std::endl;        // address of first element ("pizza1")

    std::string name = "Bro";
    std::string* pName = &name;
    std::cout << pName << std::endl;     // It outputs 0xb5903ff770
    std::cout << *pName  << std::endl;  // It outputs "Bro", using the dereference operator

    std::cout << std::endl << "Integer Example: " << std::endl;        // address of first element ("pizza1")


    int age = 21;
    int* pAge = &age;
    std::cout << *pAge  << std::endl; // print outs 21 since I am using the dereference operator


    std::cout << std::endl << "Array Example: " << std::endl;        // address of first element ("pizza1")

    std::string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};

    // By default, 'freePizzas' is a pointer to the first element
    std::cout << freePizzas << std::endl;        // address of first element ("pizza1") 0x25261ff570
    std::cout << *freePizzas << std::endl;       // first element: "pizza1"

    // Access specific elements using indices
    std::cout << freePizzas[2] << std::endl;     // "pizza3"

    // You can also use pointer arithmetic
    std::cout << *(freePizzas + 1) << std::endl; // "pizza2"
    std::cout << *(freePizzas + 3) << std::endl; // "pizza4"

        return 0;
}
