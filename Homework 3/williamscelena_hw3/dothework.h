/****************************************************************
 * Homework 3 header file for the application class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 5 August 2016
 *
**/

#ifndef DOTHEWORK_H
#define DOTHEWORK_H

#include <iostream>
#include <vector>
using namespace std;

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

#include "record.h"

class DoTheWork
{
public:
 DoTheWork();
 virtual ~DoTheWork();

 void ReadData(Scanner& data_stream);
 string ToString();
 string ToStringByName();
 string ToStringByNumber();

private:
 vector<Record> the_data_;

 void SortRecords(string how_sort);
 void Swap(int i, int j);
};

#endif
