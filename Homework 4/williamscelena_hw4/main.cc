#include "main.h"

/****************************************************************
 * Main program for Homework 4.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Modified  by: Celena Williams
 * Date: 8 October 2016
 *
**/

static const string kTag = "MAIN: ";

int main(int argc, char *argv[]) {
  int seed = 1;
  string seed_filename = "";
  string out_filename = "";
  string log_filename = "";

  Scanner seed_scanner;
  ofstream out_stream;

  GamePlay game;

  Utils::CheckArgs(3, argc, argv, "seedfilename outfilename logfilename");
  seed_filename = static_cast<string>(argv[1]);
  out_filename = static_cast<string>(argv[2]);
  log_filename = static_cast<string>(argv[3]);

  Utils::LogFileOpen(log_filename);
  Utils::FileOpen(out_stream, out_filename);
  seed_scanner.OpenFile(seed_filename);

  Utils::log_stream << kTag << "Beginning execution\n";
  Utils::log_stream.flush();

  Utils::log_stream << kTag << "outfile '" << out_filename << "'\n";
  Utils::log_stream << kTag << "logfile '" << log_filename << "'\n";

  if (seed_scanner.HasNext()) {
    seed = seed_scanner.NextInt();
  }
  out_stream << kTag << "RN seed is " << seed << endl << endl;

  game.Initialize();
  game.DealDominos(out_stream, seed);
  game.FindLongestSeq(out_stream);

  Utils::log_stream << kTag << "Ending execution\n";
  Utils::log_stream.flush();

  Utils::FileClose(out_stream);
  Utils::FileClose(Utils::log_stream);

  return 0;
}
