#include <vector>
#include <tuple>
#include <string>
#include <fstream>
#include <iostream>

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
      cout << line.substr(0,1) << " ";
      cout << line.substr(0,1).compare(";") << endl;
      if(line.substr(0,1).compare(">") == 0) header = line;
      else if(line.substr(0,1) == ";") comments.push_back(line);
      else sequence.append(line);
    }
  tuple<string, vector<string>, string> fasta{header, comments, sequence};
  return fasta;
}
