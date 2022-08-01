#include "File.hpp"
#include<iostream>
#include<fstream>
#include<random>

File::File(const std::string& fileName, std::ios_base::openmode accessMode)
    :_file(fileName, accessMode)

{
    if (!_file.is_open())
    {
        throw std::string("Nie mogę otworzyć pliku");
    }
}

File::~File()
{
    _file.close();
}

std::fstream& File::getFile()
{
    return _file;
}

Employee::Employee(std::string name, std::string lastName, double salary)
    : _name(name),
    _lastName(lastName),
    _salary(salary)
{
    _employeeNumber = generateEmployeeNumber();

}

int Employee::generateEmployeeNumber()
{
    std::random_device r;
    std::default_random_engine defEngine(r());
    std::uniform_int_distribution<int> intDistro(0, 100);

    return _employeeNumber = intDistro(defEngine);
}

double Employee::getSalary()
{
    return _salary;
}

File& operator<<(File& file, Employee& employee)
{
    file.getFile() << employee._name << "\n" << employee._lastName << "\n" << employee._employeeNumber << "\n" << employee._salary << "\n";
    return  file;
}
File& operator>>(File& file, Employee& employee)
{
    file.getFile() >> employee._name >> employee._lastName >> employee._employeeNumber >> employee._salary;
    return  file;
}

std::ostream& operator<<(std::ostream& os, const Employee& obj)
{
    os << obj._name <<"\n"<< obj._lastName <<"\n"<< obj._employeeNumber << "\n"<< obj._salary << "\n"<< "\n";
    return os;
}
