/*
graph implementation to be used for textrank algorithm   
*/


#pragma once
#include "Vertex.h"
#include <math.h>

#ifndef THRESHOLD
#define THRESHOLD 0.1
#endif

class Graph
{

public:
    Graph();
    ~Graph();

    void addVertex(Vertex *newVertex)
    {
        vertices.push_back(newVertex);
    }
    std::vector<Vertex *> getVertices()
    {
        return vertices;
    }
    Vertex *getVertexAtIndex(int i)
    {
//        try
//        {
//            return vertices.at(i);
//        }
//        catch (const std::out_of_range &e)
//        {
//            std::cerr << "out of Range" << e.what() << '\n';
//        }
        return vertices.at(i);
    }
    int numberofVertices();

    void buildGraph();

private:
    std::vector<Vertex *> vertices;
};

Graph::Graph() = default;
Graph ::~Graph()
{
}

int Graph::numberofVertices()
{
    return vertices.size();
}

void Graph::buildGraph()
{
    int limit = numberofVertices();
    for (int i = 0; i < limit; i++)
    {
        for (int j = i + 1; j < limit; j++)
        {
            double similarity = getVertexAtIndex(i)->compareTo(getVertexAtIndex(j));
            if (similarity > THRESHOLD)
            {
                vertices[i]->addEdge(vertices[j], similarity);
                vertices[j]->addEdge(vertices[i], similarity);
            }
        }
    }
}
