/*
File: Package.h
Project: CMSC 202 Project 4, Spring 2018
Author: Dane Magbuhos
Date: 4/22/18
E-mail: mag4@umbc.edu

Description: This contains the prototypes and member
variables needed to create a package object.

*/

#ifndef PACKAGE_H
#define PACKAGE_H

#include "Mail.h"
#include "Package.h"

class Package:public Mail{
 public:
  // Default Constructor
  // Preconditions: None
  // Postconditions: None
  Package();
  
  // Overloaded Constructor
  // Preconditions: valid inputs
  // Postconditions: None
  Package(int, string, string, float, float);
  
  // Destructor
  // Preconditions: Allocated object
  // Postconditions: Deallocates object from memory
  ~Package();
  
  // toString() - Converts the Package object to a string object
  // Preconditions: A valid Package object
  // Postconditions: returns a string representation of a Package
  string toString();
  
};


#endif
