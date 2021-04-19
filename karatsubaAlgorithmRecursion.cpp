#include "karatsubaAlgorithmRecursion.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

void karatsubaAlgorithm(int size, int* num1, int* num2, int*& res)
{
	res = karatsubaAlgorithmRecursion(size, num1, num2);
}

int* karatsubaAlgorithmRecursion(int size, int* num1, int* num2)
{
	int numA = 0, numB = 0, digit = 2, zero_counter = 0;
	int *a= nullptr, *b= nullptr, *c= nullptr, *d= nullptr, 
		*a_plus_b = nullptr, *c_plus_d = nullptr, *e = nullptr, 
		*res = nullptr;

	if (size == 1)
	{
		if (num1)
			numA = num1[0];
		if (num2)
			numB = num2[0];
		if (numA * numB >= 10)
			digit = 3;

		res = new int[digit];
		res[digit - 1] = -1;
		res[digit - 2] = numA * numB % 10;
		if (digit == 3)
			res[digit - 3] = numA * numB / 10;
		return res;
	}

	int n = static_cast<int>(ceil(size / 2.0));

	 a = num1;
	 b = num1 + size - n;
	 c = num2;
	 d = num2 + size - n;

	int* ac = karatsubaAlgorithmRecursion(size - n, a, c);
	int* bd = karatsubaAlgorithmRecursion(n, b, d);
	
	createAPlucBAndCPlusDArrs(a_plus_b, c_plus_d, a, b, c, d, size, n, zero_counter);
	e = karatsubaAlgorithmRecursion(IntArrLen(a_plus_b), a_plus_b, c_plus_d);
	reduceArrays(IntArrLen(e), IntArrLen(ac), e, ac);
	reduceArrays(IntArrLen(e), IntArrLen(bd), e, bd);

	res = new int[size * 2 + 1];
	fillArray(res, size * 2 + 1, 0);
	combineArrays(size * 2, IntArrLen(bd), res, bd);
	combineArrays(size * 2 - n, IntArrLen(e), res, e);
	combineArrays(size * 2 - 2 * n, IntArrLen(ac), res, ac);

	delete[] ac;
	delete[] bd;
	delete[] e;
	delete[](a_plus_b - zero_counter);
	delete[](c_plus_d - zero_counter);
	return res;
}


void createAPlucBAndCPlusDArrs(int*& a_plus_b, int*& c_plus_d, int* a, int* b, int* c, int* d, int size, int n, int& zero_counter) {
	int bigger = max(size - n, n);
	a_plus_b = new int[bigger + 2];
	fillArray(a_plus_b, bigger + 2, 0);
	combineArrays(bigger + 1, size - n, a_plus_b, a);
	combineArrays(bigger + 1, n, a_plus_b, b);

	c_plus_d = new int[bigger + 2];
	fillArray(c_plus_d, bigger + 2, 0);
	combineArrays(bigger + 1, size - n, c_plus_d, c);
	combineArrays(bigger + 1, n, c_plus_d, d);

	while (c_plus_d[0] == 0 && c_plus_d[1] != -1 && a_plus_b[0] == 0 && a_plus_b[1] != -1)
	{
		zero_counter++;
		a_plus_b++;
		c_plus_d++;
	}
}


void combineArrays(int size1, int size2, int* num1, int* num2)
{
	int temp_a = 0, temp_b = 0, temp_c = 0;
	for (; size1 >= 1; size1--, size2--)
	{
		if (size2 <= 0)
		{
			temp_b = 0;
			if (!temp_c / 10)
				return;
		}
			
		else
			temp_b = num2[size2 - 1];
		temp_a = num1[size1 - 1];
		temp_c = temp_a + temp_b;
		num1[size1 - 1] = (temp_c % 10);
		if (num1[size1 - 2] >=0)
			num1[size1 - 2] = ((num1[size1 - 2]) + (temp_c / 10));
	}

}

void reduceArrays(int size1, int size2, int* num1, int* num2)
{
	int temp_a = 0, temp_b = 0, temp_c = 0, temp_d = 0, carry = 0;
	for (; size1 >= 1; size1--, size2--)
	{
		temp_a = num1[size1 - 1];
		if (size2 <= 0)
		{
			temp_b = 0;
			if (carry == 0)
				return;
		}
			
		else
			temp_b = num2[size2 - 1];

		temp_c = temp_a - temp_b + carry;
		temp_d = (10 + temp_c) % 10;
		if (temp_c < 0)
			carry = -1;
		else
			carry = 0;
		num1[size1 - 1] = temp_d;
	}
}

void fillArray(int* arr, int size, int a)
{
	for (int i = 0; i < size - 1; i++)
	{
		arr[i] = a;
	}
	arr[size - 1] = -1;
}

int IntArrLen(const int* arr) {
	int res = 0;
	while (arr[res] != -1) {
		res++;
	}
	return res;
}