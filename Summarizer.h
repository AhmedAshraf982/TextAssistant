/*
kind of facade class where all the operations are done in required order after the creation of the respective object.  
*/

#pragma once
#include "Text.h"
#include "Graph.h"
#include "Textrank.h"
#include "Preprocess.h"
#include "Insights.h"
#include "SPQ.h"
#include <iostream>
#include <fstream>

class summarizer
{
public:
    void summaryMaker(std::ifstream &file);
    void summaryMaker(const std::string &data);

private:
    Graph graph;
    std::vector<std::string> data;
    std::string summary;
    double length;
    SPQ pq;
    void makeGraph(Preprocessor &pp);
    void joinSummary();
    void arrangingData(Preprocessor &);
    void printSummary();
    void information(Preprocessor &pp);
};

void summarizer::information(Preprocessor &pp)
{
    pp.wordTokenizing();
    pp.sentenceTokenizing();
    Insights is(pp);
    std::cout << "Number of Characters : " << is.get_no_of_characters() << "       ";
    std::cout << "Number of Sentences : " << is.get_no_of_sentences() << "       ";
    std::cout << "Number of Words : " << is.get_no_of_words() << std::endl;
    std::cout << "Reading Time  : " << is.get_reading_time() << "       ";
    std::cout << "Speaking Time  : " << is.get_speaking_time() << "       ";
    std::cout << "Unique Words  : " << is.get_uniqueness() << " % " << std::endl;
}
double Vertex::compareTo(Vertex *adjacent)
{
    double similarity = 0.0;
    Preprocessor pp;
    Insights is;
    is.make_stopwords_SAT();
    std::vector<std::string> sent = pp.breakSentenceIntoWord(getContent());
    std::vector<std::string> sent2 = pp.breakSentenceIntoWord(adjacent->getContent());
    int similarWords = 0;
    for (unsigned int i = 0; i < sent.size(); i++)
    {
        if (!is.isStopWords(sent[i]))
        {
            for (unsigned int j = 0; j < sent2.size(); j++)
            {
                if (sent[i] == sent2[j])
                {
                    similarWords++;
                }
            }
        }
    }
    similarity = similarWords / (log10(sent.size()) + log10(sent2.size()));
    return similarity;
}

void summarizer::makeGraph(Preprocessor &pp)
{
    for (auto x : pp.getSentences())
    {
        std::string temp = x;
        Vertex *v = new Vertex(temp);
        graph.addVertex(v);
    }
}
void summarizer::arrangingData(Preprocessor &local)
{
    for (unsigned int i = 0; i < data.size(); i++)
    {
        int line = 0;
        std::string temp = data[i];
        for (auto x : local.getSentences())
        {
            std::string temp1 = x;
            if (temp == temp1)
            {
                pq.push(temp, line);
            }
            else
            {
                line++;
            }
        }
    }
}
void summarizer::joinSummary()
{
    std::string temp;
    for (unsigned int i = 0; i < length; i++)
    {
        temp = graph.getVertexAtIndex(i)->getContent();
        data.emplace_back(temp);
    }
}
void summarizer::printSummary()
{
    summary.clear();
    while (!pq.isempty())
    {
        summary += pq.front();
        pq.pop();
    }
    std::cout << summary << std::endl;
}
void summarizer::summaryMaker(const std::string &data)
{
    Text txt(data);
    if (txt.contentLength())
    {
        std::cout << "  Original Paragraph   " << std::endl;
        std::cout << std::endl;
        std::cout << txt.getContent() << std::endl;
        std::cout << std::endl;
        Preprocessor pprocessor(txt);
        Preprocessor localProcessor(txt);
        localProcessor.sentenceTokenizing();
        information(pprocessor);
        Insights insight(pprocessor);
        length = (double)insight.get_no_of_sentences();
        length = ceil((length / 100) * 15);
        makeGraph(pprocessor);
        graph.buildGraph();
        textRank txtRank(graph);
        txtRank.rank();
        txtRank.sort();
        joinSummary();
        arrangingData(localProcessor);
        std::cout << std::endl;
        std::cout << "  Summary  " << std::endl;
        std::cout << std::endl;
        printSummary();
        std::cout << std::endl;
        std::cout << "  Total Sentences :  " << length << std::endl;
    }
}
void summarizer::summaryMaker(std::ifstream &file)
{
    Text txt(file);
    if (txt.contentLength())
    {
        std::cout << "  Original Paragraph   " << std::endl;
        std::cout << std::endl;
        std::cout << txt.getContent() << std::endl;
        std::cout << std::endl;
        Preprocessor pprocessor(txt);
        Preprocessor localProcessor(txt);
        localProcessor.sentenceTokenizing();
        information(pprocessor);
        Insights insight(pprocessor);
        length = (double)insight.get_no_of_sentences();
        length = ceil((length / 100) * 15);
        makeGraph(pprocessor);
        graph.buildGraph();
        textRank txtRank(graph);
        txtRank.rank();
        txtRank.sort();
        joinSummary();
        arrangingData(localProcessor);
        std::cout << std::endl;
        std::cout << "  Summary  " << std::endl;
        std::cout << std::endl;
        printSummary();
        std::cout << std::endl;
        std::cout << "  Total Sentences :  " << length << std::endl;
    }
}