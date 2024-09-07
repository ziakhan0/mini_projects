#pragma once
#include "Contact.h"
#include <string>
using namespace std;
class ContactsBook {
private:
	Contact* contacts_list; // array of contacts
	int size_of_contacts;   // storage limit
	int contacts_count;     // total contacts currently stored, next contact will be 
	                       // stored at this count plus 1 index

public:
	ContactsBook();
	ContactsBook(int size_of_list);
	~ContactsBook(); // Destructor to deallocate dynamically allocated memory

	void add_contact(const Contact& contact);
	int total_contacts();
	void print_contacts();
	void update_contact_details(const int i);

	Contact* search_contact(string first_name, string last_name);
	Contact* search_contact(string phone);
	Contact* search_contact(const Address& address);

	void print_contacts_sorted(string choice); // Only two choices first_name or last_name
	void merge_duplicates(); // Implement this function that finds and merges all the duplicates
	void load_from_file(string file_name); // This function loads contacts from the given file
	void save_to_file(string file_name); // This function saves contacts to a file
	//void sort_contacts_list(Contact** contacts_list, string choice);
	void sort_contacts_list(string choice);
	Contact* copy_contacts_list();//create copy of contactlist
private:
	bool full();
	void resize_list();
	//void sort_contacts_list(Contact* contacts_list, string choice);
};
