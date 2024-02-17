/**
 *  analyser header file for all the declaration deom the analyser.cpp file
 * 	Mnqobi Nkabinde
 * 	NKBMNQ002
 *  16 Feb 2024
*/

#include <vector>

#ifndef ANAYLSER_H
#define ANALYSER_H
	namespace NKBMNQ002{

		struct ResultBuilder{
			int words, chars;
		};

		struct CharInfo{
			char character;
			int count; 
		};

		
		int getCharIndex(char myChar);

		bool isValidChar(char myChar);

		void lineAnalyser(char* currentLine, ResultBuilder& currentWordsAndChars, std::vector<CharInfo>& myChars);
	}
#endif
