#ifndef APART_HPP
#define APART_HPP

#include <string>

class Apart {
private:
    std::string name;  // The name of the apartment
    int year;  // The year of the apartment

public:
    Apart();  // Default constructor

    void setName(const std::string &n);  // Sets the name of the apartment
    void setYear(int y);  // Sets the year of the apartment
    std::string getName() const;  // Retrieves the name of the apartment
    int getYear() const;  // Retrieves the year of the apartment
};

#endif
