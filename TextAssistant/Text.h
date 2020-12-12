#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Text
{
public:
	Text();
	Text(std::ifstream& fileName);
	Text(std::string content);
	
	void setContent(std::string content);
	
	std::string getContent();
private:
	std::string content;
	
};

