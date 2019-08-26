/*
File: FedEx.cpp
Project: CMSC 202 Project 4, Spring 2018
Author: Dane Magbuhos
Date: 4/22/18
E-mail: mag4@umbc.edu

Description: This contains the function implementations
from the FedEx.h file. In addition, this file serves as the
child class (i.e. This sub-carrier inherits from the carrier parent class).

*/
#include "FedEx.h"

#include <iostream>
#include <iomanip>

using namespace std;

FedEx::FedEx()
{

  // empty body constructor

}

FedEx::~FedEx()
{

  // empty body deconstructor
}

int FedEx::contents()
{

  int result;                                    // Did the content output succeed?
  unsigned int lastIndex = m_storage.size() - 1; // Last index of the storage vector
  unsigned int emptyVector = 0;                  // Default value for empty vector

  // Ensures there's at least one mail in FedEx carrier 
  if(m_storage.size() == emptyVector)
  {
    cout << "FedEx Carrier has no mail" << endl;
    result = 0;
  }

  else
  {
    // Traverses through storage and outputs mail content
    for(unsigned int i = 0; i < m_storage.size(); i++)
    {
      cout << *m_storage[i] << endl;
    
      // Outputs ending line after last mail item
      if(i == lastIndex)
      {
	cout << setfill('*') << setw(35) << endl;
	cout << "        " << endl;
	cout << "        " << endl;
	result = 1;
      }

    }
  }
  return result;

}

int FedEx::deliver()
{
  int result = 0;    // Was the delivery a success?
  float total = 0.0; // Total cost after delivery
  float calculation; // Temporary calculation variable
  float baseCost;    // Mail's letter or package base cost
  float size;        // Mail's letter or package size
  float speed;       // Carrier's delivery rate

  unsigned int lastIndex = 0; // Last index of storage vector
  unsigned int emptyVector = 0; // Represents no populated mail carrier

  // Checks to see if carrier was populated
  if(m_storage.size() == emptyVector){
    cout << "FedEx Carrier did not receive any mail" << endl;
    cout << "No FedEx mail was delivered" << endl;
    cout << " " << endl;
  }

  else{
  
    // Traverses through carrier and extracts each mail items
    for(unsigned int j = m_storage.size(); j-- > lastIndex;)
    {
      // Outputs delivered status and mail info
      cout << "Delivered: " << endl;
      cout << *m_storage[j] << endl;

      // Grabs the calculation components for each mail item
      baseCost = m_storage[j]->getBaseCost();
      size = m_storage[j]->getSize();
      speed = m_delivery_rate;

      // Calculates the delivery cost
      calculation = baseCost * size * speed;

      // Stores the calculation prior to next iteration
      total = total + calculation;

      // Indicates successful transaction
      if(j == lastIndex)
	result = 1;
    }

    // Rounds the total cost to the nearest hundredth place
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // Outputs the total delivery cost
    cout << "Deliveries completed. FedEx total earned $" << total << endl;
    cout << " " << endl;
  }
  return result;

}

ostream& FedEx::print(ostream& stream) const 
{
  // Streams the FedEx header section of output
  stream << "*****************************" << endl;
  stream << "FedEx Truck Contents" << endl;
  return stream;
}
