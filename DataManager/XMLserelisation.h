#pragma once
#include <fstream>
#include <string>
#include <vector>

using namespace std;


class XMLSerelisation
{
public:
	
	virtual void Serialization(string file_path) = 0;

	virtual void Deserialization(vector<string> arr) = 0;

};