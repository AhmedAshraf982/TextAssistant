/*
generic singly linked list implementation with different useful functions used to save sentences and words strings   
*/



#pragma once
#include <initializer_list>

template <typename T>
class LLNode
{
    T data;
    LLNode<T> *next;

public:
    LLNode() = default;
    LLNode(T d, LLNode<T> *n) : data(d), next(n) {}

    T &get_data() { return data; }
    LLNode<T> *get_next() { return next; }

    void set_data(T d) { data = d; }
    void set_next(LLNode *n) { next = n; }
};
template <typename T>
class Singlylist
{
    LLNode<T> *head;

public:
    Singlylist() : head(nullptr)
    {
    }
    LLNode<T> *begins()
    {
        return head;
    }
    bool is_empty()
    {
        return head == nullptr ? true : false;
    }
    LLNode<T> *ends()
    {
        return nullptr;
    }

    //void display()
    //{
    //	LLNode<T> *p = head;
    //	while (p != ends())
    //	{
    //		cout << p->get_data() << " ";
    //		p = p->get_next();
    //	}
    //}
    void insert(const T &d)
    {

        if (is_empty())
        {
            head = new LLNode<T>(d, nullptr);
        }
        else
        {
            head = new LLNode<T>(d, begins());
        }
    }
    void insert_mid(const T &d, int pos)
    {
        LLNode<T> *p = begins();
        if (pos == 0 || is_empty())
        {
            insert(d);
        }
        else
        {
            LLNode<T> *newLLNode = new LLNode<T>;
            LLNode<T> *prevLLNode = nullptr;
            for (int i = 1; i <= pos; i++)
            {
                prevLLNode = p;
                p = p->get_next();
            }
            newLLNode->set_data(d);
            newLLNode->set_next(p);
            prevLLNode->set_next(newLLNode);
        }
    }
    void insert_last(const T &d)
    {
        if (is_empty())
        {
            insert(d);
        }
        else
        {
            LLNode<T> *p = begins();
            LLNode<T> *newLLNode = new LLNode<T>;
            while (p->get_next() != end())
            {
                p = p->get_next();
            }
            newLLNode->set_data(d);
            newLLNode->set_next(nullptr);
            p->set_next(newLLNode);
        }
    }
    void remove()
    {
        LLNode<T> *temp = head;
        head = head->get_next();
        delete temp;
    }
    void remove_mid(int pos)
    {
        LLNode<T> *p = begins();
        LLNode<T> *prevLLNode = nullptr;
        if (pos == 0)
        {
            remove();
        }
        else
        {
            for (int i = 1; i <= pos; i++)
            {
                prevLLNode = p;
                p = p->get_next();
            }
            prevLLNode->set_next(p->get_next());
            delete p;
        }
    }
    void remove_last()
    {
        LLNode<T> *p = begins();
        LLNode<T> *prevLLNode = nullptr;
        while (p->get_next() != end())
        {
            prevLLNode = p;
            p = p->get_next();
        }
        prevLLNode->set_next(nullptr);
        delete p;
    }
    void reverse()
    {
        LLNode<T> *p = begins();
        LLNode<T> *q = nullptr;
        LLNode<T> *r = nullptr;

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
        LLNode<T> *ptr;

    public:
        singly_ll_iterator(LLNode<T> *p) : ptr(p)
        {
        }

        T &operator*()
        {
            return ptr->get_data();
        }

        LLNode<T> *get()
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
    T advances(LLNode<T> *root, int i)
    {
        for (int j = 1; j < i; j++)
        {
            root = root->get_next();
        }
        return root->get_data();
    }
    Singlylist(const std::initializer_list<T> &ilist) : head(NULL)
    {
        for (auto it = std::begin(ilist); it != std::end(ilist); it++)
            insert_last(*it);
    }
};
