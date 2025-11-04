#include <iostream>
using std::string;

/*
==============================
🎮 PROJECT: RPG Battle Simulator
==============================

GOAL:
    Practice Object-Oriented Programming (OOP) in C++ by building
    a console-based battle simulator using abstraction, inheritance,
    polymorphism, and composition.
*/


// ------------------------------------------------------------
// PHASE 1 — DESIGN YOUR CLASS HIERARCHY
// ------------------------------------------------------------


/*
1. Class: Character (Base Class)
    - Abstract class (cannot be instantiated)
    - Common attributes:
        - name
        - health
        - attackPower
        - defense
    - Keep attributes private
    - Provide getters/setters
    - Declare pure virtual methods:
        - attack(Character& target)
    - Add common functions:
        - takeDamage()
        - isAlive()
        - displayStats()

    // Concepts: Abstraction, Encapsulation
*/

//Character class
class Character {

// The character attributes
private:
    string name;
    int health;
    int attackPower;
    int defense;

public:
    // Default constructor
    Character() = default;

    // Constructor using member initializer lists
    Character(string name, int health, int attackPower, int defense) : name(name), health(health),attackPower(attackPower),defense(defense) {}


    virtual void attack(Character& target) = 0; // Abstract Class

    // This function is for taking damage
    void takeDamage(int damage) {
        int effectiveDamage = damage - defense;
        if (effectiveDamage < 0) {
            effectiveDamage = 0;
        }

        health -= effectiveDamage;
        if (health < 0) {
            health = 0;
        }
        std::cout << name << " took " << effectiveDamage
                  << " damage! Remaining health: " << health << std::endl;
    }

    // Checks if the character is still is alive
    bool isAlive() {
        if (health <= 0) {
            return false;
        }
        else {
            return true;
        }
    }

    // Displays Stats
    void displayStats() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "health: " << health << std::endl;
        std::cout << "AttackPower: " << attackPower << std::endl;
        std::cout << "defense: " << defense << std::endl;
    }


    // Setters
    void setName(string n) { name = n; }
    void sethealth(int h) { health = h; }
    void setAttackPower(int a) { attackPower = a; }
    void setdefense(int d) { defense = d; }

    // Getters
    string getName() const { return name; }
    int gethealth() const { return health; }
    int getAttackPower() const { return attackPower; }
    int getdefense() const { return defense; }
};





/*
2. Classes: Warrior, Mage, Archer (Derived Classes)
    - Inherit from Character
    - Each adds a unique attribute:
        - Warrior → rage
        - Mage → mana
        - Archer → arrows
    - Override attack() with unique logic
    - Add one unique ability per class (e.g. powerStrike(), fireball(), etc.)

    // Concepts: Inheritance, Polymorphism
*/

class Warrior: public Character {
private:
    bool rage;
public:
    Warrior() = default;

    Warrior(string name, int health, int attackPower, int defense)
         : Character(name, health, attackPower, defense) {
             rage(rage);
         }



         void attack(Character& target) {
             int damage = getAttackPower();
             if (rage) {
                 std::cout << "Warrior is enraged" << std::endl;
                 damage *= 1.2
                 std::cout << "Warrior attacks " << target.getName() << " with " << damage << " damage";
             }
             else {
                 std::cout << "Warrior attacks " << target.getName() << " with " << damage << " damage";
             }
         }

};







// ------------------------------------------------------------
// PHASE 2 — CREATE THE BATTLE SYSTEM
// ------------------------------------------------------------


/*
3. Class: BattleArena
    - Manages fights between characters
    - Attributes:
        - vector<Character*> fighters;
    - Methods:
        - addFighter(Character* fighter)
        - startBattle()
        - displayResults()
    - Use polymorphism to call virtual methods dynamically

    // Concepts: Polymorphism, Dynamic Dispatch
*/

// Your BattleArena class here 👇







// ------------------------------------------------------------
// PHASE 3 — ADD COMPOSITION
// ------------------------------------------------------------


/*
4. Class: Item
    - Represents usable items (potions, weapons, buffs)
    - Attributes:
        - name
        - effectValue
    - Methods:
        - applyEffect(Character& target)
*/

// Your Item class here 👇








/*
5. Class: Inventory
    - Composition: belongs to a Character
    - Attributes:
        - vector<Item> items;
    - Methods:
        - addItem()
        - useItem(Character& target)

    // Concepts: Composition (“has-a” relationship)
*/

// Your Inventory class here 👇







// ------------------------------------------------------------
// PHASE 4 — PROGRAM FLOW
// ------------------------------------------------------------


/*
6. main.cpp should:
    - Create several characters (Warrior, Mage, Archer)
    - Add them to the BattleArena
    - Optionally assign items
    - Start the battle
    - Print results

    // Concepts: Class interaction, Program structure
*/

int main() {

    // Create your objects and simulate battles here 👇




    return 0;
}
