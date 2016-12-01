#include <iostream>
#include "point.hpp"
#include "puyo.hpp"


	Puyo::Puyo(){}

	bool Puyo::get_grounded(){
		return _grounded;
	}

	int Puyo::get_x(){
		return _pos.x;
	}

	int Puyo::get_y(){
		return _pos.y;
	}


