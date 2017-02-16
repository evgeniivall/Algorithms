#ifndef ALGORITHMS_H
#define ALGORITHMS_H


template <typename T>
void swap(T& obj_1, T& obj_2)
{
    T temp = obj_1;
    obj_1 = obj_2;
    obj_2 = temp;
}

template <typename T>
bool defaultCmp(const T &obj_1, const T &obj_2)
{
    return obj_1 < obj_2;
}


template<template <typename> class Iterator, typename T, typename Comp = bool(*)(const T&, const T&)>
void bubbleSort(Iterator<T> start, Iterator<T> end,  Comp less = defaultCmp)
{
    for (Iterator<T> i = (end - 1); i != (start - 1); --i)
    {
        for (Iterator<T> j = start; j != i; ++j)
        {
            if(less(*(j+1), *j))
            {
                swap(*(j+1), *j);

            }
        }
    }
}

template<class T, class Comp = bool(*)(const T&, const T&)>
void bubbleSort(T *start, T *end,  Comp less = defaultCmp)
{
    for(T* i = (end - 1); i != (start - 1); --i)
    {
        for(T* j = start; j != i; ++j)
        {
            if(less(*(j+1), *j))
            {
                swap(*(j+1), *j);

            }
        }
    }
}

template<template <typename> class Iterator, typename T, typename Comp = bool(*)(const T&, const T&)>
void insertSort(Iterator<T> start, Iterator<T> end,  Comp less = defaultCmp)
{
    for (Iterator<T> i = start + 1; i != end; i++)
    {
        for (Iterator<T> j = i; j != start; j--)
        {
            if (less(*j,*(j-1)))
            {
                swap(*j,*(j-1));
            }
        }
    }

}

template<class T, class Comp = bool(*)(const T&, const T&)>
void insertSort(T *start, T *end,  Comp less = defaultCmp)
{
    for (T *i = start + 1; i != end; i++)
    {
        for (T *j = i; j != start; j--)
        {
            if (less(*j,*(j-1)))
            {
                swap(*j,*(j-1));
            }
        }
    }

}

template<template <typename> class Iterator, typename T, typename Comp = bool(*)(const T&, const T&)>
void selectionSort(Iterator<T> start, Iterator<T> end,  Comp less = defaultCmp)
{
    for (Iterator<T> i = start; i != end; i++)
    {
        Iterator<T> min = i;
        for (Iterator<T> j = i + 1; j != end; j++)
        {
            if ((less(*j,*min)))
                min = j;
        }
        swap(*i,*min);
    }

}

template<class T, class Comp = bool(*)(const T&, const T&)>
void selectionSort(T *start, T *end,  Comp less = defaultCmp)
{
    for (T *i = start; i != end; i++)
    {
        T *min = i;
        for (T *j = i + 1; j != end; j++)
        {
            if ((less(*j,*min)))
                min = j;
        }
        swap(*i,*min);
    }

}

template<template <typename> class Iterator, typename T>
void reverse(Iterator<T> start, Iterator<T> end)
{
    for(Iterator<T> s = start, e = (end - 1); s != e && (s+1) != e; s++, e--)
        swap(*s,*e);
}

template<typename T>
void reverse(T *start, T *end)
{
    for(T *s = start, *e = (end - 1); s != e && (s+1) != e; s++, e--)
        swap(*s,*e);
}


#endif // ALGORITHMS_H
