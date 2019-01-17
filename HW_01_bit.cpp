#include <iostream>

void test(int a, int b);


int bit_change(int x) {
	
	int y = 0;
	if ((x & 0x880) == 0x880) {
		y = x & 0xFBB;
	}
	else {
		y = -1;
	}
	return y;
}


int main() {

	const int SIZE = 10;
	int arr[SIZE] = { 0xCB0, 0x8C4, 0x8AC, 0x8AD, 0x910,
					0x960, 0x88C, 0x8C8, 0x89E, 0x89A};

	std::cout << "x\t" << "y\t" << "test\n";
	std::cout << std::endl;
	for (int i = 0; i < SIZE; ++i) {
		std::cout << arr[i] << '\t' << bit_change(arr[i]);
		test(arr[i], bit_change(arr[i]));
	}

	system("pause");
	return 0;
}


void test(int a, int b) {
	if ((a & 0x880) == 0x880 && (a & 0x44) != 0x44 && a == b) {
		std::cout << "\tOK" << std::endl;
	}
	else if ((a & 0x8C4) == 0x8C4 && a != b) {
		std::cout << "\tOK" << std::endl;
	}
	else if ((a & 0x8C0) == 0x8C0 && a != b) {
		std::cout << "\tOK" << std::endl;
	}
	else if ((a & 0x884) == 0x884 && a != b) {
		std::cout << "\tOK" << std::endl;
	}
	else if ((a & 0x880) != 0x880 && b == -1) {
		std::cout << "\tOK" << std::endl;
	}
	else {
		std::cout << "\tError" << std::endl;
	}
}