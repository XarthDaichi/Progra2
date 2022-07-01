#pragma once

class Address {
private:
	string type;
	string address;
public:
	Address();

	virtual ~Address();

	const string& getType() const;

	void setType(const string& type);

	const string& getAddress() const;

	void setAddress(const string& address);

	friend ostream &operator
};