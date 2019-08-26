/*
File: Mail.cpp
Project: CMSC 202 Project 4, Spring 2018
Author: Dane Magbuhos
Date: 4/22/18
E-mail: mag4@umbc.edu

Description: This contains the function implementations
for the Mail.h file. In addition, this serves as the 
parent class for the mail sub classes (i.e. Letter.h and Package.h).

*/

#include "Mail.h"

#include <iostream>

using namespace std;

Mail::Mail()
{
  // empty body constructor

}

Mail::Mail(int carrier, string sender, string recipient, float size, float baseCost)
{
  // Sets each member variable to it's appropriate value
  m_carrier = carrier;
  m_sender = sender;
  m_recipient = recipient;
  m_size = size;
  m_baseCost = baseCost;

}

Mail::~Mail()
{
  // empty destructor body

}

int Mail::getCarrier()
{

  return m_carrier;

}

string Mail::getSender()
{

  return m_sender;

}

string Mail::getRecipient()
{

  return m_recipient;

}

float Mail::getSize()
{

  return m_size;

}

float Mail::getBaseCost()
{

  return m_baseCost;

}

ostream &operator<< (ostream& sout, Mail& mail)
{
  // Streams the mail's string object
  sout << mail.toString() << endl;

  return sout;
  
}
