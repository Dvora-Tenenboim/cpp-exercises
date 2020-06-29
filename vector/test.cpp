#include "vector.h"
#include <gtest/gtest.h>
#include <vector>
#include <limits>
TEST(VectorBasicTests, createVectorByCtor)
{
	Vector<int> v1;
	EXPECT_TRUE(v1.empty());
	ASSERT_EQ(v1.size(), 0);
	ASSERT_EQ(v1.capacity(), 0);
	Vector<int> m_v2(5);
	std::vector<int> v2(5);
	ASSERT_EQ(m_v2.data()[0], v2.data()[0]);
	ASSERT_EQ(m_v2.data()[0], 0);
	ASSERT_EQ(m_v2.capacity(), 5);
	ASSERT_EQ(m_v2.size(), 5);
	Vector<size_t> m_v3(5,3);
	std::vector<size_t> v3(5,3);
	ASSERT_EQ(m_v3.data()[0], v3.data()[0]);
	ASSERT_EQ(m_v3.data()[0], 3);
	ASSERT_EQ(m_v3.capacity(), 5);
	ASSERT_EQ(m_v3.size(), 5);
	Vector<std::string> m_v4(5,"hello");
	ASSERT_EQ(m_v4.data()[0], "hello");
}
TEST(VectorBasicTests, createVectorByCopyCtor)
{
	Vector<long> m_v1(3,6);
	Vector<long> m_v2(m_v1);
	ASSERT_EQ(m_v1.data()[0],m_v2.data()[0]);
	ASSERT_EQ(m_v1.data()[2],m_v2.data()[2]);
	ASSERT_EQ(m_v2.data()[0], 6);
	ASSERT_EQ(m_v2.capacity(), 3);
	ASSERT_EQ(m_v2.size(), 3);
	Vector<short> m_v3(5,9);
	Vector<short> m_v4=m_v3;
	ASSERT_EQ(m_v3.data()[0],m_v4.data()[0]);
	ASSERT_EQ(m_v3.data()[4],m_v4.data()[4]);
	ASSERT_EQ(m_v4.data()[4], 9);
	ASSERT_EQ(m_v4.capacity(), 5);
	ASSERT_EQ(m_v4.size(), 5);
}
TEST(VectorBasicTests, assignOperator)
{
	Vector<long> m_v1(3,6);
	Vector<long> m_v2(4,5);
	m_v2=m_v1;
	ASSERT_EQ(m_v1.data()[0],m_v2.data()[0]);
	ASSERT_EQ(m_v1.data()[2],m_v2.data()[2]);
	ASSERT_EQ(m_v2.data()[0], 6);
	ASSERT_EQ(m_v2.capacity(), 3);
	ASSERT_EQ(m_v2.size(), 3);
	Vector<long> m_v3(1,2);
	m_v3=m_v1;
	ASSERT_EQ(m_v3.data()[0],m_v2.data()[0]);
	ASSERT_EQ(m_v3.data()[2],m_v2.data()[2]);
	ASSERT_EQ(m_v3.data()[0], 6);
	ASSERT_EQ(m_v3.capacity(), 3);
	ASSERT_EQ(m_v3.size(), 3);
}
TEST(VectorBasicTests, max_size)
{
	Vector<char> m_v1(3,'a');
	ASSERT_EQ(m_v1.max_size(), std::numeric_limits<size_t>::max());
}
TEST(VectorUseTests, reserve)
{
	Vector<int> m_v2(5);
	std::vector<int> v2(7);
	m_v2.reserve(10);
	v2.reserve(10);
	ASSERT_EQ(m_v2.capacity(), v2.capacity());
	m_v2.reserve(4);
	v2.reserve(4);
	ASSERT_EQ(m_v2.capacity(), v2.capacity());
}
TEST(VectorUseTests, acssesByIndex)
{
	Vector<int> m_v1(5,6);
	ASSERT_EQ(m_v1[4],6);
	m_v1[3]=4;
	ASSERT_EQ(m_v1[3],4);
	ASSERT_NO_THROW(m_v1[6]);
	ASSERT_EQ(m_v1.at(3), 4);
	ASSERT_ANY_THROW(m_v1.at(6));
	const Vector<int> m_v2=m_v1;
	ASSERT_EQ(m_v2[4], 6);
}
TEST(VectorUseTests, getVal)
{
	Vector<int> m_v1(5,6);
	m_v1[0]=0;
	m_v1[4]=4;
	ASSERT_EQ(m_v1.back(),4);
	ASSERT_EQ(m_v1.front(),0);
}
TEST(VectorUseTests, assign)
{
	Vector<int> m_v1(5,6);
	m_v1.assign(6,7);
	ASSERT_EQ(m_v1[5], 7); 
	ASSERT_EQ(m_v1.capacity(), 6);
	m_v1.assign(2,4);
	ASSERT_EQ(m_v1[1], 4); 
	ASSERT_EQ(m_v1.capacity(), 6);
	ASSERT_EQ(m_v1.size(), 2);
}
TEST(VectorUseTests, resize)
{
	Vector<int> m_v1(5,6);
	m_v1.resize(10,7);
	ASSERT_EQ(m_v1[5], 7);
	ASSERT_EQ(m_v1[9], 7); 
	ASSERT_EQ(m_v1[4], 6);
	ASSERT_EQ(m_v1.capacity(), 10);
	ASSERT_EQ(m_v1.size(), 10);
}
TEST(VectorUseTests, push_back)
{
	Vector<std::string> m_v1(5,"hi");
	m_v1.push_back("bi");
	ASSERT_EQ(m_v1[5], "bi");
	ASSERT_EQ(m_v1.capacity(), 10);
	ASSERT_EQ(m_v1.size(), 6);
	m_v1.push_back("bi");
	ASSERT_EQ(m_v1[6], "bi");
	ASSERT_EQ(m_v1.capacity(), 10);
	ASSERT_EQ(m_v1.size(), 7);
}
TEST(VectorUseTests, pop_back)
{
	Vector<std::string> m_v1(5,"hi");
	m_v1.pop_back();
	m_v1.pop_back();
	ASSERT_ANY_THROW(m_v1.at(3));
	ASSERT_EQ(m_v1.capacity(), 5);
	ASSERT_EQ(m_v1.size(), 3);
}
TEST(VectorUseTests, insert)
{
	Vector<std::string> m_v1(5,"hi");
	m_v1.insert(3, "bi", 3);
	ASSERT_EQ(m_v1[3],"bi");
	ASSERT_EQ(m_v1[5],"bi");
	ASSERT_EQ(m_v1[7],"hi");
	ASSERT_EQ(m_v1.size(), 8);
}
TEST(VectorUseTests, erase)
{
	Vector<std::string> m_v1(5,"hi");
	m_v1.erase(3);
	ASSERT_EQ(m_v1.size(), 4);
} 
TEST(VectorUseTests, swap)
{
	Vector<std::string> m_v1(5,"hi");
	Vector<std::string> m_v2(7, "bi");
	m_v1.swap(m_v2);
	ASSERT_EQ(m_v1.size(), 7);
	ASSERT_EQ(m_v2.size(), 5);
	ASSERT_EQ(m_v1.capacity(), 7);
	ASSERT_EQ(m_v2.capacity(), 5);
	ASSERT_EQ(m_v2[2], "hi");
	ASSERT_EQ(m_v1[2], "bi");
} 
TEST(VectorUseTests, clear)
{
	Vector<std::string> m_v1(5,"hi");
	m_v1.clear();
	EXPECT_TRUE(m_v1.empty());
}  



