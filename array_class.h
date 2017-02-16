#ifndef ARRAY_CLASS_H
#define ARRAY_CLASS_H
#include "iterator.h"
#include <iostream>
template <class Array_Type, std::size_t Array_Size>
struct Array
{
    Array_Type data_[Array_Size];

    //ELEMENT ACCESS

//access the last element
    Array_Type& back();
    const Array_Type& back() const;

//access the first element
    Array_Type& front();
    const Array_Type& front() const;

//access specified element with bounds checking
    Array_Type& at(std::size_t pos );
    const Array_Type& at(std::size_t pos ) const;

//access specified element
    Array_Type& operator[](std::size_t i);
    const Array_Type& operator[](std::size_t i) const;

//direct access to the underlying array
    Array_Type* data();
    const Array_Type* data() const;

    //ITERATOR

    iterator<Array_Type> begin()
    {
        iterator<Array_Type> it(data_);
        return it;
    }

    iterator<Array_Type> end()
    {
        iterator<Array_Type> it(&data_[Array_Size]);
        return it;
    }

    //CAPACITY

//checks whether the container is empty
    bool empty();

//returns the number of elements
    std::size_t size() const;

    //OPERATIONS

//fill the container with specified value
    void fill( const Array_Type& value );

};
#include "array_class_impl.h"
#endif // ARRAY_CLASS_H
