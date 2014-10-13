#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <stdexcept>
#include <vector>


using namespace std;

struct Student
{
  string name;
  float score;
  char grade;

  Student(string n, float s, char g)
  {
    name = n;
    score = s;
    grade = g;
  }
};

float getScore();

int main()
{ 
  vector<Student> students;

  string name = "";
  float score = 0.0;
  char grade = 'A';
  while(true)
    {
      cout << "Enter student name (enter none to quit): ";
      getline(cin, name);
      if(name.compare("none") == 0)
	{
	  break;
	}
      cin.clear();
      cin.sync();
      score = getScore();
      students.push_back(Student(name, score, grade));
    }
  //students.pop_back();

 for(int i = 0; i < students.size(); i++)
   {
     cout << students[i].name << "\t" << students[i].score << endl;
   }
  return 0;
}

float getScore()
{
  float score;
  string str;
  try
    {
      cout << "Enter student's score (0 to 100): ";
      // cin >> score;
      // score = atof(getline(cin,str).c_str());
      getline(cin,str);
      score = atof(str.c_str());
      if (score < 0 || score > 100)
	{
	  throw out_of_range("Score must be a number between 0 and 100");
	}
    }
  catch(out_of_range e)
    {
	cout << e.what() << endl;
	cin.clear();
	cin.sync();
	//score = getScore();
	score = 0.0;
    }
  return score;
}
