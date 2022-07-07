
#include <iostream>

class Fibonacci
{
public:
    int generate(int n)
    {
        if (n <= 2)
        {
            return 1;
        }
        else
        {
            return generate(n - 2) + generate(n - 1);
        }
    }

};
int main()
{
    Fibonacci fib;
    std::cout<<
}

