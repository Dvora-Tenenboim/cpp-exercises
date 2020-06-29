#include "test_dna.h"
int main(int argc, char* argv[])
{
	DnaSequence d1("ACTCTC");
	DnaSequence d2("TC");
	std::vector<size_t> vec=d1.findAll(d2);
	size_t arr[2]={2,4};
	/*size_t arr[2]={2,4};
	for (size_t i=0; i<vec.size();i++)
		ASSERT_EQ(vec[i],arr[i]);*/
	std::cout<<vec.size();
	bool x;
	for (size_t i=0; i<vec.size();i++)
	{
			x=arr[i]==vec[i];
    		std::cout << vec[i]<<"," ;
			std::cout<<x;
	}
	
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
