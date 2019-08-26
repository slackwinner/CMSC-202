/**********************************************************************
File: Car.cpp
Project: CMSC 202 Project 3, Spring 2018
Author: Dane Magbuhos
Date: 4/9/18
E-mail: mag4@umbc.edu

Description: 
This file contains the getters/setters functions from the Car.h file 
to create each individual cargo from the input text file.  

*********************************************************************/

#include "Car.h"

using namespace std;

Car::Car()
{
    m_next = NULL;
}

Car::Car(CARGO_TYPE cargo)
{
   m_cargo = cargo;
   m_next = NULL;
}


Car::~Car()
{

}

CARGO_TYPE Car::getCargo() const
{

  return m_cargo;

}

void Car::setCargo(CARGO_TYPE cargo)
{

  m_cargo = cargo;

}

Car *const Car::getNext() const
{

  return m_next;

}

void Car::setNext(Car* nextCar)
{
  m_next = nextCar;

}

/*int Car::getLength() const
{

  // Traverse through linked list and count nodes

}  */
