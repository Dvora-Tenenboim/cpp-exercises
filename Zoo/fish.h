#ifndef __FISH_H__
#define __FISH_H__
#include "animal.h"
#include "ifish.h"
class Fish: public Animal,public IFish
{
public:
	Fish(std::string name);
	virtual int getLowestDepth() const=0;
protected:
	/*virtual*/ void print(std::ostream& os)const;
};

inline Fish::Fish(std::string name):Animal(name){}
/*virtual*/inline void Fish::print(std::ostream& os)const
{
	Animal::print(os);
	os<<"lowest_depth:  "<<getLowestDepth()<<std::endl;
}

#endif
