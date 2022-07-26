#include <iostream>
#include <map>
#include <string>

std::map<char, int> NumOfLetters(std::string myString)
{
	std::string myNewString;
	for (unsigned int i = 0; i < myString.size(); ++i)
	{
		myNewString += tolower(myString[i]);
	}

	std::map<char, int> lettersCounter;
	for (unsigned int i = 0; i < myNewString.size(); ++i)
	{
		if (myNewString[i] >= 'a' && myNewString[i] <= 'z')
		{
			auto check = lettersCounter.find(myNewString[i]);
			if (check != lettersCounter.end())
			{
				++lettersCounter[myNewString[i]];
			}
			else
			{
				lettersCounter.insert({ myNewString[i], 1 });
			}
		}
	}

	return lettersCounter;
}

int main()
{
	auto map = NumOfLetters("Ala ma kota");
	std::cout << "Zawartość pierwszego łańcucha: " << std::endl;
	for (auto it = map.begin(); it != map.end(); ++it)
	{
		auto key = it->first;
		auto value = it->second;
		std::cout << key << " - " << value << std::endl;
	}

	std::cout << "Zawartość drugiego łańcucha: " << std::endl;
	auto map2 = NumOfLetters("A kot ma Ale");
	for (auto it = map2.begin(); it != map2.end(); ++it)
	{
		auto key = it->first;
		auto value = it->second;
		std::cout << key << " - " << value << std::endl;
	}

}


