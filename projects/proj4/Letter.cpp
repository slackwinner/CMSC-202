/*
File: Letter.cpp
Project: CMSC 202 Project 4, Spring 2018
Author: Dane Magbuhos
Date: 4/22/18
E-mail: mag4@umbc.edu

Description: This contains the function implementations
for the Letter.h file. In addition, this file serves as the
child class (i.e. This sub-carrier inherits from the mail parent class).

*/

#include "Mail.h"
#include "Letter.h"

#include <iostream>
#include <string>

using namespace std;

Letter::Letter(): Mail(0,"sender","recipient",0.0,0.0)
{
  // empty constructor body
}

Letter::Letter(int carrier, string sender, string recipient, float size, float baseCost)
  : Mail(carrier, sender, recipient, size, baseCost)
{
  // empty overloaded body constructor
}

Letter::~Letter()
{
  // empty body deconstructor
}

string Letter::toString()
{
  stringstream l;

  // Formats letter object into a string object
  l << "---------------------" << endl;
  l << "Letter" << endl;
  l << "To: " << m_recipient << endl;
  l << "From: " << m_sender << endl;
  l << "Size: " << m_size << " square inches " << endl;
  l << "---------------------" << endl;
  l << "---------------------" << endl;

  string concatString = l.str();
  
  return concatString;
}
