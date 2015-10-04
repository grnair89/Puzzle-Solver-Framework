/**
 *
 *  Clock.cpp
 *  
 *  Version: Clock.cpp v 1.0  2014/01/12 10.20 AM
 *  
 *  @author: 
 *         	        an3395(Arjun Nair)
 *		   	sxo4955(Shivankar Ojha)
 *			gr4075(Ganesh Rajasekharan)
 *
 *  Revisions:  
 *         Initial Revision.
 *        
 *  $Log$ 
 */


#include <iostream>
#include <queue>
#include <sstream>
#include "Abstract_class.h"


using namespace std;

class clock:public Abstract_class {
public:

/**
 * This function sets the values
 *
 *  @param   int c 		Current Time
 *  @param   int go 	goal
 */
	void setValues(int c,int go){
		current_time = c;
		goal = go;
	}

/**
 * This function calls the testing function in the Abstract_class
 *
 *  @param   int array[] 	
 *  @param   int array1[]
 *  @param   int a 			The number of hours
 */
	void Solve(int array[],int array1[],int a){
		n=a;
		testing(array,array1);
	}
}myClock;

/**
 * The main function calls the Other Function and takes the input from the user
 */
int main(int argc, char *argv[]) {
	
	int current;
	int g;
	int a;
	std::stringstream str1(argv[1]);
	str1 >> a;
	std::stringstream str2(argv[2]);
	str2 >> current;
	std::stringstream str3(argv[3]);
	str3 >> g;
	int array[a];
	int array1[a];
	myClock.setValues(current,g);
	myClock.Solve(array,array1,a);
	
}