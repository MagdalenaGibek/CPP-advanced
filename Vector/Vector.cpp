// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.hpp"

Vector::Vector()
    //: _size(0)
    //, _capacity(0)
    //, _data(nullptr)
{
    this->_capacity = 0;
    this->_size = 0;
    this->_data = nullptr;
}

Vector::Vector(unsigned int capacity)
    : _size(0)
    , _capacity(capacity)

{
    _data = new int[_capacity];

}

Vector::Vector(const Vector& old)
{
    _size = old._size;
    _capacity = old._capacity;
    _data = new int[_capacity];
    for (unsigned int i = 0; i < old._size; ++i)
    {
        _data[i] = old._data[i];
    }
}

Vector::~Vector()
{
    if (_data != nullptr)
    {
        delete[] _data;
        _data = nullptr;
    }
}

void Vector::reserve(unsigned int capacity)

{
    //todo: exception if(cap=0)
    this->_capacity = capacity;
    int* data = new int[capacity];
    for (unsigned int i = 0; i < _size; ++i)
    {
        data[i] = _data[i];
    }
    _capacity = capacity;
    delete[] _data;
    _data = data;
}

void Vector::clear()
{
    _size = 0;
}

unsigned int Vector::size() const
{
    return _size;
}

unsigned int Vector::capacity() const
{
    return _capacity;
}

bool Vector::empty() const
{
    return _size == 0;
}

void Vector::remove(unsigned int position)
{
    
    
}

void Vector::insert(int value, unsigned int position)
{
    if (_size < _capacity)
    {
        for (int i = position; i < _size; ++i)
        {
            _data[i] = _data[i + 1];
        }
    }
    else
    {
        reserve((_capacity + 1) * 2);
    }
}

void Vector::push_back(const int& value)
{
    if (_size >= _capacity)
    {
        reserve((_capacity+1) * 2);
    }
    else
    {
        _data[_size++] = value;
    }
}

int& Vector::operator[](unsigned int position)
{
    if (position > _size)
    {
        //todo exception;
    }

    //if (_data != nullptr) // powinniśmy w ten sposób sprawdzić we wszystkich metodach
    //{
    //    //todo exception;
    //}
  /*  }*/
    
    return _data[position];
}

Vector& Vector::operator=(const Vector& other)
{
    delete[] _data;
    _size = other._size;
    _capacity = other._capacity;
    _data = new int[_capacity];
    for (unsigned int i = 0; i < other._size; ++i)
    {
        _data[i] = other._data[i];
    }

    return *this;
}
