#ifndef PROBLEM7_H
#define PROBLEM7_H

#include <iostream>
#include <ctime>
#include <cmath>

/* By listing the first six prime numbers : 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
*  
*  What is the 10 001st prime number ?
*/

class Problem7 {
public:
	Problem7();
	void runProblem7(int numPrime, bool debugInfo = false);
	int segmentedSieve(int startNumber, int stopNumber, int *&primeNumberList, bool debugInfo = false);
	char* timeStamp();

};


#endif PROBLEM7_H
