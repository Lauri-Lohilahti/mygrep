#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>

#include "find.hpp"

int main(int argc, char* argv[]) {
	using namespace std;
	if (argc == 1) {
		increment_1(argv);
	}
	if (argc == 3) {
		increment_2(argv);
	}
	if (argc == 4) {
		increment_3(argv);
	}
}
