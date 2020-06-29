#include "test_dna.h"

TEST(DnaBasicTests, createDnaByCtor)
{
    DnaSequence d1("AC");
	ASSERT_EQ(d1.getAsString(),"AC");
	std::string s="CTGA";
	DnaSequence d2(s);
	ASSERT_EQ(d2.getAsString(),s);
	ASSERT_THROW(DnaSequence d3("BTTC"), InvalidNucleotide);
}
TEST(DnaBasicTests, createDnaByCopyCtor)
{
    DnaSequence d1("AC");
	DnaSequence d2(d1);
	ASSERT_EQ(d2.getAsString(),d1.getAsString());
}
TEST(DnaBasicTests, dnaAssignment)
{
    DnaSequence d1("AC");
	DnaSequence d2("TTTT");
	d1=d2;
	ASSERT_EQ(d2.getAsString(),d1.getAsString());
	d1="CTT";
	ASSERT_EQ(d1.getAsString(),"CTT");
	ASSERT_THROW(d1="BM", InvalidNucleotide);
}
TEST(DnaUseTests, compaireDna)
{
	DnaSequence d1("AC");
	DnaSequence d2("AC");
	ASSERT_EQ(d1==d2,true);
	ASSERT_EQ(d1!=d2,false);
	d1="TCT";
	ASSERT_EQ(d1==d2,false);
	ASSERT_EQ(d1!=d2,true);
}
TEST(DnaUseTests, accessInPlace)
{
	DnaSequence d1("ACCCT");
	ASSERT_EQ((char)d1[2],'C');
	d1[3]='A';
	ASSERT_EQ((char)d1[3],'A');
	ASSERT_THROW(d1[5],std::out_of_range);
	ASSERT_THROW(d1[2]='k',InvalidNucleotide);
	char c=d1[3];
	ASSERT_EQ(c,'A');
	
}
TEST(DnaUseTests, getSlice)
{
	DnaSequence d1("ACACT");
	ASSERT_EQ(d1.getSlice(1,3).getAsString(),"CAC");
	ASSERT_THROW(d1.getSlice(-1,3),std::out_of_range);
}
TEST(DnaUseTests, getPaire)
{
	DnaSequence d1("ACACT");
	ASSERT_EQ(d1.getPaire().getAsString(),"AGTGT");
}
TEST(DnaUseTests, findSubSequence)
{
	DnaSequence d1("ACTCTC");
	DnaSequence d2("TC");
	ASSERT_EQ(d1.findSubSequence(d2,1),2);
	ASSERT_EQ(d1.findSubSequence(d2,5),std::string::npos);
	ASSERT_THROW(d1.findSubSequence(d2,10),std::out_of_range);
}
TEST(DnaUseTests, findAllSubSequence)
{
	/*DnaSequence d1("ACTCTC");
	DnaSequence d2("TC");
	std::vector<size_t> vec=d1.findAll(d2);
	size_t arr[2]={2,4};
	for (size_t i=0; i<vec.size();i++)
		ASSERT_EQ(vec[i],arr[i]);*/
}
/*if(d8.find(d7,10)==std::string::npos)
			throw SubsequenceNotAppear();
		std::cout<<"has to print '10' :  "<<d8.find(d7,10)<<std::endl;*/

