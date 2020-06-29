#ifndef __CLOWNFISH_H__
#define __CLOWNFISH_H__
#include "fish.h"
class Clownfish:public Fish
{
public:
	Clownfish(const std::string& name);
	void print(std::ostream& os)const;
	const std::vector<std::string>& getSpecies() const;
	unsigned short getLifeExpectancy() const;
	const std::vector<E_continents>& getContinents() const;
	const std::vector<E_foodTipes>&  getFoodTypes() const;
	unsigned int getSpeed() const;
	int getLowestDepth() const;
private:
	static const std::vector<std::string> m_species;
	static const unsigned short m_lifeExpectancy;
	static const std::vector<E_continents> m_continents;
	static const std::vector<E_foodTipes> m_foodTypes;
	static const unsigned int m_speed=40;
	static const int m_lowestDepth;
 
};
inline Clownfish::Clownfish(const std::string& name):Fish(name){}
inline void Clownfish::print(std::ostream& os)const
{
	Animal::print(os);
	Fish::print(os);
}
inline const std::vector<std::string>& Clownfish::getSpecies() const
{
	return m_species;
}
inline unsigned short Clownfish::getLifeExpectancy() const
{
	return m_lifeExpectancy;
}
inline const std::vector<E_continents>& Clownfish::getContinents() const
{
	return m_continents;
}
inline const std::vector<E_foodTipes>& Clownfish::getFoodTypes() const
{
	return m_foodTypes;
}
inline unsigned int Clownfish::getSpeed() const
{
	return m_speed;
}
inline int Clownfish::getLowestDepth() const
{
	return m_lowestDepth;
}

#endif
