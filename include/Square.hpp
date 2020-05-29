#pragma once
#include "Chessman.hpp"

class Square {
public:
	Chessman *chessman;	//pointer to chessman on the square. void if no chessman is present.
    Square();
	Square(Chessman *);
};
