/*
Initial class to take input and store it.
*/

#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Text
{
public:
    Text();
    Text(std::ifstream &fileName);
    Text(std::string content);

    void setContent(std::string content);
    bool contentLength();
    std::string getContent();

private:
    std::string content;
};

//default constructor will set content to blank
Text::Text() : content("") {}

//paramaterized constructor will read content from file and store to content
Text::Text(std::ifstream &fileName)
{
    std::string temp = "";
    while (fileName >> temp)
    {
        content += temp;
        content += " ";
    }
    if (content.length() < 300)
        std::cerr << std::endl
                  << "Length of text is too short !" << std::endl;
}

//paramaterized constructor will directly store to content
Text::Text(std::string content)
{
    if (content.length() >= 300)
        this->content = content;
    else
        std::cerr << std::endl
                  << "length of text is too short !" << std::endl;
}

//setter to change content
void Text::setContent(std::string content)
{
    if (content.length() >= 300)
        this->content = content;
    else
        std::cerr << std::endl
                  << "Length of text is too short !" << std::endl;
}
bool Text::contentLength()
{
    if (content.length() >= 300)
        return true;
    return false;
}
std::string Text::getContent()
{
    return content;
}