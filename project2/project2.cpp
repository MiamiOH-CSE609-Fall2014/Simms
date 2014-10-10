#include <iostream>
#include <stdio.h>
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
 do
    {
      cout << "Enter student name (enter none to quit): ";
      getline(cin,name);
      students.push_back(Student(name, score, grade));
    }while(name.compare("none"));
 students.pop_back();

 for(int i = 0; i < students.size(); i++)
   {
     cout << students[i].name << endl;
   }
  return 0;
}

float getScore()
{

}
