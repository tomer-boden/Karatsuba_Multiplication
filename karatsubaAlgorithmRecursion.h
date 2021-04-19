#pragma once
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

void karatsubaAlgorithm(int size, int* num1, int* num2,int*& res);
int* karatsubaAlgorithmRecursion(int size ,int* num1, int* num2);
void createAPlucBAndCPlusDArrs(int*& a_plus_b, int*& c_plus_d, int* a, int* b, int* c, int* d, int size, int n, int& zero_counter); // creates two arrays. the first has the result of a + b , the second has c + d
void combineArrays(int size1, int size2, int* num1, int* num2); // sums the values of two arrays
void reduceArrays(int size1, int size2, int* num1, int* num2); // subtracts the values of two arrays
void fillArray(int* arr, int size, int a); //fills an array with 0 and in the last spot puts a -1
int IntArrLen(const int* arr); //finds an int* array length
