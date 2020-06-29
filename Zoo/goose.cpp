#include "goose.h"
static const std::string tmpSpeciesArr[]={"Pigeon","goose"};
static const E_continents tmpContinentsArr[]={E_North_America,E_South_America,E_Asia,E_Australia};
static const E_foodTipes tmpFoodTypesArr[]={E_fishes,E_grass};
const std::vector<std::string> Goose::m_species(tmpSpeciesArr,tmpSpeciesArr+sizeof(tmpSpeciesArr)/sizeof(tmpSpeciesArr[0]));
const unsigned short Goose::m_lifeExpectancy=2;
const std::vector<E_continents> Goose::m_continents(tmpContinentsArr,tmpContinentsArr+sizeof(tmpContinentsArr)/sizeof(tmpContinentsArr[0]));
const std::vector<E_foodTipes> Goose::m_foodTypes(tmpFoodTypesArr,tmpFoodTypesArr+sizeof(tmpFoodTypesArr)/sizeof(tmpFoodTypesArr[0]));
const unsigned int Goose::m_height=400;
const unsigned short Goose::m_wingSpan=2;

