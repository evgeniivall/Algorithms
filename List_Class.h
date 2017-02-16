#ifndef LIST_CLASS_H
#define LIST_CLASS_H


#include <iostream>
#include <initializer_list>
#include "iterator.h"


template <typename T>
class List
{
private:
    friend class iterator<T>;
    struct Node
	{
		T data;
        Node* next;
        Node* prev;
	};
    Node* head_;
    Node* tail_;

public:

    List() :head_(NULL), tail_(NULL){}
    List(const T& a);
    List(const List& lst);
    List(std::initializer_list<T> list);
    explicit List(size_t size, const T& value = T());
    List& operator =(const List &lst);
    ~List();
    void push_back(const T& a);
    void push_front(const T& a);


    void pop_back();
    void pop_front();

    iterator<T> begin()const;
    iterator<T> end()const;

    iterator<T> insert(iterator<T> pos, const T& value);

    iterator<T> erase(iterator<T> pos);
    iterator<T> erase(iterator<T> first, iterator<T> last);
    std::size_t size();
    bool empty()
    {
        return (head_ == NULL);
    }

    T& front()
    {
        return  head_->data;
    }

    const T& front()const
    {
        return  head_->data;
    }

    T& back()
    {
        return  tail_->data;
    }

    const T& back()const
    {
        return  tail_->data;
    }

};

template <typename T>
List<T>::List(const T& a)
{
    head_ = new Node;
    head_->data = a;

    head_->next = new Node;
    head_->next->next = NULL;
    head_->next->prev = head_;

    head_->next =NULL;
    head_->prev = NULL;
    tail_ = head_;
}


template <typename T>
List<T>::List(const List<T>& lst)
{
    for(iterator<T> i = lst.begin(); i != lst.end(); i++)
    {
        this->push_back(*i);
    }
}

template <typename T>
List<T>::List(std::initializer_list<T> list): head_(NULL), tail_(NULL)
{
    for(auto l = list.begin(); l != list.end(); l++)
    {
        push_back(*l);
    }
}

template <typename T>
List<T>::List(size_t size, const T& value): head_(NULL), tail_(NULL)
{
     for(std::size_t i = 0; i < size; i++)
     {
         push_back(value);
     }
}

template <typename T>
List<T>& List<T>::operator =(const List<T> &lst)
{
    if(&lst != this)
    {
        this->~List();
        for(iterator<T> i = lst.begin(); i != lst.end(); i++)
        {
            this->push_back(*i);
        }

    }
    return *this;
}

template <typename T>
List<T>::~List()
{
    while(head_ != NULL)
    {
        Node* temp = head_->next;
        delete head_;
        head_ = temp;
    }


}


template <typename T>
void List<T>::push_back(const T& a)
{
    Node* temp = new Node;
    temp->next = new Node;
    temp->next->prev = temp;
    temp->next->next = NULL;
    temp->data = a;

    if (head_ != NULL)
    {
        delete (tail_->next);
        tail_->next = temp;
        temp->prev = tail_;
        tail_ = temp;
    }
    else
    {
        temp->prev = NULL;
        head_ = temp;
        tail_ = temp;
    }

}

template <typename T>
void List<T>::push_front(const T& a)
{
    Node* temp = new Node;
    temp->prev = NULL;
    temp->data = a;
    if (head_ != NULL)
    {
        temp->next = head_;
        head_->prev = temp;
        head_ = temp;
    }
    else
    {
        temp->next = NULL;
        head_ = tail_ = temp;
    }
}

template <typename T>
void List<T>::pop_back()
{
    if(!(this->empty()))
    {
        if(!(head_ == tail_))
        {
            Node* temp = tail_->prev;
            delete tail_->next;
            delete tail_;
            tail_ = temp;
            tail_->next = new Node;
            tail_->next->next = NULL;
            tail_->next->prev = tail_;
        }
        else
        {
            delete tail_->next;
            delete tail_;
            tail_ = head_ = NULL;
        }
    }
}

template <typename T>
void List<T>::pop_front()
{
    if(!(this->empty()))
    {
        if(!(head_ == tail_))
        {
            Node* temp = head_->next;
            delete head_;
            head_ = temp;
            head_->prev = NULL;
        }
        else
        {
            delete tail_;
            tail_ = head_ = NULL;
        }
    }

}

template <typename T>
iterator<T> List<T>::begin()const
{
    iterator<T> it(head_);
    return it;
}

template <typename T>
iterator<T> List<T>::end()const
{
    iterator<T> it(tail_);
    return ++it;
}

template <typename T>
iterator<T> List<T>::insert(iterator<T> pos, const T& value)
{
    List<T> temp;
    iterator<T> ret;
    for(iterator<T> p = begin(); p != end(); ++p)
    {
        if(p == pos)
        {
          temp.push_back(value);
          ret = temp.end();
        }
        temp.push_back(*p);
    }
    this->~List();
    *this = temp;
    return ret;

}

template <typename T>
iterator<T> List<T>::erase(iterator<T> pos)
{
    List<T> temp;
    iterator<T> ret;
    for(iterator<T> p = begin(); p != end(); ++p)
    {
        if(p == pos)
        {
            continue;
        }
        temp.push_back(*p);
        ret = temp.end();
    }
    this->~List();
    *this = temp;
    return ret;
}


template <typename T>
iterator<T> List<T>::erase(iterator<T> first, iterator<T> last)
{
    List<T> temp;
    iterator<T> ret;
    for(iterator<T> p = begin(); p != end(); ++p)
    {
        if(p == first)
        {
            while(p != last + 1)
                p++;
        }
        temp.push_back(*p);
        ret = temp.end();

    }
    this->~List();
    *this = temp;
    return ret;
}


template <typename T>
std::size_t List<T>::size()
{
    std::size_t count = 0;
    Node* temp = head_;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}


#endif // LIST_CLASS_H
