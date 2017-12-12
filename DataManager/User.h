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
		this->type = "User";
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

	void Deserialization(vector<string> arr)
	{
		for (int i = 1; i < arr.size() - 1; i++)
		{
			string str;
			bool flag = false;
			for (int j = 2; j < arr[i].size(); j++)
			{
				if (arr[i][j] == '<')
				{
					break;
				}
				else if (flag)
				{
					str += arr[i][j];
				}
				else if (arr[i][j] == '>')
				{
					flag = true;
				}
			}
			switch (i)
			{
				case 1: this->name = str; break;
				case 2: this->secondName = str; break;
				case 3: this->age = stoi(str); break;
				default:
					break;
			}
		}
	}
};
