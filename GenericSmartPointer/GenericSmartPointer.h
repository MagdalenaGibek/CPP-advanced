#pragma once
#include "RefCounter.hpp"

template<typename T>
class SharedSmartPointer
{
public:
	SharedSmartPointer()
		: _data(nullptr), reference(0)
	{
		reference = new RefCounter();

		reference->AddRef(); //zwiekszamy licznik o 1 bo juz istniejmy 
	}

	SharedSmartPointer(T* data)
		: _data(data)
	{
		reference = new RefCounter();

		reference->AddRef(); //zwiekszamy licznik o 1 bo juz istniejmy 
	}

	SharedSmartPointer(const SharedSmartPointer<T>& second)
		:_data(second._data), reference(second.reference) //kopiujemy reference, wiec wspoldzielimy wskaznik na licznik
	{
		reference->AddRef();
	}

	~SharedSmartPointer()
	{
		freePointer();
	}

	T& operator*()
	{
		return *_data;
	}

	T* operator->()
	{
		return _data;
	}

	SharedSmartPointer<T> operator = (const SharedSmartPointer<T>& second)
	{
		if (this != &second)
		{
			freePointer();
			_data = second._data;
			reference = second.reference;
			reference->AddRef();
		}
		return *this;
	}

private:
	T* _data;
	RefCounter* reference;
	void freePointer()
	{
		if (reference->Release() == 0)
		{
			delete _data;
			delete reference;
		}
	}
};