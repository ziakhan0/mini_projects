#pragma once
#include <iostream>
#include <string>
#include "Address.h"
using namespace std;
class Contact {
private:
	string first_name;
	string last_name;
	string mobile_number;
	string email_address;
	Address* address = NULL;

public:
	Contact() {}
	Contact(string first_name, string last_name, string mobile_number, string email_address, Address* address);


	// Getter and setter for first name
	string getFirstName() const;
	void setFirstName(const string&);
	void print_contact();
	// Getter and setter for last name
	string getLastName() const;
	void setLastName(const string&);

	// Getter and setter for mobile number
	string getMobileNumber() const;
	void setMobileNumber(const string&);

	// Getter and setter for email address
	string getEmailAddress() const;
	void setEmailAddress(const string&);

	// Getter and setter for address
	Address* getAddress() const;
	void setAddress(Address*);

	void operator ==(Address&) {}

	bool equals(const Contact& contact) const;
	Contact* copy_contact(const Contact&);
};
