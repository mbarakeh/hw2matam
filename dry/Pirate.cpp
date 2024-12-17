
#include "Pirate.h"


Pirate::Pirate(const string& name,const int& bounty): name(name),bounty(0) {}


void Pirate::setName(const string& name){
    this->name = name;
}


std::string Pirate::getName(){
    return name;
}


std::ostream &operator<<(std::ostream &os, const Pirate &pirate){
    os << pirate.name << " " << pirate.bounty;
    return os;
}

void Pirate::set_bounty(const int &bounty) {
    this->bounty = bounty;
}

int Pirate::get_bounty() {
    return this->bounty;
}

