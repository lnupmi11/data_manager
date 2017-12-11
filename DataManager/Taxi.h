#pragma once
#include "User.h"

class Taxi : public XMLSerelisation
{
private:
	User *user;
	string type;
	int number;
public:
	Taxi()
	{
		this->type = "";
		this->number = 0;
		this->user = nullptr;
	}
	Taxi(string type, int number, User *user)
	{
		if (user != nullptr)
		{
			this->user = new User(user);
		}
		this->type = type;
		this->number = number;
	}
	string getType()
	{
		return type;
	}
	int getNumber()
	{
		return number;
	}

	void Serialization(string file_path)
	{
		ofstream out(file_path, ios_base::app);
		out << "<" << this->type << ">" << endl;
		if (this->user != nullptr)
		{
			user->Serialization(file_path);
		}
		out << "\t" << "<" << "number" << ">" << this->number << "</" << "number" << ">" << endl;
		out << "</" << this->type << ">" << endl;
	}

	void Deserialization()
	{

	}

	~Taxi()
	{
		delete user;
	}
};