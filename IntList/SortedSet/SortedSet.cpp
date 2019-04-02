#include "SortedSet.h"

using namespace std;

// struct IntNode {
//     int data;
//     IntNode *next;
//     IntNode(int data) : data(data), next(0) {}
// };
// 		IntNode* head;
// 		IntNode* tail;

// Constructor & Destructor
SortedSet::SortedSet() : IntList(){}
SortedSet::SortedSet(const SortedSet& cpy) : IntList(cpy){}
SortedSet::SortedSet(const IntList& cpy) : IntList(cpy){
	remove_duplicates();
	selection_sort();
}
SortedSet::~SortedSet(){ 
	while(head != 0){
		pop_front();
	} 
}
// Accessors
bool SortedSet::in(int data){
	IntNode* start = head;
	if(!empty()){
		while(start != 0){
			if(start->data == data){
				return true;
			}
			start = start->next;
		}
	}
	return false;
}
const SortedSet SortedSet::operator|(const SortedSet& sset2){
	SortedSet sset = SortedSet(sset2);
	if(!empty()){
		while(sset.head != 0){
			IntList::push_back(sset.head->data);
			sset.head = sset.head->next;
		}
		remove_duplicates();
		return *this;
	}
	return sset;
}
const SortedSet SortedSet::operator&(const SortedSet& sset2){
	SortedSet sset = SortedSet(sset2);
	SortedSet newSset;

	while(sset.head != 0){
		if(in(sset.head->data)){
			newSset.push_back(sset.head->data);
		}
		sset.head = sset.head->next;
	}
	return newSset;
}
// Mutators
void SortedSet::add(int data){
	insert_ordered(data);
}
void SortedSet::push_front(int data){
	add(data);
}
void SortedSet::push_back(int data){
	add(data);
}
void SortedSet::insert_ordered(int data){
	if(!in(data)){
		IntList::insert_ordered(data);
	}
}
SortedSet SortedSet::operator|=(const SortedSet& sset2){
	SortedSet sset3;
	sset3 = *this | sset2;
	swap(sset3, *this);

	return *this;
}
SortedSet SortedSet::operator&=(const SortedSet& sset2){
	SortedSet sset3;
	sset3 = *this & sset2;
	swap(sset3, *this);

	return *this;
}