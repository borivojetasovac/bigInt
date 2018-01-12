#pragma once

#include <iostream>

using namespace std;

class BigInt {
private:
	int * digits;
	int length;

	void copy(const int * digits, int length);
	void destroy();
public:
	BigInt();
	BigInt(int plain_int);
	BigInt(const BigInt & other);
	~BigInt();

	friend ostream & operator<<(ostream & out, const BigInt & big_int);
	BigInt & operator=(const BigInt & right_operand);
	friend BigInt operator+(const BigInt & left_operand, const BigInt & right_operand);
};