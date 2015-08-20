#include "..\include\Problem10.h"

/* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
*
*  Find the sum of all the primes below two million.
*/

void Problem10::runProblem10(int sumPrimesUpToNumber) {
	//Create a list of primes
	int* primeList;
	int numPrimes = 0;

	//Generate primes
	std::cout << "Generate primes up to " << sumPrimesUpToNumber << std::endl;
	numPrimes = primeSieve(sumPrimesUpToNumber, primeList);
	std::cout << "Primes generated" << std::endl;

	long long int sumOfPrimes = 0;
	for (int i = 0; i < numPrimes; i++) {
		sumOfPrimes += primeList[i];
	}

	//Print result
	std::cout << "Sum of generated primes is: " << sumOfPrimes << std::endl;

}

int Problem10::primeSieve(int largestNumber, int *&primeList) {
	//Generate a list of candidates
	std::cout << "Creating a bool array" << std::endl;
	bool* listOfCandidates = new bool[largestNumber];
	for (int i = 0; i < largestNumber; i++) {
		listOfCandidates[i] = true;
	}

	std::cout << "Starting algorithm" << std::endl;
	//Apply the sieving algorithm
	listOfCandidates[0] = false; //Zero is not a prime
	listOfCandidates[1] = false; //One is not a prime
	for (int i = 2; i*i < largestNumber + 1; i++) {
		if (listOfCandidates[i]) {
			for (int j = i*i; j < largestNumber + 1; j = j + i) {
				listOfCandidates[j] = false;
			}
		}
	}

	std::cout << "Counting the primes" << std::endl;
	//Count the number of primes
	int numPrimes = 0;
	for (int i = 0; i < largestNumber; i++) {
		if (listOfCandidates[i]) {
			numPrimes++;
		}
	}

	std::cout << "Creating the prime list" << std::endl;
	//Create list of primes
	primeList = new int[numPrimes];
	int posInList = 0;
	for (int i = 0; i < largestNumber; i++) {
		if (listOfCandidates[i]) {
			primeList[posInList] = i;
			posInList++;
		}
	}

	std::cout << "Cleaning up the temporary array" << std::endl;
	//Cleanup
	if (!listOfCandidates) {
		delete[] listOfCandidates;
		listOfCandidates = 0;
	}

	std::cout << "Returning the number of primes in the list" << std::endl;
	return numPrimes;
}
