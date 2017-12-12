#include "User.h"
#include "Taxi.h"
#include <vector>
#include <fstream>
#include "XMLserelisation.h"

int main()
{
	vector<XMLSerelisation*> objects;
	User* user = new User("Ira", "Dmytriv", 19, "User");
	User* user2 = new User("Polina", "Dalevska", 20, "User");
	Taxi* taxi = new Taxi("Taxi", 504, user);
	Taxi* taxi2 = new Taxi("Taxi", 513, nullptr);
	objects.emplace_back(user); //for dunamichni objects
	objects.emplace_back(user2);
	objects.emplace_back(taxi);
	objects.emplace_back(taxi2);
	for (auto it : objects)
	{
		it->Serialization("example.txt");
	}
	ifstream myReadFile("example.txt");
	vector<XMLSerelisation*> objects2;
	if (myReadFile.is_open())
	{
		string output;
		vector<string> arr;
		while (!myReadFile.eof())
		{
			myReadFile >> output;
			if (output.substr(0,2) == "</")
			{
				break;
			}
			arr.push_back(output);
			string fin = "</" + output.substr(1, output.size());
			while (fin != output)
			{
				myReadFile >> output;
				arr.push_back(output);
			}
			if (fin == "</Taxi>")
			{
				Taxi *object = new Taxi();
				objects2.push_back(object);
				objects2[objects2.size() - 1]->Deserialization(arr);
			}
			else
			{
				User *object = new User();
				objects2.push_back(object);
				objects2[objects2.size() - 1]->Deserialization(arr);
			}
			arr.clear();
		}
	}
	for (auto it : objects2)
	{
		it->Serialization("example2.txt");
	}
	system("pause");
	return 0;
}