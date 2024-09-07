#pragma once
#include<string>
using namespace std;
class Address {
private:
	string house;
	string street;
	string city;
	string country;

public:
	//parameterized constructor
	Address(string house, string street, string city, string country);
	//default constructor
	Address()
	{
	}

	// Getter and setter for house
	string getHouse() const;
	void setHouse(const string& house);

	// Getter and setter for street
	string getStreet() const;
	void setStreet(const string& street);

	// Getter and setter for city
	string getCity() const;
	void setCity(const string& city);

	// Getter and setter for country
	string getCountry() const;
	void setCountry(const string& country);

	bool equals(const Address& address) const;
	void print_address() const;
	Address* copy_address() const;
	bool operator==(const Address& other) const {
		return (this->house == other.house && this->street == other.street && this->city == other.city && this->country == other.country);
	}

};
