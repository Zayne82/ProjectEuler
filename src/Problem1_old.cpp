
#include <iostream>

int runProblem(){

    /* If we list all the natural numbers below 10 that are multiples of 3 or 5,
    *  we get 3, 5, 6 and 9. The sum of these multiples is 23.
    *
    *  Find the sum of all the multiples of 3 or 5 below 1000.
    */

    int stop = 1000;
    int sum = 0;

    //Loop through the numbers.
    for (int i = 1; i < stop ; i++){
        //Check if multiple of 3.
        if (!(i % 3)){
            std::cout << "Number " << i << " is a multiple of 3." << std::endl;
            sum += i;
        }else

        //Check if multiple of 5.
        if (!(i % 5)){
            std::cout << "Number " << i << " is a multiple of 5." << std::endl;
            sum += i;
        }
    }

    //Write the sum.
    std::cout << "The sum of these numbers is " << sum << std::endl;

    return -1;
}
