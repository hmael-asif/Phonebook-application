#include <iostream>
#include <string>
using namespace std; 
const int MaxContacts = 100;

class Contact {
public:
    Contact() : name(""), phoneNumber("") {}

    void setContact(const string& name, const string& phoneNumber) {
        this->name = name;
        this->phoneNumber = phoneNumber;
    }

    void displayContact() const {
        cout << "Name: " << name << "\tPhone Number: " << phoneNumber << endl;
    }

    bool isEmpty() const {
        return name.empty() && phoneNumber.empty();
    }

    const string& getName() const {
        return name;
    }

private:
    string name;
    string phoneNumber;
};

class PhoneBook {
public:
    PhoneBook() {
        for (int i = 0; i < MaxContacts; ++i) {
            contacts[i] = Contact();
        }
    }

    void addContact(const string& name, const string& phoneNumber) {
        for (int i = 0; i < MaxContacts; ++i) {
            if (contacts[i].isEmpty()) {
                contacts[i].setContact(name, phoneNumber);
                cout << "Contact added successfully!" << endl;
                return;
            }
        }
        cout << "Phone book is full. Cannot add more contacts." << endl;
    }

    void viewContacts() const {
        bool empty = true;
        for (int i = 0; i < MaxContacts; ++i) {
            if (!contacts[i].isEmpty()) {
                empty = false;
                contacts[i].displayContact();
            }
        }
        if (empty) {
            cout << "Phone book is empty." << endl;
        }
    }

    void searchContact(const string& name) const {
        bool found = false;
        for (int i = 0; i < MaxContacts; ++i) {
            if (contacts[i].getName() == name) {
                cout << "Contact found:" << endl;
                contacts[i].displayContact();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Contact not found." << endl;
        }
    }

    void deleteContact(const string& name) {
        for (int i = 0; i < MaxContacts; ++i) {
            if (contacts[i].getName() == name) {
                contacts[i] = Contact();  // Clear the contact
                cout << "Contact deleted successfully." << endl;
                return;
            }
        }
        cout << "Contact not found." << endl;
    }

private:
    Contact contacts[MaxContacts];
};

int main() {
    PhoneBook phoneBook;
    int choice;
    string name, phoneNumber; // Move variable declarations here

    while (true) {
        cout << "\nPhone Book Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                cin.ignore(); // Clear the newline character in the input buffer
                getline(cin, name);
                cout << "Enter Phone Number: ";
                getline(cin, phoneNumber);
                phoneBook.addContact(name, phoneNumber);
                break;
            case 2:
                phoneBook.viewContacts();
                break;
            case 3:
                cout << "Enter the name to search: ";
                cin.ignore(); // Clear the newline character in the input buffer
                getline(cin, name);
                phoneBook.searchContact(name);
                break;
            case 4:
                cout << "Enter the name to delete: ";
                cin.ignore(); // Clear the newline character in the input buffer
                getline(cin, name);
                phoneBook.deleteContact(name);
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
