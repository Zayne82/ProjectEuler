#ifndef PROBLEM5_H
#define PROBLEM5_H

#include <iostream>

/* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
*
*  What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?
*/

class Problem5 
{
public:
	Problem5();
	void runProblem5(int largestCommonNumber, bool debugInfo=false);
	int  getLargestNumber(int* numberList, int listSize, bool debugInfo=false);
	bool areNumbersEqual(int* numberList, int listSize, bool debugInfo=false);

	//Solution from Project Euler
	void eulerSolutionProblem5(int largestCommonNumber, bool debugInfo = false);
	long long int primeSieve(long long int largestNumber,long long int *&primeList);

};

#endif PROBLEM5_H
