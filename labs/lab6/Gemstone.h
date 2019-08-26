#ifndef GEMSTONE_H
#define GEMSTONE_H

#include <iostream>
#include <string>

using namespace std;

class Gemstone
{
 public:
  // Constructor should ask for user input and initialize array
  Gemstone();
  ~Gemstone();
  // Go through dynamically allocated array
  void Display();
 private:
  // number of gemstone in the collection
  int m_num;
  // dynamically allocated array of gemstones
  string *m_ptr;
};

#endif
