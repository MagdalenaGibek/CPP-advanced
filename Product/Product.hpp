#pragma once
#include <string>

class Product
{
public:
	Product();
	Product(float price, std::string name);
	friend std::ostream& operator<<(std::ostream& os, const Product& obj);
private:
	float _price;
	std::string _name;
 };

std::ostream& operator<<(std::ostream& os, const Product& obj);
