#include "Square.hpp"

Square::Square(void) {
	chessman = nullptr;	    //initialize the square to null
}

Square::Square(Chessman *p) {
	chessman = p;
}
