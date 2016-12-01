#ifndef _PUYO_H_
#define _PUYO_H_

#include <boost/smart_ptr.hpp>

#include "drawable.hpp"

class Puyo;
typedef boost::shared_ptr<Puyo> PuyoPtr;

class Puyo : public Drawable
{

};

#endif