#include <string>
#include <vector>
#include <fstream>

using namespace std;

class node
{
public:
    string value;
    node *left;
    node *right;
    int hei;
};

class avlTree
{
public:
    node *root;
    string max(string a, string b);
    int height(node *N);
    int max(int a, int b);
    node *newNode(string key);
    node *rightRotate(node *y);
    node *leftRotate(node *x);
    int getBalance(node *N);
    node *insert(node *node, string val);
    node *minValueNode(node *node);
    bool search(string key);
    avlTree()
    {
        root = NULL;
    }
};

bool avlTree::search(string key)
{
    node *temp = root, *parent = root;
    if (temp == NULL)
        return false;
    else
    {
        while (temp != NULL && temp->value != key)
        {
            parent = temp;
            if (temp->value < key)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
    }
    if (temp == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int avlTree::max(int a, int b)
{
    return (a > b) ? a : b;
}
int avlTree::height(node *N)
{
    if (N == NULL)
        return 0;
    return N->hei;
}

node *avlTree::newNode(string key)
{
    node *leaf = new node;
    leaf->value = key;
    leaf->left = NULL;
    leaf->right = NULL;
    leaf->hei = 1;
    return leaf;
}

node *avlTree::rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->hei = max(height(y->left), height(y->right)) + 1;
    x->hei = max(height(x->left), height(x->right)) + 1;

    return x;
}

node *avlTree::leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->hei = max(height(x->left), height(x->right)) + 1;
    y->hei = max(height(y->left), height(y->right)) + 1;

    return y;
}

int avlTree::getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node *avlTree::insert(node *nodes, string key)
{
    if (nodes == NULL)
        return newNode(key);
    if (key < nodes->value)
        nodes->left = insert(nodes->left, key);
    else
        nodes->right = insert(nodes->right, key);
    nodes->hei = max(height(nodes->left), height(nodes->right)) + 1;
    int balance = getBalance(nodes);
    if (balance > 1 && key < nodes->left->value)
        return rightRotate(nodes);
    if (balance < -1 && key > nodes->right->value)
        return leftRotate(nodes);
    if (balance > 1 && key > nodes->left->value)
    {
        nodes->left = leftRotate(nodes->left);
        return rightRotate(nodes);
    }
    if (balance < -1 && key < nodes->right->value)
    {
        nodes->right = rightRotate(nodes->right);
        return leftRotate(nodes);
    }
    return nodes;
}

avlTree avl;
void avlTreemaker()
{
    fstream f("stopword.txt");
    string words;
    if (f.is_open())
    {
        while (f >> words)
        {
            avl.root = avl.insert(avl.root, words);
        }
    }
}
