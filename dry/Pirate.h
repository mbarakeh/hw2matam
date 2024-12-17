
#pragma once

#include <iostream>

using std::string;

class Pirate {
private:
    string name;
    int bounty;

public:
    Pirate() : name("Unknown"),bounty(0) {}

    Pirate(const string& name, const int& bounty);

    ~Pirate() = default;

    void setName(const string& name);

    string getName();

    void set_bounty(const int& bounty);

    int get_bounty();

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
