/*
nlp data cleaning pipeline contains lowercasing, stopwords removal, word and sentence tokenizing   
*/


#pragma once
#include "Text.h"
#include <iostream>
#include <string>
#include "Linkedlist.h"

using LLstring = Singlylist<std::string>;

class Preprocessor
{
public:
    Preprocessor();
    Preprocessor(const Text &);

    void sentenceTokenizing();
    void wordTokenizing();
    LLstring getSentences();
    LLstring getWords();
    Text getTxt();
    std::vector<std::string> breakSentenceIntoWord(std::string str);

private:
    Text txt;
    LLstring sentences;
    LLstring words;
    std::string lowerCasing(const std::string &temp);
    bool isPeriod(char);
};

Preprocessor::Preprocessor() {}

Preprocessor::Preprocessor(const Text &thatTxt)
{
    this->txt = thatTxt;
}

std::string Preprocessor::lowerCasing(const std::string &temp)
{
    std::string text = temp;
    for (std::string::size_type i = 0; i < text.size(); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')

            (text.at(i)) += 32;
    }
    return text;
}

bool Preprocessor::isPeriod(char c)
{
    return (c == '.' || c == '?' || c == '!') ? true : false;
}

void Preprocessor::wordTokenizing()
{
    std::string temp = txt.getContent();
    std::string txt = "";
    for (unsigned int i = 0; i < temp.size(); i++)
    {
        if (ispunct(temp[i]) == false)
        {
            if (temp[i] == ' ')
            {
                words.insert_last(lowerCasing(txt));
                txt.clear();
            }
            else
            {
                txt += temp[i];
            }
        }
    }
}
std::vector<std::string> Preprocessor::breakSentenceIntoWord(std::string str)
{
    std::vector<std::string> vect;
    std::string word = "";
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {

            vect.push_back(lowerCasing(word));
            word.clear();
        }
        else
        {
            word.push_back(str[i]);
        }
    }
    return vect;
}
LLstring Preprocessor::getSentences()
{
    return sentences;
}

LLstring Preprocessor::getWords()
{
    return words;
}

Text Preprocessor::getTxt()
{
    return txt;
}

void Preprocessor::sentenceTokenizing()
{
    std::string text = txt.getContent();
    std::string temp = "";
    for (std::string::size_type i = 0; i < text.size(); i++)
    {
        if (isPeriod(text[i]))
        {
            if (temp[0] == ' ')
                temp.erase(temp.begin());
            temp += text[i];
            sentences.insert_last(temp);
            temp.clear();
        }
        else
            temp += text[i];
    }
}