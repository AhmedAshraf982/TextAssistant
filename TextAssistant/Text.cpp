#include "Text.h"

Text::Text():content("") { }

Text::Text(std::ifstream& fileName)
{
	std::string temp("");
	while (fileName>>temp)
	{
		content += temp;
		content += " ";
	}
	if (content.length() < 300)  std::cerr << std::endl << "Length of text is too short !" << std::endl;

}

Text::Text(std::string content)
{
	if (content.length() >= 300) this->content = content;
	else std::cerr << std::endl << "Length of text is too short !" << std::endl;

}

void Text::setContent(std::string content)
{
	if(content.length()>=300)
	this->content = content;
	else std::cerr << std::endl << "Length of text is too short !" << std::endl;
}

std::string Text::getContent()
{
	return content;
}
