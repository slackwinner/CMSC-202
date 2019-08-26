#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>
#include <string>
using namespace std;

static const int MAX_NO_OF_SUBJECT =4;

class Registration {
 public: 
  //Overloaded Constructor
  //**Notice** this constructor has a name and capacity with default values, therefore, 
  //a default constructor is not required (and it will cause a ambiguity error)
  Registration(string name ="John Doe", int capacity = MAX_NO_OF_SUBJECT);
  
  //Copy Constructor
  Registration(const Registration& source);
  
  //Overloaded Assignment Operator
  Registration& operator=(const Registration& source);
  
  //Destructor
  ~Registration();

  //Inserts a subject to the registration
  void insert(const string& subjectName);
  
  //Friend Function that is an overloaded << operator
  friend ostream& operator<<(ostream& os, const Registration& rg); //Overloaded << Operator
 private:
  string m_name;
  int m_capacity;
  int m_used;
  string* m_subjectArray;
};

#endif // REGISTRATION_H
