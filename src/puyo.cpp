#include <iostream>
#include "point.hpp"
#include "puyo.hpp"


	Puyo::Puyo(){}

	bool Puyo::is_grounded(){
		return _grounded;
	}

	int Puyo::pos_x(){
		return _pos.x;
	}

	int Puyo::pos_y(){
		return _pos.y;
	}


