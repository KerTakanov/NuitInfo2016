#include <iostream>
#include "point.hpp"
#include "puyo.h"
using namespace std;


	puyo(){}

	bool puyo::get_grounded(){
		return this.m_grounded;
	}

	int puyo::get_x(){
		return this.m_pos.x;
	}

	int puyo::get_y(){
		return this.m_pos.y;
	}

	puyo::puyo{}

	puyo::type m_t;
	point m_pos;
	bool m_grounded;

