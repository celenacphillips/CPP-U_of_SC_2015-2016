/****************************************************************
 * Header file for the application class for the edit distance
 * program.
 *
 * Author/copyright:  Duncan Buell
 * Date: 6 August 2016
 *
**/

#ifndef EDITDISTANCE_H
#define EDITDISTANCE_H

#include <iostream>
#include <vector>
using namespace std;

#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class EditDistance {
public:
 EditDistance();
 virtual ~EditDistance();

 void ComputeDistances();
 void Initialize(Scanner& scanner);
 string ToString();
 string ComputeMatrix ();
 string Compute (int one, int two);

private:
 const int kCostDeletion = 1;
 const int kCostInsertion = 1;
 const int kCostSubstitution = 2;
 const int kDummyDistance = -1;
 const string kDummyString = "[  ]";

 // we will pad the shorter string to get a common 'length_'
 int length_ = 0;
 int counter_ = 0;

 // note the space in '> >' because the compiler needs it
 vector<vector<string> > dist_;

 vector<string> sentence1_;
 vector<string> sentence2_;
};

#endif
