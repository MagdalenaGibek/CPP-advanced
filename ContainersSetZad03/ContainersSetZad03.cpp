#include <iostream>
#include <string>
#include <set>

bool ifAlphabet(std::string myString)
{
    std::string myNewString;
    for (unsigned int i = 0; i < myString.size(); ++i)
    {
        myNewString += tolower(myString[i]);
    }

    std::set<char> alphabet{};
    for (unsigned int i = 0; i < myNewString.size(); ++i)
    {
        if (myNewString[i] >= 'a' && myNewString[i] <= 'z')
        {
            alphabet.insert(myNewString[i]);
        }
    }

    return alphabet.size() == 26;
}
int main()
{
    std::cout<<std::boolalpha;
    std::cout <<"Czy podanym łańcuchu występują wszystykie litery alfabetu: "<< ifAlphabet("ABCDefGhiJKLMNOpQrstuVwXyz")<<std::endl;
    std::cout << "Czy podanym łańcuchu występują wszystykie litery alfabetu: " << ifAlphabet("aabbccdd") << std::endl;
    std::cout << "Czy podanym łańcuchu występują wszystykie litery alfabetu: " << ifAlphabet("Ala ma kota.") << std::endl;
}

