#pragma once
#include<string>
#include<fstream>

class File
{
public:
	File(const std::string& fileName, std::ios_base::openmode accessMode);
	~File();
	std::fstream& getFile();

	template<typename T>
	friend File& operator<<(File& file, T& value);
	template<typename T>
	friend File& operator>>(File& file, T& value);


private:
	std::fstream _file;

};


class Employee
{
public:
	Employee(std::string name, std::string lastName, double salary);
	int generateEmployeeNumber();
	double getSalary();
	friend File& operator<<(File& file, Employee& employee);
	friend File& operator>>(File& file, Employee& employee);
	friend std::ostream& operator<<(std::ostream& os, const Employee& obj);
private:
	std::string _name;
	std::string _lastName;
	double _salary = 0;
	int _employeeNumber = 0;
	
};


File& operator<<(File& file, Employee& employee);
File& operator>>(File& file, Employee& employee);
std::ostream& operator<<(std::ostream& os, const Employee& obj);

template<typename T>
File& operator<<(File& file, T& value)
{
	file._file << value;
	return  file;
}

template<typename T>
File& operator>>(File& file, T& value)
{
	file._file >> value;
	return  file;
}
