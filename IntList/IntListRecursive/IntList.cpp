#include "IntList.h"

using namespace std;

/* Initializes an empty list.
*/
IntList::IntList(){
	head = 0;
}

/* Inserts a data value to the front of the list.
*/
void IntList::push_front(int value){
	IntNode* newHead = new IntNode(value);
	if(head != 0){
		newHead->next = head;
	}
	head = newHead;
}

/* Outputs to a single line all of the int values stored in the list, each separated by a space. 
  This function does NOT output a newline or space at the end.
*/
ostream& operator<<(ostream& out, const IntList& rhs){
	IntNode* rhsHead = rhs.head;
	out << rhsHead;
	return out;
}

/* Returns true if the integer passed in is contained within the IntList, 
  otherwise returns false.
*/
bool IntList::exists(int value) const{
	if(exists(head, value) == true){
		return true;
	}
	return false;
}

/* Helper function that returns true if the integer passed in is contained within
  the IntNodes starting from the IntNode whose address is passed in,
  otherwise returns false.
*/
bool IntList::exists(IntNode* start, int value) const{
	if(start == 0){
		return false;
	}
	if(start->data == value){
		return true;
	} else{
		start = start->next;
		return exists(start, value);
	}
	return false;
}

/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream& operator<<(ostream& out, IntNode* rhs){
	if(rhs == 0){
		return out;
	}
	if(rhs->next == 0){
		out << rhs->data;
		return out;
	}
	out << rhs->data << " ";
	rhs = rhs->next;
	return (out << rhs);
}