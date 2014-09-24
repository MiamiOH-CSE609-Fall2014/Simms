#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector< vector<int> > matrixA;
  vector< vector<int> > matrixB;
  vector< vector<int> > matrixC;
  int Arow = 0;
  int Acol = 0;
  int Brow = 0;
  int Bcol = 0;
  int Crow = 0;
  int Ccol = 0;

  cout << "Rows for matrix A: ";
  cin >> Arow;
  cout << "Columns for matrix A: ";
  cin >> Acol;
  cout << "Rows for matrix B: ";
  cin >> Brow;
  cout << "Columns for matrix B: ";
  cin >> Bcol;

  if (Acol != Brow)
    {
      cout << "Invalid input\n";
      return 1;
    }

  Crow = Arow;
  Ccol = Bcol;

  cout << "Enter values for matrix A: " << endl;
  for(int r = 0; r < Arow; r++)
    {
      vector<int> row;
      for(int c = 0; c < Acol; c++)
	{
	  int value = 0;
	  cin >> value;
	  row.push_back(value);
	}
      matrixA.push_back(row);
    }
  
  cout << "Enter values for matrix B: " << endl;
  for(int r = 0; r < Brow; r++)
    {
      vector<int> row;
      for(int c = 0; c < Bcol; c++)
	{
	  int value = 0;
	  cin >> value;
	  row.push_back(value);
	}
      matrixB.push_back(row);
    }

  

  cout << "Printing matrix A: " << endl;
  for(int r = 0; r < Arow; r++)
    {
      for(int c = 0; c < Acol; c++)
	{
	  cout << matrixA[r].at(c) << " ";
	}
      cout << "\n";
    }

  cout << "Printing matrix B: " << endl;
  for(int r = 0; r < Brow; r++)
    {
      for(int c = 0; c < Bcol; c++)
	{
	  cout << matrixB[r].at(c) << " ";
	}
      cout << "\n";
    }

  return 0;
}
