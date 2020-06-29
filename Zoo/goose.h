#ifndef __GOOSE_H__
#define __GOOSE_H__
#include "birds.h"
class Goose:public Birds
{
public:
	Goose(const std::string& name);
	void print(std::ostream& os)const;
	const std::vector<std::string>& getSpecies() const;
	unsigned short getLifeExpectancy() const;
	const std::vector<E_continents>& getContinents() const;
	const std::vector<E_foodTipes>&  getFoodTypes() const;
	unsigned int getSpeed() const;
	unsigned int getHeight() const;
	unsigned short getWingSpan() const;
private:
	static const std::vector<std::string> m_species;
	static const unsigned short m_lifeExpectancy;
	static const std::vector<E_continents> m_continents;
	static const std::vector<E_foodTipes> m_foodTypes;
	static const unsigned int m_speed=70;
	static const unsigned int m_height;
	static const unsigned short m_wingSpan;
 
};
inline Goose::Goose(const std::string& name):Birds(name){}
inline void Goose::print(std::ostream& os)const
{
	Animal::print(os);
	Birds::print(os);
}
inline const std::vector<std::string>& Goose::getSpecies() const
{
	return m_species;
}
inline unsigned short Goose::getLifeExpectancy() const
{
	return m_lifeExpectancy;
}
inline const std::vector<E_continents>& Goose::getContinents() const
{
	return m_continents;
}
inline const std::vector<E_foodTipes>& Goose::getFoodTypes() const
{
	return m_foodTypes;
}
inline unsigned int Goose::getSpeed() const
{
	return m_speed;
}
inline unsigned int Goose::getHeight() const
{
	return m_height;
}
inline unsigned short Goose::getWingSpan() const
{
	return m_wingSpan;
}
#endif
