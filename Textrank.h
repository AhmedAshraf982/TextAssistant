/*
Actual implementation of text rank algorithm which is inspired from page rank algorithm of Google. This algorithm is responsible for the summary. 
*/

#pragma once
#include "Graph.h"
#include <math.h>

#ifndef DAMPING_FACTOR
#define DAMPING_FACTOR 0.85
#endif

class textRank
{
public:
    void rank();
    void sort();
    textRank();
    textRank(const Graph &gra);

private:
    Graph graph;
};

textRank::textRank() = default;
textRank::textRank(const Graph &gra)
{
    this->graph = gra;
}

void textRank::rank()
{

    const double d = DAMPING_FACTOR;
    double error = 0.0001, current_rank;
    do
    {
        current_rank = graph.getVertices().at(0)->getScore();
        for (Vertex *Vi : graph.getVertices())
        {
            double sum_first = 0.0;
            for (edge Vi_in_edge : Vi->getEdges())
            {
                double weight_jk = 1.0;
                for (auto Vj_out_edges : Vi_in_edge.neighbour->getEdges())
                {
                    weight_jk += Vj_out_edges.weight;
                }
                sum_first += (Vi_in_edge.weight / weight_jk) * Vi_in_edge.neighbour->getScore();
            }
            Vi->setScore(d / graph.numberofVertices() + (1 - d) * sum_first);
        }
    } while (error < fabs(current_rank - graph.getVertexAtIndex(0)->getScore()));
}

void textRank::sort()
{

    int flag;
    do
    {
        flag = 0;
        for (unsigned int i = 1; i < graph.getVertices().size(); i++)
        {
            if (graph.getVertexAtIndex(i)->getScore() > graph.getVertexAtIndex(i - 1)->getScore())
            {
                std::swap(*graph.getVertices()[i], *graph.getVertices()[i - 1]);
                flag++;
            }
        }
    } while (flag != 0);
}
