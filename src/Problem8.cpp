#include "..\include\Problem8.h"

/* The four adjacent digits in the 1000 - digit number that have the greatest product are 9 � 9 � 8 � 9 = 5832.
*
*  73167176531330624919225119674426574742355349194934
*  96983520312774506326239578318016984801869478851843
*  85861560789112949495459501737958331952853208805511
*  12540698747158523863050715693290963295227443043557
*  66896648950445244523161731856403098711121722383113
*  62229893423380308135336276614282806444486645238749
*  30358907296290491560440772390713810515859307960866
*  70172427121883998797908792274921901699720888093776
*  65727333001053367881220235421809751254540594752243
*  52584907711670556013604839586446706324415722155397
*  53697817977846174064955149290862569321978468622482
*  83972241375657056057490261407972968652414535100474
*  82166370484403199890008895243450658541227588666881
*  16427171479924442928230863465674813919123162824586
*  17866458359124566529476545682848912883142607690042
*  24219022671055626321111109370544217506941658960408
*  07198403850962455444362981230987879927244284909188
*  84580156166097919133875499200524063689912560717606
*  05886116467109405077541002256983155200055935729725
*  71636269561882670428252483600823257530420752963450
*
*  Find the thirteen adjacent digits in the 1000 - digit number that have the greatest product.What is the value of this product ?
*/

void Problem8::runProblem8(int numAdjacentNumbers, bool debugInfo) {
	//Load the 1000 digit number
	int stringLength = 1000;
	std::string numberString =	"73167176531330624919225119674426574742355349194934"
								"96983520312774506326239578318016984801869478851843"
								"85861560789112949495459501737958331952853208805511"
								"12540698747158523863050715693290963295227443043557"
								"66896648950445244523161731856403098711121722383113"
								"62229893423380308135336276614282806444486645238749"
								"30358907296290491560440772390713810515859307960866"
								"70172427121883998797908792274921901699720888093776"
								"65727333001053367881220235421809751254540594752243"
								"52584907711670556013604839586446706324415722155397"
								"53697817977846174064955149290862569321978468622482"
								"83972241375657056057490261407972968652414535100474"
								"82166370484403199890008895243450658541227588666881"
								"16427171479924442928230863465674813919123162824586"
								"17866458359124566529476545682848912883142607690042"
								"24219022671055626321111109370544217506941658960408"
								"07198403850962455444362981230987879927244284909188"
								"84580156166097919133875499200524063689912560717606"
								"05886116467109405077541002256983155200055935729725"
								"71636269561882670428252483600823257530420752963450";
	//Convert string representation to int representation
	int *numberArray = new int[stringLength];
	for (int i = 0; i < stringLength; i++) {
		numberArray[i] = std::stoi(numberString.substr(i, 1));
	}
	
	//Create array of sums
	int numSums = stringLength - numAdjacentNumbers + 1;
	long long int* sumArray = new long long int[numSums];

	//Create the sums
	for (int i = 0; i < numSums; i++) {
		//For each position in the array, add upp the numbers
		long long int tempSum = 1;
		for (int j = 0; j < numAdjacentNumbers; j++) {
			tempSum = tempSum*numberArray[i + j];
		}
		//Store the sum
		sumArray[i] = tempSum;
	}

	//Find the largest sum
	long long int largestSum = 0;
	int posOfLargestSum = 0;
	for (int i = 0; i < numSums; i++) {
		if (largestSum < sumArray[i]) {
			largestSum = sumArray[i];
			posOfLargestSum = i;
		}
	}

	//Print the answer
	std::cout << "The largest sum of " << numAdjacentNumbers << " adjacent numbers is:" << std::endl;
	for (int i = 0; i < numAdjacentNumbers; i++) {
		std::cout << numberArray[posOfLargestSum + i];
		if (i + 1 < numAdjacentNumbers) {
			std::cout << "x";
		}
	}
	std::cout << "=" << largestSum << std::endl;

}