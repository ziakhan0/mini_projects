#include "Address.h"
#include <iostream>
using namespace std;
Address::Address(string house, string street, string city, string country)
	: house(house), street(street), city(city), country(country) {}

string Address::getHouse() const {
	return house;
}

void Address::setHouse(const string& house) {
	this->house = house;
}

string Address::getStreet() const {
	return street;
}

void Address::setStreet(const string& street) {
	this->street = street;
}

string Address::getCity() const {
	return city;
}

void Address::setCity(const string& city) {
	this->city = city;
}

string Address::getCountry() const {
	return country;
}

void Address::setCountry(const string& country) {
	this->country = country;
}

bool Address::equals(const Address& address) const {
	return (house == address.house &&
		street == address.street &&
		city == address.city &&
		country == address.country);
}

void Address::print_address() const {
	cout << house << ", " << street << ", " << city << ", " << country << endl;
}

Address* Address::copy_address() const {
	return new Address(house, street, city, country);
}
