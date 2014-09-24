#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // Setup and initialization
  vector< vector<int> > matrixA;
  vector< vector<int> > matrixB;
  vector< vector<int> > matrixC;
  int Arow = 0;
  int Acol = 0;
  int Brow = 0;
  int Bcol = 0;
  int Crow = 0;
  int Ccol = 0;

  // For purposes of manual testing, prompts were used for cleaner input
  // For automatic testing (and for final turn in) prompts will be commented out.
  // cout << "Rows for matrix A: ";
  cin >> Arow;
  // cout << "Columns for matrix A: ";
  cin >> Acol;
  // cout << "Rows for matrix B: ";
  cin >> Brow;
  // cout << "Columns for matrix B: ";
  cin >> Bcol;

  // Test for bad input; If rows for matrix A and rows for matrix B do not match, stop and return 1
  if (Acol != Brow)
    {
      cout << "Invalid input\n";
      return 1;
    }

  // Assign rows and columns for new matrix (C)
  Crow = Arow;
  Ccol = Bcol;

  /*
    Input algorithm:
    2D vectors were declared at start of program. Since a 2D vector is a vector of vectors, 
    each row vector is populated using STDIN and push_back()
    The row vectors are then added to the matrix with push_back()
   */

  // Input for matrix A. Prompts commented out for final turn in.
  // cout << "Enter values for matrix A: " << endl;
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
  
  // Input for matrix B. Prompts commented out for final turn in.
  // cout << "Enter values for matrix B: " << endl;
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

  /*
    Multiplication algorithm:
    New matrix has rows and columns Crow and Ccol (init above)
    As before, row vectors are declared and populated with column values
    Column values are computed by finding the sum of products of A row and B col
    sum is pushed back onto the row vector
    row is added to resulting matrix with push_back()
   */
 
  // Create product matrix
  for(int r = 0; r < Crow; r++)
    {
      vector<int> row;
      for(int c = 0; c < Ccol; c++)
	{
	  int sum = 0;
	  for(int i = 0; i < Acol; i++)
	    {
	      sum += matrixA[r].at(i)*matrixB[i].at(c);
	    }
	  row.push_back(sum);
	}
      matrixC.push_back(row);
    }
  
  // Printing. Prompts commented out for final turn in
  // cout << "Printing matrix A: " << endl;
  for(int r = 0; r < Arow; r++)
    {
      for(int c = 0; c < Acol; c++)
	{
	  cout << matrixA[r].at(c) << " ";
	}
      cout << "\n";
    }
  // Newline added for clarity
  // cout << "\n";

  // cout << "Printing matrix B: " << endl;
  for(int r = 0; r < Brow; r++)
    {
      for(int c = 0; c < Bcol; c++)
	{
	  cout << matrixB[r].at(c) << " ";
	}
      cout << "\n";
    }
  // Newline added for clarity
  // cout << "\n";

  // cout << "Printing matrix C: " << endl;
  for(int r = 0; r < Crow; r++)
    {
      for(int c = 0; c < Ccol; c++)
	{
	  cout << matrixC[r].at(c) << " ";
	}
      cout << "\n";
    }
  return 0;
}
