#ifndef FIND_HPP
#define FIND_HPP

#include <string>

int find(std::string l, std::string s, bool& isFound);
int find(std::string l, std::string s, bool& isFound, std::string filename);
int find(std::string l, std::string s, bool& isFound, int& occurances, int& counter, bool count);
int find(std::string l, std::string s, bool& isFound, int& occurances, int& counter, bool count, bool reverse, bool icase, int& ioc);

bool checkFile(std::string fileName);

void increment_1(char* argv[]);
void increment_2(char* argv[]);
void increment_4(char* argv[]);
void increment_3(char* argv[]);

#endif // !FIND_HPP
