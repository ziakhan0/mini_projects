#include"ContactsBook.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
ContactsBook::ContactsBook()
{

}

ContactsBook::ContactsBook(int size_of_list)
	: size_of_contacts(size_of_list), contacts_count(0) {
	contacts_list = new Contact[size_of_list];
}

ContactsBook::~ContactsBook() {
	delete[] contacts_list; // Deallocate dynamically allocated memory
}

void ContactsBook::add_contact(const Contact& contact) {
	if (full()) {
		//resize list function call only in the case when the list is full
		resize_list();
	}
	contacts_list[contacts_count++] = contact;
}

int ContactsBook::total_contacts() {
	return contacts_count;
}

bool ContactsBook::full() {
	return (contacts_count >= size_of_contacts);
}

void ContactsBook::resize_list()
{
	int new_size = size_of_contacts * 2;
	if (new_size == 0) new_size++;
	Contact* new_list = new Contact[new_size];
	for (int i = 0; i < size_of_contacts; ++i) {
		new_list[i] = contacts_list[i];
	}
	delete[] contacts_list;
	contacts_list = new_list;
	size_of_contacts = new_size;
}

// Function to search for a contact by first name and last name.
Contact* ContactsBook::search_contact(string first_name, string last_name) {
	for (int i = 0; i < contacts_count; ++i) {
		if (contacts_list[i].getFirstName() == first_name && contacts_list[i].getLastName() == last_name) {
			return &contacts_list[i];
		}
	}
	return nullptr;
}
void ContactsBook::print_contacts()
{
	for (int i = 0; i < contacts_count; i++)
	{
		cout << "Contact" << i + 1 << endl;
		contacts_list[i].print_contact();
		cout << endl;
	}
}
void ContactsBook::update_contact_details(const int i)
{
	string first, last, mob_num, mail;

	if (i >= size_of_contacts || i < 0)
	{
		cout << "Input out of bound\n";
	}
	else
	{
		cout << "Enter new first name: ";
		cin >> first;
		cout << "Enter new last name: ";
		cin >> last;
		cout << "Enter new mobile number: ";
		cin >> mob_num;
		while (mob_num.length() != 11)
		{
			cout << "Invalid mobile number. Please enter an 11-digit mobile number: ";
			cin >> mob_num;
		}
		cout << "Enter new email address: ";
		cin >> mail;

		// Update the member variables directly
		contacts_list[i].getFirstName() = first;
		contacts_list[i].getLastName() = last;
		contacts_list[i].getMobileNumber() = mob_num;
		contacts_list[i].getEmailAddress() = mail;
		//contactsBook.save_to_file("up.txt");
		cout << "Contact details updated successfully.\n";


	}
}


Contact* ContactsBook::search_contact(string phone) {
	for (int i = 0; i < contacts_count; ++i) {
		if (contacts_list[i].getMobileNumber() == phone) {
			return &contacts_list[i]; // Return a pointer to the found contact
		}
	}
	return nullptr;
}

Contact* ContactsBook::search_contact(const Address& address) {
	for (int i = 0; i < contacts_count; ++i) {
		if (*(contacts_list[i].getAddress()) == address) {
			return &contacts_list[i]; // Return the found contact
		}
	}
	return nullptr;
}


void ContactsBook::print_contacts_sorted(string choice) {
	Contact* sorted_list = new Contact[contacts_count];
	for (int i = 0; i < contacts_count; ++i) {
		sorted_list[i] = contacts_list[i];
	}
	//sort_contacts_list(sorted_list, choice);
	for (int i = 0; i < contacts_count; ++i) {
		sorted_list[i].print_contact();
	}
	delete[] sorted_list;
}
Contact* ContactsBook::copy_contacts_list()
{
	Contact* copied_contacts = new Contact[contacts_count];
	for (int i = 0; i < contacts_count; ++i) {
		copied_contacts[i] = contacts_list[i];
	}
	return copied_contacts;
}
void ContactsBook::sort_contacts_list(string choice) {
	if (choice == "first_name") {
		// Sort by first name
		for (int i = 0; i < contacts_count - 1; ++i) {
			for (int j = i + 1; j < contacts_count; ++j) {
				if (contacts_list[i].getFirstName() > contacts_list[j].getFirstName()) {
					swap(contacts_list[i], contacts_list[j]);
				}
			}
		}
	}
	else if (choice == "last_name") {
		// Sort by last name
		for (int i = 0; i < contacts_count - 1; ++i) {
			for (int j = i + 1; j < contacts_count; ++j) {
				if (contacts_list[i].getLastName() > contacts_list[j].getLastName()) {
					swap(contacts_list[i], contacts_list[j]);
				}
			}
		}
	}
	else {
		// Invalid choice, default to sorting by first name
		for (int i = 0; i < contacts_count - 1; ++i) {
			for (int j = i + 1; j < contacts_count; ++j) {
				if (contacts_list[i].getFirstName() > contacts_list[j].getFirstName()) {
					swap(contacts_list[i], contacts_list[j]);
				}
			}
		}
	}
}





void ContactsBook::merge_duplicates()
{
	int duplicate_count = 0;
	for (int i = 0; i < contacts_count; i++)
	{
		for (int j = i + 1; j < contacts_count; j++)
		{
			if (contacts_list[i].equals(contacts_list[j]))
			{
				// Merge the duplicate by removing the duplicate contact
				for (int k = j; k < contacts_count - 1; k++)
				{
					contacts_list[k] = contacts_list[k + 1];
				}
				contacts_count--;
				duplicate_count++;
			}
		}
	}
	cout << "Number of Duplicates : " << duplicate_count << endl;
	for (int i = 0; i < contacts_count; i++)
	{
		cout << "Contact " << i + 1 << endl;
		contacts_list[i].print_contact();
		cout << "=====================" << endl;
	}
}



void ContactsBook::load_from_file(string file_name) {
	ifstream file(file_name);
	if (!file) {
		cout << "Failed to open file: " << file_name << endl;
		return;
	}
	else {
		int count;
		file >> count;
		file.ignore();
		for (int i = 0; i < count; i++)
		{
			string first_name, last_name, mobile_number, email_address, house, street, city, country;
			file >> first_name >> last_name >> mobile_number >> email_address >> house >> street >> city >> country;
			Address address(house, street, city, country);
			Contact contact(first_name, last_name, mobile_number, email_address, &address);
			add_contact(contact);
			file.ignore();
		}
	}
	file.close();
}

void ContactsBook::save_to_file(string file_name) {
	ofstream file(file_name);
	if (!file) {
		cout << "Failed to create file: " << file_name << endl;
		return;
	}
	else {
		file << contacts_count << endl;
		for (int i = 0; i < contacts_count; ++i) {
			file << contacts_list[i].getFirstName() << " "
				<< contacts_list[i].getLastName() << " "
				<< contacts_list[i].getMobileNumber() << " "
				<< contacts_list[i].getEmailAddress() << " "
				<< contacts_list[i].getAddress()->getHouse() << " "
				<< contacts_list[i].getAddress()->getStreet() << " "
				<< contacts_list[i].getAddress()->getCity() << " "
				<< contacts_list[i].getAddress()->getCountry() << endl;
		}
	}
	file.close();
}