#include "IntVector.h"
#include <iostream>

using namespace std;

int main(){
   IntVector IntVector(10, -3);

   if(IntVector.empty() == true){
      cout << "IntVector is empty." << endl;
   }

   cout << "size: " << IntVector.size() << endl;
   cout << "capacity: " << IntVector.capacity() << endl;
   cout << "front: " << IntVector.front() << endl;
   cout << "back: " << IntVector.back() << endl;
   cout << "at 4: " << IntVector.at(4) << endl << endl;

   IntVector.insert(5, 0);
   cout << "size: " << IntVector.size() << endl;
   cout << "capacity: " << IntVector.capacity() << endl;
   cout << "front: " << IntVector.front() << endl;
   cout << "back: " << IntVector.back() << endl;
   cout << "at 5: " << IntVector.at(5) << endl << endl;

   IntVector.erase(4);
   cout << "size: " << IntVector.size() << endl;
   cout << "capacity: " << IntVector.capacity() << endl;
   cout << "front: " << IntVector.front() << endl;
   cout << "back: " << IntVector.back() << endl;
   cout << "at 4: " << IntVector.at(4) << endl << endl;

   for(unsigned i = 0; i < IntVector.size(); i++){
      cout << "at " << i << ": " << IntVector.at(i) << endl;
   }
   cout << endl;
   IntVector.assign(5, -2);

   if(IntVector.empty() == true){
      cout << "IntVector is empty." << endl;
   }
   cout << "size: " << IntVector.size() << endl;
   cout << "capacity: " << IntVector.capacity() << endl;
   cout << "front: " << IntVector.front() << endl;
   cout << "back: " << IntVector.back() << endl;
   cout << "at 3: " << IntVector.at(3) << endl << endl;

   IntVector.push_back(5);
   cout << "size: " << IntVector.size() << endl;
   cout << "capacity: " << IntVector.capacity() << endl;
   cout << "front: " << IntVector.front() << endl;
   cout << "back: " << IntVector.back() << endl;
   cout << "at 4: " << IntVector.at(4) << endl << endl;

   for(unsigned i = 0; i < IntVector.size(); i++){
      cout << "at " << i << ": " << IntVector.at(i) << endl;
   }
   cout << endl;

   IntVector.pop_back();
   cout << "size: " << IntVector.size() << endl;
   cout << "capacity: " << IntVector.capacity() << endl;
   cout << "front: " << IntVector.front() << endl;
   cout << "back: " << IntVector.back() << endl;
   cout << "at 4: " << IntVector.at(4) << endl << endl;

   for(unsigned i = 0; i < IntVector.size(); i++){
      cout << "at " << i << ": " << IntVector.at(i) << endl;
   }
   cout << endl;
   
   IntVector.reserve(3);
   if(IntVector.empty() == true){
      cout << "IntVector is empty." << endl;
      return 0;
   }
   cout << "size: " << IntVector.size() << endl;
   cout << "capacity: " << IntVector.capacity() << endl;
   cout << "front: " << IntVector.front() << endl;
   cout << "back: " << IntVector.back() << endl;
   cout << "at 4: " << IntVector.at(4) << endl << endl;

   IntVector.resize(15, 4);
   if(IntVector.empty() == true){
      cout << "IntVector is empty." << endl;
      return 0;
   }
   cout << "size: " << IntVector.size() << endl;
   cout << "capacity: " << IntVector.capacity() << endl;
   cout << "front: " << IntVector.front() << endl;
   cout << "back: " << IntVector.back() << endl;
   cout << "at 4: " << IntVector.at(4) << endl << endl;


   IntVector.clear();
   if(IntVector.empty() == true){
      cout << "IntVector is empty." << endl;
   }

      return 0;
}