#include <iostream>
#include <sstream>
#include "analyser.h"

#define updateResult(x, y)(NKBMNQ002::lineAnalyser(x,y))

int main(char argc, char* argv){
	
	NKBMNQ002::ResultBuilder myResult;
	int lines = 0;
	myResult.words = 0;
	myResult.chars = 0;
	int lineBufferLimit = 300;
	char myLine[lineBufferLimit]; // if we were to use <string> it would be so much cleaner
	while (std::cin.getline(myLine, lineBufferLimit)){
		updateResult(myLine, myResult);
	}
	std::cout << lines << " " << myResult.words << " " << myResult.chars << std::endl;
	return 0;
}
