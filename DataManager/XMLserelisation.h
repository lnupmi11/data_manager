#pragma once
#include <fstream>
#include <string>

using namespace std;


class XMLSerelisation
{
public:
	
	virtual void Serialization(string file_path) = 0;

	virtual void Deserialization() = 0;

};