// Stores the elf's family name as a string.

// The elf does not attack elf's from its own family.
// Elf &opp = dynamic_cast<Elf &>(opponent);

// The damage done by the elf is the percentage of the elf's health remaining (health / MAX_HEALTH) multiplied by the elf's attack strength.
#ifndef ELF_H
#define ELF_H

#include "Character.h"
#include <iostream>

class Elf : public Character{
    private:
    	string family;
    public:
        Elf(const string &name, double health, double attackStrength, const string& family);
        const string& getFamily() const;
        void attack(Character &);
};

#endif