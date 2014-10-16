#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <cmath>

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
float calcMean(vector<Student>);
float calcStdDev(vector<Student>, float);
void setGrade(vector<Student>&, float, float);
void printScale(float, float);
void printStudents(vector<Student>);

int main()
{ 
  vector<Student> students;

  string name = "";
  float score = 0.0;
  char grade = 'A';
  float mean = 0.0;
  float stdev = 0.0;

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
  mean = calcMean(students);
  stdev = calcStdDev(students, mean);
  setGrade(students, mean, stdev);
  
  printScale(mean, stdev);
  printStudents(students);
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
	score = getScore();
	//	score = 0.0;
    }
  return score;
}

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

void printStudents(vector<Student> s)
{
  //cout << "Name" << setw(50) << "Score" << setw(10) << "Grade" << endl;
  printf("Name\t\t\t\t\tGrade\t\tScore\n");
  for (int i = 0; i < s.size(); i++)
    {
      // cout << i + 1 << ". " << s[i].name << setw(50) << fixed << s[i].score
      printf("%d. %-35s%.1f%%\t\t%c\n", i + 1, s[i].name.c_str(), s[i].score, s[i].grade);
    }
}
