#include "User.h"
#include "Taxi.h"
#include <vector>
#include <fstream>
#include "XMLserelisation.h"

int main()
{
	vector<XMLSerelisation*> objects;
	User* user = new User("Oleh", "Datskiv", 19, "User");
	User* user2 = new User("Ira", "Dmytriv", 20, "User");
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
	system("pause");
	return 0;
}