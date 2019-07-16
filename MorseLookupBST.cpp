#include "MorseLookupBST.h"

MorseLookupBST::MorseLookupBST()
{
	tree = new BST<MorseChar>; // initialize the BST
	infile.open("MorseTable.txt");
	if (infile.is_open())
	{
		char str[10] = { 0 };
		MorseChar tempMorseChar;
		while (!infile.eof())
		{
			infile >> tempMorseChar; // extract data from file
			tree->insertNode(tempMorseChar); // insert data into the tree
		}
	}
	infile.close();
}

MorseLookupBST::~MorseLookupBST()
{
	delete tree;
}

void MorseLookupBST::runApp()
{
	tree->printTree();
	convertFile();
}

void MorseLookupBST::convertFile()
{
	fileToConvert.open("convert.txt");

	char tempChar = 0;

	MorseChar tempTarget;

	std::cout << "Converted Text: " << std::endl;
	if (fileToConvert.is_open()) // file open validation
	{
		while (!fileToConvert.eof()) // loop until end of file
		{
			fileToConvert >> std::noskipws >> tempChar; // don't skip white space
			if (fileToConvert.eof()) // make sure that the last char isn't read twice
				break;
			tempChar = toupper(tempChar); // convert to uppercase
			if (tempChar == ' ')
			{
				std::cout << " ";
			}
			else if (tempChar == '\n')
			{
				std::cout << '\n';
			}
			else
			{
				tempTarget.setEnglish(tempChar); // put the read character into a temp morseChar object
				MorseChar *tempPtr = tree->searchTree(tempTarget);
				if (tempPtr != nullptr)
				{
					std::cout << tree->searchTree(tempTarget)->getMorse(); //print corresponding morse code
				}
			}
		}
	}
	fileToConvert.close();
}
