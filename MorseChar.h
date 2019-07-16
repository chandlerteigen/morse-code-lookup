#pragma once
#include <string>
#include <iostream>

class MorseChar
{

public:

	MorseChar(const char* = "", const char newEnglish = '\0');

	
	~MorseChar();

	// Accessors
	std::string &getMorse();
	char getEnglish();

	void setMorse(std::string &newMorse);
	void setEnglish(char newEnglish);

	void printEnglish();
	void printMorse();

	MorseChar &operator= (MorseChar& rhs);

	

private:
	std::string morse;
	char english;
	
};

//overloaded operators
bool operator< (MorseChar &lhs, MorseChar &rhs);
bool operator> (MorseChar &lhs, MorseChar &rhs);
bool operator== (MorseChar &lhs, MorseChar &rhs);
std::ifstream &operator>> (std::ifstream &lhs, MorseChar &rhs);
std::ostream &operator<< (std::ostream &lhs, MorseChar &rhs);
