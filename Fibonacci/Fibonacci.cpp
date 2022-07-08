
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

class FibonacciVer2
{
public:
    int generate(int n)
    {
        int a = 0;
        int b = 1;
        int sum = 0;

        for (int i = 1; i <= n-1; ++i)
        {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }
};
int main()
{
    Fibonacci fib;
    std::cout << fib.generate(20)<<std::endl;

    FibonacciVer2 fib2;
    std::cout << fib2.generate(10);
}

