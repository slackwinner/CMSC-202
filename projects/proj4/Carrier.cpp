/*
File: Carrier.cpp
Project: CMSC 202 Project 4, Spring 2018
Author: Dane Magbuhos
Date: 4/22/18
E-mail: mag4@umbc.edu

Description: This contains the function implementations 
from the Carrier.h file. In addition, this file serves as the
parent class for the child classes (i.e. Ups.h and FedEx.h)

*/

#include "Carrier.h"

#include <iostream>

using namespace std;

Carrier::Carrier()
{
  // Empty body constructor
}

Carrier::~Carrier()
{
  // Empty body deconstructor
}

int Carrier::insert(Mail* mail)
{

  int result = 1;     // Did the carrier reach max capacity?
  int currentStorage; // Current amount of mail items in carrier

  // Adds mail item in carrier
  m_storage.push_back(mail);

  // Grabs amount of mail items in carrier
  currentStorage = m_storage.size();

  // Checks to see that the storage is not overfilled
  if(currentStorage > m_max_capacity)
    result = 0;

  return result;
}

void Carrier::setMaxCapacity(int maxCap)
{
  // Sets the max capacity the carrier can hold
  m_max_capacity = maxCap;
}

void Carrier::setRate(float rate)
{
  // Sets the delivery rate for the carrier
  m_delivery_rate = rate;
}

ostream &operator<<(ostream& sout,const Carrier& carrier)
{
  // Invokes the carrier print function
  carrier.print(sout);
  
  return sout;
}
