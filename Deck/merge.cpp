#include <cstdlib>

#include "Deck.h"

using namespace std;

void fillHand(vector<Card> &hand, Deck &d, unsigned handSize) {
   hand.resize(handSize);
   for (unsigned i = 0; i < hand.size(); ++i) {
      hand.at(i) = d.dealCard();
   }
}

/* Assumes all values from begin to mid are in suit order,
   (see above SortBySuit function for definition of suit order)
   and all values from mid + 1 to end are in suit order.
   Merges the two halves so that all values from begin to end
   are in suit order.
*/
void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end){
   unsigned mergedSize = end - begin + 1;
   vector<Card> MergeVector(mergedSize);
   unsigned mergePos = 0;
   unsigned leftPos = begin;
   unsigned rightPos = mid + 1;

   while(leftPos <= mid && rightPos <= end){
      if(v.at(leftPos).getSuit() < v.at(rightPos).getSuit()){
         MergeVector.at(mergePos) = v.at(leftPos);
         ++leftPos;
      } else if(v.at(leftPos).getSuit() == v.at(rightPos).getSuit()){
         if(v.at(leftPos).getRank() < v.at(rightPos).getRank()){
            MergeVector.at(mergePos) = v.at(leftPos);
            ++leftPos;
         } else{
            MergeVector.at(mergePos) = v.at(rightPos);
            ++rightPos;
         }
      } else{
         MergeVector.at(mergePos) = v.at(rightPos);
         ++rightPos;
      }
      ++mergePos;
   }
   while(leftPos <= mid){
      MergeVector.at(mergePos) = v.at(leftPos);
      ++leftPos;
      ++mergePos;
   }
   while(rightPos <= end){
      MergeVector.at(mergePos) = v.at(rightPos);
      ++rightPos;
      ++mergePos;
   }

   for(mergePos = 0; mergePos < MergeVector.size(); ++mergePos){
      v.at(begin + mergePos) = MergeVector.at(mergePos);
   }

}
/* Uses the recursive merge sort algorithm to sort the contents
   of the vector from begin to end in suit order.
   (see above SortBySuit function for definition of suit order)
   Uses merge helper function to merge the two sorted
   halves.
*/
void mergeSort(vector<Card> &v, unsigned begin, unsigned end){
   unsigned mid = 0;
   if(begin < end){
      mid = (begin + end) / 2;
      mergeSort(v, begin, mid);
      mergeSort(v, mid + 1, end);
      merge(v, begin, mid, end);
   }
}
/* Sorts the contents of v into suit order,
   i.e., all clubs first (in numerically ascending order),
   then all diamonds (in ascending order),
   then all hearts (in ascending order),
   and finally all spades (in ascending order).
   Calls mergeSort recursive function to actually sort the vector.
*/
void sortBySuit(vector<Card> &v){
   if(!v.empty()){
      mergeSort(v, 0, v.size() - 1);
   }
}

//This is the function you implemented for PROGRAM 3
ostream & operator<<(ostream &, const vector<Card> &);

int main() {
   vector<Card> hand;
   Deck deck;
   int handSize;
   int seed;
   cout << "Enter seed value: ";
   cin >> seed;
   cout << endl;
   cout << "Enter hand size: ";
   cin >> handSize;
   cout << endl;

   srand(seed);
   deck.shuffleDeck();
   fillHand(hand, deck, handSize);
   cout << hand << endl;


   sortBySuit(hand);
   cout << hand << endl;
   return 0;
}

/* Passes in a vector of Cards and outputs to the stream each Card
separated by a comma and a space, 
with no comma, space, or newline at the end.
*/
ostream & operator<<(ostream & out, const vector<Card>& stuff){
   if(stuff.size() == 0){
      return out;
   }
      for(unsigned int i = 0; i < stuff.size() - 1; i++){
         out << stuff.at(i) << ", ";
      }
      out << stuff.at(stuff.size() - 1);

  return out;
}

