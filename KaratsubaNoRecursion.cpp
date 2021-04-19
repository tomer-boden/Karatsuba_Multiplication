#include "karatsubaNoRecursion.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <math.h>

int START = 0;
int CREATE_BD = 1;
int CREATE_E = 2;
int RETURN_RESULT = 3;

using namespace std;

int* intArrDuplicate(const int* arr) {
	int i, len = IntArrLen(arr);
	int* res = new int[len + 1];
	for (i = 0; i < len; i++) {
		res[i] = arr[i];
	}
	res[len] = -1;
	return res;
}

void KaratsubaNoRecursion(int size, int* num1, int* num2, int*&result)
{
	Stack S;
	ItemType *Curr, *Next;
	int* a = nullptr, * b = nullptr, * c = nullptr, * d = nullptr,
		* a_plus_b = nullptr, * c_plus_d = nullptr, * e = nullptr,
		* returnValue = nullptr, * res = nullptr;
	int numA = 0, numB = 0, digit = 2, n, zero_counter = 0;
	Curr = new ItemType(size, num1, num2, nullptr, nullptr, nullptr, START);

	S.Push(*Curr);
	n = 0;
	while (!S.IsEmpty()) {
		Curr = const_cast<ItemType*>(S.Pop());
		if (Curr->getLine() == START) {
			if (Curr ->getSize() == 1) {
				if (Curr->getArray1())
					numA = Curr->getArray1()[0];
				if (Curr->getArray2())
					numB = Curr->getArray2()[0];
				if (numA * numB >= 10)
					digit = 3;
				res = new int[digit];
				res[digit - 1] = -1;
				res[digit - 2] = numA * numB % 10;
				if (digit == 3)
					res[digit - 3] = numA * numB / 10;
				returnValue = res;
				
			}
			else {

				Curr->setLine(CREATE_BD);
				S.Push(*Curr);
				int curSize = Curr->getSize();
				n = (int)ceil(curSize / 2.0);
				a = Curr->getArray1();
				c = Curr->getArray2();
				Next = new ItemType(curSize - n, a, c, nullptr, nullptr, nullptr, START);
				S.Push(*Next);
			}
		}
		else if (Curr->getLine() == CREATE_BD) {
			Curr->setACArr(returnValue);
			delete[] returnValue;
			returnValue = nullptr;
			Curr->setLine(CREATE_E);
			S.Push(*Curr);
			n = (int)ceil(Curr->getSize() / 2.0);
			int curSize = Curr->getSize();
			b = Curr->getArray1() + curSize - n;
			d = Curr->getArray2() + curSize - n;
			Next = new ItemType(n, b, d, nullptr, nullptr, nullptr, START);
			S.Push(*Next);

		}
		else if (Curr->getLine() == CREATE_E) {
			Curr->setBDArr(returnValue);
			delete[] returnValue;
			returnValue = nullptr;
			Curr->setLine(RETURN_RESULT);
			S.Push(*Curr);
			int curSize = Curr->getSize();
			n = (int)ceil(curSize / 2.0);
			a = Curr->getArray1();
			c = Curr->getArray2();
			b = Curr->getArray1() + curSize - n;
			d = Curr->getArray2() + curSize - n;
			createAPlucBAndCPlusDArrs(a_plus_b, c_plus_d, a, b, c, d, curSize, n, zero_counter);


			Next = new ItemType(IntArrLen(a_plus_b), a_plus_b, c_plus_d, nullptr, nullptr, nullptr, START);
			S.Push(*Next);
		}
		else if (Curr->getLine() == RETURN_RESULT) {
			Curr->setEArr(returnValue);
			delete[] returnValue;
			returnValue = nullptr;
			int* e = Curr->getEArr();

			reduceArrays(IntArrLen(e), IntArrLen(Curr->getACArr()), e, Curr->getACArr());
			reduceArrays(IntArrLen(e), IntArrLen(Curr->getBDArr()), e, Curr->getBDArr());
			Curr->setEArr(e);
			
			n = (int)ceil(Curr->getSize() / 2.0);
			int* res = new int[Curr->getSize() * 2 + 1];
			fillArray(res, Curr->getSize() * 2 + 1, 0);
			combineArrays(Curr->getSize() * 2, IntArrLen(Curr->getBDArr()), res, Curr->getBDArr());
			combineArrays(Curr->getSize() * 2 - n, IntArrLen(Curr->getEArr()), res, Curr->getEArr());
			combineArrays(Curr->getSize() * 2 - 2 * n, IntArrLen(Curr->getACArr()), res, Curr->getACArr());
			returnValue = res;
			delete[] e;
			
		}
	}
	result = returnValue;
}


