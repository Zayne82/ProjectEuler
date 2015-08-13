#include "../include/Problem4.h"
#include <string>
#include <iostream>

Problem4::Problem4(){
}


void Problem4::findLargestPalindrome(int largestNumber){

    int largestPalindrome = 0;
    int largestA = 0;
    int largestB = 0;

    int tempNumber;

    for(int A = largestNumber; A > 0; A--){
        for(int B = largestNumber - (largestNumber - A); B > 0; B--){
            tempNumber= A*B;
            if(isPalindrome(tempNumber)){
                if(largestPalindrome<tempNumber){
                    largestPalindrome = tempNumber;
                    largestA = A;
                    largestB = B;
                }
            }
        }
    }

    std::cout << "Largest palindrome is a product of " << largestA << " and " << largestB << " which is " << largestPalindrome << std::endl;
}

void Problem4::testProblem4(){
    int testNumber1 = 9;
    int testNumber2 = 10;
    int testNumber3 = 11;
    int testNumber4 = 111;
    int testNumber5 = 121;
    int testNumber6 = 122;

    std::cout << "Number " << testNumber1 << " is evaluated to: ";
    if(isPalindrome(testNumber1)){
        std::cout << "True" << std::endl;
    }else{
        std::cout << "False" << std::endl;
    }
    std::cout << "Number " << testNumber2 << " is evaluated to: ";
    if(isPalindrome(testNumber2)){
        std::cout << "True" << std::endl;
    }else{
        std::cout << "False" << std::endl;
    }
    std::cout << "Number " << testNumber3 << " is evaluated to: ";
    if(isPalindrome(testNumber3)){
        std::cout << "True" << std::endl;
    }else{
        std::cout << "False" << std::endl;
    }
    std::cout << "Number " << testNumber4 << " is evaluated to: ";
    if(isPalindrome(testNumber4)){
        std::cout << "True" << std::endl;
    }else{
        std::cout << "False" << std::endl;
    }
    std::cout << "Number " << testNumber5 << " is evaluated to: ";
    if(isPalindrome(testNumber5)){
        std::cout << "True" << std::endl;
    }else{
        std::cout << "False" << std::endl;
    }
    std::cout << "Number " << testNumber6 << " is evaluated to: ";
    if(isPalindrome(testNumber6)){
        std::cout << "True" << std::endl;
    }else{
        std::cout << "False" << std::endl;
    }
}

bool Problem4::isPalindrome(int number){
    //Turn number into string
    std::string numberString = std::to_string(number);
    //std::cout << std::endl << "Number = " << number << " String = " << numberString << std::endl;

    //Get length and set up first and last position
    int left = 0;
    int right = numberString.size();
    //Step right one place to the last character. (Moves away from \0)
    right--;
    //std::cout << std::endl << "left = " << left << " right = " << right << std::endl;

    while(left <= right){
            //std::cout << std::endl << "left = " << left << " right = " << right << std::endl;

        //Check if left and right position is the same position
        if(left == right){
            return true;
        }
        //Check if left and right character is the same
        if(numberString[left] != numberString[right]){
            //std::cout << "numberString[" << left << "] = " << numberString[left] << " != numberString[" << right << "] = " << numberString[right] << std::endl;
            return false;
        }
        //Increase left and decrease right
        left++;
        right--;
    }
    //Default is true
    return true;
}
