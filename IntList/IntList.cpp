#include "IntList.h"

using namespace std;

IntList::IntList(){
	head = new IntNode(0);
	tail = new IntNode(0);
}
IntList::~IntList(){
	while(head->next != 0){
		pop_front();
	} 
}
void IntList::display() const{
	IntNode* Count = head;
	unsigned count = 0;
	while(Count->next != 0){
		++count;
		Count = Count->next;
	}
	IntNode* start = head;
	for(unsigned i = 1; i < count; i++){
		cout << start->data << " ";
		start = start->next;
	}
	if(start->next != 0){
		cout << start->data;
	}
}
void IntList::push_front(int value){
	IntNode* temp = new IntNode(value);
	temp->next = this->head;
	head = temp;
	if(tail == 0){
		tail = temp;
		tail->next = new IntNode(0);
	}
}
void IntList::pop_front(){
	if(empty() != true){
		IntNode* temp = head->next;
		delete head;
		head = temp;
	}
}
bool IntList::empty() const{
	if(head->next == 0 && head->data == 0){
		return true;
	}
	return false;
}

IntList::IntList(const IntList& cpy){
	head = new IntNode(0);
	tail = new IntNode(0);
	IntNode* copyList = cpy.head;
	while(copyList->next != 0){
		push_back(copyList->data);
		copyList = copyList->next;
	}
}
IntList& IntList::operator=(const IntList& rhs){
	if(this != &rhs){ 
		clear();
		head = new IntNode(0);
		tail = new IntNode(0);
		if(rhs.empty() != true){
			IntNode* rhsHead = rhs.head;
			while(rhsHead->next != 0){
				push_back(rhsHead->data);
				rhsHead = rhsHead->next;
			}
		}
	}
	return *this;
}
void IntList::push_back(int value){
	IntNode* temp = new IntNode(value);
	tail->next = temp;
	tail = tail->next;
	tail->next = new IntNode(0);
	if(empty() == true){
		head = tail;
	}
}
void IntList::clear(){
	while(head->next != 0){
		pop_front();
	}
}
void IntList::selection_sort(){
	IntNode* start = head;
	if(empty() != true){
		while(start->next != 0){
			IntNode* nextVal = start->next;
			while(nextVal->next != 0){	
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
	if(empty() != true){
		if(head == tail){
			if(insert->data >= head->data){
				head->next = insert;
				tail = insert;
			} else{
				insert->next = head;
				tail = head;
				head = insert;
			}
			tail->next = new IntNode(0);
		} else if(insert->data >= tail->data){
			tail->next = insert;
			tail = tail->next;
			tail->next = new IntNode(0);
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
	if(empty() != true){
		while(start->next != 0){
			IntNode* prevVal = start;
			while(prevVal->next->next != 0){
				IntNode* nextVal = prevVal->next;
				if(start->data == nextVal->data){
					prevVal->next = nextVal->next;
					delete nextVal;
					nextVal = prevVal->next;				
					if(prevVal->next == 0){
						tail = prevVal;
						tail->next = new IntNode(0);
					}
				} else{
					prevVal = prevVal->next;
				}
			}
			start = start->next;
		}
	}
}
ostream&operator<<(ostream& out, const IntList& rhs){
	unsigned count = 0;
  	IntNode* Count = rhs.head;
	while(Count->next != 0){
		count++;
		Count = Count->next;
	}
	IntNode* start = rhs.head;
	for(unsigned i = 1; i < count; i++){
		out << start->data << " ";
		start = start->next;
	}
	if(start->data != 0){
		out << start->data;
	}
	return out;
}


// dereferencing tools: * [] ->  - segmentation fault occurs when dereferencing