#include <iostream>
#include <memory>
#include "Product.hpp"

int main()
{

	std::unique_ptr<Product> ptr1 = std::make_unique<Product>();
	std::unique_ptr<Product> ptr2 = std::make_unique<Product>(2.99, "mąka: ");
	std::unique_ptr<Product> ptr3 = std::make_unique<Product>(8.59, "masło: ");
	std::unique_ptr<Product> ptr4 = std::make_unique<Product>(10.50, "ser żółty: ");
	std::unique_ptr<Product> ptr5 = std::make_unique<Product>(5.49, "wędlina: ");

	// ta wersja też zadziała, ale wtedy wskaźnik się przenosi i nie możemy się już odwołać przez ptr2, tylko przez tab[0] 
	// std::unique_ptr<Product> tab[4] = { std::move(ptr2), std::move(ptr3), std::move(ptr4), std::move(ptr5) };
	std::unique_ptr<Product> tab[4] = { std::make_unique<Product>(2.99, "mąka: "),
	std::make_unique<Product>(8.59, "masło: "),
	std::make_unique<Product>(10.50, "ser żółty: "),
	std::make_unique<Product>(5.49, "wędlina: ") };

	for (int i = 0; i < 4; ++i)
	{
		std::cout << *tab[i] << std::endl;
	}

	std::cout << std::endl;

	// --- smart

	/*std::shared_ptr<Product> ptr10 = std::make_shared<Product>();

	std::cout << *ptr10 << std::endl;

	std::shared_ptr<Product> tab2[1] = { ptr10 };

	std::cout << *tab2[0] << std::endl;
	std::cout << *ptr10 << std::endl;*/
}