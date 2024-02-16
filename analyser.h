#ifndef ANAYLSER_H
#define ANALYSER_H
	namespace NKBMNQ002{
		struct ResultBuilder{
			int words, chars;
		};

		void lineAnalyser(char* currentLine; ResultBuilder& currentWordsAndChars);
	}
#endif
