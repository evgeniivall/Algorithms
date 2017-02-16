#ifndef ITERATOR_H
#define ITERATOR_H

template<class T>
class iterator
{
private:
    T* current;
public:
    iterator():current(NULL){}
    explicit iterator(T* ptr):current(ptr){}
    iterator<T>& operator =(const iterator<T>& other);

    T& operator*();
    const int& operator*() const;
    T* operator->();
    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);

    iterator operator+(const std::size_t& n) const;
    iterator operator-(const std::size_t& n) const;
    iterator& operator+=(const std::size_t& n);
    iterator& operator-=(const std::size_t& n);

    std::ptrdiff_t operator-(const iterator<T> & other);
    T* base() const;
};

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
    return *current;
}

template<class T>
const int& iterator<T>::operator*() const
{
    return *current;
}

template<class T>
T* iterator<T>::operator ->()
{
    return current;
}

template<class T>
iterator<T>& iterator<T>::operator++()
{
    current++;
    return *this;
}

template<class T>
iterator<T> iterator<T>::operator++(int)
{
    return iterator(current++);
}

template<class T>
iterator<T>& iterator<T>::operator--()
{
    current--;
    return *this;
}

template<class T>
iterator<T> iterator<T>::operator--(int)
{
    return iterator(current--);
}

template<class T>
iterator<T> iterator<T>::operator+(const std::size_t& n) const
{
    return iterator(current + n);
}

template<class T>
iterator<T> iterator<T>::operator-(const std::size_t& n) const
{
    return iterator(current - n);
}

template<class T>
iterator<T>& iterator<T>::operator+=(const std::size_t& n)
{
    current += n;
    return *this;
}

template<class T>
iterator<T>& iterator<T>::operator-=(const std::size_t& n)
{
    current -= n;
    return *this;
}

template<class T>
std::ptrdiff_t iterator<T>::operator -(const iterator<T> & other)
{
    return current - other.current;
}

template<class T>
T* iterator<T>::base() const { return current; }

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
