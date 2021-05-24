#pragma once
#include <iostream>
#include "Decimal.h"

using namespace std;

int main() {
	Decimal zero(5);
	cout << "zero: " << zero << endl;
	Decimal a(12, "12340567");
	cout << "a: " << a << endl;
	cout << "a[2]: " << a[2] << endl;
	cout << "a[20]: ";
	try {
		cout << "a[20]: " << a[20] << endl;
	}
	catch (int) {
		cout << "Error! Index out of range!" << endl;
	}

	Decimal aa(12);
	cout << "aa = a + a " << endl;
	aa = a + a;
	cout << "aa: " << aa << endl;
	Decimal a1(20, "9999999999999999"), a2(20, "2"), a3(20);
	cout << "a1: " << a1 << endl;
	cout << "a2: " << a2 << endl;
	cout << "a3 = a1 + a2 " << endl;
	a3 = a1 + a2;
	cout << "a3: " << a3 << endl;
	Decimal b(12);
	cout << "b: " << b << endl;
	Decimal c(12);
	cout << "c = a " << endl;
	c = a;
	cout << "c: " << c << endl;
	cout << "a == c: " << (a == c) << endl;
	cout << "b == c: " << (b == c) << endl;
	Decimal d(12);
	cout << "Input Decimal d: ";
	cin >> d;
	cout << "d: " << d << endl;
	Decimal e(10);
	cout << "e: " << e << endl;
	cout << "a == e: " << endl;
	try {
		cout << "a == e: " << (a == e) << endl;
	}
	catch (int) {
		cout << "Error! Different sizes" << endl;
	}
	return 0;
}