/****************************************************************
 * Header file for the phone book record for homework 3.
 *
 * Author/copyright:  Duncan Buell
 * Date: 5 August 2016
 *
**/

#ifndef RECORD_H
#define RECORD_H

#include <iostream>
using namespace std;

#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class Record
{
public:
 Record();
 virtual ~Record();

 int CompareName(Record that);
 int CompareNumber(Record that);
 string GetSurname();
 string GetPhoneNumber();
 void ReadData(Scanner& data_stream);
 string ToString();

 string forename_ = "";
 string othername_ = "";
 string surname_ = "";
 string phone_number_ = "";
};

#endif
