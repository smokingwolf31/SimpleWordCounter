#ifndef ANAYLSER_H
#define ANALYSER_H
	namespace NKBMNQ002{
		struct ResultBuilder{
			int words, chars;
		};

		struct CharInfo{
			char myChar;
			int frequency;
		};

		bool isValidChar(char yChar);

		void lineAnalyser(char* currentLine, ResultBuilder& currentWordsAndChars);
	}
#endif
