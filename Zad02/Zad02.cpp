// Zad02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

void printElement(int n)
{
    std::cout<< n<<"; ";
}

struct LessThan
{
    void operator()(int n) const
    {
        if (n < 50)
        {
            std::cout << n << "; ";
        }
    }
};

bool largerThan4 (int n)
{
    return n > 4;
}

int main()
{
    std::vector<int>numbers(100);
    for (size_t i = 0; i < 100; ++i)
    {
        numbers[i] = i + 1;
    }


    std::for_each(numbers.begin(), numbers.end(),
        printElement);

    std::cout << std::endl << std::endl;

    LessThan lessThan;
    std::for_each(numbers.begin(), numbers.end(),
        lessThan);

    std::cout << std::endl << std::endl;

    std::cout << "Ilość większych niż 4: " << std::count_if(numbers.begin(), numbers.end(),
        largerThan4);

    std::cout << std::endl << std::endl;

    std::for_each(numbers.begin(), numbers.end(),
        [](int n) {std::cout << n << "; "; });

    std::cout << std::endl << std::endl;

    std::for_each(numbers.begin(), numbers.end(),
        [](int n) {if (n < 50)
    {
        std::cout << n << "; ";
    }});

    std::cout << std::endl << std::endl;

    std::cout << "Ilość większych niż 4: " << std::count_if(numbers.begin(), numbers.end(),
        [](int n) {return n > 4; });

    std::cout << std::endl << std::endl;

    int dzielnik = 3;

    std::for_each(numbers.begin(), numbers.end(),
        [&dzielnik](int n) {if (n % dzielnik ==0)
    {
        std::cout << n << "; ";
    }});

    std::cout << std::endl << std::endl;

    int sum = 0;

    std::for_each(numbers.begin(), numbers.end(),
        [&sum](int n) {if (n % 2 == 0)
    {
        sum += n;
    }});

    std::cout << "Suma wszytkich liczb parzystych: " << sum << std::endl;
    std::cout << std::endl << std::endl;

   

}

