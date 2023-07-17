#include <iostream>
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

    if(Phonebook::contacts.empty()){
        std::cout<<"Phonebook is Empty\n";
        return;
    }
    else{

    std::cout << "INDEX" << '\t'  << "NAME" << '\n';

    for (int i=0;i<contacts.size();i++){
        std::cout << (i+1) << '\t'  <<contacts[i].Name << '\n';
    }

    int index;
    std::cout<<"Choose index of contract: ";
    std::cin>>index;
    index--;

    if(index<0 || index>=contacts.size()){
        std::cout<<"Invaild index\n";
        return;
    }
    else{

      std::cout << "Name: " << Phonebook::contacts[index].Name << " , "
                << "PhoneNumber: " << Phonebook::contacts[index].PhoneNumber << " , "
                << "NickName: " << Phonebook::contacts[index].NickName << '\n';
        }
    while (1){
        std::string Y_N;
        std::cout<<"Do you want to bookmark this contract? (Y/N): ";
        std::cin>>Y_N;

        if (Y_N=="Y" || Y_N == "y"){
            contacts[index].bookmarked = true;
            std::cout<<contacts[index].Name<<"'s contract is Added on Bookmark\n";
            break;
        }
        else if (Y_N=="N" || Y_N == "n"){
            std::cout<<"Not Added\n";
            break;
            }
        }
    }
};


void Phonebook::REMOVE(){

    if(Phonebook::contacts.empty()){
        std::cout<<"Phonebook is Empty\n";
        return;
    }

    else{
        std::string Index_or_phoneN;

         for (int i=0;i<contacts.size();i++){
        std::cout << (i+1) << '\t'  << "Name : " << contacts[i].Name << "PhoneNumber : " << 
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


void Phonebook::BOOKMARK(){

   std::cout << "Bookmarked Contacts:\n";
    for (const auto& contact : contacts) {
        if(contact.IsBookmarked()){
        std::cout << "Name: " << contact.Name << "\n";
        std::cout << "Phone Number: " << contact.PhoneNumber << "\n";
        std::cout << "Nickname: " << contact.NickName << "\n\n";
        }
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




