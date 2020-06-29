#ifndef __DNA_SEQUENCE_H__
#define __DNA_SEQUENCE_H__
#include <iostream>
#include <stdbool.h>
#include <cstring>
#include <string>
#include <stdexcept>    
#include "invalid_nucleotide.h"
#include "open_dna_file_error.h"
#include <fstream>
#include <vector>
class DnaSequence
{
private:
	class Nucleotide
	{
	public:
		Nucleotide();
		Nucleotide(const char nucleotide);
		Nucleotide& operator=(const char nucleotide);
		char getNucleotide()const;
		operator char();
	private:
		char m_nucleotide;
	};	
	Nucleotide*  m_sequence;
	size_t m_length;
	void ctorInit(const char* sequence);
	DnaSequence& assignmentOp(const char* sequence);
	void copy(const Nucleotide* src);
	void copy(const char* src);
public:
	DnaSequence(const std::string& sequence);
	DnaSequence(const char* sequence);
	DnaSequence(const DnaSequence& dnaSec);
	DnaSequence(std::ifstream file);
	~DnaSequence();
	DnaSequence& operator=(const DnaSequence& dnaSec);
	DnaSequence& operator=(const std::string& sequence);
	DnaSequence& operator=(const char* dnaSec);
	const Nucleotide& operator[](const size_t i)const;
	Nucleotide& operator[](const size_t i);
	DnaSequence getSlice(size_t ind1,size_t ind2)const;
	DnaSequence getPaire()const;
	void writeToFile(const char* fileName)const;
	size_t findSubSequence(const DnaSequence& dnaSeq,size_t pos)const;
	std::vector<size_t> findAll(const DnaSequence& dnaSeq)const;
	std::vector<DnaSequence> findConsensusSequences()const;
	size_t getSequenceLength()const;
	const Nucleotide* getSequence()const;
	std::string getAsString()const;
	friend std::ostream& operator<<(std::ostream& os ,const DnaSequence& dnaSec);
	friend std::ostream& operator<<(std::ostream& os ,const Nucleotide& nucleotide);
	
	
};


/*global functions*/
bool isValid(const char nucleotide);
char paire(const char c);
inline bool operator==(const DnaSequence& dnaSec1,const DnaSequence& dnaSec2)
{
	size_t length1=dnaSec1.getSequenceLength();
	if(length1!=dnaSec2.getSequenceLength())
		return false;
	for(size_t i=0;i<length1;i++)
	{
		if((dnaSec1.getSequence()[i]).getNucleotide()!=(dnaSec2.getSequence()[i]).getNucleotide())
			return false;
	}
	return true;
}
inline bool operator!=(const DnaSequence& dnaSec1,const DnaSequence& dnaSec2)
{
	return !(dnaSec1 == dnaSec2);
}
inline std::ostream& operator<<(std::ostream& os ,const DnaSequence::Nucleotide& nucleotide)
{
	os<<nucleotide.getNucleotide();
	return os;
}
inline std::ostream& operator<<(std::ostream& os ,const DnaSequence& dnaSec)
{
	os<<dnaSec.getAsString();
	return os;
}
/*member functions of DnaSequence class*/
inline void DnaSequence::ctorInit(const char* sequence)
{
	m_sequence=new Nucleotide[m_length];
	try
	{
		copy(sequence);
	}
	catch(InvalidNucleotide& e)
	{
		delete[]m_sequence;
		throw;
	}
	
}
inline DnaSequence& DnaSequence::assignmentOp(const char* sequence)
{
	m_length=strlen(sequence);
	Nucleotide* tmp=m_sequence;
	m_sequence=new Nucleotide[m_length];
	try
	{
		copy(sequence);
	}
	catch(InvalidNucleotide& e)
	{
		delete[]m_sequence;
		throw;
	}
	delete[]tmp;
	return *this;
}
inline DnaSequence::DnaSequence(const std::string& sequence):m_sequence(NULL),m_length(sequence.length())
{
	ctorInit(sequence.c_str());
}
inline DnaSequence::DnaSequence(const char* sequence):m_sequence(NULL),m_length(strlen(sequence))
{
	ctorInit(sequence);
}
inline DnaSequence::DnaSequence(const DnaSequence& dnaSec)
{
	m_length=dnaSec.m_length;
	m_sequence=new Nucleotide[m_length];
	copy(dnaSec.m_sequence);
}
inline DnaSequence::DnaSequence(std::ifstream file)
{
	std::string dnaStr;
    if (file.is_open())
	{
		while (file.good())
             getline(file, dnaStr);
        file.close();
	}
	else
		throw OpenDnaFileError();
    *this=DnaSequence(dnaStr);
	
}
inline DnaSequence& DnaSequence::operator=(const DnaSequence& dnaSec)
{
	m_length=dnaSec.m_length;
	Nucleotide* tmp=m_sequence;
	m_sequence=new Nucleotide[m_length];
	delete[]tmp;
	copy(dnaSec.m_sequence);
	return *this;
}
inline DnaSequence& DnaSequence::operator=(const std::string& sequence)
{
	return assignmentOp(sequence.c_str());
}
inline DnaSequence& DnaSequence::operator=(const char* sequence)
{
	return assignmentOp(sequence);
}
inline DnaSequence::~DnaSequence()
{
	delete[]m_sequence;
}
inline const DnaSequence::Nucleotide& DnaSequence::operator[](const size_t i)const
{
	if(i>=m_length)
		throw std::out_of_range("out_of_range:  the length of dna sequence is smaller then given index");
	return m_sequence[i];
	
}
inline DnaSequence::Nucleotide& DnaSequence::operator[](const size_t i)
{
	if(i>=m_length)
		throw std::out_of_range("out_of_range:  the length of dna sequence is smaller then given index");
	return m_sequence[i];
	
}
inline void DnaSequence::writeToFile(const char* fileName)const
{
	std::ofstream myfile(fileName);
  	if (myfile.is_open())
  	{
    	myfile << getAsString() << std::endl;
    	myfile.close();
  	}
  	else
		throw OpenDnaFileError();
   
}
inline size_t DnaSequence::getSequenceLength()const
{
	return m_length;
}

inline void DnaSequence::copy(const char* src)
{
	for(size_t i=0;i<m_length;i++)
	{
		m_sequence[i]=src[i];
	}	
}
inline void DnaSequence::copy(const Nucleotide* src)
{
	for(size_t i=0;i<m_length;i++)
	{
		m_sequence[i]=src[i];
	}	
}

inline const DnaSequence::Nucleotide* DnaSequence::getSequence()const
{
	return m_sequence;
}
inline std::string DnaSequence::getAsString()const
{
	std::string dnaString;
	for(size_t i=0;i<m_length;i++)
	{
		dnaString+=(*this)[i].getNucleotide();
	}
	return dnaString;
}


/*member functions of Nucleotide class*/
inline DnaSequence::Nucleotide::Nucleotide(){}
inline DnaSequence::Nucleotide::Nucleotide(const char nucleotide):m_nucleotide(nucleotide)
{
	if(!isValid(nucleotide))
	{
		throw InvalidNucleotide();
	}
}
inline DnaSequence::Nucleotide& DnaSequence::Nucleotide::operator=(const char nucleotide)
{
	if(!isValid(nucleotide))
	{
		throw InvalidNucleotide();
	}
	m_nucleotide=nucleotide;
	return *this;
}

inline char DnaSequence::Nucleotide::getNucleotide()const
{
	return m_nucleotide;
}
inline DnaSequence::Nucleotide::operator char()
{
	return m_nucleotide;
}
#endif
