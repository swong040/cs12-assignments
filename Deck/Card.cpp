#include "Card.h"

using namespace std;

// CARD
/* Assigns a default value of 2 of Clubs
*/
Card::Card(){
  suit = 'c';
  rank = 2;

  return;
}

/* Assigns the Card the suit and rank provided.
   suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
   If an invalid suit is provided, sets the suit to Clubs
   ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
   If an invalid rank is provided, sets the rank to 2
   Accepts lower or upper case characters for suit
*/  
Card::Card(char s, int r){
  if(s == 'c' || s == 'C'){
    suit = 'c';
  } else if(s == 'd' || s == 'D'){
    suit = 'd';
  } else if(s == 'h' || s == 'H'){
    suit = 'h';
  } else if (s == 's' || s == 'S'){
    suit = 's';
  } else {
    suit = 'c';
  }

  if(r >= 1 && r <= 13){
    rank = r;
  } else{
    rank = 2;
  }

  return;
}


/* Returns the Card's suit
*/
char Card::getSuit() const{
  return suit;
}


/* Returns the Card's rank as an integer
*/
int Card::getRank() const{
  return rank;
}

/* Outputs a Card in the following format: Rank of Suit
   For example, if the rank is 3 and the suit is h: 3 of Hearts
   Or, if the rank is 1 and the suit is d: Ace of Diamonds
   Or, if the rank is 12 and the suit is c: Queen of Clubs
   etc.
*/ 
// SOMETHING HERE
ostream & operator<<(ostream & out, const Card& stuff){
  if(stuff.suit == 'c'){
    if(stuff.rank == 1){
      out << "Ace of Clubs";
    } else if(stuff.rank == 11){
      out << "Jack of Clubs";
    } else if(stuff.rank == 12){
      out << "Queen of Clubs";
    } else if(stuff.rank == 13){
      out << "King of Clubs";
    } else if(stuff.rank > 1 && stuff.rank < 11){
      out << stuff.getRank() << " of Clubs";
    }
  } else if(stuff.suit == 'd'){
    if(stuff.rank == 1){
      out << "Ace of Diamonds";
    } else if(stuff.rank == 11){
      out << "Jack of Diamonds";
    } else if(stuff.rank == 12){
      out << "Queen of Diamonds";
    } else if(stuff.rank == 13){
      out << "King of Diamonds";
    } else if(stuff.rank > 1 && stuff.rank < 11){
      out << stuff.getRank() << " of Diamonds";
    }
  } else if(stuff.suit == 'h'){
    if(stuff.rank == 1){
      out << "Ace of Hearts";
    } else if(stuff.rank == 11){
      out << "Jack of Hearts";
    } else if(stuff.rank == 12){
      out << "Queen of Hearts";
    } else if(stuff.rank == 13){
      out << "King of Hearts";
    } else if(stuff.rank > 1 && stuff.rank < 11){
      out << stuff.getRank() << " of Hearts";
    }
  } else if(stuff.suit == 's'){
    if(stuff.rank == 1){
      out << "Ace of Spades";
    } else if(stuff.rank == 11){
      out << "Jack of Spades";
    } else if(stuff.rank == 12){
      out << "Queen of Spades";
    } else if(stuff.rank == 13){
      out << "King of Spades";
    } else if(stuff.rank > 1 && stuff.rank < 11){
      out << stuff.getRank() << " of Spades";
    }
  }

  return out;
}