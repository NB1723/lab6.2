#pragma once
#include <iostream>
#include "Decimal.h"

using namespace std;

Decimal::Decimal(int _len)throw(bad_alloc, invalid_argument) {
	len = _len;
	digits = new unsigned char[len];
	for (int i = 0; i < len; i++) {
		digits[i] = '0';
	}
}

Decimal::Decimal(int _len, const char* value)throw(bad_alloc, invalid_argument) {
	len = _len;
	digits = new unsigned char[len];
	for (int i = 0; i < len; i++) {
		digits[i] = '0';
	}
	int size = strlen(value);
	for (int i = 0; i < size; i++) {
		digits[i] = (unsigned char)value[size - i - 1];
	}
}

unsigned char Decimal::operator [] (int i) {
	if (i >= len) throw(2);
	return digits[i];
}

ostream& operator << (ostream& out, const Decimal& d) {
	bool zeros = true;
	bool allzeros = true;
	for (int i = d.len - 1; i >= 0; i--) {
		if (zeros && (d.digits[i] == '0')) continue;
		out << d.digits[i];
		zeros = false;
		allzeros = false;
	}
	if (allzeros) out << '0';
	return out;
}

istream& operator >> (istream& in, Decimal& d) {
	char value[12];
	in >> value;
	int size = strlen(value);
	for (int i = 0; i < size; i++) {
		d.digits[i] = (unsigned char)value[size - i - 1];
	}
	return in;
}

const Decimal& Decimal::operator = (const Decimal& d) {
	for (int i = 0; i < len; i++) {
		digits[i] = d.digits[i];
	}
	return *this;
}

bool operator == (const Decimal& a, const Decimal& b) {
	if (a.len != b.len)throw(1);
	for (int i = 0; i < a.len; i++) {
		if (a.digits[i] != b.digits[i]) return false;
	}
	return true;
}

Decimal& operator + (const Decimal& a1, const Decimal& a2) {
	Decimal* a = new Decimal(a1.len);
	int shift = 0;
	for (int i = 0; i < a1.len; i++) {
		int b = int(a1.digits[i]) - 48 + int(a2.digits[i]) - 48 + shift;
		shift = b / 10;
		a->digits[i] = unsigned char(b % 10 + 48);
	}
	Decimal& result = *a;
	return result;
}