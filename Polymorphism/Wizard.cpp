// Stores the wizard's rank as an int.

// When a wizard attacks another wizard, the damage done is the wizard's attack strength multiplied by the ratio of the attacking wizard's rank over the defending wizard's rank.
// Wizard &opp = dynamic_cast<Wizard &>(opponent);

// The damage done to non-wizards is just the attack strength. The wizard's health is not taken into consideration.

#include "Wizard.h"

using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, const int& rank){
	type = WIZARD;
	this->name = name;
	this->health = health;
	this->attackStrength = attackStrength;
	this->rank = rank;
}
int Wizard::getRank() const{
	return rank;
}
void Wizard::attack(Character & opponent){
	double damage = attackStrength;
	if(opponent.getType() == type){
 		Wizard &opp = dynamic_cast<Wizard &>(opponent);
 		damage = static_cast<double>(rank) / opp.getRank() * attackStrength;
	}
	cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
	cout << opponent.getName() << " takes " << damage << " damage." << endl;

	opponent.setHealth(opponent.getHealth() - damage);
}