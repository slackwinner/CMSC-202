/*
File: Package.cpp
Project: CMSC 202 Project 4, Spring 2018
Author: Dane Magbuhos
Date: 4/22/18
E-mail: mag4@umbc.edu

Description: This contains the function implementations
for the Package.h file. In addition, this file serves as the
child class (i.e. This sub-carrier inherits from the mail parent class).

*/

#include "Package.h"

#include <iostream>
#include <string>

using namespace std;

Package::Package() : Mail(1,"sender","recipient",0.0,0.0)
{
  // empty body constructor
}

Package::Package(int carrier, string sender, string recipient, float size, float baseCost)
  : Mail(carrier, sender, recipient, size, baseCost)
{
  // empty overloaded body constructor
}

Package::~Package()
{
  // empty body deconstructor
}

string Package::toString()
{

  stringstream p;
  
  // Converts package object into a string object
  p << "---------------------" << endl;
  p << "Package: " << endl;
  p << "To: " << m_recipient << endl;
  p << "From " << m_sender << endl;
  p << "Weight: " << m_size << " lbs " <<  endl;
  p << "---------------------" << endl;
  p << "---------------------" << endl;

  string concatString = p.str();

  return concatString;


}
