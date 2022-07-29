
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
	std::vector<int>numbers(201);
	std::iota(numbers.begin(), numbers.end(), -100);
	std::cout << "Stworzony wektor." << std::endl;
	std::for_each(numbers.begin(), numbers.end(), [](const int i) {std::cout << i << "; "; });
	std::cout << std::endl << std::endl;

	
	int min = *std::min_element(numbers.begin(), numbers.end());
	std::cout << std::boolalpha;
	std::cout << "Czy wszystkie liczby są dodatnie?" << (min > 0) << std::endl;
	std::cout << std::endl << std::endl;

	auto it = std::find_if(numbers.begin(), numbers.end(), [](const int i)
		{return i % 3 == 0 && i % 5 == 0 && i % 30 == 0; });
	std::cout << "Czy istnieje jakakolwiek liczba podzielna przez 3, 5 i 30?" << (it != numbers.end()) << std::endl;
	std::cout << std::endl << std::endl;

	std::remove(numbers.begin(), numbers.end(), 0);

	auto it2 = std::find(numbers.begin(), numbers.end(), 0);
	std::cout << "Czy kontener zawiera wartość 0." << (it2 != numbers.end()) << std::endl;
	std::cout << std::endl << std::endl;

	bool isFirstElement = true;
	int prevElement = 0;
	bool isSorted = true;
	std::for_each(numbers.begin(), numbers.end(), [&isFirstElement, &prevElement, &isSorted](int i)
		{
			if (isFirstElement)
			{
				isFirstElement = false;
			}
			else
			{
				if (i < prevElement)
				{
					isSorted = false;
				}
			}
			prevElement = i;
		});

	std::cout << "Czy kontener jest posortowany? " << isSorted<< std::endl;
	std::cout << std::endl << std::endl;

	std::vector<int> to_vector;
	std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(to_vector), [](const int i)
		{return i > 90 || i < -90; });
	std::for_each(to_vector.begin(), to_vector.end(), [](const int i) {std::cout << i << "; "; });
	std::cout << std::endl << std::endl;

	std::vector<int> to_vector2;
	auto it3 = std::find(numbers.begin(), numbers.end(), 78);
	std::copy(it3, it3 + 10, std::back_inserter(to_vector2));
	std::for_each(to_vector2.begin(), to_vector2.end(), [](const int i) {std::cout << i << "; "; });
	std::cout << std::endl << std::endl;


}



