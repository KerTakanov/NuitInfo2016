#include <iostream>
#include "point.hpp"
#include "puyo.hpp"


	Puyo::Puyo(){}

	bool puyo::get_grounded(){
		return _grounded;
	}

	int puyo::get_x(){
		return _pos.x;
	}

	int puyo::get_y(){
		return _pos.y;
	}


