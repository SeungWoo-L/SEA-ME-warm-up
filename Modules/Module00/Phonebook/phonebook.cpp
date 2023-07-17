#include <iostream>
#include <limits>
#include "phonebook.hpp"



Phonebook::Phonebook(){}

void Phonebook::ADD() {
    std::string Name, PhoneNumber, NickName;
    std::cout << "Contact Information (Name, Phone number, Nickname)\n";
    std::cout << "Name: ";
    std::cin >> Name;

    std::cout << "Phone number: ";
    std::cin >> PhoneNumber;

    while(isDuplicate(PhoneNumber)){
        std::cout << "This Number is already Registered" << std::endl;
        std::cout << "Please Enter the different PhoneNumber : " ;
        std::cin >> PhoneNumber;
        
    }

    std::cout << "Nickname: ";
    std::cin >> NickName;

    Contact person(Name, PhoneNumber, NickName);

    std::cout << "\n";

    contacts.push_back(person);
}

void Phonebook::SEARCH() {
    if (Phonebook::contacts.empty()) {
        std::cout << "Phonebook is Empty\n";
        return;
    }
    else {
        std::cout << "INDEX" << '\t' << "NAME" << '\n';

        for (int i = 0; i < contacts.size(); i++) {
            std::cout << (i + 1) << '\t' << contacts[i].Name << '\n';
        }

        int index;
        std::cout << "Choose index of contract: ";
        std::cin >> index;

        if (std::cin.fail()) {
            std::cout << "Invalid input! Please enter a valid index number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        index--;

        if (index < 0 || index >= contacts.size()) {
            std::cout << "Invalid index\n";
            return;
        }
        else {
            std::cout << "Name: " << Phonebook::contacts[index].Name << " , "
                      << "PhoneNumber: " << Phonebook::contacts[index].PhoneNumber << " , "
                      << "NickName: " << Phonebook::contacts[index].NickName << '\n';
        }

        while (true) {
            std::string Y_N;
            std::cout << "Do you want to bookmark this contract? (Y/N): ";
            std::cin >> Y_N;

            if (Y_N == "Y" || Y_N == "y") {
                contacts[index].SetBookmarked(true);
                std::cout << contacts[index].Name << "'s contract is added to bookmarks\n";
                break;
            }
            else if (Y_N == "N" || Y_N == "n") {
                std::cout << "Not added\n";
                break;
            }
        }
    }
}



void Phonebook::REMOVE(){

    if(Phonebook::contacts.empty()){
        std::cout<<"Phonebook is Empty\n";
        return;
    }

    else{
        std::string Index_or_phoneN;

         for (int i=0;i<contacts.size();i++){
        std::cout << (i+1) << '\t'  << "Name : " << contacts[i].Name << "  PhoneNumber : " << 
         contacts[i].PhoneNumber <<  '\n';
        }

        std::cout <<"Which Contract do you want to remove? (Index or PhoneNumber) : ";
        
        
        std::cin >> Index_or_phoneN;

        for (int i=0; i<contacts.size();i++){
            if (Index_or_phoneN == contacts[i].PhoneNumber){
                std::cout<<contacts[i].Name<<"'s contract is Deleted\n";
                contacts.erase(contacts.begin()+i);
                return;
            }
        }

        int index = std::stoi(Index_or_phoneN);

        if(index<=0 || index > contacts.size()){
             std::cout<<"Invaild Phone number or Index!\n";
            return;
            
        }

        index--;
        std::cout<<contacts[index].Name<<"'s contract is Deleted\n";
        contacts.erase(contacts.begin()+index);
        return;
    }

}


void Phonebook::BOOKMARK() {
    std::vector<int> bookmarkedIndices;

    std::cout << "Bookmarked Contacts:\n";
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].IsBookmarked()) {
            bookmarkedIndices.push_back(i);
            std::cout << "Index: " << (i + 1) << "\t";
            std::cout << "Name: " << contacts[i].Name << "\t";
            std::cout << "Phone Number: " << contacts[i].PhoneNumber << "\t";
            std::cout << "Nickname: " << contacts[i].NickName << "\t\n";
        }
    }

    if (bookmarkedIndices.empty()) {
        std::cout << "No bookmarked contacts found.\n";
        return;
    }

    std::cout << "Do you want to change the Bookmark setting? (Y/N): ";
    std::string choice;
    std::cin >> choice;

    if (choice == "Y" || choice == "y") {
        int index;
        std::cout << "Enter the index number of the contact to remove the bookmark: ";
        if (!(std::cin >> index)) {
            std::cout << "Invalid input! Please enter a valid index number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        if (index <= 0 || index > bookmarkedIndices.size()) {
            std::cout << "Invalid index number!\n";
            return;
        }

        index = bookmarkedIndices[index - 1];
        contacts[index].SetBookmarked(false);
        std::cout << contacts[index].Name << "'s bookmark has been removed\n";
    }
}


 void Phonebook::EXIT(){
    std::cout << "Exiting the phonebook. Goodbye!\n";

 }


 bool Phonebook::isDuplicate(const std::string& phoneNumber) const{
    for (const auto& contacts : contacts){
        if(contacts.GetPhoneNum() == phoneNumber){
            return true;
        }
    } 
    return false;
 }




