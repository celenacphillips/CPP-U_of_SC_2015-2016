#include "record.h"

/******************************************************************************
*3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
* Class 'Record' for a single phone book record in a tree.
*
* Author: Duncan A. Buell
* Modified by: Celena Williams
* Date last modified: 21 October 2016
**/

static const string kTag = "Record:\t\t\t";

/******************************************************************************
* Constructor
**/
Record::Record() {
}

/******************************************************************************
* Destructor
**/
Record::~Record() {
}

/******************************************************************************
* Accessors and Mutators
**/
/******************************************************************************
* Accessor for 'phone_number_'
*
* Returns:
*   'phone_number_'
**/
string Record::GetPhoneNumber() {
  return phone_number_;
}

/******************************************************************************
* Accessor for 'surname_'
*
* Returns:
*   'surname_'
**/
string Record::GetSurname() {
  return surname_;
}

/******************************************************************************
* General functions.
**/

/******************************************************************************
* Comparison function for 'phone_number_'
*
* Parameter:
*   that - the 'Record' to compare 'this' against
*
* Returns:
*   negative number if 'this' is less than 'that'
*   zero number if 'this' is equal to 'that'
*   positive number if 'this' is greater than 'that'
**/
int Record::CompareNumber(Record that) {
  if (that.GetPhoneNumber () > phone_number_) {
    return -1;
  }

  if (that.GetPhoneNumber () < phone_number_) {
    return +1;
  }

  if (that.GetPhoneNumber () == phone_number_) {
    return 0;
  }
}

/******************************************************************************
* Comparison function for 'surname_'
*
* Parameter:
*   that - the 'Record' to compare 'this' against
*
* Returns:
*   true if 'this' Record 'surname_' is less than 'that' Record 'surname_'
**/
int Record::CompareName(Record that) {
  if (that.GetSurname () > surname_) {
    return -1;
  }

  if (that.GetSurname () < surname_) {
    return +1;
  }

  if (that.GetSurname () == surname_) {
    return 0;
  }
}

/******************************************************************************
* Function 'ReadData'.
*
* We read the distinct lines of input data. Each line is a label
* of the item, the number bought, and the cost per item.
*
* THERE IS NO BULLETPROOFING OF THE INPUT DATA.
*
* Parameter:
*   data_stream - the opened 'Scanner' to read from
**/
void Record::ReadData(Scanner& data_stream) {
  vector<string> tokens;
  ScanLine scanline;
  string str = data_stream.NextLine ();

  scanline.OpenString (str);

  while (scanline.HasNext ()) {
    string s = scanline.Next ();
    tokens.push_back (s);
  }

  int size = tokens.size () - 1;
  assert (size <= 3);

  forename_ = "";
  othername_ = "";
  surname_ = "";
  phone_number_ = "";

  if (size <= 3) {
    forename_ = tokens.at (0);
    othername_ = "";
    surname_ = tokens.at (1);
    phone_number_ = tokens.at (2);
  }
  else {
    int newSize = size - 1;
    forename_ = tokens.at (0);

    for (unsigned int counter = 1; counter <= newSize - 2; counter++) {
      othername_.append (" " + tokens.at (counter));
    }

    surname_ = tokens [newSize - 1];
    phone_number_ = tokens [newSize];
  }

  #ifdef EBUG
  Utils::log_stream << kTag << "enter ReadData\n"; 
  #endif

  #ifdef EBUG
  Utils::log_stream << kTag << "leave readData\n"; 
  #endif
} // void Record::readData(Scanner& data_stream)

/******************************************************************************
* Function 'ToString'.
* This is the usual 'ToString' that returns the formatted data in the class.
**/
string Record::ToString() {
  string str = "";

  str.append (forename_);
  str.append (" " + surname_);
  str.append (" " + phone_number_);
  str.append ("\n");

  return str;
} // void Record::ToString()
