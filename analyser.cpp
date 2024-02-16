#include "analyser.h"

bool NKBMNQ002::isValidChar(char myChar){
	int charAscii = myChar;
	if((charAscii>47 && charAscii<58) || (charAscii>64 && charAscii<91) || (charAscii>96 && charAscii<123))
		return true;
	else return false;
}

void NKBMNQ002::lineAnalyser(char* currentLine, ResultBuilder& currentNumberOfWordsAndChars){
	using namespace NKBMNQ002;
	int numberOfChars = 0;
	int numberOfWords = 0;
	int index=0;
	bool sameWord = false; //Used to identify if a char contributes to an existing word or it is a start of a new one"
	while(currentLine[index] != '\n' && currentLine[index] != '\0'){
		char currentChar = currentLine[index];
		if(isValidChar(currentChar)){
			numberOfChars += 1;
			if(!sameWord){
				numberOfWords += 1;
				sameWord = true;
			}
		}
		else
			sameWord = false;
	}
	currentNumberOfWordsAndChars.chars += numberOfChars;
	currentNumberOfWordsAndChars.words += numberOfWords;
}
