
#pragma once

#include <iostream>

using std::string;

enum DEVIL_FRUIT {
    GUM_GUM_FRUIT,
    SMOKE_SMOKE_FRUIT,
    FLAME_FLAME_FRUIT,
    RUMBLE_RUMBLE_FRUIT,
    STRING_STRING_FRUIT,
    ICE_ICE_FRUIT,
    NONE
};

class Pirate {
private:
    string name;
    int bounty;
    DEVIL_FRUIT devilFruit;

public:
    Pirate(): name("Unknown"), bounty(0), devilFruit(DEVIL_FRUIT::NONE){}

    Pirate(const string& name, int bounty ,const DEVIL_FRUIT& devilFruit = DEVIL_FRUIT::NONE);

    ~Pirate() = default;

    void setName(const string& name);
    void setDevilFruit(DEVIL_FRUIT devilFruit);
    void set_bounty(int bounty);
    int get_bounty();

    string getName();
    DEVIL_FRUIT getDevilFruit();

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
