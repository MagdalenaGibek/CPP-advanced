#include "Product.hpp"
#include <iostream>

Product::Product()
{
	_price = 0;
	_name = {};
}

Product::Product(float price, std::string name)
	: _price(price)
	, _name(name)
{
}

std::ostream& operator<<(std::ostream& os, const Product& obj)
{
	os << obj._name << obj._price;
	return os;
}
