#pragma once
#include "Text.h"
#include <iostream>
#include <string>
#include <vector>
using std::vector;

class Preprocessor
{
public:
	Preprocessor();
	Preprocessor(const Text&);

	void lowerCasing();
	void sentenceTokenizing(); 
	bool isPeriod(char);
	void wordTokenizing();
	void removingPunctuation();

	



private:
	Text txt;
	vector<std::string> sentences;
	vector<std::string> words;
};

