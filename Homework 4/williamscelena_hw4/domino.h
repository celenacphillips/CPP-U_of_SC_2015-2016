/****************************************************************
 * Header file for a single domino.
 *
 * Author/copyright:  Duncan Buell
 * Date: 6 August 2016
 *
**/

#ifndef DOMINO_H
#define DOMINO_H

#include <iostream>
#include <vector>
using namespace std;

#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

const int kDummyInt = -1;

class Domino {
public:
 Domino();
 Domino(int left, int right);
 virtual ~Domino();

 void FlipEnds();
 int GetLeft() const;
 int GetRight() const;
 bool HasBeenPlayed() const;
 void SetDealt(bool value);
 void SetPlayed(bool value);
 bool WasDealt() const;
 string ToString() const;

 /////////////////////////////////////////////////////////////////
 // Overloaded 'friend' operators.
//  friend ostream& operator <<(ostream& outputStream, const Domino& dom);

private:
 bool played_ = false;
 bool dealt_ = false;
 int left_ = kDummyInt;
 int right_ = kDummyInt;
};

#endif
