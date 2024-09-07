#include "Contact.h"
using namespace std;
Contact::Contact(string first_name, string last_name, string mobile_number, string email_address, Address* address) {
	this->first_name = first_name;
	this->last_name = last_name;
	this->mobile_number = mobile_number;
	this->email_address = email_address;
	this->address = address->copy_address();
}

string Contact::getFirstName() const
{
	return first_name;
}

void Contact::setFirstName(const string& first_name) {
	if (!first_name.empty())
		this->first_name = first_name;
}

string Contact::getLastName() const {
	return last_name;
}

void Contact::setLastName(const string& last_name) {
	if (!last_name.empty())
		this->last_name = last_name;
}

string Contact::getMobileNumber() const {
	return mobile_number;
}
void Contact::setMobileNumber(const string& mobile_number) {
	if (mobile_number.size() == 11) // Assuming mobile number must be 11 digits
		this->mobile_number = mobile_number;
}

string Contact::getEmailAddress() const {
	return email_address;
}
void Contact::setEmailAddress(const string& email_address) {
	if (!email_address.empty())
		this->email_address = email_address;
}
Address* Contact::getAddress() const {
	return address;
}
void Contact::setAddress(Address* address)
{
	this->address = address;
}
bool Contact::equals(const Contact& contact) const
{
	return (first_name == contact.first_name &&
		last_name == contact.last_name &&
		mobile_number == contact.mobile_number &&
		email_address == contact.email_address &&
		address->equals(*contact.getAddress()));
}
Contact* Contact::copy_contact(const Contact& other) {
	// Create a new Contact object
	Contact* new_contact = new Contact();

	// Copy attributes
	new_contact->first_name = other.first_name;
	new_contact->last_name = other.last_name;
	new_contact->email_address = other.email_address;
	new_contact->mobile_number = other.mobile_number;

	// Deep copy address by creating a new Address object
	new_contact->setAddress(new Address(*(other.address)));

	return new_contact;
}
void Contact::print_contact() {
	cout << "First Name: " << first_name << endl;
	cout << "Last Name: " << last_name << endl;
	cout << "Mobile Number: " << mobile_number << endl;
	cout << "Email Address: " << email_address << endl;
	cout << "Address: ";
	address->print_address();
}
