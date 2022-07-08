#include <iostream>

class NWD
{
public:
    static int findNWD(int a, int b)
    {

        do
        {
            if (a < b)
            {
                b -= a;
            }
            else
            {
                a -= b;
            }
        } while (a != b);

        return a;
    }
};
class NWDVer2
{
public:
    static int findNWD(int a, int b)
    {

        do
        {
            int t = b;
            b = a % b;
            a = t;
        } while (b!=0);

        return a;
    }
};

class NWW
{
public:
    int findNWW(int a, int b)
    {
        return (a * b) / NWD::findNWD(a, b);
    }
};
int main()
{
    NWD div1;
    NWD div2;
    NWDVer2 div3;
    NWDVer2 div4;
    NWW multi;
    NWW multi2;
    std::cout << div1.findNWD(28, 24) << std::endl;
    std::cout << div2.findNWD(64, 120) << std::endl;
    std::cout << div3.findNWD(64, 120) << std::endl;
    std::cout << div4.findNWD(28, 24) << std::endl;
    std::cout << multi.findNWW(24, 32) << std::endl;
    std::cout << multi2.findNWW(150, 315) << std::endl;
}
