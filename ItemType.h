#pragma once


class ItemType {
	private:
		int _size;
		int* _array1 = nullptr;
		int* _array2 = nullptr;
		int* _acArr = nullptr;
		int* _bdArr = nullptr;
		int* _eArr = nullptr;
		int _line;
	public:
		//Constructors
		ItemType(const int num , const int* array1, const int* array2, const int* acArr, const int* bdArr, const int* eArr, const int line);
		ItemType(const ItemType& itemType);
		//Distructors
		~ItemType();
		// Getters
		int getSize() const { return this->_size; }
		int* getArray1() const { return this->_array1; }
		int* getArray2() const { return this->_array2; }
		int* getACArr() const { return this->_acArr; }
		int* getBDArr() const { return this->_bdArr; }
		int* getEArr() const { return this->_eArr; }
		int getLine() const { return this-> _line; }

		//Setters
		void setSize(const int size);
		void setArray1(const int* array1);
		void setArray2(const int* array2);
		void setACArr(const int* acArr);
		void setBDArr(const int* bdArr);
		void setEArr(const int* eArr);
		void setLine(const int line);

		const ItemType& operator=(const ItemType& itemType);

};