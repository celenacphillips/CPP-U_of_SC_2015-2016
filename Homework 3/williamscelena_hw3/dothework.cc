#include "dothework.h"

/******************************************************************************
*3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
* Homework 3 'DoTheWork' application class.
*
* Author: Duncan A. Buell
* Modified by: Celena Williams
* Date last modified: 21 October 2016
**/

static const string kTag = "DoTheWork:\t";
Record record;

/******************************************************************************
* Constructor
**/
DoTheWork::DoTheWork() {
}

/******************************************************************************
* Destructor
**/
DoTheWork::~DoTheWork() {
}

/******************************************************************************
* Accessors and Mutators
**/

/******************************************************************************
* General functions.
**/

/******************************************************************************
* Function 'ReadData'.
* We read data from the input stream, record by record, and push it into
* the 'vector' named 'the_data_'.
*
* NOTE: We are assuming that if there is any data, there is an entire record,
* so we can just read the entire record as a unit. 
*
* Parameter:
*   data_stream -- the input data stream
**/
void DoTheWork::ReadData(Scanner& data_stream) {
  while (data_stream.HasNext ()) {
    record.ReadData (data_stream);
    the_data_.push_back (record);
  }

  #ifdef EBUG
  Utils::log_stream << kTag << "enter ReadData\n"; 
  #endif

  #ifdef EBUG
  Utils::log_stream << kTag << "leave ReadData\n"; 
  #endif
} // void DoTheWork::ReadData(Scanner& data_stream)

/******************************************************************************
* Function 'SortRecords'.
* We sort the records either by 'surname_' or by 'phone_number_'.
*
* This is a simple bubble sort.
*
* Parameter:
*   how_sort -- either the string 'name' or 'number'
**/

void DoTheWork::SortRecords(string how_sort) {
  int size = the_data_.size ();

  for (unsigned int counter = 0; counter <= size - 1; counter++) {
    Record temp_record = the_data_.at (counter);

    for (unsigned int counter2 = counter; counter2 < size; counter2++) {
      Record temp_record2 = the_data_.at (counter2);

      if (how_sort == "name") {
        if (temp_record.CompareName (temp_record2) > 0)
          Swap (counter, counter2);
        }

        if (how_sort == "number") {
          if (temp_record.CompareNumber (temp_record2) < 0)
            Swap (counter, counter2);
      }
    }
  }

  if (how_sort != "name" && how_sort != "number") {
    Utils::log_stream << "ERROR!";
    exit (0);
  }

  #ifdef EBUG
  Utils::log_stream << kTag << "enter SortRecords\n"; 
  #endif

  #ifdef EBUG
  Utils::log_stream << kTag << "leave SortRecords\n"; 
  #endif
} // void DoTheWork::SortRecords(string howSort)

/******************************************************************************
* Swap function, swaps subscripts 'one' and 'two' data in 'the_data_'
**/
void DoTheWork::Swap(int one, int two) {
  Record temp_record = the_data_.at (one);
  the_data_.at (one) = the_data_.at (two);
  the_data_.at (two) = temp_record;
} // void Swap(int one, int two) {

/******************************************************************************
* Function 'ToString'.
* This is the usual 'ToString'. We output the 'vector' of 'Record'
* instances without regard to the order.
*
* Returns:
*   a formatted 'string' version of the 'vector' of records
**/
string DoTheWork::ToString() {
  string str = "";

  if (the_data_.size () == 0) {
    str.append ("Empty!");
    exit (0);
  }
  else {
    for (unsigned int counter = 0; counter < the_data_.size (); counter++) {
      Record temp_record = the_data_.at (counter);

      str.append (temp_record.ToString ());
    }
  }

  #ifdef EBUG
  Utils::log_stream << kTag << "enter ToString\n"; 
  #endif

  #ifdef EBUG
  Utils::log_stream << kTag << "leave ToString\n"; 
  #endif
  return str;
} // void DoTheWork::ToString()

/******************************************************************************
* Function 'ToStringByName'.
*
* First we sort the data by name, then we call the regular 'ToString'.
*
* Returns:
*   a string of the records output in sorted order by name
**/
string DoTheWork::ToStringByName() {
  SortRecords ("name");

  #ifdef EBUG
  Utils::log_stream << kTag << "enter ToStringByName\n"; 
  #endif

  #ifdef EBUG
  Utils::log_stream << kTag << "leave ToStringByName\n"; 
  #endif

  return ToString ();
} // void DoTheWork::ToStringByName()

/******************************************************************************
* Function 'ToStringByNumber'.
*
* First we sort the data by number, then we call the regular 'ToString'.
*
* Returns:
*   a string of the records output in sorted order by number
**/
string DoTheWork::ToStringByNumber() {
  SortRecords ("number");

  #ifdef EBUG
  Utils::log_stream << kTag << "enter ToStringByNumber\n"; 
  #endif

  #ifdef EBUG
  Utils::log_stream << kTag << "leave ToStringByNumber\n"; 
  #endif

  return ToString ();
} // void DoTheWork::ToStringByNumber()
