#include "domino.h"

/******************************************************************************
*3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
* Class 'Domino' for a single domino.
*
* Author: Duncan A. Buell
* Modified by: Celena Williams 
* Date last modified: 21 October 2016
**/

/******************************************************************************
* Constructor
**/
Domino::Domino() {
}

/******************************************************************************
* Constructor with data supplied
**/
Domino::Domino(int left, int right) {
  left_ = left;
  right_ = right;
}

/******************************************************************************
* Destructor
**/
Domino::~Domino() {
}

/******************************************************************************
* Accessors and Mutators
**/

/******************************************************************************
* Accessor 'GetLeft'.
*
* Returns:
*   the left of the numbers on the domino 
**/
int Domino::GetLeft() const {
  return left_;
}

/******************************************************************************
* Accessor 'GetRight'.
*
* Returns:
*   the right of the numbers on the domino 
**/
int Domino::GetRight() const {
  return right_;
}

/******************************************************************************
* Accessor 'HasBeenPlayed'.
*
* Returns:
*   the boolean value of 'played_'
**/
bool Domino::HasBeenPlayed() const {
  return played_;
}

/******************************************************************************
* Accessor 'WasDealt'.
*
* Returns:
*   the boolean value of 'dealt'
**/
bool Domino::WasDealt() const {
  return dealt_;
}

/******************************************************************************
* Mutator 'SetDealt'.
*
* Parameters:
*   the boolean value to be set
**/
void Domino::SetDealt(bool value) {
  dealt_ = value;
}

/******************************************************************************
* Mutator 'SetPlayed'.
*
* Parameters:
*   the boolean value to be set
**/
void Domino::SetPlayed(bool value) {
  played_ = value;
}

/******************************************************************************
* General functions.
**/
/******************************************************************************
* Function 'FlipEnds' to flip a domino end for end.
**/
void Domino::FlipEnds() {
  int temp = right_;
  right_ = left_;
  left_ = temp;
}

/******************************************************************************
* Function 'ToString'.
* This returns the 'played_' as well as the left and right numbers.
**/
string Domino::ToString() const {
  string str = "**";

  if (played_) {
    str.append ("HasBeenPlayed ");
  }
  else {
    str.append ("HasNotBeenPlayed ");
  }

  str.append (Utils::Format (left_, 3) + Utils::Format (right_, 3) + "**\n");

  return str;
}
