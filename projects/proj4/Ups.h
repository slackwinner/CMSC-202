/*
File: Ups.h
Project: CMSC 202 Project 4, Spring 2018
Author: Dane Magbuhos
Date: 4/22/18
E-mail: mag4@umbc.edu

Description: This contains the prototypes and member
variables needed to create a UPS carrier.

*/

#ifndef UPS_H
#define UPS_H

#include "Carrier.h"

class Ups : public Carrier{
public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Ups();

  // Destructor
  // Preconditions: An allocated object in memory
  // Postconditions: Deallocates the memory
  ~Ups();

  // contents() - displays the mail items in UPS object
  // Preconditions: mail present in m_storage
  // Postconditions: outputs data and returns a status # (0 - fail, 1 - success)
  int contents();

  // deliver() - performs the actions of delivering as a UPS object
  // Preconditions: mail present in m_storage
  // Postconditions: outputs delivered data and returns a status # (0 - fail, 1 - success)
  int deliver();

private:
  // toString() - method to format the object as a string
  // Preconditions: a valid UPS object
  // Postconditions: returns the UPS object as a string
  ostream& print(ostream&) const;

};

#endif
