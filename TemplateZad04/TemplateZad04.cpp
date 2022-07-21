#include <iostream>
#include <exception>
#include "StaticTable.hpp"

int main()
{
    try 
    {
        StaticTable<int, 10> table1;
        for (int i = 0; i < 10; ++i)
        {
            table1[i] = i;
        }
        table1.print(", ");
        std::cout << std::endl;

        StaticTable<bool, 2> table2;
        table2[0] = true;
        table2[1] = false;
        table2.print(", ");
        std::cout << std::endl;

        StaticTable<const char*, 2> table3;
        table3[0] = "Pierwszy tekst";
        table3[1] = "Drugi tekst";
        table3.print(", ");
        std::cout << std::endl;

        StaticTable<int*, 2> table4;
        int a = 20;
        int b = 30;
        table4[0] = &a;
        table4[1] = &b;
        table4.print(", ");
        std::cout << std::endl;

        StaticTable<int, 0> table5;
        table5.print(", ");
        std::cout << std::endl;

        table5[1] = 1;
    }
    catch (std::exception err)
    {
        std::cout << "Wyjątek: " << err.what() << std::endl;
    }
}

