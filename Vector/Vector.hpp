#pragma once
class Vector
{
public:

	Vector(); // konstruktor domyślny, tworzy pusty vector
	Vector(unsigned int capacity); // rezerwuje miejsca na podaną liczbę elementów 
	Vector(const Vector& old); // c-tor kopiujący
	virtual~Vector(); // d-tor

	void reserve(unsigned int capacity); // zwiększa rozmiar zarezerwowanej pamięci vectora;
	//void resize(unsigned int size); // pozwala zmniejszyć rozmiar vectora,
	 //Gettery
	unsigned int size() const;
	unsigned int capacity() const;
	bool empty() const;

	void remove(unsigned int position); // pozwala wstawić wartość do wektora na zadane pozycje
	void insert(int value, unsigned int position); // usuwa element z wektora
	void reserve(unsigned int capacity);
	void clear(); // usuwa wszystkie elementy z wektora, jendka nie zmniejsza zrezerwowanej pamięci
	void push_back(const int& value); // odkłada element na ostatnie wolne miejsce
	//void pop_back(const int& value); // odkłada 
	int& operator[](unsigned int i); // operator dostępu do danych na danej pozycji
	Vector& operator=(const Vector&); // to samo co c-tor kopiujący
	
private:
	unsigned int _size;
	unsigned int _capacity;
	int* _data; // inna notacja mData, m od member;
};

//Vector vect;
//int i = vect[1];
//tab[1];