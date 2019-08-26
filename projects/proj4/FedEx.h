/*
File: FedEx.h
Project: CMSC 202 Project 4, Spring 2018
Author: Dane Magbuhos
Date: 4/22/18
E-mail: mag4@umbc.edu

Description: This contains the prototypes and member
variables needed to create a FedEx carrier.

*/

#ifndef FEDEX_H
#define FEDEX_H

#include "Carrier.h"

class FedEx : public Carrier{
public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  FedEx();
  
  // Destructor
  // Preconditions: An allocated object in memory
  // Postconditions: Deallocates the memory
  ~FedEx();

  // contents()
  // Preconditions: mail present in m_storage
  // Postconditions: outputs data and returns a status # (0 - fail, 1 - success)
  int contents();
  
  // deliver() - performs the actions of delivering as a FedEx object
  // Preconditions: mail present in m_storage
  // Postconditions: outputs delivered data and returns a status # (0 - fail, 1 - success)
  int deliver();
 private:
  // toString() - method to format the object as a string
  // Preconditions: a valid FedEx object
  // Postconditions: returns the FedEx object as a string
  ostream& print(ostream&) const;
};

#endif
