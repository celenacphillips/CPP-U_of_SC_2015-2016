#include "main.h"

/******************************************************************************
*3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
* Homework 3 main program.
*
* This program reads a sequence of phone book records and provides for
* output in two sorted orders.
*
* Author: Duncan A. Buell
* Modified by: Celena Williams
* Date last modified: 21 October 2016
**/
static const string kTag = "MAIN:\t\t\t\t";

int main(int argc, char *argv[])
{
  string data_filename = "";
  string out_filename = "";
  string log_filename = "";
  ofstream out_stream;

  Scanner data_stream;

  DoTheWork do_the_work;

  Utils::CheckArgs(3, argc, argv, "datafilename outfilename logfilename");
  data_filename = static_cast<string>(argv[1]); // DO NOT USE OLD CAST!
  out_filename = static_cast<string>(argv[2]);
  log_filename = static_cast<string>(argv[3]);

  Utils::LogFileOpen(log_filename);

  Utils::log_stream << kTag << "Beginning execution\n";
  Utils::log_stream.flush();

  Utils::FileOpen(out_stream, out_filename);

  Utils::log_stream << kTag << "datafile  '" << data_filename << "'\n";
  Utils::log_stream << kTag << "outfile '" << out_filename << "'\n";
  Utils::log_stream << kTag << "logfile '" << log_filename << "'\n";

  data_stream.OpenFile(data_filename);
  do_the_work.ReadData(data_stream);

  out_stream << "RAW DATA\n" << do_the_work.ToString() << endl;
  out_stream.flush();

  out_stream << "BY NAME\n" << do_the_work.ToStringByName() << endl;
  out_stream.flush();

  out_stream << "BY NUMBER (Reversed Order)\n" << do_the_work.ToStringByNumber() << endl;
  out_stream.flush();

  Utils::FileClose(out_stream);

  Utils::log_stream << kTag << "Ending execution\n";
  Utils::log_stream.flush();

  Utils::FileClose(Utils::log_stream);

  return 0;
}
