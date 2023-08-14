/*
SPQ is String Priority Queue (max/min heap) used for appropriate ranking of sentences.  
*/

#pragma once
#include <iostream>
#include <string>

class spqNode
{
public:
    std::string data;
    double priority;
    spqNode *next;
    spqNode(std::string d = "", double p = 0, spqNode *n = nullptr)
    {
        data = d;
        priority = p;
        next = n;
    }
};
class SPQ
{
public:
    SPQ();
    bool isempty();
    spqNode *begin();
    void push(const std::string &d, double priority);
    void pop();
    std::string front();

private:
    spqNode *top;
};

SPQ::SPQ()
{
    top = nullptr;
}
bool SPQ::isempty()
{
    return top == nullptr ? true : false;
}
spqNode *SPQ::begin()
{
    return top;
}
void SPQ::push(const std::string &d, double priority)
{
    if (isempty())
    {
        top = new spqNode(d, priority, nullptr);
    }
    else
    {
        if (priority < top->priority)
        {
            top = new spqNode(d, priority, begin());
        }
        else
        {
            spqNode *temp = top;
            spqNode *newspqNode = new spqNode(d, priority);
            while (temp->next && temp->next->priority <= priority)
            {
                temp = temp->next;
            }
            newspqNode->next = temp->next;
            temp->next = newspqNode;
        }
    }
}
void SPQ::pop()
{
    spqNode *temp = begin();
    top = top->next;
    delete temp;
}
std::string SPQ::front()
{
    return top->data;
}