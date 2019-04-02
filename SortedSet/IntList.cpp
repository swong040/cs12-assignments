#include "IntList.h"
#include <iostream>
#include <algorithm>

using namespace std;

IntList::IntList(){
	head = 0;
	tail = 0;
}
IntList::~IntList(){
	while(head != 0){
		pop_front();
	} 
}
void IntList::display() const{
	if(!empty()){
		IntNode* start = head;

		cout << start->data;
		start = start->next;
		while(start != 0){	
			cout << " " << start->data;
			start = start->next;
		}
	}
}
void IntList::push_front(int value){
	IntNode* temp = new IntNode(value);
	temp->next = this->head;
	head = temp;
	if(tail == 0){
		tail = temp;
	}
}
void IntList::pop_front(){
	if(!empty()){
		IntNode* temp = head;
		head = head->next;
		if(head == 0){
			tail = 0;
		}
		delete temp;
	}
}
bool IntList::empty() const{
	if(head == 0){
		return true;
	}
	return false;
}

IntList::IntList(const IntList& cpy){
	head = 0;
	tail = 0;
	IntNode* copyList = cpy.head;
	while(copyList != 0){
		push_back(copyList->data);
		copyList = copyList->next;
	}
}
IntList& IntList::operator=(const IntList& rhs){
	if(this != &rhs){ 
		clear();
		IntNode* rhsHead = rhs.head;
		while(rhsHead != 0){
			push_back(rhsHead->data);
			rhsHead = rhsHead->next;
		}
	}
	return *this;
}
void IntList::push_back(int value){
	IntNode* temp = new IntNode(value);
	if(empty()){
		tail = head = temp;
	} else {
		tail->next = temp;
		tail = tail->next;
	}
}
void IntList::clear(){
	while(head != 0){
		pop_front();
	}
}
void IntList::selection_sort(){
	IntNode* start = head;
	if(!empty()){
		while(start != 0){
			IntNode* nextVal = start->next;
			while(nextVal != 0){	
				IntNode* minVal = start;
				if(minVal->data > nextVal->data){
					minVal = nextVal;
				}
				if(minVal->data != start->data){
					swap(start->data, minVal->data);
				}
				nextVal = nextVal->next;
			}
			start = start->next;
		}
	}
}
void IntList::insert_ordered(int value){
	IntNode* insert = new IntNode(value);
	if(!empty()){
		if(head == tail){
			if(insert->data >= head->data){
				head->next = insert;
				tail = insert;
			} else{
				insert->next = head;
				tail = head;
				head = insert;
			}
		} else if(insert->data >= tail->data){
			tail->next = insert;
			tail = tail->next;
		} else if(insert->data <= head->data){
			insert->next = head;
			head = insert;
		} else{
			IntNode* prevVal = head;
			while(prevVal->next != 0){
				IntNode* nextVal = prevVal->next;
				if(prevVal->data <= insert->data && insert->data < nextVal->data){
					prevVal->next = insert;
					insert->next = nextVal;
				}
				prevVal = prevVal->next;
			}
		}
	} else{
		tail = head = insert;
	}
}
void IntList::remove_duplicates(){
	IntNode* start = head;
		while(start != 0){
			IntNode* prevVal = start;
			while(prevVal->next != 0){
				IntNode* nextVal = prevVal->next;
				if(start->data == nextVal->data){
					prevVal->next = nextVal->next;
					delete nextVal;
					nextVal = prevVal->next;				
					if(prevVal->next == 0){
						tail = prevVal;
					}
				} else{
					prevVal = prevVal->next;
				}
			}
			start = start->next;
		}
}
ostream&operator<<(ostream& out, const IntList& rhs){
	if(!rhs.empty()){
		IntNode* start = rhs.head;
		out << start->data;
		start = start->next;
		while(start != 0){	
			out << " " << start->data;
			start = start->next;
		}
	}
	return out;

}


// dereferencing tools: * [] ->  - segmentation fault occurs when dereferencing