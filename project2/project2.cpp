#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

/*
struct Student
contains name, score, and grade for each student entered
*/

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
float calcMean(vector<Student>);
float calcStdDev(vector<Student>, float);
void setGrade(vector<Student>&, float, float);
void printScale(float, float);
void printStudents(vector<Student>);

int main()
{ 
  /*
    Initialization
  */

  vector<Student> students;

  string name = "";
  float score = 0.0;
  char grade = 'A';
  float mean = 0.0;
  float stdev = 0.0;

  /*
    Main loop
    Allows user to enter student names until 'none' is entered
    Note: 'none' is case sensitive
    Calls getScore() for error checking
  */
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

  /*
    Calculations using functions defined below main
    Printing using functions defined below main
  */
  mean = calcMean(students);
  stdev = calcStdDev(students, mean);
  setGrade(students, mean, stdev);
  
  printScale(mean, stdev);
  printStudents(students);
  return 0;
}

/*
float getScore()
Uses recursive calls for range error checking;
does not check for character or string inputs

returns score
*/

float getScore()
{
  float score;
  string str;
  try
    {
      cout << "Enter student's score (0 to 100): ";
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
	score = getScore();
    }
  return score;
}

/*
float calcMean(vector<Student>)
determines the mean of student scores mathematically

returns mean
*/

float calcMean(vector<Student> s)
{
  float mean;
  for (int i = 0; i < s.size(); i++)
    {
      mean += s[i].score;
    }
  mean = mean / s.size();
  return mean;
}

/*
float calcStdDev(vector<Student>, float)
determines the standard deviation of student scores mathematically
uses mean as input to avoid excess looping

returns stdev
*/

float calcStdDev(vector<Student> s, float mean)
{
  float stdev;
  float ss;
  for (int i = 0; i < s.size(); i++)
    {
      ss += pow(s[i].score - mean, 2);
    }
  stdev = sqrt(ss / s.size());
  return stdev;
}

/*
void setGrade(vector<Student>&, float, float)
sets the grade for each student based on input mean and standard deviation

*/

void setGrade(vector<Student> &s, float mean, float stdev)
{
  for (int i = 0; i < s.size(); i++)
    {
      if (s[i].score > mean + 1.5*stdev)
	s[i].grade = 'A';
      else if (s[i].score <= mean + 1.5*stdev && s[i].score > mean + 0.5*stdev)
	s[i].grade = 'B';
      else if (s[i].score <= mean + 0.5*stdev && s[i].score > mean - 0.5*stdev)
	s[i].grade = 'C';
      else if (s[i].score <= mean - 0.5*stdev && s[i].score > mean - 1.5*stdev)
	s[i].grade = 'D';
      else
	s[i].grade = 'F';
    }
}

/*
void printScale(float, float)
prints the grading scale
also prints the mean and standard deviation
*/

void printScale(float mean, float stdev)
{
  printf("\n\tGrading Scale\n");
  printf("A    above %.1f%%\n", mean + 1.5*stdev);
  printf("B    %.1f%% - %.1f%%\n", mean + 0.5*stdev, mean + 1.5*stdev);
  printf("C    %.1f%% - %.1f%%\n", mean - 0.5*stdev, mean + 0.5*stdev);
  printf("D    %.1f%% - %.1f%%\n", mean - 1.5*stdev, mean - 0.5*stdev);
  printf("F    below %.1f%%\n", mean - 1.5*stdev);
  printf("     Mean: %.1f%%\n", mean);
  printf("     Standard Deviation: %.1f%%\n", stdev);
}

/*
void printStudents(vector<Student>)
prints student names, grades, and scores in a nicely formatted string
*/

void printStudents(vector<Student> s)
{
  printf("Name\t\t\t\t\tGrade\t\tScore\n");
  for (int i = 0; i < s.size(); i++)
    {
      printf("%d. %-35s%.1f%%\t\t%c\n", i + 1, s[i].name.c_str(), s[i].score, s[i].grade);
    }
}
