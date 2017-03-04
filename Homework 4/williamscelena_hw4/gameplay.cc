#include "gameplay.h"

/******************************************************************************
*3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
* Class 'GamePlay' for playing part of a dominos game.
*
* Author: Duncan A. Buell
 * Modified by: Celena Williams 
* Date last modified: 21 October 2016
**/

/******************************************************************************
* Constructor
**/
GamePlay::GamePlay() {
}

/******************************************************************************
* Destructor
**/
GamePlay::~GamePlay() {
}

/******************************************************************************
* Accessors and Mutators
**/

/******************************************************************************
* General functions.
**/

/******************************************************************************
* Function 'DealDominos'.
*
* We run a loop to print out the first ten random numbers just to be able to
* check that we are getting the same sequence of numbers.
*
* Then we loop until we get 'kHandsize' number of dominos.
*
*
* Parameters:
*   out_stream - the output stream to which to write
**/
void GamePlay::DealDominos(ofstream& out_stream, int seed) {
  string str = "";
  set<int> random_numbers;

  MyRandom random;
  random = MyRandom (seed);

  for (unsigned int counter = 0; counter < 10; counter++) {
    int counter2 = random.RandomUniformInt (0,90);

    Utils::log_stream << "Random Number " << Utils::Format (counter, 4)
                      << " " << Utils::Format (counter2, 8) << endl;
  }

  while (random_numbers.size () < kHandsize) {
    int counter = random.RandomUniformInt (0, 90);
    random_numbers.insert (counter);
  }

  for (auto counter = random_numbers.begin ();
       counter !=  random_numbers.end (); counter++) {
    Domino dom = all_dominos_.at (*counter);
    all_dominos_.at (*counter).SetDealt (true);
    my_dominos_.push_back (dom);
  }

  str = "MY HAND \n";
  out_stream << ToStringSeq (str, my_dominos_) << endl << endl;

  #ifdef EBUG
  Utils::log_stream << "enter DealDominos\n"; 
  #endif

  #ifdef EBUG
  Utils::log_stream << "leave DealDominos\n"; 
  #endif
}

/******************************************************************************
* Function 'ExtendSeq'.
* This function extends the sequence.
*
* Parameters:
*   from - the number to be matched from unplayed dominos
*   seq - the current sequence of played dominos
*   level - the level of recursion on entry to this function
*   out_stream - the output stream to which to write
**/
void GamePlay::ExtendSeq(int from, const vector<Domino>& seq, int level,
  ofstream& out_stream) {
  bool use = false;
  string str = "";

  if (level > kHandsize) {
    Utils::log_stream << "ERROR!" << endl;
    exit (0);
  }

  str = "LEVEL " + Utils::Format (level, 3) + " : ";
  str.append ("FROM " + Utils::Format (from, 3) + " : ");
  Utils::log_stream << ToStringSeq (str, my_seq_) << endl;

  for (unsigned int counter = 0; counter < my_dominos_.size (); counter++) {
    use = false;

    if (my_dominos_.at (counter).HasBeenPlayed ()) {
      Utils::log_stream << "   PLAYED   " << my_dominos_.at (counter).ToString () << endl;
      continue;
    }

    if (my_dominos_.at (counter).GetLeft () == from)
      use = true;

    if (my_dominos_.at (counter).GetRight () == from) {
      my_dominos_.at (counter).FlipEnds ();
      use = true;
    }

    if (use) {
      Utils::log_stream << "   GOOD   " << my_dominos_.at (counter).ToString () << endl;

      my_dominos_.at (counter).SetPlayed (true);
      my_seq_.push_back (my_dominos_.at (counter));

      if (my_seq_.size () >= max_length) {
        max_length = my_seq_.size ();
        max_seq_ = my_seq_;

        str = "   NEW MAX   : (" + Utils::Format (max_length, 2) + ") : ";
        Utils::log_stream << ToStringSeq (str, max_seq_) << endl;
        out_stream << ToStringSeq (str, max_seq_) << endl;
      }

      level++;
      Utils::log_stream << "  RETURN ExtendSeq  " << level << endl;
      my_dominos_.at (counter).SetPlayed (false);
      my_seq_.pop_back ();
    }
    else {
      Utils::log_stream << "   NO MATCH   " << my_dominos_.at (counter).ToString () << endl;
    }
  }

  Utils::log_stream << "   Loop Ended   " << ToStringSeq ("LOOPEND", my_seq_) << endl;


  #ifdef EBUG
  Utils::log_stream << "enter extendSeq\n"; 
  #endif

  #ifdef EBUG
  Utils::log_stream << "leave ExtendSeq\n"; 
  #endif
}

/******************************************************************************
* Function 'FindLongestSeq'.
*
* Parameters:
*   out_stream - the output stream to which to write
**/
void GamePlay::FindLongestSeq(ofstream& out_stream) {
  int level = 0;

  for (unsigned int start_num = 0; start_num <= 12; start_num++) {
    out_stream << "start_num " << start_num << endl;
    max_length = 0;
    my_seq_.clear ();
    max_seq_.clear ();
    ExtendSeq (start_num, my_seq_, level, out_stream);

    int max_len = max_seq_.size ();
    string str = Utils::Format (start_num, 4) + " : !!";
    str.append (Utils::Format (max_len, 2) + "!! : ");
    out_stream << ToStringSeq (str, max_seq_) << endl << endl;
  }

  #ifdef EBUG
  Utils::log_stream << "enter FindLongestSeq\n"; 
  #endif

  #ifdef EBUG
  Utils::log_stream << "leave FindLongestSeq\n"; 
  #endif
}

/******************************************************************************
* Function 'Initialize'.
**/
void GamePlay::Initialize() {
  for (unsigned int counter = 0; counter <= kHandsize; ++counter) {
    for (unsigned int counter2 = 0; counter2 <= counter; ++counter2) {
      Domino new_domino = Domino (counter, counter2);
      all_dominos_.push_back (new_domino);
    }
  }

  #ifdef EBUG
  Utils::log_stream << "enter Initialize\n"; 
  #endif

  #ifdef EBUG
  Utils::log_stream << "leave initialize\n"; 
  #endif
}

/******************************************************************************
* Function 'ToString'.
* This function dumps the 'vector' of all dominos to a 'string' and returns it.
*
* Returns:
*   the 'ToString' of the data in the class
**/
string GamePlay::ToString() const {
  string str = "";

  str.append ("\nALL DOMINOS: ");

  for (auto counter = all_dominos_.begin (); counter != all_dominos_.end (); counter++) {
    str.append ((*counter).ToString ()) + "\n";
  }


  #ifdef EBUG
  Utils::log_stream << "enter ToString\n"; 
  #endif

  #ifdef EBUG
  Utils::log_stream << "leave ToString\n"; 
  #endif
  return str;
}

/******************************************************************************
* Function 'ToStringSeq'.
* This function dumps the 'mySeq' data to a 'string' and returns it, with a
* label for helping know what is being dumped.
*
* Returns:
*   the 'ToString' of the 'vector' of dominoes passed in to the function
**/
string GamePlay::ToStringSeq(string label, const vector<Domino>& the_seq) const {
  string str = "";

  str.append (label + " ");

  for (auto counter = the_seq.begin (); counter != the_seq.end (); counter++) {
    str.append ((*counter).ToString ());
  }

  #ifdef EBUG
  Utils::log_stream << "enter ToStringSeq\n"; 
  #endif

  #ifdef EBUG
  Utils::log_stream << "leave ToStringSeq\n"; 
  #endif
  return str;
}
