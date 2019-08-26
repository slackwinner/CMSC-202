#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal{

 public:
  void setMakeSound(string sound);
  void setName(string name);
  string getMakeSound();
  string getName();
  void WhoAmI();


 private:
  string m_makeSound;
  string m_name;

};

#endif
