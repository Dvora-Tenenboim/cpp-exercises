#ifndef __ZOO_H__
#define __ZOO_H__
#include "animal.h"
class Zoo
{
public:
	void addAnimal(Animal*);
	void printZoo();

private:
	std::vector<Animal*> m_animales;
};
inline void Zoo::printZoo()
{
	std::vector<Animal*>::const_iterator ianimales=m_animales.begin();
	for(;ianimales!=m_animales.end();ianimales++)
	{
		std::cout<<*ianimales<<std::endl;
	}
}
inline void Zoo::addAnimal(Animal* animal)
{
	m_animales.push_back(animal);
}
#endif
