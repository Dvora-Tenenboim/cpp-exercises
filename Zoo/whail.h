#ifndef __WHAIL_H__
#define __WHAIL_H__
#include "mammals.h"
#include "fish.h"
class Whail:public IMammals,public Fish
{
public:
	Whail(const std::string& name);
	void print(std::ostream& os)const;
	const std::vector<std::string>& getSpecies() const;
	unsigned short getLifeExpectancy() const;
	const std::vector<E_continents>& getContinents() const;
	const std::vector<E_foodTipes>&  getFoodTypes() const;
	unsigned int getSpeed() const;
	unsigned short getPregnancyDuration() const;
	unsigned short getYoungBorn() const;
	int getLowestDepth() const;

private:
	static const std::vector<std::string> m_species;
	static const unsigned short m_lifeExpectancy;
	static const std::vector<E_continents> m_continents;
	static const std::vector<E_foodTipes> m_foodTypes;
	static const unsigned int m_speed =60;
	static const unsigned short m_pregnancyDuration;
	static const unsigned short m_youngBorn;
	static const int m_lowestDepth=-600;
 
};
inline Whail::Whail(const std::string& name):Fish(name){}
inline void Whail::print(std::ostream& os)const
{
	Fish::print(os);
	os<<"pregnancy_duration:  "<<getPregnancyDuration()<<std::endl;
	os<<"young_born:  "<<getYoungBorn()<<std::endl;
	
	
}
inline const std::vector<std::string>& Whail::getSpecies() const
{
	return m_species;
}
inline unsigned short Whail::getLifeExpectancy() const
{
	return m_lifeExpectancy;
}
inline const std::vector<E_continents>& Whail::getContinents() const
{
	return m_continents;
}
inline const std::vector<E_foodTipes>& Whail::getFoodTypes() const
{
	return m_foodTypes;
}
inline unsigned int Whail::getSpeed() const
{
	return m_speed;
}
inline unsigned short Whail::getPregnancyDuration() const
{
	return m_pregnancyDuration;
}
inline unsigned short Whail::getYoungBorn() const
{
	return m_youngBorn;
}
inline int Whail::getLowestDepth() const
{
	return m_lowestDepth;
}
#endif
