// Stores the warrior's allegiance as a string.

// The warrior does not attack warriors that have the same allegiance.
// Warrior &opp = dynamic_cast<Warrior &>(opponent);

// The damage done by the warrior is the percentage of the warrior's health remaining (health / MAX_HEALTH) multiplied by the warrior's attack strength.
#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"
#include <iostream>

class Warrior : public Character{
    private:
    	string allegiance;
    public:
        const string& getAllegiance() const;
        Warrior(const string &name, double health, double attackStrength, const string& allegiance);
        void attack(Character &);
};

#endif