#pragma once
#include <iostream>
#include <sstream>
using namespace std;

void longMultiplicationAlgorithm(int size, int* num1, int* num2, int& mulArrSize, int*& res);
void multiply(int& size, int* num1, int* num2, int& mulArrSize, int*& res); //multiply
void initMulArr(int& mulArrSize, int*& res); //initMulArr
void reverseArr(int& mulArrSize, int*& res); //reverse the array order
