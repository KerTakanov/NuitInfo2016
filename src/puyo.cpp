#include <iostream>
#include "point.hpp"
#include "puyo.hpp"


	Puyo::Puyo(){}

	type Puyo::get_t(){
		return _t;
	}

	bool Puyo::get_grounded(){
		return _grounded;
	}

	int Puyo::get_x(){
		return _pos.x;
	}

	int Puyo::get_y(){
		return _pos.y;
	}

	void Puyo::set_x(int x1){
		_pos.x=x1;
	}

	void Puyo::set_y(int y1){
		_pos.y=y1;
	}

	void Puyo::set_grounded(bool g1){
		_grounded=g1;
	}

	void Puyo::set_t(type t1){
		_t=t1;
	}

