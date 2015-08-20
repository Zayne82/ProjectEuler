#ifndef PROBLEM10_H
#define PROBLEM10_H

#include <iostream>

/* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
*
*  Find the sum of all the primes below two million.
*/

class Problem10 {
public:
	void runProblem10(int sumPrimesUpToNumber);
private:
	int primeSieve(int largestNumber, int *&primeList);
};

#endif PROBLEM10_H