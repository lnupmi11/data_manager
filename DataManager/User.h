#pragma once
#include<iostream>
#include <string>
#include "XMLserelisation.h"

using namespace std;

class User : public XMLSerelisation
{
private:
	string name;
	string secondName;
	float age;
	string type;
public:
	User()
	{
		this->name = "";
		this->secondName = "";
		this->age = 0;
		this->type = "";
	}
	User(string name, string secondName, float age, string type)
	{
		this->name = name;
		this->secondName = secondName;
		this->age = age;
		this->type = type;
	}

	User(const User* object)
	{
		this->age = object->age;
		this->name = object->name;
		this->secondName = object->secondName;
		this->type = object->type;
	}

	string getName()
	{
		return name;
	}
	string getSecondName()
	{
		return secondName;
	}
	float getAge()
	{
		return age;
	}
	string getType()
	{
		return type;
	}

	void Serialization(string file_path)
	{
		ofstream out(file_path, ios_base::app);
		out << "<" << this->type << ">" << endl;
		out << "\t" << "<" << "name" << ">" << this->name << "</" << "name" << ">" << endl;
		out << "\t" << "<" << "secondName" << ">" << this->secondName << "</" << "secondName" << ">" << endl;
		out << "\t" << "<" << "age" << ">" << this->age << "</" "age" << ">" << endl;;
		out << "</" << this->type << ">" << endl;
	}

	void Deserialization()
	{

	}
};
