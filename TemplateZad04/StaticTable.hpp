#pragma once

template<typename T, unsigned int N>
class StaticTable
{
public:
	T& operator[](const unsigned int i)
	{
		//TODO: wyj¹tek out_of_range, gdy i >= N; https://en.cppreference.com/w/cpp/error/out_of_range
		if (i >= N)
		{
			throw std::out_of_range("Liczba jest spoza zakresu.");
		}
		
		return tab[i];
	}

	template<typename T2>
	void print(T2 separator)
	{
		//wypisuje cała tablice używając zmiennej T2 separator jako znaku rozdzielającego wartości
		std::cout << "Szablon główny: [";
		for (int i = 0; i < N; ++i)
		{
			std::cout << tab[i];
			if (i < N - 1)
			{
				std::cout << separator;
			}
		}
		std::cout << "]";
	}

private:
	T tab[N];
};

//specjalizacja szablonu klasy
template<unsigned int N>
class StaticTable<bool, N>
{
public:
	bool& operator[](const unsigned int i)
	{
		//TODO: wyj¹tek out_of_range, gdy i >= N; https://en.cppreference.com/w/cpp/error/out_of_range

		if (i >= N)
		{
			throw std::out_of_range("Liczba jest spoza zakresu.");
		}
		return tab[i];
	}
	template<typename T2>
	void print(T2 separator)
	{
		//wypisuje cała tablice używając zmiennej T2 separator jako znaku rozdzielającego wartości
		std::cout << "Szablon dla bool: [";
		for (int i = 0; i < N; ++i)
		{
			std::cout << std::boolalpha<< tab[i];
			if (i < N - 1)
			{
				std::cout << separator;
			}
		}
		std::cout << "]";
	}

private:
	bool tab[N];
};

//specjalizacja szablonu klasy dla wskaźników
template<typename T, unsigned int N>
class StaticTable<T*, N>
{
public:
	T*& operator[](const unsigned int i)
	{
		//todo: wyj¹tek out_of_range, gdy i >= n; https://en.cppreference.com/w/cpp/error/out_of_range
		if (i >= N)
		{
			throw std::out_of_range("liczba jest spoza zakresu.");
		}

		return tab[i];
	}
	template<typename T2>
	void print(T2 separator)
	{
		//wypisuje cała tablice używając zmiennej T2 separator jako znaku rozdzielającego wartości
		std::cout << "Szablon dla wskaźników: [";
		for (int i = 0; i < N; ++i)
		{
			std::cout << *tab[i];
			if (i < N - 1)
			{
				std::cout << separator;
			}
		}
		std::cout << "]";
	}

private:
	T* tab[N];
};

//specjalizacja szablonu klasy dla tekstów

template<unsigned int N>
class StaticTable<const char*, N>
{
public:
	const char*& operator[](const unsigned int i)
	{
		//todo: wyj¹tek out_of_range, gdy i >= n; https://en.cppreference.com/w/cpp/error/out_of_range
		if (i >= N)
		{
			throw std::out_of_range("liczba jest spoza zakresu.");
		}

		return tab[i];
	}
	template<typename T2>
	void print(T2 separator)
	{
		//wypisuje cała tablice używając zmiennej T2 separator jako znaku rozdzielającego wartości
		std::cout << "Szablon dla tekstów: [";
		for (int i = 0; i < N; ++i)
		{
			std::cout << "\"" <<tab[i] << '"';
			if (i < N - 1)
			{
				std::cout << separator;
			}
		}
		std::cout << "]";
	}

private:
	const char* tab[N];
};

template<typename T>
class StaticTable<T, 0>
{
public:
	T& operator[](const unsigned int i)
	{
		//TODO: wyj¹tek out_of_range, gdy i >= N; https://en.cppreference.com/w/cpp/error/out_of_range
		throw std::out_of_range("Liczba jest spoza zakresu.");
	}

	template<typename T2>
	void print(T2 separator)
	{
		//wypisuje cała tablice używając zmiennej T2 separator jako znaku rozdzielającego wartości
		std::cout << "Szablon dla N=0: brak elementów" << std::endl;
	}
};
//template<typename T, unsigned int N>
//T& StaticTable::operator[](const unsigned int i)
//{
//	//TODO: wyj¹tek out_of_range, gdy i >= N; https://en.cppreference.com/w/cpp/error/out_of_range
//	return tab[i]; 
//}
