#include <iostream>


int main()
{
    auto print = []() {std::cout << "Hello World!" << std::endl; };
    auto addition = [](double a, double b) { return a + b; };

    print();
    std::cout<<addition(5, 7)<<std::endl;

}

