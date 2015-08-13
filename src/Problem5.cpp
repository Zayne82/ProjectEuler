#include "..\include\Problem5.h"

/* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
*
*  What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?
*/

Problem5::Problem5() {
}
void Problem5::runProblem5(int largestCommonNumber, bool debugInfo){
	//Create and initialize array of numbers
	int* numberArray = new int[largestCommonNumber];
	for (int i = 1; i < largestCommonNumber + 1; i++) {
		numberArray[i-1] = i;
		if (debugInfo) {
			std::cout << "numberArray[" << i - 1 << "] = " << i << std::endl;
		}
	}

	//While the numbers differ from each other
	int largestNumber = 0;
	while (!areNumbersEqual(numberArray, largestCommonNumber, debugInfo)) {
		//Increase all the numbers of the array by a multiple of itself untill no longer smaller than largestNumber
		if (debugInfo) {
			std::cout << "Numbers are not equal" << std::endl;
		}
		for (int i = 1; i < largestCommonNumber + 1; i++) {
			//Get the largest number
			while(largestNumber = getLargestNumber(numberArray, largestCommonNumber, debugInfo) > numberArray[i - 1]) {
				numberArray[i - 1] += i;
			}
			if (debugInfo) {
				std::cout << "numberArray[" << i << "] = " << numberArray[i - 1] << std::endl;
			}
		}
	}

	//Numbers are now equal.
	std::cout << "Numbers are equal, smallest common denominator found" << std::endl;
	for (int i = 1; i < largestCommonNumber + 1; i++) {
		std::cout << "Number[" << i << "] = " << numberArray[i - 1] << " is " << i << "x" << numberArray[i - 1] / i << std::endl;
	}

}

bool Problem5::areNumbersEqual(int* numberList, int listSize, bool debugInfo) {
	//Go through the list and compare the size of the numbers
	for (int i = 1; i < listSize; i++) {
		if (numberList[0] != numberList[i]) {
			if (debugInfo) {
				std::cout << "Number[0] = " << numberList[0] << " and Number[" << i << "] = " << numberList[i] << std::endl;
			}
			return false;
		}
	}
	return true;
}

int Problem5::getLargestNumber(int* numberList, int listSize, bool debugInfo){
	//Go through the list and compare the size of the numbers
	int largestNumber = 0;
	for (int i = 0; i < listSize; i++) {
		if (largestNumber < numberList[i]) {
			largestNumber = numberList[i];
		}
	}
	if (debugInfo) {
		std::cout << "The largest number in the list is " << largestNumber << std::endl;
	}
	return largestNumber;
}

void Problem5::eulerSolutionProblem5(int largestCommonNumber, bool debugInfo) {
	//Generate list of prime number up to largestCommonNumber
	long long int* primeList;
	long long int numPrimes = primeSieve(largestCommonNumber, primeList);

	/*Let us consider the case of finding the least value of N for k = 20. We know that N must be divisible by each of the primes, p[i], less than or equal to k.But what determines the exponent, a[i], in the prime factorisation of N is the greatest perfect power of p[i] that is less than or equal to k.For example, as 2 ^ 4 = 16 and 2 ^ 5 = 32, we know that a[1] = 4 as no other numbers, 2 ? j ? 20, can contain more than four repeated factors of 2. Similarly 3 ^ 2 = 9 and 3 ^ 3 = 27, so a[2] = 2. And for p[i] ? 5, a[i] = 1.
		Hence N = 2 ^ 4 * 3 ^ 2 * 5 * 7 * 11 * 13 * 17 * 19 = 232792560.
		For a given p[i] we can determine a[i] in the following way.
		Let p[i] ^ a[i] = k.By “logging” both sides : a[i] log(p[i]) = log(k).So a[i] = log(k) / log(p[i]).But as a[i] must be integer, a[i] = floor(log(k) / log(p[i])).
		For example, when k = 20, the exponent of the first primes factor, p[1] = 2, will be : a[1] = floor(log(20) / log(2)) = floor(4.32…) = 4
		To optimise the approach even further we note that a[i] = 1 for p[i] ^ 2 > k.In other words, we only need to evaluate a[i] for p[i] ? sqrt(k).
		To put all this together into an algorithm we shall assume that an array of primes p[1], p[2], p[3], … has already been created.*/
}

long long int Problem5::primeSieve(long long int largestNumber, long long int *&primeList) {
	//Generate a list of candidates
	bool* listOfCandidates = new bool[largestNumber];
	for (long long int i = 0; i < largestNumber; i++) {
		listOfCandidates[i] = true;
	}

	//Apply the sieving algorithm
	listOfCandidates[0] = false; //Zero is not a prime
	listOfCandidates[1] = false; //One is not a prime
	for (long long int i = 2; i*i < largestNumber + 1; i++) {
		if (listOfCandidates[i]) {
			for (long long int j = i*i; j < largestNumber + 1; j = j + i) {
				listOfCandidates[j] = false;
			}
		}
	}

	//Count the number of primes
	long long int numPrimes = 0;
	for (long long int i = 0; i < largestNumber; i++) {
		if (listOfCandidates[i]) {
			numPrimes++;
		}
	}

	//Create list of primes
	primeList = new long long int[numPrimes];
	long long int posInList = 0;
	for (long long int i = 0; i < largestNumber; i++) {
		if (listOfCandidates[i]) {
			primeList[posInList] = i;
			posInList++;
		}
	}

	//Cleanup
	delete[] listOfCandidates;

	return numPrimes;
}
