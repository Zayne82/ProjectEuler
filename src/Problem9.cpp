#include "..\include\Problem9.h"

/* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
*	a^2 + b^2 = c^2
*
*  For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
*  i.e a + b + c = 12
*
*  There exists exactly one Pythagorean triplet for which a + b + c = 1000.
*  Find the product a*b*c.
*/

void Problem9::runProblem9(int sumOfNumbers) {
	//Print description
	std::cout << "Find a + b + c = " << sumOfNumbers << " such that a^2 + b^2 = c^2" << std::endl;
	bruteForce(sumOfNumbers);
}

void Problem9::bruteForce(int sumOfNumbers) {
	//Brute force function, trial and error.
	for (int a = 1; a < sumOfNumbers / 3; a++) {
		for (int b = a + 1; b < (sumOfNumbers - a)/2 + 1; b++) {
			int c = sumOfNumbers - a - b;
			if (c > b) {
				if (a*a + b*b == c*c) {
					//Found solution
					std::cout << "Found a solution: a = " << a << ", b = " << b << ", c = " << c << std::endl;
					std::cout << "                  a*b*c = " << a*b*c << std::endl;
				}
			}
		}
	}

}