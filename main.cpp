/*************************************************************
Programmer: Chandler Teigen
Date: July 15, 2019
Description: This program reads english text from convert.txt
			 and converts it to morse code using a binary search
			 tree.
**************************************************************/

#include "BST.h"
#include "MorseChar.h"
#include "MorseLookupBST.h"
int main()
{
	MorseLookupBST morseCodeConverter;

	morseCodeConverter.runApp();

	std::cin.get();

	return 0;
}