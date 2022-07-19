#pragma once
class Vector
{
public:
	Vector(); // konstruktor domyslny, tworzy pusty wektor
	Vector(unsigned int capacity); // rezerwuje miejsca na podana liczbe elementow
	Vector(const Vector& old); //c-tor kopiuj¹cy
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


	int& operator[](unsigned int position); //operator dostepu do danych na podanej pozycji
	Vector& operator=(const Vector& other); //to samo co c-tor kopiujacy

	//Praca domowa:
	void copyTo(Vector& other, unsigned int index); //skopiuj zawartosc wektora other w podane miejsce,
	void remove(unsigned int from, unsigned int to); //usuwa wiele wartosci od indeksu from do indeksu to
	void pop_back(); // usuwa ostatni element
	void bubbleSort(); //sortowanie za pomoc¹ algorytmu sortowania babelkowego

private:
	unsigned int _size;
	unsigned int _capacity;
	int* _data;
};