#include "stack.h"

Stack::Stack() {
	_top = nullptr;
}

Stack::~Stack() {
	MakeEmpty();
}

void Stack::MakeEmpty() {
	Node* temp;
	while (_top) {
		temp = _top;
		_top = _top->getNext();
		delete temp;
	}
}

int Stack::IsEmpty() const {
	return _top == nullptr;
}

void Stack::Push(ItemType item) {
	_top = new Node(item, _top);
}

const ItemType* Stack::Pop() {
	if (IsEmpty())
		return nullptr;
	Node* temp = _top;
	ItemType* item = new ItemType(_top->getData());
	_top = _top->getNext();
	delete temp;
	return item;
}