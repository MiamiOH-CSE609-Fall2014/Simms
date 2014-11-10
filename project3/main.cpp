#include <vector>
#include <iostream>
#include <tuple>
#include <string>
#include <map>

#include "functions.h"

using namespace std;

int main(int argc, char ** argv)
{
  if(argc != 2) return -1;
  tuple<string, vector<string>, string> foo = parseFastaFile(string(argv[1]));
  //cout << argv[1] << endl;
  cout << get<0>(foo) << endl;
  vector<string> comments = get<1>(foo);
  for(int i = 0; i < comments.size(); i++)
    cout << comments[i] << endl;
  cout << get<2>(foo) << endl;

  string seq = get<2>(foo);
  map<string, int> scores = digramFreqScores(seq);
  for(map<string, int>::iterator it = scores.begin(); it != scores.end(); ++it)
    cout << it->first << " " << it->second << endl;
  return 0;
}
