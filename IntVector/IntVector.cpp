#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
#include "IntVector.h"

// unsigned sz: stores the size of the IntVector (the number of elements currently being used).
// unsigned cap: store the size of the array
// int *data: stores the address of the dynamically-allocated array of integers

IntVector::IntVector(){
	sz = 0;
	cap = 0;
	data = new int[sz];

	return;
}
IntVector::IntVector(unsigned size, int value){
	sz = size;
	cap = size;
	data = new int[sz];
	for(unsigned i = 0; i < sz; i++){
		data[i] = value;
	}

	return;
}
IntVector::~IntVector(){
	delete data;

	return;
}
unsigned IntVector::size() const{
	return sz;
}
unsigned IntVector::capacity() const{
	return cap;
}
bool IntVector::empty() const{
	if(sz == 0){
		return true;
	}
	return false;
}
const int& IntVector::at(unsigned index) const{
	if(index >= sz){
		throw out_of_range("IntVector::at_range_check");
	}
	return data[index];
}
const int& IntVector::front() const{
	return data[0];
}
const int& IntVector::back() const{
	return data[sz - 1];
}
int& IntVector::at(unsigned index){
	if(index >= sz){
		throw out_of_range("IntVector::at_range_check");
	}
	return data[index];
}
void IntVector::insert(unsigned index, int value){
	if(sz == cap){
		expand();
	}
	if(index > sz){
		throw out_of_range("IntVector::insert_range_check");
	}
	sz += 1;

	for(unsigned i = index; i < sz; i++){
		data[i + 1] = data[i];
	}
	data[index] = value;
}
void IntVector::erase(unsigned index){
	if(index >= sz){
		throw out_of_range("IntVector::erase_range_check");
	}
	sz -= 1;
	for(unsigned i = index; i < sz; i++){
		data[i] = data[i + 1];
	}
}
int& IntVector::front(){
	return data[0];
}
int& IntVector::back(){
	return data[sz - 1];
}
void IntVector::assign(unsigned n, int value){
	delete data;
	sz = n;
	data = new int[sz];
	if(sz > cap){
		if((cap + (sz - cap)) > (cap * 2)){
			expand(sz - cap);
		} else{
			expand();
		}
	}
	for(unsigned i = 0; i < sz; i++){
		data[i] = value;
	}
}
void IntVector::push_back(int value){
	if(sz >= cap){
		expand();
	}
	sz += 1;
	data[sz - 1] = value;
}
void IntVector::pop_back(){
	if(sz == 0){
		return;
	}
	sz -= 1;
}
void IntVector::clear(){
	sz = 0;
}
void IntVector::resize(unsigned size, int value){
	if(size > cap){
		if(((size - cap) + cap) > (cap * 2)){
			expand(size - cap);
		} else{
			expand();
		}
	}
	if(size < sz){
		sz = size;
	} else{
		for(unsigned i = sz; i < size; i++){
			data[i] = value;
		}
		sz = size;
	}
}
void IntVector::reserve(unsigned n){
	// It changes the capacity (if the capacity is less than n) to n. 
	// Basically, reserve sets the minimum capacity of the class to n.
	// You add capacity by using the expand functions, which are discussed
	// in the function description :].
	// P.S. It's implied, but if the capacity is greater than or equal to n,
	// you don't change the capacity.

	if(cap < n){
		if(((n - cap) + cap) > (cap * 2)){
			expand(n - cap);
		} else{
			expand();
		}
	}
}
void IntVector::expand(){
	int* data2;
	if(cap == 0){
		cap += 1;
		delete data;
		data = new int[cap];
		data[0] = 0;
	} else {
		cap = cap * 2;
		data2 = new int[cap];
		for(unsigned i = 0; i < sz; i++){
			data2[i] = data[i];
		}
		data = data2;	
	}
}
void IntVector::expand(unsigned amount){
	int* data2 = data;
	delete data;
	cap = cap + amount;
	data = new int[cap];
	for(unsigned i = 0; i < sz; i++){
		data[i] = data2[i];
	}
}
