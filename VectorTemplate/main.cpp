#include <iostream>
#include "VectorTemplate.hpp"

int main()
{
	try
	{

		Vector<int> test;
		Vector<int> test2;

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

		for (unsigned int i = 0; i < test.size(); ++i)
		{
			std::cout << "[" << i << "]= " << test[i] << std::endl;
		}

		Vector<char> test3;
		Vector<char> test4;

		std::cout << "cap= " << test3.capacity() << std::endl;
		std::cout << "size= " << test3.size() << std::endl;
		std::cout << "empty= " << test3.empty() << std::endl;

		test3.push_back('a');

		std::cout << "cap= " << test3.capacity() << std::endl;
		std::cout << "size= " << test3.size() << std::endl;
		std::cout << "empty= " << test3.empty() << std::endl;
		test3.push_back('b');
		test3.push_back('c');
		test3.push_back('d');
		test3.push_back('e');

		std::cout << "cap= " << test3.capacity() << std::endl;
		std::cout << "size= " << test3.size() << std::endl;
		std::cout << "empty= " << test3.empty() << std::endl;

		for (unsigned int i = 0; i < test3.size(); ++i)
		{
			std::cout << "[" << i << "]= " << test3[i] << std::endl;
		}

		test4.push_back('f');
		test4.push_back('g');
		test4.push_back('h');

		std::cout << "cap= " << test4.capacity() << std::endl;
		std::cout << "size= " << test4.size() << std::endl;
		std::cout << "empty= " << test4.empty() << std::endl;

		std::cout << std::endl << std::endl;
		for (unsigned int i = 0; i < test4.size(); ++i)
		{
			std::cout << "[" << i << "]= " << test4[i] << std::endl;
		}

		std::cout << "Wstawiam drugi wektor do pierwszego wektora. " << std::endl << std::endl;
		test3.copyTo(test4, 0);

		for (unsigned int i = 0; i < test3.size(); ++i)
		{
			std::cout << "[" << i << "]= " << test3[i] << std::endl;
		}

		std::cout << "Usuwam mijesca od 3 do 5. " << std::endl << std::endl;
		test3.remove(3, 5);

		for (unsigned int i = 0; i < test3.size(); ++i)
		{
			std::cout << "[" << i << "]= " << test3[i] << std::endl;
		}

		std::cout << "Sorowanie bombelkowe." << std::endl << std::endl;
		test3.bubbleSort();

		for (unsigned int i = 0; i < test3.size(); ++i)
		{
			std::cout << "[" << i << "]= " << test3[i] << std::endl;
		}

		std::cout << "Usuwam ostatnie miejesce." << std::endl << std::endl;
		test3.pop_back();

		for (unsigned int i = 0; i < test3.size(); ++i)
		{
			std::cout << "[" << i << "]= " << test3[i] << std::endl;
		}

		int i = test4[1000];
	}
	catch (std::string& error)
	{
		std::cout << error << std::endl;
	}
}