/*void testFunc()
{
	char a[2]="A";
	std::string b="CTGA";
	try
	{
		DnaSequence d1(a);
		std::cout<<"has to print 'A' :  "<<d1<<std::endl;
		DnaSequence d2("AC");
		std::cout<<"has to print 'AC' :  "<<d2<<std::endl;
		DnaSequence d3(d2);
		std::cout<<"has to print 'AC' :  "<<d3<<std::endl;
		//DnaSequence("BC");
		d2=d1;
		std::cout<<"has to print 'A' :  "<<d2<<std::endl;
		std::cout<<"has to print 'AC' :  "<<d3<<std::endl;
		//d2="hello";
		d2="ACCC";
		std::cout<<"has to print 'ACCC' :  "<<d2<<std::endl;
		std::cout<<"has to print 'A' :  "<<d1<<std::endl;
		d2=b;
		std::cout<<"has to print 'CTGA' :  "<<d2<<std::endl;
		DnaSequence d4(b);
		std::cout<<"has to print 'CTGA' :  "<<d4<<std::endl;
		std::cout<<"has to print 'T' :  "<<d4[1]<<std::endl;
		std::cout<<"has to print '4' :  "<<d4.getSequenceLength()<<std::endl;
		bool x=d1==d4;
		std::cout<<"has to print '0' :  "<<x<<std::endl;
		x=d2==d4;
		std::cout<<"has to print '1' :  "<<x<<std::endl;
		std::cout<<"has to print 'C' :  "<<d4[0]<<std::endl;
		d4[0]='T';
		std::cout<<"has to print 'T' :  "<<d4[0]<<std::endl;
		//d4[3]='H';
		char c=d4[0];
		std::cout<<"has to print 'T' :  "<<c<<std::endl;
		DnaSequence d5=d4.getSlice(1,3);
		std::cout<<"has to print 'TGA' :  "<<d5<<std::endl;
		DnaSequence d6=d4.getSlice(0,2);
		std::cout<<"has to print 'TTG' :  "<<d6<<std::endl;
		d6=d4.getPaire();
		std::cout<<"has to print 'TCAA' :  "<<d6<<std::endl;
		DnaSequence d7("TATA");
		DnaSequence d8("TATAGGTACGTATATA");//0,10,12
		if(d8.find(d7,10)==std::string::npos)
			throw SubsequenceNotAppear();
		std::cout<<"has to print '10' :  "<<d8.find(d7,10)<<std::endl;
		std::vector<size_t> vec=d8.findAll(d7);
		std::cout<<"has to print '0','10','12', :  ";
		for (size_t i=0; i<vec.size();i++)
    		std::cout << vec[i]<<"," ;
    	std::cout << std::endl;
    	DnaSequence d10("ATGTAGATGTAA");
    	std::cout<<"has to print 'ATGTAG' :  "<<d10.getSlice(0,5)<<std::endl;
    	std::vector<DnaSequence> vec2;
    	vec2=d10.findConsensusSequences();
    	for (size_t i=0; i<vec2.size();i++)
    		std::cout << vec2[i]<<"," ;
    	std::cout << std::endl;
    	
	}
	catch(SubsequenceNotAppear& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	catch(std::bad_alloc& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	catch(InvalidNucleotide& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	catch (std::out_of_range outofrange)
	{ 
       std::cout << "OUT OF RANGE" << outofrange.what();
    }
}


#include "stack.h"
#include <gtest/gtest.h>

TEST(StackBasicTests, DISABLED_EmptyStack)
{
    Stack<int> s;
    ASSERT_TRUE(s.isEmpty());
}

TEST(StackBasicTests, PushOneToStack)
{
    Stack<int> s;
    EXPECT_TRUE(s.isEmpty());
    s.push(5);
    ASSERT_FALSE(s.isEmpty());
}
TEST(StackBasicTests, PopFromEmptyStack)
{
    Stack<int> s;
    ASSERT_THROW(s.top(), EmptyStackException);
    ASSERT_THROW(s.top(), StackException);
    ASSERT_THROW(s.top(), std::runtime_error);
}
TEST(StackAdvancedTests, PushesAndPops)
{
    Stack<int> s;
    s.push(2);
    s.push(4);
    s.push(6);
    ASSERT_EQ(s.pop(), 6);
    ASSERT_EQ(s.pop(), 4);
    ASSERT_EQ(s.pop(), 2);
    EXPECT_TRUE(s.isEmpty());
    s.push(8);
    ASSERT_EQ(s.pop(), 8);
}
int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/


