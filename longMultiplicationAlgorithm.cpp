#include <iostream>
#include <sstream>
#include <algorithm>
#include "longMultiplicationAlgorithm.h"

using namespace std;

void longMultiplicationAlgorithm(int size, int* num1, int* num2, int& mulArrSize, int*& res) {
    multiply(size, num1, num2, mulArrSize, res);
    reverseArr(mulArrSize,res);
}

void multiply(int& size, int* num1, int* num2, int& mulArrSize, int*& res) {
    int n1, n2, sum, carry, idxN1 = 0, idxN2 = 0; //two indexes are used to find positions in result.
    initMulArr(mulArrSize,res);

    for (int i = size - 1; i >= 0; i--) // Go from right to left in num1 
    {
        carry = 0;
        n1 = num1[i];
        idxN2 = 0;

        for (int j = size - 1; j >= 0; j--) // Go from right to left in num2    
        {
            n2 = num2[j]; // Take current digit of second number 
            sum = n1 * n2 + res[idxN1 + idxN2] + carry;
            carry = sum / 10;
            res[idxN1 + idxN2] = sum % 10;  // Store result in multiply arr.
            idxN2++;
        }

        if (carry > 0) // store carry in next cell 
            res[idxN1 + idxN2] += carry;
        idxN1++; // To shift position to left after every multiplication of a digit in num1. 
    }
}

void initMulArr(int& mulArrSize, int*& res) {
    //init every cell to 0
    for (int i = 0; i < mulArrSize; i++) {
        res[i] = 0;
    }
}

void reverseArr(int& mulArrSize, int*& res) {
    int* reverseArr = new int[mulArrSize];
    for (int i = 0; i < mulArrSize; i++) {
        reverseArr[i] = res[mulArrSize-i-1];
    }
    delete[] res;
    res = reverseArr;
}