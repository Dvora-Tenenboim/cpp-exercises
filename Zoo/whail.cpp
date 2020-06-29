#include "whail.h"
static const std::string tmpSpeciesArr[]={"whailA","whailB"};
static const E_continents tmpContinentsArr[]={E_North_America,E_South_America,E_Asia};
static const E_foodTipes tmpFoodTypesArr[]={E_fishes,E_grass};
const std::vector<std::string> Whail::m_species(tmpSpeciesArr,tmpSpeciesArr+sizeof(tmpSpeciesArr)/sizeof(tmpSpeciesArr[0]));
const unsigned short Whail::m_lifeExpectancy=30;
const std::vector<E_continents> Whail::m_continents(tmpContinentsArr,tmpContinentsArr+sizeof(tmpContinentsArr)/sizeof(tmpContinentsArr[0]));
const std::vector<E_foodTipes> Whail::m_foodTypes(tmpFoodTypesArr,tmpFoodTypesArr+sizeof(tmpFoodTypesArr)/sizeof(tmpFoodTypesArr[0]));
const unsigned short Whail::m_pregnancyDuration=6;
const unsigned short Whail::m_youngBorn=3;



