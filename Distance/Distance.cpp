#include <iostream>
using namespace std;

#include "Distance.h"


/* Constructs a default Distance of 0 (0 feet and 0.0 inches)
*/
Distance::Distance(){
    feet = 0;
    inches = 0.0;

    return;
}


/* Constructs a distance of ft feet and in inches,
    unless in >= 12, in which case the values of feet and inches
    are adjusted accordingly. A Distance will always be positive.
*/
Distance::Distance(unsigned ft, double in){
    feet = ft;
    inches = in;

    init();

    return;
}


/* Constructs a distance of 0 ft and in inches, 
    unless in >= 12, in which case the values of feet and inches
    are adjusted accordingly. A Distance will always be positive.
*/
Distance::Distance(double in){
    feet = 0;
    inches = in;

    init();

    return;
}


/* Returns just the feet portion of the Distance
*/
unsigned Distance::getFeet() const{
    return feet;
}


/* Returns just the inches portion of the Distance
*/
double Distance::getInches() const{
    return inches;
}


/* Returns the entire distance as the equivalent amount of inches.
    (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
*/
double Distance::distanceInInches() const{
    double totalInches = (feet * 12) + inches;

    return totalInches;
}


/* Returns the entire distance as the equivalent amount of feet.
    (e.g., 3 feet 6 inches would be returned as 3.5 feet)
*/
double Distance::distanceInFeet() const{

    double totalFeet = feet + (inches / 12.0);

    return totalFeet;
}


/* Returns the entire distance as the equivalent amount of meters.
    1 inch equals 0.0254 meters.
    (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
*/
double Distance::distanceInMeters() const{
    double totalMeters = distanceInInches() * 0.0254;

    return totalMeters;
}


/* Returns the sum of 2 Distances.
*/
const Distance Distance::operator+(const Distance &rhs) const{
    Distance lhs;

    lhs.feet = feet + rhs.feet;
    lhs.inches = inches + rhs.inches;
    lhs.init();

    return lhs;
}


/* Returns the difference between 2 Distances.
*/
const Distance Distance::operator-(const Distance &rhs) const{
    Distance lhs;

    lhs.inches = distanceInInches() - rhs.distanceInInches();
    lhs.init();

    return lhs;
}


/* Outputs to the stream out the Distance in the format: 
    feet' inches'' (i.e. 3' 3.41'')
*/
ostream& operator<<(ostream &out, const Distance &rhs){
    out << rhs.feet << "' ";
    out << rhs.inches << "\"";

    return out;
}

/* Used by the 2 parameterized constructors to convert any negative values to positive and
    inches >= 12 to the appropriate number of feet and inches.
*/
void Distance::init(){

    if( getFeet() < 0.0){
        feet = -feet;
    } 
    if(getInches() < 0.0){
        inches = -inches;
    } if(getInches() >= 12){
        feet = distanceInFeet();
        inches = static_cast<int>(inches) % 12 + (inches - static_cast<int>(inches));
    }

}