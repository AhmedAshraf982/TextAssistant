/*
vertex and edge structures to build graphs   
*/



#include <string>
#include <iostream>
#include <vector>

class Vertex;
class edge
{
public:
    Vertex *neighbour;
    double weight;
};

class Vertex
{
    std::string content;
    double score;
    std::vector<edge> edges;

public:
    Vertex();
    Vertex(std::string content);
    ~Vertex();

    // ---- SETTERS ----
    void addEdge(Vertex *neighbour, double weight);
    void setContent(std::string data);
    void setScore(double newScore);

    double compareTo(Vertex *neighbor);

    // ---- GETTERS ----
    std::string getContent();
    double getScore();
    std::vector<edge> getEdges();
    edge getEdgeIndex(int i);
    int numberOfEdges();
};

Vertex::Vertex()
{
    score = 1;
}
Vertex::Vertex(std::string str)
{
    content = str;
    score = 1;
}

Vertex::~Vertex()
{
}

void Vertex::addEdge(Vertex *neighbour, double weight)
{
    edge link;
    link.neighbour = neighbour;
    link.weight = weight;
    edges.push_back(link);
}

void Vertex::setContent(std::string data)
{
    content = data;
}

void Vertex::setScore(double newScore)
{
    score = newScore;
}

std::string Vertex::getContent()
{
    return content;
}
double Vertex::getScore()
{
    return score;
}
std::vector<edge> Vertex::getEdges()
{
    return edges;
}
edge Vertex::getEdgeIndex(int i)
{
    return edges[i];
}

int Vertex::numberOfEdges()
{
    return edges.size();
}