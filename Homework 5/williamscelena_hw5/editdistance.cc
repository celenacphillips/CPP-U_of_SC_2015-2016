#include "editdistance.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'EditDistance' for the edit distance computation.
 *
 * Author: Duncan A. Buell
 * Modified by: Celena Williams
 * Date last modified: 26 November 2016
**/


/******************************************************************************
 * Constructor
**/
EditDistance::EditDistance() {
}

/******************************************************************************
 * Destructor
**/
EditDistance::~EditDistance() {
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function 'ComputeDistances'.
 * This function computes the distances between the two sentences.
 *
**/
void EditDistance::ComputeDistances() {
	int length1 = sentence1_.size ();
	int length2 = sentence2_.size ();

	if (length1 > length2)
		length_ = length1;

	if (length2 > length1)
		length_ = length2;

	if (length1 == length2)
		length_ = length1;

	while (length1 != length_) {
		sentence1_.push_back (kDummyString);
		length1++;
	}

	while (length2 != length_) {
		sentence2_.push_back (kDummyString);
		length2++;
	}
}

/******************************************************************************
 * Function 'Initialize'.
**/
void EditDistance::Initialize(Scanner& scanner) {
	ScanLine scanline;
	string str;
	int counter = 0;

	sentence1_.push_back (kDummyString);
	sentence2_.push_back (kDummyString);

	while (scanner.HasNext ()) {
		str = scanner.NextLine ();
		scanline.OpenString (str);

		counter++;

		while (scanline.HasNext ()) {
			string s = scanline.Next ();

			if (counter == 1)
				sentence1_.push_back (s);

			if (counter == 2)
				sentence2_.push_back (s);
		}
 	}
 }

/******************************************************************************
 * Function 'ToString'.
 * Returns:
 *   a 'string' of the two sentences and the matrix with the edit distances
**/
string EditDistance::ToString() {
	string str = "Sentence ONE:\n";

	int counter = 0;
	while (counter != length_) {
		str.append (sentence1_.at (counter) + " | ");
		counter++;
	}

	counter = 0;
	str.append ("\nSentence TWO:\n");

	while (counter != length_) {
		str.append (sentence2_.at (counter) + " | ");
		counter++;
	}

	str.append ("\n\n" + ComputeMatrix ());

	return str;
}


/*
 const int kCostDeletion = 1;
 const int kCostInsertion = 1;
 const int kCostSubstitution = 2;
 const int kDummyDistance = -1;

 // note the space in '> >' because the compiler needs it
 vector<vector<string> > dist_;
 */



string EditDistance::ComputeMatrix () {
	string s = "Distance Matrix:\n\t\t";
  vector <string> row;
  row.push_back("\t\t");
  dist_.push_back(row);

  //sentence 1
	for (int i = 0; i < length_; i++) {    
    row.push_back (sentence1_.at(i));
    dist_.push_back (row);
    row.push_back ("\t "); 
    dist_.push_back (row);
  }

  //sentence 2
  for (int j = 0; j < length_; j++) {
    row.push_back ("\n\t ");
    dist_.push_back(row);
    row.push_back (sentence2_.at(j));
    dist_.push_back (row);
    if (sentence2_.at(j).size() <= 2) {
      row.push_back ("\t\t\t"); 
    } else if (sentence2_.at(j).size() <= 4) {
      row.push_back ("\t\t"); 
    } else {
      row.push_back("\t");
    }
    dist_.push_back(row);

    //numbers after each token on sentence 2
    for (int k = 0; k < length_; k++){
      string comp = Compute (j, k);
      row.push_back (comp);
      dist_.push_back (row);
      if (comp.size() >= 2) {
        row.push_back ("\t\t");
      } else {
        row.push_back ("\t\t\t");
      }
      dist_.push_back (row);
    }
  }

  //prints out double vector
	for (int i = 0; i < dist_.size (); i++) {
		s.append (dist_.at(i).at(i));
	}

	return s;
}

string EditDistance::Compute (int one, int two) {
  string s;
  string token_one = sentence1_.at (two);
  string token_two = sentence2_.at (one);

  if (two == 0) {
    int index = one;
    s += to_string (index);
    index++;
  }
  else
    if (one == 0) {
      int index = two;
      s += to_string (index);
      index++;
    }
    else
      if (one == two) {
        if (token_one.compare (token_two) == 0)
          counter_ += 0;
        else {
          if (token_one.compare (kDummyString) == 0
           || token_two.compare (kDummyString) == 0)
            counter_ += kCostInsertion;
          else
            counter_ += kCostSubstitution;
        }
        s = to_string (counter_);
      }
      else
        if (one == (two - 1)) {
          if (token_one.compare (token_two) == 0) {
            counter_ += 0;
          }
          else
            if (token_one.compare (kDummyString) == 0
             || token_two.compare (kDummyString) == 0) {
              s = to_string (counter_);
            }
            else {
              s = to_string (counter_ + 1);
            }
        }

  return s;
}