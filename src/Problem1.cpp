#include "../include/Problem1.h"
#include <iostream>

Problem1::Problem1() {
}

void Problem1::runProblem1(int limit, bool debugInfo) {
	//Create a sum variable
	int sum = 0;

	//Find multiples of 3 and 5
	if (limit > 2) {
		//Create limits
		int limitThree = (limit - 1) / 3;
		int limitFive  = (limit - 1) / 5;
		if (debugInfo) {
			std::cout << "The number of multiples of 3 is " << limitThree << std::endl;
			std::cout << "The number of multiples of 5 is " << limitFive << std::endl;
		}

		//Create arrays for the numbers
		int* multipleOfThree = new int[limitThree];
		int* multipleOfFive  = new int[limitFive];

		//Populate arrays
		for (int i = 1; i < limitThree + 1; i++) {
			multipleOfThree[i-1] = i * 3;
			//Print debug info if so wanted
			if (debugInfo) {
				std::cout << "Multiple number " << i << " of 3 is: " << i * 3 << std::endl;
			}

		}
		for (int i = 1; i < limitFive + 1; i++) {
			multipleOfFive[i-1] = i * 5;
			if (debugInfo) {
				std::cout << "Multiple number " << i << " of 5 is: " << i * 5 << std::endl;
			}
		}

		//Create sum, taking care not to count the same number twice.
		for (int i = 0; i < limitThree; i++) {
			bool addIt = true;
			int  candidate = multipleOfThree[i];

			//No need to check if number is zero
			if (candidate != 0) {
				for (int j = 0; j < limitFive; j++) {
					//If the same number exists in the multiple of five array, don't add it.
					if (multipleOfFive[j] == candidate) {
						addIt = false;
					}
				}
				if (addIt) {
					sum += candidate;
				}
				else {
					if (debugInfo) {
						std::cout << "Do not add " << candidate << " since it is also a multiple of 5." << std::endl;
					}
				}
			}
		}
		//Now add all the multiples of five.
		for (int i = 0; i < limitFive; i++) {
			sum += multipleOfFive[i];
		}

		//Print result
		std::cout << "The sum is: " << sum << std::endl;


	} else {
		std::cout << "Answer = 0" << std::endl;
	}
	
	
}