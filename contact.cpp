/*
This is a simple address book program, in this we have the options to add contacts, view the contact
list, and search for contacts based on a particular keyword.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string phoneNumber;
};

class AddressBook {
public:
    void run() {
        loadContacts();  // Load existing contacts from file

        while (true) {
            displayMenu();
            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    addContact();
                    break;
                case 2:
                    viewContacts();
                    break;
                case 3:
                    searchContacts();
                    break;
                case 4:
                    saveContacts();  // Save contacts to file before exiting
                    std::cout << "Exiting the address book. Goodbye!\n";
                    return;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        }
    }

private:
    std::vector<Contact> contacts;

    void displayMenu() {
        std::cout << "\nAddress Book Menu:\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. View Contacts\n";
        std::cout << "3. Search Contacts\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
    }

    void addContact() {
        Contact newContact;
        std::cin.ignore();  // Clear the input buffer
        std::cout << "Enter contact name: ";
        std::getline(std::cin, newContact.name);
        std::cout << "Enter contact phone number: ";
        std::getline(std::cin, newContact.phoneNumber);
        contacts.push_back(newContact);
        std::cout << "Contact added successfully.\n";
    }

    void viewContacts() {
        if (contacts.empty()) {
            std::cout << "No contacts available.\n";
        } else {
            std::cout << "\nContact List:\n";
            for (const auto& contact : contacts) {
                std::cout << "Name: " << contact.name << "\tPhone: " << contact.phoneNumber << "\n";
            }
        }
    }

    void searchContacts() {
        std::cin.ignore();  // Clear the input buffer
        std::cout << "Enter search keyword: ";
        std::string keyword;
        std::getline(std::cin, keyword);

        std::vector<Contact> searchResults;

        for (const auto& contact : contacts) {
            // Search both name and phone number for the keyword
            if (contact.name.find(keyword) != std::string::npos ||
                contact.phoneNumber.find(keyword) != std::string::npos) {
                searchResults.push_back(contact);
            }
        }

        if (searchResults.empty()) {
            std::cout << "No matching contacts found.\n";
        } else {
            std::cout << "\nSearch Results:\n";
            for (const auto& result : searchResults) {
                std::cout << "Name: " << result.name << "\tPhone: " << result.phoneNumber << "\n";
            }
        }
    }

    void loadContacts() {
        std::ifstream inputFile("contacts.txt");

        if (inputFile.is_open()) {
            while (!inputFile.eof()) {
                Contact contact;
                std::getline(inputFile, contact.name);
                std::getline(inputFile, contact.phoneNumber);

                if (!contact.name.empty() && !contact.phoneNumber.empty()) {
                    contacts.push_back(contact);
                }
            }

            inputFile.close();
        }
    }

    void saveContacts() {
        std::ofstream outputFile("contacts.txt");

        if (outputFile.is_open()) {
            for (const auto& contact : contacts) {
                outputFile << contact.name << "\n";
                outputFile << contact.phoneNumber << "\n";
            }

            outputFile.close();
        }
    }
};

int main() {
    AddressBook addressBook;
    addressBook.run();

    return 0;
}
