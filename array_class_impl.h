#ifndef ARRAY_CLASS_IMPL_H
#define ARRAY_CLASS_IMPL_H


template <class Array_Type, std::size_t Array_Size>
void Array<Array_Type,Array_Size>::fill(const Array_Type& value )
{
    for(int i = 0; i < Array_Size; i++)
    {
        data_[i] = value;
    }
}

template <class Array_Type, std::size_t Array_Size>
Array_Type& Array<Array_Type,Array_Size>::back()
{
    return data_[Array_Size - 1];
}

template <class Array_Type, std::size_t Array_Size>
const Array_Type& Array<Array_Type,Array_Size>::back() const
{
    return data_[Array_Size - 1];
}

template <class Array_Type, std::size_t Array_Size>
Array_Type& Array<Array_Type,Array_Size>::front()
{
    return data_[0];
}

template <class Array_Type, std::size_t Array_Size>
const Array_Type& Array<Array_Type,Array_Size>::front() const
{
    return data_[0];
}


template <class Array_Type, std::size_t Array_Size>
Array_Type* Array<Array_Type,Array_Size>::data()
{
    return data_;
}

template <class Array_Type, std::size_t Array_Size>
const Array_Type* Array<Array_Type,Array_Size>::data() const
{
    return data_;
}


template <class Array_Type, std::size_t Array_Size>
Array_Type& Array<Array_Type,Array_Size>::at(std::size_t pos )
{
    return data_[pos];
}

template <class Array_Type, std::size_t Array_Size>
const Array_Type& Array<Array_Type,Array_Size>::at(std::size_t pos ) const
{
    return data_[pos];
}

template <class Array_Type, std::size_t Array_Size>
bool Array<Array_Type,Array_Size>::empty()
{
    return (size == 0)?true:false;
}

template <class Array_Type, std::size_t Array_Size>
std::size_t Array<Array_Type,Array_Size>::size() const
{
    return Array_Size;
}

template <class Array_Type, std::size_t Array_Size>
Array_Type& Array<Array_Type,Array_Size>::operator[](std::size_t i)
{
    return data_[i];
}

template <class Array_Type, std::size_t Array_Size>
const Array_Type& Array<Array_Type,Array_Size>::operator[](std::size_t i) const
{
    return data_[i];
}


template <class Array_Type, std::size_t Array_Size>
bool operator==(Array<Array_Type,Array_Size>& lhs, Array<Array_Type,Array_Size>& rhs)
{
    for(unsigned i = 0; i < Array_Size; i++)
    {
        if(lhs[i] != rhs[i])
            return false;
    }
    return true;
}

template <class Array_Type, std::size_t Array_Size>
bool operator!=(Array<Array_Type,Array_Size>& lhs, Array<Array_Type,Array_Size>& rhs)
{
    return !(rhs==lhs);
}

#endif // ARRAY_CLASS_IMPL_H
