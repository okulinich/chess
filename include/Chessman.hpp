#pragma once
#include <string>

class Chessman     //defines a chessman
{
public:
	std::string name;    //chessman name
	int player;     //player identifier that corresponds to this chessman
	Chessman(std::string, int);	//type constructor
};
