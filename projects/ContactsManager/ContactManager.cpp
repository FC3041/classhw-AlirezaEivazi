#include <iostream>
#include <vector>
#include <string>
#include<fstream>

using namespace std;

class Contact
{
public:
    string name;
    string phonenumber;
    string email;
    string address;

    Contact(const string &name, const string &phonenumber, const string &email, const string &address)
        : name(name), phonenumber(phonenumber), email(email), address(address) {}
};

class ContactManager
{
public:
    vector<Contact> Contacts;

    ContactManager() {}

    void add(const Contact &newcontact)
    {
        Contacts.push_back(newcontact);
        saveToFile();
    }

    void printContacts()
    {
        cout << "Your Contacts: " << endl;

        if (Contacts.empty())
        {
            cout << "No Contacts Found!" << endl;
            return;
        }

        for (int i = 0; i < Contacts.size(); i++)
        {
            cout << i + 1 << "_ Name: " << Contacts[i].name << endl
                 << "   Phone Number: " << Contacts[i].phonenumber << endl
                 << "   Email: " << Contacts[i].email << endl
                 << "   Address: " << Contacts[i].address << endl
                 << "--------------------------" << endl;
        }
    }

    void removeContact()
    {
        if (Contacts.empty())
        {
            cout << "No contacts to remove!" << endl;
            return;
        }

        cout << "Enter the index of the contact to remove: ";
        int index;
        cin >> index;

        if (index < 1 || index > Contacts.size()) 
        {
            cout << "Invalid Index!" << endl;
        }
        else
        {
            Contacts.erase(Contacts.begin() + (index - 1));
            cout << "Contact removed successfully!" << endl;
            saveToFile();
        }
    }

    void searchContact()
    {
        if (Contacts.empty()) 
        {
            cout << "No contacts available to search!" << endl;
            return;
        }
    
        cout << "Enter name to search: ";
        cin.ignore(); 
        string name;
        getline(cin, name);
    
        for (int i = 0; i < Contacts.size(); i++)
        {
            if (Contacts[i].name == name)
            {
                cout << "_ Name: " << Contacts[i].name << endl
                     << "   Phone Number: " << Contacts[i].phonenumber << endl
                     << "   Email: " << Contacts[i].email << endl
                     << "   Address: " << Contacts[i].address << endl
                     << "--------------------------" << endl;
                return; 
            }
        }
    
        cout << "Contact not found!" << endl;
    };

    void editContact()
    {
        if (Contacts.empty()) 
        {
            cout << "No contacts available to edit!" << endl;
            return;
        }
    
        cout << "Enter index to edit: ";
        int index;
        cin >> index;
    
        if (index < 1 || index > Contacts.size()) 
        {
            cout << "Invalid index!" << endl;
            return;
        }
    
        index--; 
    
        cout << "The current contact details are:\n";
        cout << "_ Name: " << Contacts[index].name << endl
             << "   Phone Number: " << Contacts[index].phonenumber << endl
             << "   Email: " << Contacts[index].email << endl
             << "   Address: " << Contacts[index].address << endl
             << "--------------------------" << endl;
    
        cout << "Enter new details (press Enter to keep the current value):\n";
    
        cin.ignore(); 
    
        string newname, newnumber, newemail, newaddress;
        
        cout << "New Name: ";
        getline(cin, newname);
        if (!newname.empty()) 
            Contacts[index].name = newname;
    
        cout << "New Phone Number: ";
        getline(cin, newnumber);
        if (!newnumber.empty()) 
            Contacts[index].phonenumber = newnumber;
    
        cout << "New Email: ";
        getline(cin, newemail);
        if (!newemail.empty()) 
            Contacts[index].email = newemail;
    
        cout << "New Address: ";
        getline(cin, newaddress);
        if (!newaddress.empty()) 
            Contacts[index].address = newaddress;
    
        cout << "Contact updated successfully!\n";
        saveToFile();
    };
    
    void saveToFile()
    {
        ofstream file("contacts.txt");
        if (!file)
        {
            cout << "Error saving contacts to file!" << endl;
            return;
        }

        for (const auto &contact : Contacts)
        {
            file << contact.name << endl
                 << contact.phonenumber << endl
                 << contact.email << endl
                 << contact.address << endl;
        }

        file.close();
    };

    void loadFromFile()
    {
        ifstream file("contacts.txt");
        if (!file)
        {
            cout << "No existing contacts found!" << endl;
            return;
        }

        Contacts.clear();
        string name, phonenumber, email, address;

        while (getline(file, name) && getline(file, phonenumber) && getline(file, email) && getline(file, address))
        {
            Contacts.push_back(Contact(name, phonenumber, email, address));
        }

        file.close();

        if (Contacts.empty()) {
            cout << "No existing contacts found!" << endl;
        };
    };

    void ShowMenu()
    {
        cout<<"1. Add Contact  "<<endl
            <<"2. Remove Contact  "<<endl
            <<"3. Search Contact  "<<endl
            <<"4. Edit Contact  "<<endl
            <<"5. Show All Contacts  "<<endl
            <<"6. Exit  "<<endl
            <<"Enter your choice: "<<endl;
    };
};

int main()
{
    ContactManager newcontact;
    newcontact.loadFromFile();

    int number;
    do{
        newcontact.ShowMenu();
        cin>>number;
        
        switch(number)
        {
            case 1:
            {
                string name, phone, email, address;
                cin.ignore();
                cout << "Enter Name: "; getline(cin, name);
                cout << "Enter Phone Number: "; getline(cin, phone);
                cout << "Enter Email: "; getline(cin, email);
                cout << "Enter Address: "; getline(cin, address);
                newcontact.add(Contact(name, phone, email, address));
                break;
            }
            case 2:
                newcontact.removeContact();
                break;
            
            case 3:
                newcontact.searchContact();
                break;
            
            case 4:
                newcontact.editContact();
                break;
            
            case 5:
                newcontact.printContacts();
                break;
            
            case 6:
                cout << "Exiting program..." << endl;
                return 0;
            
            default:
                cout << "Invalid choice, please try again!" << endl;
        }
    }while(true);
};