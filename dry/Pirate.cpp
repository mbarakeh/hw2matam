
#include "Pirate.h"


Pirate::Pirate(const string& name, int bounty,const DEVIL_FRUIT& devilFruit): name(name),bounty(bounty),devilFruit(devilFruit) {}


void Pirate::setName(const string& name){
    this->name = name;
}


std::string Pirate::getName(){
    return name;
}


DEVIL_FRUIT Pirate::getDevilFruit(){
    return devilFruit;
}

void Pirate::setDevilFruit(DEVIL_FRUIT devilFruit){
    this->devilFruit = devilFruit;
}


const char* const devilFruitNames[] = {
        "Gum Gum",
        "Smoke Smoke",
        "Flame Flame",
        "Rumble Rumble",
        "String String",
        "Ice Ice",
        "None"
};


std::ostream &operator<<(std::ostream &os, const Pirate &pirate){
    os << pirate.name << " " << pirate.bounty << " (Devil Fruit: " << devilFruitNames[pirate.devilFruit] << ")"  ;
    return os;
}

void Pirate::set_bounty(int bounty) {
    this->bounty = bounty;
}

int Pirate::get_bounty() {
    return this->bounty;
}

