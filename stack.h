#pragma once
#include "node.h"

class Stack {
	private:
		Node* _top;
	public:
		Stack();
		~Stack();
		void MakeEmpty();
		int IsEmpty() const;
		void Push(ItemType item);
		const ItemType* Pop();
};