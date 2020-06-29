#ifndef __INVALID_NUCLEOTIDE_H__
#define __INVALID_NUCLEOTIDE_H__
#include <exception>
#include <iostream>
class InvalidNucleotide : public std::exception
{
public:
	const char* what() const throw();

	
};

inline const char* InvalidNucleotide::what() const throw()
{
    return "InvalidNucleotide:   Nucleotide must be  one of the following characters:  'A','C','T','G'  .";
}
#endif


