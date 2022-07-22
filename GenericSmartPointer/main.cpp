#include "GenericSmartPointer.h"
#include <iostream>

class MyInt 
{
public:
	MyInt(int value)
		: myInt(value)
	{
	}
	~MyInt()
	{
		std::cout << "Object " << myInt <<" is destructed."<< std::endl;
	}
	friend std::ostream& operator<<(std::ostream& os, const MyInt& obj);
private:
	int myInt = 0;
};
std::ostream& operator<<(std::ostream& os, const MyInt& obj)
{
	os << obj.myInt;
	return os;
}

int main()
{
	SharedSmartPointer<MyInt > ptr1(new MyInt(1));
	SharedSmartPointer<MyInt > ptr2(new MyInt(2));

	std::cout << "Wartość pod wskaźnikiem ptr1 wynosi: " << *ptr1 << std::endl;
	std::cout << "Wartość pod wskaźnikiem ptr2 wynosi: " << *ptr2 << std::endl;

	ptr1 = ptr2;

	std::cout << "Wartość pod wskaźnikiem ptr1 wynosi: " << *ptr1 << std::endl;
	std::cout << "Wartość pod wskaźnikiem ptr2 wynosi: " << *ptr2 << std::endl;

	return 0;
}