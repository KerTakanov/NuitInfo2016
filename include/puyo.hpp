#ifndef _PUYO_H_
#define _PUYO_H_

#include <boost/smart_ptr.hpp>

#include "point.hpp"
#include "drawable.hpp"

class Puyo;
typedef boost::shared_ptr<Puyo> PuyoPtr;

class Puyo : public Drawable
{
public:
	Puyo();

	typedef enum { red, green, blue, violet, yellow, nil } type;

	bool get_grounded();

	int get_x();

	int get_y();

private:
	type _t;
	Point _pos;
	bool _grounded;
};

#endif