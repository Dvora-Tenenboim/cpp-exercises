#ifndef __MAMMALS_H__
#define __MAMMALS_H__
#include "animal.h"
#include "imammals.h"
class Mammals:public Animal,public IMammals
{
public:
	Mammals(std::string name);
	virtual unsigned short getPregnancyDuration() const=0;
	virtual unsigned short getYoungBorn() const=0;
protected:
	/*virtual*/ void print(std::ostream& os)const;
};

inline Mammals::Mammals(std::string name):Animal(name){}
/*virtual*/inline void Mammals::print(std::ostream& os)const
{
	Animal::print(os);
	os<<"pregnancy_duration:  "<<getPregnancyDuration()<<std::endl;
	os<<"young_born:  "<<getYoungBorn()<<std::endl;
}

#endif
