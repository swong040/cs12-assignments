// Deck.cpp work

#include "Deck.h"

using namespace std;

// DECK
/* Constructs a Deck of 52 cards:
   Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
   Cards should start off in this order with the order of suits being:
   Clubs, Diamonds, Hearts, Spades.
*/

Deck::Deck(){
  int r;
  char s;
  for(unsigned int i = 13; i > 0; i--){
    s = 's';
    r = i;
    theDeck.push_back(Card(s,r));
  }
  for(unsigned int i = 13; i > 0; i--){
    s = 'h';
    r = i;
    theDeck.push_back(Card(s,r));
  }
  for(unsigned int i = 13; i > 0; i--){
    s = 'd';
    r = i;
    theDeck.push_back(Card(s,r));
  }
  for(unsigned int i = 13; i > 0; i--){
    s = 'c';
    r = i;
    theDeck.push_back(Card(s,r));
  }  
  return;
}

/* Deals (returns) the top card on the deck. 
   Removes this card from theDeck and places it in the dealtCards.
*/
Card Deck::dealCard(){
  Card topCard = theDeck.at(theDeck.size() - 1);
  dealtCards.push_back(topCard);
  theDeck.pop_back();

  return topCard;
}


/* Places all cards back into theDeck and shuffles them into random order.
   Uses random_shuffle function from algorithm standard library.
*/
// SOMETHING HERE
void Deck::shuffleDeck(){
  for(unsigned int i = 0; i < dealtCards.size(); i++){
    theDeck.push_back(dealtCards.at(i));
  }
  random_shuffle(theDeck.begin(), theDeck.end());
}


/* returns the size of the Deck (how many cards have not yet been dealt).
*/
unsigned Deck::deckSize() const{
  return theDeck.size();
}

