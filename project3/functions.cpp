#include <vector>
#include <tuple>
#include <string>
#include <fstream>
#include <iostream>
#include <map>

#include "functions.h"

using namespace std;

tuple<string, vector<string>, string> parseFastaFile(string filepath)
{
  string header;
  vector<string> comments;
  string sequence;
  fstream file;
  file.open(filepath, fstream::in);
  string line;
  while(getline(file, line).good())
    {
      if(line.substr(0,1) == ">") header = line;
      else if(line.substr(0,1) == ";") comments.push_back(line);
      else sequence.append(line);
    }
  tuple<string, vector<string>, string> fasta{header, comments, sequence};
  return fasta;
}

map<string, int> digramFreqScores(string s)
{
  string digrams[16] = {"AA", "AT", "AC", "AG", "TA", "TT", "TC", "TG", "CA", "CT", "CC", "CG", "GA", "GT", "GC", "GG"};
  int counters[16] = {};
  map<string, int> scores;
  for(int i = 0; i < s.length() - 1; i++)
    {
      if(s.substr(i,2) == digrams[0]) { counters[0]++; scores[ digrams[0] ] = counters[0]; }
      else if(s.substr(i,2) == digrams[1]) { counters[1]++; scores[ digrams[1] ] = counters[1]; }
      else if(s.substr(i,2) == digrams[2]) { counters[2]++; scores[ digrams[2] ] = counters[2]; }
      else if(s.substr(i,2) == digrams[3]) { counters[3]++; scores[ digrams[3] ] = counters[3]; }
      else if(s.substr(i,2) == digrams[4]) { counters[4]++; scores[ digrams[4] ] = counters[4]; }
      else if(s.substr(i,2) == digrams[5]) { counters[5]++; scores[ digrams[5] ] = counters[5]; }
      else if(s.substr(i,2) == digrams[6]) { counters[6]++; scores[ digrams[6] ] = counters[6]; }
      else if(s.substr(i,2) == digrams[7]) { counters[7]++; scores[ digrams[7] ] = counters[7]; }
      else if(s.substr(i,2) == digrams[8]) { counters[8]++; scores[ digrams[8] ] = counters[8]; }
      else if(s.substr(i,2) == digrams[9]) { counters[9]++; scores[ digrams[9] ] = counters[9]; }
      else if(s.substr(i,2) == digrams[10]) { counters[10]++; scores[ digrams[10] ] = counters[10]; }
      else if(s.substr(i,2) == digrams[11]) { counters[11]++; scores[ digrams[11] ] = counters[11]; }
      else if(s.substr(i,2) == digrams[12]) { counters[12]++; scores[ digrams[12] ] = counters[12]; }
      else if(s.substr(i,2) == digrams[13]) { counters[13]++; scores[ digrams[13] ] = counters[13]; }
      else if(s.substr(i,2) == digrams[14]) { counters[14]++; scores[ digrams[14] ] = counters[14]; }
      else if(s.substr(i,2) == digrams[15]) { counters[15]++; scores[ digrams[15] ] = counters[15]; }

    }
  return scores;
}
