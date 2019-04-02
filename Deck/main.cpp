#include <fstream>
#include <cstdlib>

#include "Deck.h"

using namespace std;


/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.
*/
bool hasPair(const vector<Card> &);


/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space, 
   with no comma, space, or newline at the end.
*/
ostream & operator<<(ostream &, const vector<Card> &);

int main(){
  srand(2222);
  string fileAnswer;
  Deck playDeck;
  vector<Card> HandCards;

  cout << "Do you want to output all hands to a file?(Yes/No) ";
  cin >> fileAnswer;
  cout << endl;
  string fileName;
  ifstream inFS;

  if(fileAnswer == "Yes" || fileAnswer == "yes"){
    cout << "Enter name of output file: ";
    cin >> fileName;
    cout << endl;
    
     inFS.open(fileName.c_str());
  //   // if(!inFS.is_open()){
  //   //   cout << "Error opening " << fileName << endl;
  //   //   return 1;
  //   // }
  //   // // finish

    inFS.close();
  }

  int numCards = 0;
  cout << "Enter number of cards per hand: ";
  cin >> numCards;
  cout << endl;

  int numDeals = 0;
  cout << "Enter number of deals (simulations): ";
  cin >> numDeals;
  cout << endl;

  HandCards.clear();

  int handWithPair = 0;
  for(int i = 0; i < numDeals; i++){
    playDeck.shuffleDeck();
    
    for(int i = 0; i < numCards; i++){
      HandCards.push_back(playDeck.dealCard());
    }

    if(hasPair(HandCards) == true){
      handWithPair = handWithPair + 1;
    }
    playDeck.shuffleDeck();
    HandCards.clear();

  }

  double pairChance = (static_cast<double>(handWithPair) / numDeals) * 100;

  cout << "Chances of receiving a pair in a hand of " << numCards << " cards is: " << pairChance << '%' << endl;


	return 0;
}

// GLOBAL
/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
Otherwise returns false.
*/
bool hasPair(const vector<Card>& stuff){
  for(unsigned int i = 0; i < stuff.size() - 1; i++){
    for(unsigned int j = i + 1; j < stuff.size(); j++){
      if(stuff.at(i).getRank() == stuff.at(j).getRank()){
        return true;
      }
    }
  }

  return false;
}


/* Passes in a vector of Cards and outputs to the stream each Card
separated by a comma and a space, 
with no comma, space, or newline at the end.
*/
ostream & operator<<(ostream & out, const vector<Card>& stuff){
  for(unsigned int i = 0; i < stuff.size() - 1; i++){
    out << stuff.at(i) << ", ";
  }
    out << stuff.at(stuff.size() - 1);

  return out;
}