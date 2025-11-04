#include <iostream>
#include <vector>
#include <memory>
using std::string;
using std::vector;
using std::cout;
using std::endl;

/*
==============================
🎮 PROJECT: RPG Battle Simulator
==============================
*/

// ------------------------------------------------------------
// PHASE 1 — CHARACTER CLASSES
// ------------------------------------------------------------

class Character {
private:
    string name;
    int health;
    int attackPower;
    int defense;

public:
    Character() = default;

    Character(string name, int health, int attackPower, int defense)
        : name(name), health(health), attackPower(attackPower), defense(defense) {}

    virtual ~Character() = default;

    virtual void attack(Character& target) = 0; // pure virtual

    void takeDamage(int damage) {
        int effectiveDamage = damage - defense;
        if (effectiveDamage < 0) effectiveDamage = 0;
        health -= effectiveDamage;
        if (health < 0) health = 0;
        cout << name << " took " << effectiveDamage
             << " damage! Remaining health: " << health << endl;
    }

    bool isAlive() const { return health > 0; }

    void displayStats() const {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "AttackPower: " << attackPower << endl;
        cout << "Defense: " << defense << endl;
    }

    // setters/getters
    string getName() const { return name; }
    int getHealth() const { return health; }
    int getAttackPower() const { return attackPower; }
    int getDefense() const { return defense; }

    void setHealth(int h) { health = h; }
};

// ------------------------------------------------------------
// Warrior Class
// ------------------------------------------------------------

class Warrior : public Character {
private:
    bool rage;

public:
    Warrior() = default;
    Warrior(string name, int health, int attackPower, int defense)
        : Character(name, health, attackPower, defense), rage(false) {}

    void attack(Character& target) override {
        int damage = getAttackPower();

        if (rage) {
            cout << "\n⚔️  " << getName() << " is enraged! Attack boosted!\n";
            damage = static_cast<int>(damage * 1.2);
            rage = false;
        }

        cout << getName() << " attacks " << target.getName()
             << " with " << damage << " damage!\n";
        target.takeDamage(damage);
        cout << target.getName() << " now has " << target.getHealth() << " HP.\n";

        if (!rage) {
            rage = true;
            cout << getName() << " builds up RAGE for the next attack!\n";
        }
    }
};

// ------------------------------------------------------------
// Mage Class
// ------------------------------------------------------------

class Mage : public Character {
private:
    int mana;

public:
    Mage() = default;
    Mage(string name, int health, int attackPower, int defense, int mana = 30)
        : Character(name, health, attackPower, defense), mana(mana) {}

    void attack(Character& target) override {
        int damage = getAttackPower();

        if (mana >= 10) {
            damage *= 2;
            mana -= 10;
            cout << "\n🔥 " << getName() << " casts FIREBALL on " << target.getName()
                 << " for " << damage << " damage!\n";
        } else {
            cout << "\n✨ " << getName() << " uses EMBER on " << target.getName()
                 << " for " << damage << " damage!\n";
            mana += 5; // recharge a bit
        }

        target.takeDamage(damage);
        cout << target.getName() << " now has " << target.getHealth() << " HP.\n";
    }
};

// ------------------------------------------------------------
// PHASE 2 — BATTLE ARENA
// ------------------------------------------------------------

class BattleArena {
private:
    vector<Character*> fighters;

public:
    void addFighter(Character* fighter) {
        fighters.push_back(fighter);
    }

    void startBattle() {
        cout << "\n==============================\n";
        cout << "⚔️  Battle Begins!\n";
        cout << "==============================\n";

        if (fighters.size() < 2) {
            cout << "Need at least two fighters to start a battle!\n";
            return;
        }

        Character* fighter1 = fighters[0];
        Character* fighter2 = fighters[1];

        int round = 1;
        while (fighter1->isAlive() && fighter2->isAlive()) {
            cout << "\n----- Round " << round++ << " -----\n";
            fighter1->attack(*fighter2);
            if (!fighter2->isAlive()) break;
            fighter2->attack(*fighter1);
        }

        displayResults();
    }

    void displayResults() {
        cout << "\n==============================\n";
        cout << "🏁 Battle Over!\n";
        cout << "==============================\n";

        for (auto f : fighters) {
            cout << f->getName() << " - " << (f->isAlive() ? "Alive" : "Defeated") << endl;
        }
    }
};

// ------------------------------------------------------------
// PHASE 3 — ITEMS & INVENTORY
// ------------------------------------------------------------

class Item {
private:
    string name;
    int effectValue;

public:
    Item(string name, int effectValue) : name(name), effectValue(effectValue) {}

    void applyEffect(Character& target) {
        cout << "\n💊 " << target.getName() << " uses " << name
             << " and restores " << effectValue << " HP!\n";
        int newHealth = target.getHealth() + effectValue;
        target.setHealth(newHealth);
    }

    string getName() const { return name; }
};

class Inventory {
private:
    vector<Item> items;

public:
    void addItem(const Item& item) { items.push_back(item); }

    void useItem(int index, Character& target) {
        if (index >= 0 && index < items.size()) {
            items[index].applyEffect(target);
            items.erase(items.begin() + index);
        } else {
            cout << "Invalid item index!\n";
        }
    }

    void showItems() const {
        cout << "\nInventory:\n";
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i << ": " << items[i].getName() << endl;
        }
    }
};

// ------------------------------------------------------------
// PHASE 4 — MAIN
// ------------------------------------------------------------

int main() {
    Warrior w("Thor", 100, 25, 5);
    Mage m("Gandalf", 80, 20, 3);

    // Optional: Items and Inventory
    Inventory inv;
    inv.addItem(Item("Health Potion", 30));
    inv.addItem(Item("Mega Potion", 50));

    // Display initial stats
    cout << "\n--- Fighter Stats ---\n";
    w.displayStats();
    cout << endl;
    m.displayStats();

    // Arena
    BattleArena arena;
    arena.addFighter(&w);
    arena.addFighter(&m);

    // Start battle
    arena.startBattle();

    // Post-battle healing example
    cout << "\n🏥 After battle...\n";
    inv.showItems();
    inv.useItem(0, w);
    cout << w.getName() << " now has " << w.getHealth() << " HP.\n";

    return 0;
}
