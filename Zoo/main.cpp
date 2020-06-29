/*#include "lion.h"
#include "goose.h"
#include "clownfish.h"
#include "whail.h"
#include "zoo.h"*/
#include <iostream>
int main()
{
	/*Zoo myZoo;
	Lion A("Simba");
	Lion B("Mufasa");
	Goose C("Akka");
	Goose D("Morten");
	Clownfish E("Nemo");
	Whail F("Tigo");
	myZoo.addAnimal(&A);
	myZoo.addAnimal(&B);
	myZoo.addAnimal(&C);
	myZoo.addAnimal(&D);
	myZoo.addAnimal(&E);
	myZoo.addAnimal(&F);
	myZoo.printZoo();*/
	int arr[]={1,2,3,4};
	int* ptr=arr;
	std::cout<<*ptr<<  "        "<<*(++ptr);
	//std::cout<<char(arr_ptr+1)-char(arr_ptr);
	return 0;
}


