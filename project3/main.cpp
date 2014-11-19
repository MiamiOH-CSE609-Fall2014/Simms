#include <vector>
#include <iostream>
#include <tuple>
#include <string>
#include <map>
#include <utility>

#include "functions.h"

using namespace std;

int main(int argc, char ** argv)
{
  if(argc != 3)
    {
      cout << "Must include FASTA and csv scoring file" << endl;
      return -1;
    }
  cout << argv[0] << " " << argv[1] << " " << argv[2] << endl;
  tuple<string, vector<string>, string> fasta = parseFastaFile(string(argv[1]));
  string sequence = get<2>(fasta);
  map<string, int> scores = digramFreqScores(sequence);
  vector< vector<int> > freqMatrix = digramFreqMatrix(scores);

  string header = "   A  G  C  T";
  string header2 = "   A G C T";
  vector<string> heads = {"A","G","C","T"};
  cout << "\t\tDigram Frequency Matrix:" << endl;
  cout << "\t\t" << header << endl;
  for(int r = 0; r < 4; r++)
    {
      cout << "\t\t" << heads[r] << "  ";
      for(int c = 0; c < 4; c++)
	{
	  cout << freqMatrix[r][c] << " ";
	}
      cout << "\n";
    }
  vector< vector<int> > scoreMatrix = parseScoringFile(string(argv[2]));

  cout << "\n\t\tScoring Matrix:" << endl;
  cout << "\t\t" << header2 << endl;
  for(int r = 0; r < 4; r++)
    {
      cout << "\t\t" << heads[r] << "  ";
      for(int c = 0; c < 4; c++)
	{
	  cout << scoreMatrix[r][c] << " ";
	}
      cout << "\n";
    }
  cout << "\n";

  int num_seq;
  vector<string> seqs;
  string line;
  cout << "How many sequences would you like to score? ";
  cin >> num_seq;
  for(int i = 0; i < num_seq; i++)
    {
      cout << "Enter sequence #" << i + 1 << " on a single line:" << endl;
      cin >> line;
      seqs.push_back(line);
    }
  cout << "\n";

  pair<int, int> tmp;
  for(int i = 0; i < num_seq; i++)
    {
      tmp = scoreSequence(sequence, seqs[i], scoreMatrix);
      cout << "Sequence: " << seqs[i] << endl;
      cout << "Score: " << tmp.second << " at position " << tmp.first << endl;
      cout << "\n";
    }
  cout << "\n";

  tuple<int, int, string> highScore = findHighScore(sequence, seqs, scoreMatrix);
  cout << "Highest score: " << get<2>(highScore) << " with score " << get<1>(highScore) << " at position " << get<0>(highScore) << endl;
  cout << "\n"; 

  return 0;
}
