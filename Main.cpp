#include<iostream>
#include<string>
#include<string.h>
#include "Address.h"
#include "Contact.h"
#include "ContactsBook.h"
#include "Group.h"
#include "history.h"
#include "historyob.h"

int main()
{
    ContactsBook contactsBook(10);
    group contactGroup(10); // Create a group instance
    try { //exception handling to avoid exceptions
        for (;;)
        {
            cout << "\t.................... Contacts Book Menu ................." << endl;
            cout << "\t=================================================================\n";
            cout << "\t\t\t1. Add Contact" << endl;
            cout << "\t\t\t2. Search Contact" << endl;
            cout << "\t\t\t3. Print Contacts Sorted by First Name" << endl;
            cout << "\t\t\t4. Print Contacts Sorted by Last Name" << endl;
            cout << "\t\t\t5. Merge and Print Contacts" << endl;
            cout << "\t\t\t6. Total Contacts" << endl;
            cout << "\t\t\t7. Load Contacts from File" << endl;
            cout << "\t\t\t8. Save Contacts to File" << endl;
            cout << "\t\t\t9. Search History" << endl;
            cout << "\t\t\t10. Add Contact In Group" << endl;
            cout << "\t\t\t11. Display contact in group" << endl;
            cout << "\t\t\t12. Save group to file" << endl;
            cout << "\t\t\t13. Load group from file" << endl;
            cout << "\t\t\t14. Display contacts" << endl;
            cout << "\t\t\t15. Update contacts" << endl;
            cout << "\t\t\t0. Exit" << endl;
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;
            if (choice <= 0) {
                throw(choice);
            }
            //switch case for choices
            switch (choice)
            {
            case 1: {
                string first_name, last_name, mobile_number, email_address;
                string house, street, city, country;
                cout << "Enter first name: ";
                cin >> first_name;
                cout << "Enter last name: ";
                cin >> last_name;
                cout << "Enter mobile number: ";
                cin >> mobile_number;
                cout << "Enter email address: ";
                cin >> email_address;
                cout << "Enter house number: ";
                cin >> house;
                cout << "Enter street: ";
                cin >> street;
                cout << "Enter city: ";
                cin >> city;
                cout << "Enter country: ";
                cin >> country;
                Address* address = new Address(house, street, city, country);
                Contact new_contact(first_name, last_name, mobile_number, email_address, address);
                contactsBook.add_contact(new_contact);

                break;
            }
            case 2: {
                int n;
                cout << "Searching Menu\n 1.by name \n2.by phone number\n3.by address: ";
                cout << "Enter your choice : ";
                cin >> n;
                if (n == 1) {
                    string first_name, last_name;
                    cout << "Enter first name: ";
                    cin >> first_name;
                    cout << "Enter last name: ";
                    cin >> last_name;
                    Contact* found_contact = contactsBook.search_contact(first_name, last_name);
                    if (found_contact) {
                        cout << "Contact found:" << endl;
                        found_contact->print_contact();

                    }
                    else {
                        cout << "Contact not found." << endl;
                    }
                }
                else if (n == 2) {
                    string phone;
                    cout << "Enter phone number: ";
                    cin >> phone;
                    Contact* found_contact = contactsBook.search_contact(phone);
                    if (found_contact) {
                        cout << "Contact found:" << endl;
                        found_contact->print_contact();

                    }
                    else {
                        cout << "Contact not found." << endl;
                    }
                }
                else if (n == 3) {
                    string house, street, city, country;
                    cout << "Enter house number: ";
                    cin >> house;
                    cout << "Enter street: ";
                    cin >> street;
                    cout << "Enter city: ";
                    cin >> city;
                    cout << "Enter country: ";
                    cin >> country;
                    Address search_address(house, street, city, country);
                    Contact* found_contact = contactsBook.search_contact(search_address);
                    if (found_contact) {
                        cout << "Contact found:" << endl;
                        found_contact->print_contact();

                    }
                    else {
                        cout << "Contact not found." << endl;
                    }
                }

                break;
            }
            case 3: {
                cout << "Contacts sorted by first name:" << endl;
                contactsBook.sort_contacts_list("first_name");
                contactsBook.print_contacts_sorted("first_name");

                break;
            }
            case 4: {
                cout << "Contacts sorted by last name:" << endl;
                contactsBook.sort_contacts_list("last_name");
                contactsBook.print_contacts_sorted("last_name");

                break;
            }
            case 5:
                cout << "Merged Contacts" << endl;
                contactsBook.merge_duplicates();

                break;
            case 6: {
                cout << "Total contacts: " << contactsBook.total_contacts() << endl;

                break;
            }
            case 7: {
                string file_name;
                cout << "Enter file name to load contacts from: ";
                cin >> file_name;
                contactsBook.load_from_file(file_name);
                contactsBook.print_contacts();

                break;
            }
            case 8: {
                string file_name;
                cout << "Enter file name to save contacts to: ";
                cin >> file_name;
                contactsBook.save_to_file(file_name);

                break;
            }
            case 9: {
                cout << "You are now searching for history\n";

                SearchHistory searchHistory;
                int choice;
                for (int i = 0; i <= 4; i++) {
                    cout << "\nMenu:\n"
                        << "1. Search Contacts\n"
                        << "2. Display Search History\n"
                        << "3. Display Top 5 Searched Contacts\n"
                        << "4. Exit Program\n"
                        << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                    case 1: {
                        int n;
                        cout << "You are searching contact\n";
                        cout << "Enter your choice 1.by name 2.by address 3.by phone number: ";
                        cin >> n;
                        if (n == 1) {
                            string first_name;
                            cout << "Enter first name: ";
                            cin >> first_name;
                            Contact* found_contact = contactsBook.search_contact(first_name, " ");
                            if (found_contact) {
                                cout << "Contact found:" << endl;
                                found_contact->print_contact();

                            }
                            else {
                                cout << "Contact not found." << endl;
                            }
                            searchHistory.searchadd(first_name);
                        }
                        else if (n == 2) {
                            string phone;
                            cout << "Enter phone number: ";
                            cin >> phone;
                            Contact* found_contact = contactsBook.search_contact(phone);
                            if (found_contact) {
                                cout << "Contact found:" << endl;
                                found_contact->print_contact();

                            }
                            else {
                                cout << "Contact not found." << endl;
                            }
                            searchHistory.searchadd(phone);
                        }

                        break;
                    }
                    case 2:
                    {
                        // View Search History
                        searchHistory.Display_History();

                        break;
                    }
                    case 3:
                    {
                        // View Top 5 Frequently Searched Contacts
                        searchHistory.Display_Top5_Contacts();

                        break;
                    }
                    case 4: {
                        cout << "Exiting program." << endl;

                        break;
                    }
                    default: {
                        cout << "Invalid choice. Please try again." << endl;

                        break;
                    }
                    }
                }

                break;
            }
            case 10:
            {
                // Add Contact to Group
                string groupName;
                cout << "Enter group name: ";
                cin >> groupName;
                Contact* contact = contactsBook.copy_contacts_list(); // Copy contacts list
                cout << "Select a contact to add to group:" << endl;
                for (int i = 0; i < contactsBook.total_contacts(); ++i) {
                    cout << i + 1 << ". ";
                    contact[i].print_contact();
                }
                int contactIndex;
                cout << "Enter the index of the contact to add to group: ";
                cin >> contactIndex;
                if (contactIndex >= 1 && contactIndex <= contactsBook.total_contacts()) {
                    // Add the contact to the contactGroup
                    contactGroup.AddContact(contact[contactIndex - 1]);
                }
                else {
                    cout << "Invalid contact index. Please enter a valid index." << endl;
                }

                break;
            }
            case 11:
            {
                cout << "you are now displaying contacts in groups\n";
                contactGroup.DisplayContacts();

                break;
            }
            case 12:
            {
                cout << "you are now saving group in a file\n";
                string file_name;
                cout << "Enter file name to save contacts to: ";
                cin >> file_name;
                break;
            }
            case 13:
            {
                cout << "you are now loading group from file\n";
                string file_name;
                cout << "Enter file name to load contacts from: ";
                cin >> file_name;
                contactsBook.load_from_file(file_name);
                contactsBook.print_contacts();

                break;

            }
            case 14:
            {
                contactsBook.print_contacts();
                break;

            }
            case 15:
            {
                // Update Contact Details
                int index;
                cout << "Enter the index of the contact to update: ";
                cin >> index;
                contactsBook.update_contact_details(index);
                contactsBook.save_to_file("up.txt");
                break;
            }
            case 0: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice! Please enter a valid option." << endl;

                break;
            }
            }
        }
    }
    catch (int a)
    {
        cout << "Please give valid input!!";

    }

    system("pause");
    return 0;
}
