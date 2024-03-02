#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>

#include "find.hpp"

/*Aliohjelmat, joka vertailevat kahta stringia.
l on tiedoston line tai ensimmaisen inkrementin lause, jota tutkitaan.
s on sana tai kirjainyhdistelma (searchterm), jota yritetaan etsia l:sta.
Mikali l sisaltaa s:n on isFound true ja ohjelma antaa sen mukaisen tulostuksen
riippuen mista inkrementista on kyse.
int find(std::string l, std::string s, bool& isFound) {
	int length1 = l.length();
	int length2 = s.length();
	for (int i = 0; i < length1 - length2; i++) {
		int n;
		for (n = 0; n < length2; n++) {
			if (l[i + n] != s[n]) {
				isFound = false;
				break;
			}
		}
		if (n == length2) {
			isFound = true;
			return i;
		}
	}
	return -1;
}
int find(std::string l, std::string s, bool& isFound, std::string filaname) {
	int length1 = l.length();
	int length2 = s.length();
	for (int i = 0; i < length1 - length2; i++) {
		int n;
		for (n = 0; n < length2; n++) {
			if (l[i + n] != s[n]) {
				isFound = false;
				break;
			}
		}
		if (n == length2) {
			isFound = true;
			std::cout << l << std::endl;
			return i;
		}
	}
	return -1;
}
int find(std::string l, std::string s, bool& isFound, int& occurances, int& counter, bool count) {
	int length1 = l.length();
	int length2 = s.length();
	for (int i = 0; i < length1 - length2; i++) {
		int n;
		for (n = 0; n < length2; n++) {
			if (l[i + n] != s[n]) {
				isFound = false;
				break;
			}
		}
		if (n == length2) {
			isFound = true;
			occurances++;
			if (count == true) {
				std::cout << counter << ":" << l << std::endl;
			}
			else {
				std::cout << l << std::endl;
			}
			return i;
		}
	}
	return -1;
}
int find(std::string l, std::string s, bool& isFound, int& occurances, int& counter, bool count, bool reverse, bool icase, int& ioc) {
	int length1 = l.length();
	int length2 = s.length();
	if (icase == true) {
		transform(l.begin(), l.end(), l.begin(), [](unsigned char c) {return tolower(c); });
		transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {return tolower(c); });
	}
	if (length1 == 0 && reverse == true) {
		occurances++;
		if (count == true) {
			std::cout << counter << ":" << l << std::endl;
		}
		else {
			std::cout << l << std::endl;
		}
		return 1;
	}
	for (int i = 0; i < length1 - length2; i++) {
		int n;
		if (length1 < length2) {
			isFound = false;
			break;
		}
		for (n = 0; n < length2; n++) {
			if (l[i + n] != s[n]) {
				isFound = false;
				break;
			}
		}
		if (n == length2) {
			isFound = true;
			if (reverse == true) {
			break;
			}
			else {
				ioc++;
				if (count == true) {
					std::cout << counter << ":" << l << std::endl;
				}
				else {
					std::cout << l << std::endl;
				}
			}
		}
	}
	if (reverse == true && isFound == false) {
		occurances++;
		if (count == true) {
			std::cout << counter << ":" << l << std::endl;
		}
		else {
			std::cout << l << std::endl;
		}
		return 1;
	}
	return 1;
}
//Aliohjelma, joka tarkistaa onko tiedosto olemassa.
//Vaaativammassa ohjelmassa olisi voinut laittaa enemman virhekoodeja, mutta en nahnyt tassa tarpeelliseksi.
bool checkFile(std::string fileName) {
	std::ifstream file(fileName);
	try {
		if (file.is_open()) {
			file.close();
			return 1;
		}
		else {
			throw(1);
		}
	}
	catch (int err) {
		std::cout << "Error " << err << std::endl;
		std::cout << "Couldn't open file \"" << fileName << "\"\n";
		std::cout << "Please check file name and try again.\n";
	}
}
//Inkrementtien omat aliohjelmat.
//Suoritettava aliohjelma valitaan mainissa sen perusteella montako argumenttia sille on syotetty.
void increment_1(char* argv[]) {
	using namespace std;
	string s1{};
	string s2{};
	bool isFound{};
	std::cout << "Give a string from which to search for: ";
	getline(cin, s1);
	std::cout << "Give search string: ";
	getline(cin, s2);
	int position = find(s1, s2, isFound);
	if (isFound) {
		std::cout << endl << "\"" << s2 << "\" found in " << s1 << " in position " << position;
	}
	else {
		std::cout << endl << "\"" << s2 << "\" NOT found in " << "\"" << s1 << "\"";
	}
}
void increment_2(char* argv[]) {
	using namespace std;
	string searchTerm = argv[1];
	string fileName = argv[2];
	string line;
	bool isFound;
	ifstream file(fileName);
	checkFile(fileName);
	if (file.is_open()) {
		while (getline(file, line)) {
			find(line, searchTerm, isFound, fileName);
		}
		file.close();
	}
}
void increment_4(char* argv[]) {
	using namespace std;
	string arguments = argv[1];
	string searchTerm = argv[2];
	string fileName = argv[3];
	string line;
	int counter{ 0 };
	int occurances{ 0 };
	int ioc{ 0 };
	bool isFound;
	bool count{ false };
	bool occur{ false };
	bool reverse{ false };
	bool icase{ false };
	checkFile(fileName);
	arguments.erase(0, 2);
	if (arguments.find('o') != std::string::npos) {
		occur = true;
	}
	if (arguments.find('l') != std::string::npos) {
		count = true;
	}
	if (arguments.find('r') != std::string::npos) {
		reverse = true;
	}
	if (arguments.find('i') != std::string::npos) {
		icase = true;
	}
	ifstream file(fileName);
	if (file.is_open()) {
		while (getline(file, line)) {
			counter++;
			find(line, searchTerm, isFound, occurances, counter, count, reverse, icase, ioc);
		}
		if (icase == true && reverse == false) {
			occurances = ioc;
		}
		if (occur == true && reverse == false) {
			std::cout << endl << "Occurances of lines containing \"" << searchTerm << "\" : " << occurances;
		}
		if (occur == true && reverse == true) {
			std::cout << endl << "Occurances of lines NOT containing \"" << searchTerm << "\" : " << occurances;
		}
		file.close();
	}

}
void increment_3(char* argv[]) {
	using namespace std;
	string arguments = argv[1];		//Kayttajan syottamat argumentit (l tai o)
	string searchTerm = argv[2];	//Sana jota haetaan
	string fileName = argv[3];		//Tiedostonimi
	string line;					//Rivi, jota kasitellaan
	int counter{ 1 };
	int occurances{ 0 };
	bool isFound;
	bool count{ false };			//Tulostetaanko rivinumerot
	bool occur{ false };			//Tulostetaanko sanojen maara
	arguments.erase(0, 2);			//Poistaa argumenttien alusta -ol
	//Jos kayttaja on syottanyt argumenteissa r:n tai i:n lahtee suorittamaan 4 inkrementin aliohjelmaa
	if (arguments.find('r') != std::string::npos || arguments.find('i') != std::string::npos) {
		increment_4(argv);
	}	
	else {
		checkFile(fileName);
		if (arguments.find('o') != std::string::npos) {
			occur = true;
		}
		if (arguments.find('l') != std::string::npos) {
			count = true;
		}
		ifstream file(fileName);
		if (file.is_open()) {
			while (getline(file, line)) {
				find(line, searchTerm, isFound, occurances, counter, count);
				counter++;
			}
			if (occur == true) {
				std::cout << endl << "Occurances of lines containing \"" << searchTerm << "\" : " << occurances;
			}
			file.close();
		}
	}
}*/
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