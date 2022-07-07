#pragma once
class Vector
{
public:

	Vector(); // konstruktor domyślny, tworzy vector na 1 lelemtn i korzysta z konstruktora od capacity
	Vector(unsigned int capacity); // rezerwuje miejsca na podaną liczbę elementów 
	Vector(const Vector& old); // c-tor kopiujący
	virtual~Vector(); // d-tor

	void reserve(unsigned int capacity); // zwiększa rozmiar zarezerwowanej pamięci vectora;
	void resize(unsigned int size); // pozwala zmniejszyć rozmiar vectora,

	unsigned int size() const;
	unsigned int capacity() const;
	unsigned int empty() const;

	void remove(unsigned int position); // pozwala wstawić wartość do wektora na zadane pozycje
	void insert(int value, unsigned int position); // usuwa element z wektora
	void clear(); // usuwa wszystkie elementy z wektora, jendka nie zmniejsza zrezerwowanej pamięci
	void push_back(int& value); // odkłada element na ostatnie wolne miejsce

	int& operator[](unsigned int i); // operator dostępu do danych na danej pozycji
	Vector& operator=(const Vector&); // to samo co c-tor kopiujący
	
private:
	unsigned int size;
	unsigned int capacity;
	int* _data; // inna notacja mData, m od member;
};

//Vector vect;
//int i = vect[1];
//tab[1];