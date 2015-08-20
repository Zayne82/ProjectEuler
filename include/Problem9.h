#ifndef PROBLEM9_H
#define PROBLEM9_H

#include <iostream>

/* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
*	a^2 + b^2 = c^2
*
*  For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
*  i.e a + b + c = 12 
*
*  There exists exactly one Pythagorean triplet for which a + b + c = 1000.
*  Find the product a*b*c.
*/

class Problem9 {
public:
	void runProblem9(int sumOfNumbers);
private:
	void bruteForce(int sumOfNumbers);
};

#endif PROBLEM9_H