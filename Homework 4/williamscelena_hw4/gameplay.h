/****************************************************************
 * Header file for the class to find sequences in a domino game.
 *
 * Author/copyright:  Duncan Buell
 * Date: 6 August 2016
 *
**/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <set>
#include <vector>
using namespace std;

#include "domino.h"
#include "myrandom.h"

#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class GamePlay {
public:
 GamePlay();
 virtual ~GamePlay();

 void DealDominos(ofstream& out_stream, int seed);
 void Initialize();
 void FindLongestSeq(ofstream& out_stream);
 string ToString() const;
 string ToStringSeq(string label, const vector<Domino>& the_seq) const;

private:
 const int kHandsize = 12;
 int max_length;

 vector<Domino> all_dominos_;
 vector<Domino> my_dominos_;
 vector<Domino> max_seq_;
 vector<Domino> my_seq_;

 void ExtendSeq(int from, const vector<Domino>& seq,
                int level, ofstream& out_stream);
};

#endif
