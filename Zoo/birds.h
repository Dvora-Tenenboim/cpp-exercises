#ifndef __BIRDS_H__
#define __BIRDS_H__
#include "animal.h"
#include "ibirds.h"
class Birds: public Animal,public IBirds
{
public:
	Birds(std::string name);
	virtual unsigned int getHeight() const=0;
	virtual unsigned short getWingSpan() const=0;
protected:
	/*virtual*/ void print(std::ostream& os)const;
private:
	unsigned int m_height;
	unsigned short m_wing_span;
};
inline Birds::Birds(std::string name):Animal(name){}
/*virtual*/inline void Birds::print(std::ostream& os)const
{
	Animal::print(os);
	os<<"height:  "<<getHeight()<<std::endl;
	os<<"wing span:  "<<getWingSpan()<<std::endl;
}

#endif
