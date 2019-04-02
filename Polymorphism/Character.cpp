#include "Character.h"
#include <iostream>

using namespace std;

//    CharType type;
//    string name;
//    double health;
//    double attackStrength;
Character::Character(){
     type = type;
     name = "";
     health = 0;
     attackStrength = 0;
}
Character::Character(CharType type, const string &name, double health, double attackStrength){
     this->type = type;
     this->name = name;
     this->health = health;
     this->attackStrength = attackStrength;
}
CharType Character::getType() const{
     return type;
}
const string & Character::getName() const{
     return name;
}
/* Returns the whole number of the health value (static_cast to int). */
int Character::getHealth() const{
     return static_cast<int>(health);
}
void Character::setHealth(double h){
     health = h;
}
/* Returns true if getHealth() returns an integer greater than 0, otherwise false */
bool Character::isAlive() const{
     if(health > 0){
          return true;
     }
     return false;
}
