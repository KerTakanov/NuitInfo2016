#ifndef _PUYO_H_
#define _PUYO_H_

#include <boost/smart_ptr.hpp>

#include "drawable.hpp"

class Puyo;
typedef boost::shared_ptr<Puyo> PuyoPtr;

class Puyo : public Drawable
{
public:
	enum type { red, green, blue, violet, yellow, nil };

	bool is_grounded();

	int pos_x();

	int pos_y();

private:
	puyo::type m_t;
	point m_pos;
	bool m_grounded;
};

#endif