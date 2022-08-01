//Klasa File
//* RAII
//* c - tor przyjmujacy nazwę pliku, rzuca wyjątek gdy nie uda się otwrzyc pliku
//* d - tor zamyka plik
//* Mile widziane funkjce szablonowe zapisujące / wczytjące dowonly typ danych(wspierający operator << >>)
//* Zakładamy, ze 1 linia pliku 1 wartość(dane nie mogą zwierać białych znaków)
//* Zakładamy, że użytkownik zna format pliku i będzie wczytywał różne typy według znanej sobie kolejności
//np :
//string
//int
//double
//int
//* Dodaj klase Pracownik(imie, nazwisko, losowy numer pracownika, wysokość pensji)
//* Numer pracownika ma się generować losowo podczas tworznia nowego pracownika, dla ułatwienia mogą się powtarzać
//* warto dodać operator << i >>
//*Użyj klasy File do zapisania danych 10 pracowników
//* Wczytaj ze pomocą tej klasy te dane do wektora a następnie wypisz pracowników posortowanych według wysokości pensji

#include <iostream>
#include "File.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


int main()
{
	std::vector<Employee> staff
	{
		Employee("Zenon", "Martyniuk", 10000.21),
		Employee("Dorota", "Rabczewska", 20898.21),
		Employee("Jan", "Kowalski", 5065.32),
		Employee("Jakub", "Nowak", 5479.21),
		Employee("Katarzyna", "Zalewska", 8032.23),
		Employee("Anna", "Hłasko", 3254.43),
		Employee("Grażyna", "Sołowow", 4242.54),
		Employee("Janusz", "Lipińki", 3743.32),
		Employee("Sebastian", "Foch", 5444.21),
		Employee("Angelika", "Gawin", 4239.32),
	};


	{
		std::string test("D:\\Documents\\Szkolenie\\test.txt");
		File file(test, std::ios::out | std::ios::trunc);
		std::for_each(staff.begin(), staff.end(), [&file](Employee i) {file << i << "\n";});
	}

	{
		std::string test("D:\\Documents\\Szkolenie\\test.txt");
		File file(test, std::ios::in);
		std::vector<Employee>sortedStaff;
		for (size_t i = 0; i < 10; ++i)
		{
			Employee tmp("", "", 0.0);
			file >> tmp;
			sortedStaff.push_back(tmp);
		}
		std::sort(sortedStaff.begin(), sortedStaff.end(), [](Employee& a, Employee& b) {
			return a.getSalary() > b.getSalary(); });

		std::for_each(sortedStaff.begin(), sortedStaff.end(), [](Employee i) {std::cout << i << "\n"; });
	}
	


}

