#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>


int main() {
    Phonebook phonebook;
    std::string choice;
    int index;

    while (1) {
        std::cout << "ADD  |  SEARCH  |  REMOVE  |  BOOKMARKED  |  EXIT" << std::endl;
        std::cout << "Enter your Mode: ";
        std::cin >> choice;
        
        
        if (choice == "ADD") {
            phonebook.ADD();
        } else if (choice == "SEARCH") {
            phonebook.SEARCH();
        } else if (choice == "REMOVE") {
            phonebook.REMOVE();
        } else if (choice == "BOOKMARKED"){
            phonebook.BOOKMARK();
        }
         else if (choice == "EXIT") {
            phonebook.EXIT();
            return 0;
        } else {
            std::cout << "Invalid choice" << std::endl;
        }
    }

    return 0;
}