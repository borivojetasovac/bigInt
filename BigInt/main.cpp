#include <iostream>
#include "BigInt.h"

using namespace std;

int main() {

	int i;
	BigInt bi(2147483647);
	BigInt bi2;

	cout << bi << endl;
	cout << bi2 << endl;

	for (i = 0; i < 100; i += 5) {
		bi2 = bi2 + bi;
		cout << bi2 << endl;
	}

	return 0;
}