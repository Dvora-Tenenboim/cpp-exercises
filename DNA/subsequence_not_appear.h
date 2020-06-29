#ifndef __SUBSEQUENCENOAPPEAR_H__
#define __SUBSEQUENCENOAPPEAR_H__
#include <exception>
#include <iostream>
class SubsequenceNotAppear : public std::exception
{
public:
	const char* what() const throw();

	
};

inline const char* SubsequenceNotAppear::what() const throw()
{
    return "SubsequenceNotAppear:   Sub sequence isn't appear in the dna sequence .";
}
#endif


