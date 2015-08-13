#include "..\include\Problem3.h"

/* The prime factors of 13195 are 5, 7, 13 and 29.
*
*  What is the largest prime factor of the number 600851475143 ?
*/

Problem3::Problem3() {
}


void Problem3::runProblem3(long long int numberToBeFactored, bool debugInfo){

	std::cout << timeStamp() << "Number to be factored: " << numberToBeFactored << std::endl;
	double rootOfNumber = sqrt(numberToBeFactored);
	if (debugInfo) {
		std::cout << timeStamp() << "Root of that number is: " << rootOfNumber << std::endl;
	}
	
    long long int* primeNumberList;
    long long int listSize          = 0;
    long long int factorNumber		= numberToBeFactored;
	long long int partialNumber		= floor(rootOfNumber+1);
    long long int largestFactor     = 0;
    long long int currentFactor     = 0;
    long long int numFactors        = 0;

	if (debugInfo) {
		std::cout << timeStamp() << "Call to generate list of primes up to the number " << partialNumber << std::endl;
	}
	//listSize = sieveOfEratosthenes(number, primeNumberList);
	listSize = sieveOfEratosthenes(partialNumber, primeNumberList, debugInfo);
	if (debugInfo){
		std::cout << timeStamp() << "Done generating primes. Number of primes is " << listSize << std::endl;
	}

    /*Factor the number into primes*/
    //While number is not a prime
	if (debugInfo) {
		std::cout << timeStamp() << "Starting prime factor generation of number: " << factorNumber << std::endl;
	}
	while(!isPrime(factorNumber, primeNumberList, listSize)){
        //Find the largest prime possible to divide by
        bool abortSearch = false;
        for(long long int i = 0; (i < listSize+1) && !abortSearch; i++){
            //Find largest prime smaller than or equal to number.
            if(factorNumber >= primeNumberList[i]){
                //Check if we can divide
                if(factorNumber % primeNumberList[i] == 0){
                    //Found a factor
                    abortSearch = true;
                    numFactors++;
                    currentFactor = primeNumberList[i];
					factorNumber = factorNumber / currentFactor;
					if (debugInfo) {
						std::cout << timeStamp() << "Factor[" << numFactors << "] = " << currentFactor << std::endl;
					}
                }
            }

        }
        //Check if the new factor is larger than any earlier factor
        if(currentFactor > largestFactor){
            largestFactor = currentFactor;
        }
    }
    //Check to see if the remaining number is larger than any earlier factor
    if(factorNumber > largestFactor){
        largestFactor = factorNumber;
		if (debugInfo){
			std::cout << timeStamp() << "Factor[" << numFactors+1 << "] = " << largestFactor << std::endl;
		}
    }

    //Print the largest factor
    std::cout << timeStamp() << "The largest factor is: " << largestFactor << std::endl;

    //Cleanup
    if(!primeNumberList)
        delete[] primeNumberList;

}

char* Problem3::timeStamp(){
    //Create a timestamp
    time_t rawtime;
    tm* timeinfo;
    static char buffer [80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
	strftime(buffer,80,"[%Y-%m-%d %H:%M:%S] ",timeinfo);

	//buffer = new char[5];
    return buffer;
}

long long int Problem3::sieveOfEratosthenes(long long int largestNumber, long long int *&primeNumberList, bool debugInfo){
	//Divide the larger number up in smaller parts to reduce the needed memory.
	int segmentSize = 1000000;
	long long int numberOfSegments = 1;
	if (largestNumber > segmentSize) {
		numberOfSegments = largestNumber / segmentSize;
		int rest = largestNumber % segmentSize;
		if (largestNumber % segmentSize) {
			numberOfSegments++;
		}
	}
	
	//Create a temporary list to hold the partial list
	long long int* segmentList;
	long long int* fullList;
	long long int* tempList; 
	long long int segmentNum = 0;
	long long int fullNum = 0;
	long long int tempNum = 0;

	//Loop through the segments
	if (debugInfo) {
		std::cout << timeStamp() << "Starting sieve function" << std::endl;
	}
	for (long long int segment = 0; segment < numberOfSegments; segment++) {
		//Create the partial list
		if ((segment + 1)*segmentSize > largestNumber) {
			segmentNum = segmentedSieve(segment*segmentSize, largestNumber, segmentList);
		}
		else {
			segmentNum = segmentedSieve(segment*segmentSize, (segment + 1)*segmentSize, segmentList);
		}

		//Merge the lists
		tempNum = fullNum + segmentNum;
		tempList = new long long int[tempNum];
		for (int i = 0; i < fullNum; i++) {
			tempList[i] = fullList[i];
		}
		for (int i = 0; i < segmentNum; i++) {
			tempList[i + fullNum] = segmentList[i];
		}
		fullList = tempList;
		fullNum  = tempNum;
	
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
			std::cout << timeStamp() << "Segment " << segment << " of " << numberOfSegments << " done." << std::endl;
		}
	}
	
	//Assign the list of prime numbers to the supplied parameter
	primeNumberList = fullList;

	//Clean up
	if (!fullList) {
		delete[] fullList;
		fullList = 0;
	}
	if (!tempList) {
		delete[] tempList;
		tempList = 0;
	}
	if (!segmentList) {
		delete[] segmentList;
		segmentList = 0;
	}

	//Return the number of primes found.
	return fullNum;

    
}

long long int Problem3::segmentedSieve(long long int startNumber, long long int stopNumber, long long int *&primeNumberList, bool debugInfo) {
	//Create array of booleans to tell if number is prime.
	long long int candidateSize = stopNumber - startNumber + 1;
	bool *listOfCandidates = new bool[candidateSize];
	
	//Set all booleans to true
	for (long long int i = 0; i < candidateSize; i++) {
		listOfCandidates[i] = true;
	}
	if (startNumber > 0) {
		for (long long int i = 2; i*i < stopNumber + 1; i++) {
			//Calculate starting point
			long long int startPoint = (startNumber - i*i) / (i+1);
			for (long long int j = i*i + startPoint*i; j < stopNumber + 1; j = j + i) {
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
		for (long long int i = 2; i*i < stopNumber + 1; i++) {
			if (listOfCandidates[i]) {
				for (long long int j = i*i; j < stopNumber + 1; j = j + i) {
					listOfCandidates[j] = false;
				}
			}
		}
	}
	
	//Count the number of primes
	long long int numPrimes = 0;
	for (long long int i = 0; i < candidateSize; i++) {
		if (listOfCandidates[i]) {
			numPrimes++;
		}
	}

	//Create list of primes
	primeNumberList = new long long int[numPrimes];
	long long int posInList = 0;
	for (long long int i = 0; i < candidateSize; i++) {
		if (listOfCandidates[i]) {
			primeNumberList[posInList] = i + startNumber;
			posInList++;
		}
	}
	
	//Cleanup
	delete[] listOfCandidates;

	return numPrimes;
}

bool Problem3::isPrime(long long int number, long long int primeList[], long long int primeListSize){
    //Go through list and check if number is a prime.
    for (long long int i = 0; i <= primeListSize; i++){
        if (number == primeList[i]){
            return true;
        }
    }
    return false;
}
