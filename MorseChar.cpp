#include "MorseChar.h"
#include <fstream>

MorseChar::MorseChar(const char* newMorse, const char newEnglish)
{
	morse.assign(newMorse);
	english = newEnglish;
}



MorseChar::~MorseChar()
{
}

std::string & MorseChar::getMorse() { return morse; }
char MorseChar::getEnglish() { return english; }

void MorseChar::setMorse(std::string &newMorse)
{
	morse.assign(newMorse);
}

void MorseChar::setEnglish(char newEnglish)
{
	english = newEnglish;
}

void MorseChar::printEnglish()
{
	std::cout << english;
}

void MorseChar::printMorse()
{
	std::cout << morse;
}

// overloaded copy assignment operator
MorseChar & MorseChar::operator=(MorseChar & rhs)
{
	english = rhs.english;
	morse.assign(rhs.morse);
	return *this;
}


bool operator<(MorseChar & lhs, MorseChar & rhs)
{
	return lhs.getEnglish() < rhs.getEnglish();
}

bool operator>(MorseChar &lhs, MorseChar & rhs)
{
	return lhs.getEnglish() > rhs.getEnglish();
}

bool operator== (MorseChar &lhs, MorseChar &rhs)
{
	return (lhs.getEnglish() == rhs.getEnglish());
}

std::ifstream & operator>>(std::ifstream & lhs, MorseChar & rhs)
{
	std::string tempStr;
	lhs >> tempStr;
	rhs.setEnglish(tempStr[0]);
	lhs >> tempStr;
	rhs.setMorse(tempStr);
	return lhs;
}

std::ostream & operator<<(std::ostream & lhs, MorseChar & rhs)
{
	std::cout << "English: " << rhs.getEnglish() << "\n" << "Morse: " << rhs.getMorse() << "\n" << std::endl;
	return lhs;
}
