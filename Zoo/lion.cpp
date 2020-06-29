#include "lion.h"
static const std::string tmpSpeciesArr[]={"lionA","lionB"};
static const E_continents tmpContinentsArr[]={E_North_America,E_South_America,E_Asia};
static const E_foodTipes tmpFoodTypesArr[]={E_meat,E_grass};
const std::vector<std::string> Lion::m_species(tmpSpeciesArr,tmpSpeciesArr+sizeof(tmpSpeciesArr)/sizeof(tmpSpeciesArr[0]));
const unsigned short Lion::m_lifeExpectancy=70;
const std::vector<E_continents> Lion::m_continents(tmpContinentsArr,tmpContinentsArr+sizeof(tmpContinentsArr)/sizeof(tmpContinentsArr[0]));
const std::vector<E_foodTipes> Lion::m_foodTypes(tmpFoodTypesArr,tmpFoodTypesArr+sizeof(tmpFoodTypesArr)/sizeof(tmpFoodTypesArr[0]));
const unsigned short Lion::m_pregnancyDuration=9;
const unsigned short Lion::m_youngBorn=1;



