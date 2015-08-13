#include "..\include\Problem6.h"

/* The sum of the squares of the first ten natural numbers is,
*  12 + 22 + ... + 102 = 385
*
*  The square of the sum of the first ten natural numbers is,
*  (1 + 2 + ... + 10)2 = 552 = 3025
*
*  Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 ? 385 = 2640.
*  Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

Problem6::Problem6() {
}

void Problem6::runProblem6(int number, bool debugInfo) {
	//Use formula
	//n^4/4 + n^3/6 - n^2/4 - n/6
	long long int difference = number*number*number*number / 4 + number*number*number / 6 - number*number / 4 - number / 6;
	std::cout << "The difference between the sum of the squares" << std::endl;
	std::cout << "and the square of the sum of the natural numbers up to " << number << std::endl;
	std::cout << "is: " << difference << std::endl;
}