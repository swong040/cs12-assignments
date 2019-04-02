// Stores the elf's family name as a string.

// The elf does not attack elf's from its own family.
// Elf &opp = dynamic_cast<Elf &>(opponent);

// The damage done by the elf is the percentage of the elf's health remaining (health / MAX_HEALTH) multiplied by the elf's attack strength.

#include "Elf.h"

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, const string& family){
	type = ELF;
	this->name = name;
	this->health = health;
	this->attackStrength = attackStrength;
	this->family = family;
}
const string& Elf::getFamily() const{
	return family;
}
void Elf::attack(Character & opponent){
    if(opponent.getType() == type){
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if(opp.getFamily() == family){
            cout << "Elf " << name << " does not attack Elf " << opponent.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
            return;
        }
    } 
        double damage = health / MAX_HEALTH * attackStrength;
        cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
        opponent.setHealth(opponent.getHealth() - damage);
}
