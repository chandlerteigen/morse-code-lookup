#include "BST.h"
#include "MorseChar.h"
#include <fstream>

class MorseLookupBST
{
public:

	MorseLookupBST();

	~MorseLookupBST();
	/*************************************************************
	Function: runApp
	Parameters: void
	Returns: void
	Description: calls the printTree function on the tree member, and calls the convert file
				 function on convert.txt.
	**************************************************************/	
	void runApp();
	
	

private:

	void convertFile();

	BST<MorseChar> *tree;
	std::ifstream infile;
	std::ifstream fileToConvert;
};