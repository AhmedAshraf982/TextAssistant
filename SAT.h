/*
SAT is String AVL tree (self-balancing BST) used for optimized searching of stopwords in input and then their deletion.  
*/


#pragma once
#include <iostream>

class SATNode
{
public:
    std::string value;
    SATNode *left;
    SATNode *right;
    int height;
};

class SAT
{
public:
    SAT();

    int getHeight(SATNode *N);
    int getMax(int a, int b);

    SATNode *getNewSATNode(std::string key);

    SATNode *rightRotate(SATNode *y);
    SATNode *leftRotate(SATNode *x);

    int getBalance(SATNode *N);

    SATNode *insert(SATNode *N, std::string key);

    bool search(std::string key);

    SATNode *root;
};

SAT::SAT() { root = nullptr; }

bool SAT::search(std::string key)
{
    SATNode *temp = root, *parent = root;
    if (temp == NULL)
        return false;
    else
    {
        while (temp != NULL && temp->value != key)
        {
            parent = temp;
            if (temp->value < key)
                temp = temp->right;
            else
                temp = temp->left;
        }
    }
    if (temp == NULL)
        return false;
    else
        return true;
}

int SAT::getHeight(SATNode *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

int SAT::getMax(int a, int b)
{
    return (a > b) ? a : b;
}

SATNode *SAT::getNewSATNode(std::string key)
{
    SATNode *leaf = new SATNode();
    leaf->value = key;
    leaf->left = nullptr;
    leaf->right = nullptr;
    leaf->height = 1;
    return leaf;
}

SATNode *SAT::rightRotate(SATNode *y)
{
    SATNode *x = y->left;
    SATNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

SATNode *SAT::leftRotate(SATNode *x)
{
    SATNode *y = x->right;
    SATNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

int SAT::getBalance(SATNode *N)
{
    if (N == NULL)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}

SATNode *SAT::insert(SATNode *N, std::string key)
{

    if (N == NULL)
        return getNewSATNode(key);
    if (key < N->value)
        N->left = insert(N->left, key);
    else
        N->right = insert(N->right, key);
    N->height = getMax(getHeight(N->left), getHeight(N->right)) + 1;
    int balance = getBalance(N);
    if (balance > 1 && key < N->left->value)
        return rightRotate(N);
    if (balance < -1 && key > N->right->value)
        return leftRotate(N);
    if (balance > 1 && key > N->left->value)
    {
        N->left = leftRotate(N->left);
        return rightRotate(N);
    }
    if (balance < -1 && key < N->right->value)
    {
        N->right = rightRotate(N->right);
        return leftRotate(N);
    }
    return N;
}
