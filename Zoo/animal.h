#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include <iostream>
#include <vector>

enum E_continents
{
	E_North_America,
	E_South_America,
	E_Asia,
	E_Europe,
	E_Africa,
	E_Australia,
	E_Antarctica

};

enum E_foodTipes
{
	E_meat,
	E_grass,
	E_vegetables,
	E_bugs,
	E_fishes
};
static const std::string continentsArr[7]={"North_America","South_America","Asia","Europe","Africa","Australia","Antarctica"};
static const std::string foodTipesArr[5]={"meat","grass","vegetables","bugs","fishes"};
class Animal
{
public:
	Animal(const std::string& name);
	virtual ~Animal();
	virtual const std::vector<std::string>& getSpecies() const=0;
	virtual unsigned short getLifeExpectancy() const=0;
	virtual const std::vector<E_continents>& getContinents() const=0;
	virtual const std::vector<E_foodTipes>&  getFoodTypes() const=0;
	virtual unsigned int getSpeed() const=0;
	friend std::ostream& operator<<(std::ostream& os,const Animal* animal);

protected:
	virtual void print(std::ostream& os)const;

private:
	std::string m_name;

};

inline Animal::Animal(const std::string& name):m_name(name){}
/*virtual*/inline  Animal::~Animal(){}
inline std::ostream& operator <<(std::ostream& os,const Animal* animal)
{
	animal->print(os);
	return os;
}

/*virtual*/inline void Animal::print(std::ostream& os)const
{
	os<<"name:  "<<m_name<<std::endl;
	os<<"species:  ";
	std::vector<std::string>::const_iterator ispecies=getSpecies().begin();
	for(;ispecies!=getSpecies().end();ispecies++)
	{
		os<<*ispecies<<" ";
	}
    os<<std::endl;
	os<<"lifeExpectancy:  "<<getLifeExpectancy()<<std::endl;
	os<<"Continents:   ";
	std::vector<E_continents>::const_iterator iContinents=getContinents().begin();
	for(;iContinents!=getContinents().end();iContinents++)
	{
		os<<continentsArr[*iContinents]<<" ";
	}
    os<<std::endl;
    os<<"foodTypes:   ";
    std::vector<E_foodTipes>::const_iterator iFoodTypes=getFoodTypes().begin();
	for(;iFoodTypes!=getFoodTypes().end();iFoodTypes++)
	{
		os<<foodTipesArr[*iFoodTypes]<<" ";
	}
	os<<std::endl;
	os<<"speed:  "<<getSpeed()<<std::endl;
	
}
#endif
