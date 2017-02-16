#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class List;



template<class T>
class iterator
{
private:
    typename List<T>::Node* current;
public:
    iterator():current(NULL){}
    iterator(const iterator<T> & other);
    explicit iterator(typename List<T>::Node* ptr):current(ptr){}
    iterator<T>& operator =(const iterator<T>& other);

    T& operator*();
    const T& operator*() const;
    T* operator->();
    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);

    iterator operator+(const std::size_t& n) const;
    iterator operator-(const std::size_t& n) const;
    iterator& operator+=(const std::size_t& n);
    iterator& operator-=(const std::size_t& n);

    typename List<T>::Node* base() const;
};

template<class T>
iterator<T>::iterator(const iterator<T> & other)
{
    current = other.current;
}

template<class T>
iterator<T>& iterator<T>::operator =(const iterator<T>& other)
{
    if (this != &other)
    {
        current = other.current;
    }
    return *this;
}

template<class T>
T& iterator<T>::operator*()
{
    return current->data;
}

template<class T>
const T& iterator<T>::operator*() const
{
    return current->data;
}

template<class T>
T* iterator<T>::operator ->()
{
    return &(current->data);
}

template<class T>
iterator<T>& iterator<T>::operator++()
{
	current = current->next;
    return *this;
}

template<class T>
iterator<T> iterator<T>::operator++(int)
{
    iterator temp = *this;
    ++(*this);
    return temp;
}

template<class T>
iterator<T>& iterator<T>::operator--()
{
	current = current->prev;
    return *this;
}

template<class T>
iterator<T> iterator<T>::operator--(int)
{
    iterator temp = *this;
    --(*this);
    return temp;
}

template<class T>
iterator<T> iterator<T>::operator+(const std::size_t& n) const
{
    iterator<T> it(*this);
    for(std::size_t i = 0; i < n; i++)
    {
        ++it;
    }
    return it;
}

template<class T>
iterator<T> iterator<T>::operator-(const std::size_t& n) const
{
    iterator<T> it(*this);
    for(std::size_t i = 0; i < n; i++)
    {
        --it;
    }
    return it;
}

template<class T>
iterator<T>& iterator<T>::operator+=(const std::size_t& n)
{
    for(std::size_t i = 0; i < n; i++)
    {
        ++(*this);
    }
    return *this;
}

template<class T>
iterator<T>& iterator<T>::operator-=(const std::size_t& n)
{
    for(std::size_t i = 0; i < n; i++)
    {
        --(*this);
    }
    return *this;
}



template<class T>
typename List<T>::Node* iterator<T>::base() const { return current; }

template <class T>
inline bool operator==(const iterator<T> &lhs, const iterator<T> &rhs)
{
    return lhs.base() == rhs.base();
}

template <class T>
inline bool operator!=(const iterator<T> &lhs, const iterator<T> &rhs)
{
    return lhs.base() != rhs.base();
}

#endif // ITERATOR_H
