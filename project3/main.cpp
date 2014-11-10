#include <vector>
#include <iostream>
#include <tuple>
#include <string>

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
  return 0;
}
