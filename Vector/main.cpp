#include <iostream>
#include "Vector.hpp"


int main()
{
	try
	{

		Vector test;
		Vector test2;



		std::cout << "cap= " << test.capacity() << std::endl;
		std::cout << "size= " << test.size() << std::endl;
		std::cout << "empty= " << test.empty() << std::endl;

		test.push_back(1);

		std::cout << "cap= " << test.capacity() << std::endl;
		std::cout << "size= " << test.size() << std::endl;
		std::cout << "empty= " << test.empty() << std::endl;
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);

		std::cout << "cap= " << test.capacity() << std::endl;
		std::cout << "size= " << test.size() << std::endl;
		std::cout << "empty= " << test.empty() << std::endl;

		for (unsigned int i = 0; i < test.size(); ++i)
		{
			std::cout << "[" << i << "]= " << test[i] << std::endl;
		}

		test2.push_back(6);
		test2.push_back(7);
		test2.push_back(8);

		std::cout << "cap= " << test2.capacity() << std::endl;
		std::cout << "size= " << test2.size() << std::endl;
		std::cout << "empty= " << test2.empty() << std::endl;

		std::cout << std::endl << std::endl;
		for (unsigned int i = 0; i < test2.size(); ++i)
		{
			std::cout << "[" << i << "]= " << test2[i] << std::endl;
		}

		std::cout << "Wstawiam drugi wektor do pierwszego wektora. " << std::endl << std::endl;
		test.copyTo(test2, 0);

		for (unsigned int i = 0; i < test.size(); ++i)
		{
			std::cout << "[" << i << "]= " << test[i] << std::endl;
		}

		//std::cout << "Wstawiam" << std::endl << std::endl;
		//test.insert(66, 3);

		std::cout << "Usuwam mijesca od 3 do 5. " << std::endl << std::endl;
		test.remove(3, 5);

		for (unsigned int i = 0; i < test.size(); ++i)
		{
			std::cout << "[" << i << "]= " << test[i] << std::endl;
		}

		std::cout << "Sorowanie bombelkowe." << std::endl << std::endl;
		test.bubbleSort();

		for (unsigned int i = 0; i < test.size(); ++i)
		{
			std::cout << "[" << i << "]= " << test[i] << std::endl;
		}

		std::cout << "Usuwam ostatnie mijesce." << std::endl << std::endl;
		test.pop_back();

		//std::cout << "Usuwam" << std::endl << std::endl;
		//test.remove(3);

		for (unsigned int i = 0; i < test.size(); ++i)
		{
			std::cout << "[" << i << "]= " << test[i] << std::endl;
		}

		//std::cout << "Magia: " << test.operator[](2) << " to jest to samo co: " << test[2];
		int i = test2[1000]; // test wyjątku
	}
	catch (std::string& error)
	{
		std::cout << error << std::endl;
	}
}