/*
this class save all required information about the input text   
*/

#pragma once
#include "SAT.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include "Preprocess.h"

class Insights
{
public:
    Insights() = default;
    Insights(const Preprocessor &);
    void make_stopwords_SAT();
    int get_no_of_characters();
    double get_no_of_words();
    int get_no_of_sentences();
    int get_reading_time();
    int get_speaking_time();
    double get_uniqueness();

    bool isStopWords(const std::string &);

private:
    Preprocessor p;
    SAT stopwordsSAT;
    SAT uniquewordsSAT;
    int no_of_characters;
    double no_of_words;
    int no_of_sentences;
    int reading_time;
    int speaking_time;
    double uniqueness;
    void make_uniquewords_SAT(const std::string &);
    void calUnique();
};
Insights::Insights(const Preprocessor &otherP)
{
    this->p = otherP;
    no_of_characters = 0;
    no_of_words = 0.0;
    no_of_sentences = 0;
    reading_time = 0;
    speaking_time = 0;
    uniqueness = 0.0;
}

void Insights::make_stopwords_SAT()
{
    std::fstream f("stopwords.txt");
    std::string words;
    if (f.is_open())
    {
        while (f >> words)
        {
            stopwordsSAT.root = stopwordsSAT.insert(stopwordsSAT.root, words);
        }
    }
}

void Insights::make_uniquewords_SAT(const std::string &temp)
{
    uniquewordsSAT.root = uniquewordsSAT.insert(uniquewordsSAT.root, temp);
}

int Insights::get_no_of_characters()
{
    std::string temp = p.getTxt().getContent();
    for (unsigned int i = 0; i < temp.size(); i++)
        no_of_characters++;
    return no_of_characters;
}

double Insights::get_no_of_words()
{
    no_of_words = 0.0;
    for (auto x : p.getWords())
        no_of_words++;
    return no_of_words;
}

int Insights::get_no_of_sentences()
{
    for (auto x : p.getSentences())
        no_of_sentences++;
    return no_of_sentences;
}

int Insights::get_reading_time()
{
    double min = 0;
    double second = modf(no_of_words / 200, &min);
    second *= 10;
    if (second > 30)
    {
        min++;
    }
    return (int)min;
}

int Insights::get_speaking_time()
{
    double min = 0;
    double second = modf(no_of_words / 130, &min);
    second *= 10;
    if (second > 30)
    {
        min++;
    }
    if (min == 0)
    {
        min++;
    }
    return (int)min;
}

double Insights::get_uniqueness()
{
    calUnique();
    double uniquePercentage = uniqueness / no_of_words;
    uniquePercentage = uniquePercentage * 100;
    uniquePercentage = ceil(uniquePercentage);
    return uniquePercentage;
}

void Insights::calUnique()
{
    std::string temp = "";
    for (auto x : p.getWords())
    {
        temp = x;
        if (!stopwordsSAT.search(temp))
        {
            if (!uniquewordsSAT.search(temp))
            {
                make_uniquewords_SAT(temp);
                uniqueness++;
            }
        }
    }
}
bool Insights::isStopWords(const std::string &temp)
{
    if (stopwordsSAT.search(temp))
    {
        return true;
    }
    return false;
}