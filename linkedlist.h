#include <string>
#include <iostream>
using namespace std;

class Node
{
    string data;
    Node *next;

public:
    Node(string d = "", Node *n = nullptr) : data(d), next(n)
    {
    }
    string &get_data()
    {
        return data;
    }
    Node *get_next()
    {
        return next;
    }
    void set_data(string d)
    {
        data = d;
    }
    void set_next(Node *n)
    {
        next = n;
    }
};

class UserDefine
{
    Node *head;

public:
    UserDefine() : head(nullptr)
    {
    }
    Node *begins()
    {
        return head;
    }
    bool is_empty()
    {
        return head == nullptr ? true : false;
    }
    Node *ends()
    {
        return nullptr;
    }

    void display()
    {
        Node *p = head;
        while (p != ends())
        {
            cout << p->get_data() << " ";
            p = p->get_next();
        }
    }
    void insert(const string &d)
    {

        if (is_empty())
        {
            head = new Node(d, nullptr);
        }
        else
        {
            head = new Node(d, begins());
        }
    }
    void insert_mid(const string &d, int pos)
    {
        Node *p = begins();
        if (pos == 0 || is_empty())
        {
            insert(d);
        }
        else
        {
            Node *newNode = new Node();
            Node *prevNode = nullptr;
            for (int i = 1; i <= pos; i++)
            {
                prevNode = p;
                p = p->get_next();
            }
            newNode->set_data(d);
            newNode->set_next(p);
            prevNode->set_next(newNode);
        }
    }
    void insert_last(const string &d)
    {
        if (is_empty())
        {
            insert(d);
        }
        else
        {
            Node *p = begins();
            Node *newNode = new Node();
            while (p->get_next() != end())
            {
                p = p->get_next();
            }
            newNode->set_data(d);
            newNode->set_next(nullptr);
            p->set_next(newNode);
        }
    }
    void remove()
    {
        Node *temp = head;
        head = head->get_next();
        delete temp;
    }
    void remove_mid(int pos)
    {
        Node *p = begins();
        Node *prevNode = nullptr;
        if (pos == 0)
        {
            remove();
        }
        else
        {
            for (int i = 1; i <= pos; i++)
            {
                prevNode = p;
                p = p->get_next();
            }
            prevNode->set_next(p->get_next());
            delete p;
        }
    }
    void remove_last()
    {
        Node *p = begins();
        Node *prevNode = nullptr;
        while (p->get_next() != end())
        {
            prevNode = p;
            p = p->get_next();
        }
        prevNode->set_next(nullptr);
        delete p;
    }
    void reverse()
    {
        Node *p = begins();
        Node *q = nullptr;
        Node *r = nullptr;

        while (p != nullptr)
        {
            r = q;
            q = p;
            p = p->get_next();
            q->set_next(r);
        }
        head = q;
    }
    struct singly_ll_iterator
    {
    private:
        Node *ptr;

    public:
        singly_ll_iterator(Node *p) : ptr(p)
        {
        }

        string &operator*()
        {
            return ptr->get_data();
        }

        Node *get()
        {
            return ptr;
        }

        singly_ll_iterator &operator++() // pre-increment
        {
            ptr = ptr->get_next();
            return *this;
        }

        singly_ll_iterator operator++(int) // post-increment
        {
            singly_ll_iterator result = *this;
            ++(*this);
            return result;
        }

        friend bool operator==(const singly_ll_iterator &left, const singly_ll_iterator &right)
        {
            return left.ptr == right.ptr;
        }

        friend bool operator!=(const singly_ll_iterator &left, const singly_ll_iterator &right)
        {
            return left.ptr != right.ptr;
        }
    };
    singly_ll_iterator begin()
    {
        return singly_ll_iterator(head);
    }

    singly_ll_iterator end()
    {
        return singly_ll_iterator(NULL);
    }

    singly_ll_iterator begin() const
    {
        return singly_ll_iterator(head);
    }

    singly_ll_iterator end() const
    {
        return singly_ll_iterator(NULL);
    }

    UserDefine(const std::initializer_list<string> &ilist) : head(NULL)
    {
        for (auto it = std::begin(ilist); it != std::end(ilist); it++)
            insert_last(*it);
    }
};
