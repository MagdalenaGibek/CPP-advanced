#include "Vector.hpp"
#include <string>

Vector::Vector()
	: _size(0)
	, _capacity(0)
	, _data(nullptr) 
{

}

Vector::Vector(unsigned int capacity)
	: _size(0)
	, _capacity(capacity)
{
	_data = new int[_capacity];
}

Vector::Vector(const Vector& old)
{
	_capacity = old._capacity;
	_size = old._size;

	_data = new int[_capacity]; //utworz nowa pamiec dla naszego wektora
	for (unsigned int i = 0; i < old._size; ++i) //i skopiuj do niej wszystko z drugiego wektora
	{
		_data[i] = old._data[i];
	}
}

Vector::~Vector()
{
	if (_data != nullptr) // usunięcie nullptr jest calkowicie legalne, ale uczymy sie i zapamietujemy ze mimio wszystko jakikolwiek dostep do wskaznika powinien byc poprzedzony sprawdzeniem czy wskazuje na cokolwiek
	{
		delete[] _data; // usuwamy tablice na ktora wskazuje wskaznik _data
		_data = nullptr; // po usunieciu wskaznika (zwolnieniu pamieci) ustawimy zawsze nulltpr aby dwa razy nie usunac tej pamieci, albo zeby niechcacy nie probowac sie do niej dobrac
	}
}

unsigned int Vector::capacity() const
{
	return _capacity;
}

unsigned int Vector::size() const
{
	return _size;
}

bool Vector::empty() const
{
	return _size == 0;
}

void Vector::push_back(const int& value)
{
	if (_size >= _capacity) //jesli potrzeba to zwiększ pamięć
	{
		reserve((_capacity + 1) * 2);
	}

	_data[_size++] = value;
}

void Vector::reserve(unsigned int capacity)
{
	//todo: exception if cap=0
	if (capacity == 0)
	{
		throw std::string("Pojemność musi być większa od 0. ");
	}
	int* data = new int[capacity]; //nowa tablica na elementy
	for (unsigned int i = 0; i < _size; ++i) //skopiuj wszystko do niej
	{
		data[i] = _data[i];
	}
	_capacity = capacity;
	delete[] _data; //zwolnij stara pamiec 
	_data = data; //nadpisz wskzanik tak zeby wektor przechowywał już nowa większa pamięć
}

void Vector::clear()
{
	_size = 0;
}

int& Vector::operator[](unsigned int position)
{
	if (position >= _size)
	{
		//todo: exception
		throw std::string("Pozycja spoza zakresu.");
	}

	return _data[position];
}

Vector& Vector::operator=(const Vector& other)
{
	//przy wolaniu delete nie trzeba sprawdzac czy wskaznik jest nullptr
	delete[] _data; // usuwamy tablice na ktora wskazuje wskaznik _data

	_capacity = other._capacity;
	_size = other._size;

	_data = new int[_capacity]; //utworz nowa pamiec dla naszego wektora
	for (unsigned int i = 0; i < other._size; ++i) //i skopiuj do niej wszystko z drugiego wektora
	{
		_data[i] = other._data[i];
	}

	return *this;
}

void Vector::copyTo(Vector& other, unsigned int index)
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
	for (unsigned int i = index; i < (index+other.size()); ++i)
	{
		_data[i] = other[i-index];
	}
	_size += other.size();
}

void Vector::remove(unsigned int from, unsigned int to)
{
	for (int i = from; i <= to; ++i)
	{
		_data[i] = _data[i+(to - from + 1)];
	}

	_size -= (to - from + 1);
}

void Vector::pop_back()
{
	_size -= 1;
}

void Vector::bubbleSort()
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

void Vector::insert(int value, unsigned int index)
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

void Vector::remove(unsigned int index)
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