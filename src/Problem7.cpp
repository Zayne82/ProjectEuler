#include "..\include\Problem7.h"

/* By listing the first six prime numbers : 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
*
*  What is the 10 001st prime number ?
*/

Problem7::Problem7() {
}

void Problem7::runProblem7(int numPrime, bool debugInfo) {
	//Create lists to hold the prime numbers
	int* segmentList;
	int  segmentNum = 0;
	int* primeNumberList;
	int  numberOfPrimes = 0;
	int* tempList;
	int  tempNum = 0;

	//Define the size of the segments
	int segmentSize = 10000;
	int segment		= 0;

	//Create more primes until we have reached the requred number
	while (numberOfPrimes < numPrime) {
		//Run a segment
		segmentNum = segmentedSieve(segment*segmentSize, (segment + 1)*segmentSize, segmentList);

		//Merge the lists
		tempNum = numberOfPrimes + segmentNum;
		tempList = new int[tempNum];
		for (int i = 0; i < numberOfPrimes; i++) {
			tempList[i] = primeNumberList[i];
		}
		for (int i = 0; i < segmentNum; i++) {
			tempList[i + numberOfPrimes] = segmentList[i];
		}
		primeNumberList = tempList;
		numberOfPrimes  = tempNum;

		//Delete the temporary lists
		if (!segmentList) {
			delete[] segmentList;
			segmentList = 0;
		}
		if (!tempList) {
			delete[] tempList;
			tempList = 0;
		}

		//Print indicator
		if (debugInfo) {
			std::cout << timeStamp() << "Number of generated primes is now " << numberOfPrimes << std::endl;
		}

		segment++;
	}

	//Print the desired prime number
	std::cout << timeStamp() << "Prime number " << numPrime << " is " << primeNumberList[numPrime - 1] << std::endl;
 	
}
//
//long long int Problem7::sieveOfEratosthenes(long long int largestNumber, long long int *&primeNumberList, bool debugInfo) {
//	//Divide the larger number up in smaller parts to reduce the needed memory.
//	int segmentSize = 1000000;
//	long long int numberOfSegments = 1;
//	if (largestNumber > segmentSize) {
//		numberOfSegments = largestNumber / segmentSize;
//		int rest = largestNumber % segmentSize;
//		if (largestNumber % segmentSize) {
//			numberOfSegments++;
//		}
//	}
//
//	//Create a temporary list to hold the partial list
//	long long int* segmentList;
//	long long int* fullList;
//	long long int* tempList;
//	int segmentNum = 0;
//	int fullNum = 0;
//	int tempNum = 0;
//
//	//Loop through the segments
//	if (debugInfo) {
//		std::cout << timeStamp() << "Starting sieve function" << std::endl;
//	}
//	for (long long int segment = 0; segment < numberOfSegments; segment++) {
//		//Create the partial list
//		if ((segment + 1)*segmentSize > largestNumber) {
//			segmentNum = segmentedSieve(segment*segmentSize, largestNumber, segmentList);
//		}
//		else {
//			segmentNum = segmentedSieve(segment*segmentSize, (segment + 1)*segmentSize, segmentList);
//		}
//
//		//Merge the lists
//		tempNum = fullNum + segmentNum;
//		tempList = new long long int[tempNum];
//		for (int i = 0; i < fullNum; i++) {
//			tempList[i] = fullList[i];
//		}
//		for (int i = 0; i < segmentNum; i++) {
//			tempList[i + fullNum] = segmentList[i];
//		}
//		fullList = tempList;
//		fullNum = tempNum;
//
//		//Delete the temporary lists
//		if (!segmentList) {
//			delete[] segmentList;
//			segmentList = 0;
//		}
//		if (!tempList) {
//			delete[] tempList;
//			tempList = 0;
//		}
//
//		//Print indicator
//		if (debugInfo) {
//			std::cout << timeStamp() << "Segment " << segment + 1 << " of " << numberOfSegments << " done." << std::endl;
//		}
//	}
//
//	//Assign the list of prime numbers to the supplied parameter
//	primeNumberList = fullList;
//
//	//Clean up
//	if (!fullList) {
//		delete[] fullList;
//		fullList = 0;
//	}
//	if (!tempList) {
//		delete[] tempList;
//		tempList = 0;
//	}
//	if (!segmentList) {
//		delete[] segmentList;
//		segmentList = 0;
//	}
//
//	//Return the number of primes found.
//	return fullNum;
//
//
//}

int Problem7::segmentedSieve(int startNumber, int stopNumber, int *&primeNumberList, bool debugInfo) {
	//Create array of booleans to tell if number is prime.
	int candidateSize = stopNumber - startNumber + 1; //Segment size determines the maximum difference of these numbers.
	bool *listOfCandidates = new bool[candidateSize];

	//Set all booleans to true
	for (int i = 0; i < candidateSize; i++) {
		listOfCandidates[i] = true;
	}
	if (startNumber > 0) {
		for (int i = 2; i*i < stopNumber + 1; i++) {
			//Calculate starting point
			int startPoint = (startNumber - i*i) / (i + 1);
			for (int j = i*i + startPoint*i; j < stopNumber + 1; j = j + i) {
				if (j >= startNumber) {
					listOfCandidates[j - startNumber] = false;
				}
			}
		}
	}
	else {
		//Apply the sieving algorithm
		listOfCandidates[0] = false; //Zero is not a prime
		listOfCandidates[1] = false; //One is not a prime
		for (int i = 2; i*i < stopNumber + 1; i++) {
			if (listOfCandidates[i]) {
				for (int j = i*i; j < stopNumber + 1; j = j + i) {
					listOfCandidates[j] = false;
				}
			}
		}
	}

	//Count the number of primes
	int numPrimes = 0;
	for (int i = 0; i < candidateSize; i++) {
		if (listOfCandidates[i]) {
			numPrimes++;
		}
	}

	//Create list of primes
	primeNumberList = new int[numPrimes];
	int posInList = 0;
	for (int i = 0; i < candidateSize; i++) {
		if (listOfCandidates[i]) {
			primeNumberList[posInList] = i + startNumber;
			posInList++;
		}
	}

	//Cleanup
	delete[] listOfCandidates;

	return numPrimes;
}

char* Problem7::timeStamp() {
	//Create a time stamp
	time_t rawtime;
	tm timeinfo;
	static char buffer[80];
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	strftime(buffer, 80, "[%Y-%m-%d %H:%M:%S] ", &timeinfo);

	//Returns the formated time stamp string.
	return buffer;
}
