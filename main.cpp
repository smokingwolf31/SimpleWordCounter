/**
 *  Main cpp file to run the word count program logic
 * 	Mnqobi Nkabinde
 * 	NKBMNQ002
 *  16 Feb 2024
*/

#include <iostream>
#include <sstream>
#include "analyser.h"

#define updateResult(x, y, z)(NKBMNQ002::lineAnalyser(x,y,z))

int main(int argc, char** argv){
	NKBMNQ002::ResultBuilder myResult;
	std::vector<NKBMNQ002::CharInfo> myChars(26);
	int lines = NKBMNQ002::wordCounter(myResult, myChars);
	std::cout << lines << " " << myResult.words << " " <<myResult.chars;

	bool firstElement = true;
	for (int index=0; index<26; index++){
		if (myChars[index].count != 0){
			if(firstElement){
				std::cout << " ["<< myChars[index].character << ":" << myChars[index].count;
				firstElement = false;
			}
			else
				std::cout << " "<< myChars[index].character << ":" << myChars[index].count;
		}
	}
	if (!firstElement)
		std::cout << "]" << std::endl;
	else 
		std::cout << " [ ]" << std::endl;
	return 0; 
}
