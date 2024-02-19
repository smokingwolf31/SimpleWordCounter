/**
 *  analyser cpp file used to count the number of words in a given string and update the word count and character frequency count
 * 	@author Mnqobi Nkabinde
 * 	NKBMNQ002
 *  @date 17 Feb 2024
*/

#include <iostream>
#include "analyser.h"


/**
 * Used to cheack is a given char is a digit or a letter of the alphabet
 * @return bool true if its a letter or a digit, false if its neither
 * @arg pass in a char you wish to check
*/
bool NKBMNQ002::isValidChar(char myChar){
	int charAscii = myChar;
	if((charAscii>47 && charAscii<58) || (charAscii>64 && charAscii<91) || (charAscii>96 && charAscii<123))
		return true;
	else return false;
}

/**
 * Used to cheack where a char falls in the alphabet
 * @return int returns the the number which the char falls in in the alphabet (e.g A=0, b=1 ,Z=25)
 * @arg pass in a char you wish to check
*/
int NKBMNQ002::getCharIndex(char myChar){
	int charAscii = myChar;
	if (charAscii<91){
		charAscii += 32;
	}
	return charAscii - 97;
}

/**
 * Used to count the number of words given a string while keeping track of the freqency of particular chars
 * @return void
 * @arg char* pass the pointer to the first char in the string
 * @arg ResultBuilder& pass in the refrence to the ResultBuilder struct you wish to update
 * @arg CharInfo[] pass in the array of CharInfo you wish to update the frequency of.
*/
void NKBMNQ002::lineAnalyser(char* currentLine, ResultBuilder& currentNumberOfWordsAndChars, std::vector<CharInfo>& myChars){

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
			if(currentChar > 57){
				int charIndex = getCharIndex(currentChar);
				if(myChars[charIndex].count == 0){
					myChars[charIndex].count = 1;
					int asciiChar = int(currentChar);
					if (asciiChar < 91){
						asciiChar += 32;
						myChars[charIndex].character = char(asciiChar);
					}
					else
						myChars[charIndex].character = currentChar;
				}
				else{
					myChars[charIndex].count += 1;
				}
			}
		}
		else
			sameWord = false;
		index +=1;
	}
	currentNumberOfWordsAndChars.chars += numberOfChars;
	currentNumberOfWordsAndChars.words += numberOfWords;
}

int NKBMNQ002::wordCounter(NKBMNQ002::ResultBuilder& myResult, std::vector<NKBMNQ002::CharInfo>& myChars){

	int lines = 0;
	myResult.words = 0;
	myResult.chars = 0;
	int lineBufferLimit = 300;
	for (int index=0 ; index<26; index++){
		myChars[index].count = 0;
	}
	char myLine[lineBufferLimit]; // if we were to use <string> it would be so much cleaner
	while (std::cin.getline(myLine, lineBufferLimit)){
		lineAnalyser(myLine, myResult, myChars);
		lines += 1;
	}
	return lines;
}
