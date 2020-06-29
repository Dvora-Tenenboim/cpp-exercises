#ifndef __OPEN_DNA_FILE_ERROR_H__
#define __OPEN_DNA_FILE_ERROR_H__
#include <exception>
#include <iostream>
class OpenDnaFileError : public std::exception
{
public:
	const char* what() const throw();

	
};

inline const char* OpenDnaFileError::what() const throw()
{
    return "OpenDnaFileError:   can't open dna file  .";
}
#endif


