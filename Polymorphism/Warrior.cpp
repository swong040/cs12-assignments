// Stores the warrior's allegiance as a string.

// The warrior does not attack warriors that have the same allegiance.
// Warrior &opp = dynamic_cast<Warrior &>(opponent);

// The damage done by the warrior is the percentage of the warrior's health remaining (health / MAX_HEALTH) multiplied by the warrior's attack strength.

#include "Warrior.h"

using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, const string& allegiance){
    type = WARRIOR;
    this->name = name;
    this->health = health;
    this->attackStrength = attackStrength;
    this->allegiance = allegiance;
}
const string& Warrior::getAllegiance() const{
    return allegiance;
}
void Warrior::attack(Character & opponent){
    if(opponent.getType() == type){
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(opp.getAllegiance() == allegiance){
            cout << "Warrior " << name << " does not attack Warrior " << opponent.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
            return;
        }
    } 
        double damage = health / MAX_HEALTH * attackStrength;
        cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
        opponent.setHealth(opponent.getHealth() - damage);

}
