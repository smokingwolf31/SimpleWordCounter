#ifndef ANAYLSER_H
#define ANALYSER_H
	namespace NKBMNQ002{
		struct ResultBuilder{
			int words, chars;
		};

		bool isValidChar(char yChar);

		void lineAnalyser(char* currentLine; ResultBuilder& currentWordsAndChars);
	}
#endif
