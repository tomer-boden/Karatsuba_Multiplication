#include <iostream>
#include "ItemType.h"
#include "karatsubaNoRecursion.h"

using namespace std;

ItemType::ItemType(const int num, const int* array1, const int* array2, const int* acArr, const int* bdArr, const int* eArr, const int line) : _size(num) , _line(line)
{
	if (array1) {
		this->_array1 = intArrDuplicate(array1);
	}
	if (array2) {
		this->_array2 = intArrDuplicate(array2);
	}
	if (acArr) {
		this->_acArr = intArrDuplicate(acArr);
	}
	if (bdArr) {
		this->_bdArr = intArrDuplicate(bdArr);
	}
	if (eArr) {
		this->_eArr = intArrDuplicate(eArr);
	}
}

ItemType::ItemType(const ItemType& itemType)
{
	*this = itemType;
}

ItemType::~ItemType() {
	delete[] _array1;
	delete[] _array2;
	delete[] _acArr;
	delete[] _bdArr;
	delete[] _eArr;
}

void ItemType::setSize(const int size) {
	this->_size = size;
}

void ItemType::setArray1(const int* array1) {
	this->_array1 = intArrDuplicate(array1);
}

void ItemType::setArray2(const int* array2) {
	this->_array2 = intArrDuplicate(array2);
}

void ItemType::setACArr(const int* acArr) {
	this->_acArr = intArrDuplicate(acArr);
}

void ItemType::setBDArr(const int* bdArr) {
	this->_bdArr = intArrDuplicate(bdArr);
}

void ItemType::setEArr(const int* eArr) {
	this->_eArr = intArrDuplicate(eArr);
}

void ItemType::setLine(const int line) {
	this->_line = line;
}

const ItemType& ItemType::operator=(const ItemType& itemType) 
{
	_size = itemType._size;
	_line = itemType._line;
	if(itemType._array1)
		_array1 = intArrDuplicate(itemType._array1);
	if (itemType._array2)
		_array2 = intArrDuplicate(itemType._array2);
	if (itemType._acArr)
		_acArr = intArrDuplicate(itemType._acArr);
	if (itemType._bdArr)
		_bdArr = intArrDuplicate(itemType._bdArr);
	if (itemType._eArr)
		_eArr = intArrDuplicate(itemType._eArr);
	return *this;
}
