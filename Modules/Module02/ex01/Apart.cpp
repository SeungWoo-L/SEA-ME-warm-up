#include "Apart.hpp"

Apart::Apart() : name("Unknown"), year(0) {}  // Default constructor that initializes the name as "Unknown" and the year as 0

void Apart::setName(const std::string &n) {
    name = n;
}

void Apart::setYear(int y) {
    year = y;
}

std::string Apart::getName() const {
    return name;
}

int Apart::getYear() const {
    return year;
}