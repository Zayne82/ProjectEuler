#ifndef PROBLEM3_H
#define PROBLEM3_H

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>

/* The prime factors of 13195 are 5, 7, 13 and 29.
*
*  What is the largest prime factor of the number 600851475143 ?
*/

class Problem3
{
public:
	Problem3();
	void runProblem3(long long int numberToBeFactored, bool debugInfo = false);
	bool isPrime(long long int number, long long int primeList[], long long int primeListSize);
	long long int sieveOfEratosthenes(long long int largestNumber, long long int *&primeNumberList, bool debugInfo = false);
	int segmentedSieve(long long int startNumber, long long int stopNumber, long long int *&primeNumberList, bool debugInfo = false);
	char* timeStamp();


};

#endif // PROBLEM3_H
