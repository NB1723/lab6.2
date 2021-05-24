#pragma once
#include <iostream>
#include <string>

using namespace std;

class Decimal {
public:
	typedef unsigned char* iterator;
	typedef const unsigned char* const_iterator;
private:
	int len;
	unsigned char* digits;
public:
	Decimal(int _len)throw(bad_alloc, invalid_argument);
	Decimal(int _len, const char* value)throw(bad_alloc, invalid_argument);
	friend ostream& operator << (ostream& out, const Decimal& d);
	friend istream& operator >> (istream& in, Decimal& d);
	unsigned char operator[](int i);
	friend bool operator == (const Decimal& a, const Decimal& b);
	const Decimal& operator = (const Decimal& d);
	friend Decimal& operator + (const Decimal& a1, const Decimal& a2);
	iterator begin() { return digits; }
	const_iterator begin() const { return digits; }
	iterator end() { return digits + len; }
	const_iterator end() const { return digits + len; }
	~Decimal() { delete[]digits; };
};