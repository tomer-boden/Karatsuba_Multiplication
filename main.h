#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono> 
#include <iomanip>
#include <string>
#include <string.h>
#include "longMultiplicationAlgorithm.h"
#include "karatsubaAlgorithmRecursion.h"
#include "karatsubaNoRecursion.h"

using namespace std;

bool getInputFromUser(int& size, char** firstNum, char** secondNum);
bool isNumber(const string& s);
void printResult(int* res, int resSize);
void CharArrToIntArr(char* arr, int*& res);
void initNumbersArr(int& size, char** firstNum, char** secondNum);
