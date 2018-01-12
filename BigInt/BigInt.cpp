#include <iostream>
#include "BigInt.h"

using namespace std;


void BigInt::copy(const int * digits, int length) {
	this->digits = new int[length];
	this->length = length;

	for (int i = 0; i < length; i++) {
		this->digits[i] = digits[i];
	}
}
void BigInt::destroy() {
	delete[] digits;
	digits = NULL;
	length = -1;
}

BigInt::BigInt() {
	digits = new int[1];
	digits[0] = 0;
	length = 1;
}
BigInt::BigInt(int plain_int) {
	int i, temp = plain_int;

	for (i = 0; temp > 0; i++)
		temp /= 10;

	length = i;
	digits = new int[length];

	temp = plain_int;

	for (i = 0; i < length; i++) {
		digits[i] = temp % 10;
		temp /= 10;
	}
}
BigInt::BigInt(const BigInt & other) {
	copy(other.digits, other.length);
}
BigInt::~BigInt() {
	destroy();
}

ostream & operator<<(ostream & out, const BigInt & big_int) {
	for (int i = big_int.length - 1; i >= 0; i--)
		out << big_int.digits[i];

	return out;
}
BigInt & BigInt::operator = (const BigInt & right_operand) {
	if (this != &right_operand) {
		destroy();
		copy(right_operand.digits, right_operand.length);
	}

	return *this;
}
BigInt operator+(const BigInt & left_operand, const BigInt & right_operand) {
	int min_length = left_operand.length < right_operand.length ? left_operand.length : right_operand.length;
	int max_length = left_operand.length > right_operand.length ? left_operand.length : right_operand.length;
	int i, sum, length, carry = 0;

	int * digits = new int[max_length + 1];

	for (i = 0; i < min_length; i++) {
		sum = left_operand.digits[i] + right_operand.digits[i] + carry;

		digits[i] = sum % 10;
		carry = sum / 10;
	}

	if (min_length == left_operand.length) {
		for (; i < max_length; i++) {
			sum = right_operand.digits[i] + carry;

			digits[i] = sum % 10;
			carry = sum / 10;
		}
	}
	else {
		for (; i < max_length; i++) {
			sum = left_operand.digits[i] + carry;

			digits[i] = sum % 10;
			carry = sum / 10;
		}
	}

	if (carry == 1) {
		digits[i] = 1;
		length = max_length + 1;
	}
	else
		length = max_length;

	BigInt result;
	result.destroy();
	result.copy(digits, length);

	return result;
}