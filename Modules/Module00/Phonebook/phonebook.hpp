#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include "contact.hpp"
#include <vector>

class Phonebook {
private:
    std::vector<Contact> contacts;
  

public:
    Phonebook();

    void ADD();
    void SEARCH();
    void REMOVE();
    void BOOKMARK(); // show the bookmarked lists
    void EXIT();



    
    bool isDuplicate(const std::string& phoneNumber) const; 
};

#endif

