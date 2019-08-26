/*
File: Ups.cpp
Project: CMSC 202 Project 4, Spring 2018
Author: Dane Magbuhos
Date: 4/22/18
E-mail: mag4@umbc.edu

Description: This contains the function implementations
from the Ups.h file. In addition, this file serves as the
child class (i.e. This sub-carrier inherits from the carrier parent class).

*/

#include "Ups.h"

#include <iostream>
#include <iomanip>

using namespace std;

Ups::Ups()
{
  // empty body constructor
}

Ups::~Ups()
{
  // empty body deconstructor
}

int Ups::contents()
{

  int result;                                    // Did the output contents succeed?
  unsigned int emptyVector = 0;                  // Indicates the default value for an empty storage
  unsigned int lastIndex = m_storage.size() - 1; // Last index of the storage vector 

  // Ensures that there's at least one mail in UPS carrier
  if(m_storage.size() == emptyVector)
  {
    cout << "UPS Carrier has no mail" <<endl;
    result = 0;
  }

  else
  {
    // Traverses through storage an output mail contents
    for(unsigned int j = 0; j < m_storage.size(); j++)
    {
      cout << *m_storage[j] << endl;

      // Outputs ending line after last mail item
      if((j == lastIndex) && (m_storage.size() > emptyVector))
      {
	cout << setfill('*') << setw(35) << endl;
	cout << "      " << endl;
	cout << "      " << endl;
	result = 1;
      }
    }
  }
  return result;

}

int Ups::deliver()
{
  int result = 0;    // Was the delivery a success?
  float total = 0.0; // Total cost after delivery
  float calculation; // Temporary calculation variable
  float baseCost;    // Mail's letter or package base cost 
  float size;        // Mail's letter or package size
  float speed;       // carrier's speed

  unsigned int lastIndex = 0; // Last index of the storage vector
  unsigned int emptyVector = 0; // Represents no populated mail carrier

  // Checks to see if mail carrier is populated
  if(m_storage.size() == emptyVector){
    cout << "UPS Carrier did not receive any mail" << endl;
    cout << "No UPS mail was delivered" << endl;
    cout << " " << endl;
  }

  else{

    // Traverses through carrier and extracts each mail items
    for(unsigned int i = m_storage.size(); i-- > lastIndex;)
    {
      // Outputs delievered status and mail info
      cout << "Delivered: " << endl;
      cout << *m_storage[i] << endl;
    
      // Grabs the calculation components for each mail item
      baseCost = m_storage[i]->getBaseCost();
      size = m_storage[i]->getSize();
      speed = m_delivery_rate;

      // Calculates the delivery cost
      calculation = baseCost * size * speed;
   
      // Stores the calculation prior to the next iteration 
      total = total + calculation;

      // Indicates successful transaction 
      if(i == lastIndex)      
	result = 1;
    }

    // Rounds the total cost to the nearest hundredth place
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // Outputs total amount of delivery cost
    cout << "Deliveries completed. UPS total earned $" << total << endl; 
    cout << " " << endl;
  }
  return result;

}

ostream& Ups::print(ostream& stream) const
{
  // Streams the UPS Header within output 
  stream << "****************************" << endl;
  stream << "UPS Truck Contents: " << endl;
  
  return stream;

}
