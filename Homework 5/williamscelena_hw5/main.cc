#include "main.h"

/****************************************************************
 * Main program for Homework 5.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Modified by: Celena Williams
 * Date: 26 November 2016
 *
**/

static const string TAG = "Main: ";

int main(int argc, char *argv[]) {
  string in_filename = "";
  string out_filename = "";
  string log_filename = "";
  ofstream out_stream;

  Scanner scanner;
  EditDistance edit_distance;

  Utils::CheckArgs(3, argc, argv, "infilename outfilename logfilename");
  in_filename = static_cast<string>(argv[1]);
  out_filename = static_cast<string>(argv[2]);
  log_filename = static_cast<string>(argv[3]);

  Utils::LogFileOpen(log_filename);
  Utils::FileOpen(out_stream, out_filename);

  Utils::log_stream << TAG << "Beginning execution\n";
  Utils::log_stream.flush();

  Utils::log_stream << TAG << "infile  '" << in_filename << "'\n";
  Utils::log_stream << TAG << "outfile '" << out_filename << "'\n";
  Utils::log_stream << TAG << "logfile '" << log_filename << "'\n";

  scanner.OpenFile(in_filename);
  edit_distance.Initialize(scanner);
  scanner.Close();
  edit_distance.ComputeDistances();

  out_stream << "Distances\n" << edit_distance.ToString() << endl;
  out_stream.flush();

  Utils::log_stream << TAG << "Ending execution\n";
  Utils::log_stream.flush();

  Utils::FileClose(out_stream);
  Utils::FileClose(Utils::log_stream);

  return 0;
}
