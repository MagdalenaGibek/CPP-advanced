#pragma once

#include <string>

template<typename T>
class Vector
{
public:
	Vector(); // konstruktor domyslny, tworzy pusty wektor
	Vector(unsigned int capacity); // rezerwuje miejsca na podana liczbe elementow
	Vector(const Vector<T>& old); //c-tor kopiuj¹cy
	virtual ~Vector(); //d-tor

	void reserve(unsigned int capacity); // zwiêksza rozmiar zarezerwowanej pamieci vectora, ale nie mozna zmienjszyc

	//Gettery:
	unsigned int capacity() const;
	unsigned int size() const;
	bool empty() const;

	void insert(int value, unsigned int index); //pozwala wstawic wartosc do wektora na zadana pozycje
	void remove(unsigned int index); //usuwa element z wektora
	void clear(); //usuwa wszystkie elementy zwektora, jednak nie zmniejsza zarezerwowanej pamieci
	void push_back(const int& value); // odklada element na ostatnie wolne miejsce 


	T& operator[](unsigned int position); //operator dostepu do danych na podanej pozycji
	Vector<T>& operator=(const Vector<T>& other); //to samo co c-tor kopiujacy

	//Praca domowa:
	void copyTo(Vector<T>& other, unsigned int index); //skopiuj zawartosc wektora other w podane miejsce,
	void remove(unsigned int from, unsigned int to); //usuwa wiele wartosci od indeksu from do indeksu to
	void pop_back(); // usuwa ostatni element
	void bubbleSort(); //sortowanie za pomoc¹ algorytmu sortowania babelkowego

private:
	unsigned int _size;
	unsigned int _capacity;
	T* _data;
};

template<typename T>
Vector<T>::Vector()
	: _size(0)
	, _capacity(0)
	, _data(nullptr)
{

}

template<typename T>
Vector<T>::Vector(unsigned int capacity)
	: _size(0)
	, _capacity(capacity)
{
	_data = new T[_capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& old)
{
	_capacity = old._capacity;
	_size = old._size;

	_data = new T[_capacity]; //utworz nowa pamiec dla naszego wektora
	for (unsigned int i = 0; i < old._size; ++i) //i skopiuj do niej wszystko z drugiego wektora
	{
		_data[i] = old._data[i];
	}
}

template<typename T>
Vector<T>::~Vector()
{
	if (_data != nullptr) // usunięcie nullptr jest calkowicie legalne, ale uczymy sie i zapamietujemy ze mimio wszystko jakikolwiek dostep do wskaznika powinien byc poprzedzony sprawdzeniem czy wskazuje na cokolwiek
	{
		delete[] _data; // usuwamy tablice na ktora wskazuje wskaznik _data
		_data = nullptr; // po usunieciu wskaznika (zwolnieniu pamieci) ustawimy zawsze nulltpr aby dwa razy nie usunac tej pamieci, albo zeby niechcacy nie probowac sie do niej dobrac
	}
}

template<typename T>
unsigned int Vector<T>::capacity() const
{
	return _capacity;
}

template<typename T>
unsigned int Vector<T>::size() const
{
	return _size;
}

template<typename T>
bool Vector<T>::empty() const
{
	return _size == 0;
}

template<typename T>
void Vector<T>::push_back(const int& value)
{
	if (_size >= _capacity) //jesli potrzeba to zwiększ pamięć
	{
		reserve((_capacity + 1) * 2);
	}

	_data[_size++] = value;
}

template<typename T>
void Vector<T>::reserve(unsigned int capacity)
{
	//todo: exception if cap=0
	if (capacity == 0)
	{
		throw std::string("Pojemność musi być większa od 0. ");
	}
	T* data = new T[capacity]; //nowa tablica na elementy
	for (unsigned int i = 0; i < _size; ++i) //skopiuj wszystko do niej
	{
		data[i] = _data[i];
	}
	_capacity = capacity;
	delete[] _data; //zwolnij stara pamiec 
	_data = data; //nadpisz wskzanik tak zeby wektor przechowywał już nowa większa pamięć
}

template<typename T>
void Vector<T>::clear()
{
	_size = 0;
}

template<typename T>
T& Vector<T>::operator[](unsigned int position)
{
	if (position >= _size)
	{
		//todo: exception
		throw std::string("Pozycja spoza zakresu.");
	}

	return _data[position];
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	//przy wolaniu delete nie trzeba sprawdzac czy wskaznik jest nullptr
	delete[] _data; // usuwamy tablice na ktora wskazuje wskaznik _data

	_capacity = other._capacity;
	_size = other._size;

	_data = new T[_capacity]; //utworz nowa pamiec dla naszego wektora
	for (unsigned int i = 0; i < other._size; ++i) //i skopiuj do niej wszystko z drugiego wektora
	{
		_data[i] = other._data[i];
	}

	return *this;
}

template<typename T>
void Vector<T>::copyTo(Vector<T>& other, unsigned int index)
{
	if (index > _size)
	{

		//to do wyjątek
		throw std::string("Pozycja spoza zakresu.");
	}
	if ((_size + other.size()) >= _capacity)
	{
		reserve((_capacity + other.size()) * 2);
	}

	for (int i = _size - 1; i >= static_cast<int>(index); --i) // bez static cast i przyjmuje liczby ujemne
	{
		_data[i + other.size()] = _data[i];
	}
	for (unsigned int i = index; i < (index + other.size()); ++i)
	{
		_data[i] = other[i - index];
	}
	_size += other.size();
}

template<typename T>
void Vector<T>::remove(unsigned int from, unsigned int to)
{
	for (int i = from; i <= to; ++i)
	{
		_data[i] = _data[i + (to - from + 1)];
	}

	_size -= (to - from + 1);
}

template<typename T>
void Vector<T>::pop_back()
{
	_size -= 1;
}

template<typename T>
void Vector<T>::bubbleSort()
{
	bool swapped = false;
	int counter = _size - 1;
	do
	{
		swapped = false;


		for (unsigned int i = 0; i < counter; i++)// zadanie domowe, zrobić tak, żeby nie ruszać elementów końcowych, bo największy zawsze jest na końcu, wtedy można zrobić bez flagi
				// może pętla w pętli, zmieniać size, 
		{
			if (_data[i] > _data[i + 1])
			{
				int tmp = _data[i + 1];
				_data[i + 1] = _data[i];
				_data[i] = tmp;
				swapped = true;
			}
		}
		--counter;
	} while (swapped);
}

template<typename T>
void Vector<T>::insert(int value, unsigned int index)
{
	if (index > _size)
	{
		//todo: wyjatek
		throw std::string("Pozycja spoza zakresu.");
	}

	if (_size >= _capacity) //upewnic sie ze mamy miejsce na przesuwanie
	{
		reserve((_capacity + 1) * 2);
	}

	for (unsigned int i = _size; i > index; --i) //petla robiaca miejsce na wstawiany element
	{
		_data[i] = _data[i - 1];
	}

	_data[index] = value; // wpisujemy nową wartość
	++_size; //zwiekszamy rozmiar o 1
}

template<typename T>
void Vector<T>::remove(unsigned int index)
{
	if (index >= _size)
	{
		//todo: wyjatek
		throw std::string("Pozycja spoza zakresu.");
	}

	for (unsigned int i = index; i < _size; ++i)
	{
		_data[i] = _data[i + 1];
	}

	--_size;
}