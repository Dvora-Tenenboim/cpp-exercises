#ifndef __LION_H__
#define __LION_H__
#include "mammals.h"
class Lion:public Mammals
{
public:
	Lion(const std::string& name);
	void print(std::ostream& os)const;
	const std::vector<std::string>& getSpecies() const;
	unsigned short getLifeExpectancy() const;
	const std::vector<E_continents>& getContinents() const;
	const std::vector<E_foodTipes>&  getFoodTypes() const;
	unsigned int getSpeed() const;
	unsigned short getPregnancyDuration() const;
	unsigned short getYoungBorn() const;

private:
	static const std::vector<std::string> m_species;
	static const unsigned short m_lifeExpectancy;
	static const std::vector<E_continents> m_continents;
	static const std::vector<E_foodTipes> m_foodTypes;
	static const unsigned int m_speed =60;
	static const unsigned short m_pregnancyDuration;
	static const unsigned short m_youngBorn;
 
};
inline Lion::Lion(const std::string& name):Mammals(name){}
inline void Lion::print(std::ostream& os)const
{
	Animal::print(os);
	Mammals::print(os);
}
inline const std::vector<std::string>& Lion::getSpecies() const
{
	return m_species;
}
inline unsigned short Lion::getLifeExpectancy() const
{
	return m_lifeExpectancy;
}
inline const std::vector<E_continents>& Lion::getContinents() const
{
	return m_continents;
}
inline const std::vector<E_foodTipes>& Lion::getFoodTypes() const
{
	return m_foodTypes;
}
inline unsigned int Lion::getSpeed() const
{
	return m_speed;
}
inline unsigned short Lion::getPregnancyDuration() const
{
	return m_pregnancyDuration;
}
inline unsigned short Lion::getYoungBorn() const
{
	return m_youngBorn;
}

#endif
