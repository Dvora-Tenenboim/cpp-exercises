#include "clownfish.h"
static const std::string tmpSpeciesArr[]={"Clownfish","Leviathan"};
static const E_continents tmpContinentsArr[]={E_North_America,E_South_America,E_Asia,E_Europe};
static const E_foodTipes tmpFoodTypesArr[]={E_bugs,E_grass};
const std::vector<std::string> Clownfish::m_species(tmpSpeciesArr,tmpSpeciesArr+sizeof(tmpSpeciesArr)/sizeof(tmpSpeciesArr[0]));
const unsigned short Clownfish::m_lifeExpectancy=4;
const std::vector<E_continents> Clownfish::m_continents(tmpContinentsArr,tmpContinentsArr+sizeof(tmpContinentsArr)/sizeof(tmpContinentsArr[0]));
const std::vector<E_foodTipes> Clownfish::m_foodTypes(tmpFoodTypesArr,tmpFoodTypesArr+sizeof(tmpFoodTypesArr)/sizeof(tmpFoodTypesArr[0]));
const int Clownfish::m_lowestDepth=-250;



