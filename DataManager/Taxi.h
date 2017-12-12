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
		this->type = "Taxi";
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

	void Deserialization(vector<string> arr)
	{
		if (arr.size() == 3)
		{
			string str;
			bool flag = false;
			for (int j = 2; j < arr[1].size(); j++)
			{
				if (arr[1][j] == '<')
				{
					break;
				}
				else if (flag)
				{
					str += arr[1][j];
				}
				else if (arr[1][j] == '>')
				{
					flag = true;
				}
			}
			this->number = stoi(str);
		}
		else
		{
			vector<string> _arr;
			for (int i = 1; i < arr.size() - 2; i++)
			{
				_arr.push_back(arr[i]);
			}
			this->user = new User();
			this->user->Deserialization(_arr);
			string str;
			bool flag = false;
			for (int j = 2; j < arr[arr.size() - 2].size(); j++)
			{
				if (arr[arr.size() - 2][j] == '<')
				{
					break;
				}
				else if (flag)
				{
					str += arr[arr.size() - 2][j];
				}
				else if (arr[arr.size() - 2][j] == '>')
				{
					flag = true;
				}
			}
			this->number = stoi(str);
		}
	}

	~Taxi()
	{
		delete user;
	}
};