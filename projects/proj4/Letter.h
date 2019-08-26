/*
File: Letter.h
Project: CMSC 202 Project 4, Spring 2018
Author: Dane Magbuhos
Date: 4/22/18
E-mail: mag4@umbc.edu

Description: This contains the prototypes and member
variables needed to create a letter object.

*/

#ifndef LETTER_H
#define LETTER_H

#include "Mail.h"

class Letter:public Mail{
 public:
  // Default Constructor
  // Preconditions: None
  // Postconditions: None
  Letter();
  
  // Overloaded Constructor
  // Preconditions: Valid inputs
  // Postconditions: None
  Letter(int, string, string, float, float);
  
  // Destructor
  // Preconditions: A letter object allocated in memory
  // Postconditions: Deallocates the object in memory
  ~Letter();
  
  // toString() - method to format the Letter object as a string
  // Preconditions: A Letter object
  // Postconditions: returns the letter object as a string
  string toString();
  
};

#endif
