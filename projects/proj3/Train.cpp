/*************************************************************************************
File: Train.cpp
Project: CMSC 202 Project 3, Spring 2018
Author: Dane Magbuhos
Date: 4/9/18
E-mail: mag4@umbc.edu

Description:
This file contains the add, remove, display, and getters/setters functions from
the Train.h file that constructs a train from the input files.

**************************************************************************************/

#include "Train.h"

using namespace std;

Train::Train()
{
   m_head = NULL;
   m_len = 0;
}

Train::Train(int t)
{

   m_number = t;
   m_head = NULL;
   m_len = 0;
}


Train::~Train()
{

  Car *currentNode; // Current cargo pointer
  Car *next;        // Next cargo pointer

  // Starts at first pointer
  currentNode = m_head;

  while(currentNode != NULL)
  {
    // Stores next nodes' address
    next = currentNode -> getNext();
    
    // Deletes previous node
    delete currentNode;

    // Sets current node to next node 
    currentNode = next;

  }

  m_head = NULL;
 
}

void Train::display(ostream& stream) const
{
  Car *currentCar = m_head; // Starting point

  // Traverses through entire train list and outputs corresponding value
  while(currentCar != NULL)
  {
    // Grabs the cargo type based on current car iteration
    CARGO_TYPE cargo = currentCar -> getCargo();
    
    switch(cargo)
    {
       case BIOLOGICAL:
        stream <<"BIO";
        break;

       case POISONOUS:
         stream <<"POI";
         break;
      
       case COMBUSTIBLE:
        stream <<"COM";
        break;
      
       case OXIDIZER:
        stream <<"OXI";
        break;

       case RADIOACTIVE:
        stream <<"RAD";
        break;
      
       case LOCOMOTIVE:
        stream <<"ENGINE";
        break;
      
       case CABOOSE:
	 stream <<"CABOOSE";
        break;
      
      default:
	stream <<"Error";
	break;
     }

    // Outputs arrow in between cargos
    if(currentCar->getCargo() != CABOOSE)
       stream << "->";

    // Grabs next cargo link
    currentCar = currentCar-> getNext();
  }
  
}

bool Train::isValid() const
{

  Car *currentCar = m_head; // Current cargo pointer
  Car *secondCar = NULL;    // Second cargo pointer
  Car *thirdCar = NULL;     // Third cargo pointer
  Car *fourthCar = NULL;    // Fourth cargo pointer 
  Car *fifthCar = NULL;     // Fifth cargo pointer
  bool result = true;       // Is result true?

  // Traverses through train until CABOOSE is reached or result is false
  while((currentCar->getCargo() != CABOOSE) && (result == true))
  {
    // Handles the COMBUSTIBLE and OXIDIZER condition
    if(currentCar->getCargo() == COMBUSTIBLE)
    {
      // Builds second cargo pointer
      secondCar = currentCar->getNext();

      // Determines if second cargo is OXIDIZER
      if(secondCar-> getCargo() == OXIDIZER)
      {
	result = false;
      }
      // Handles the COMBUSTIBLE 3x condition
      else if(secondCar->getCargo() == COMBUSTIBLE)
      {
	// Builds the third cargo pointer
	if(secondCar->getNext() != NULL)
	{
	  thirdCar = secondCar->getNext();

	  // Determines if third cargo is COMBUSTIBLE
	  if(thirdCar->getCargo() == COMBUSTIBLE)
	  {
	    result = false;
	  }
	}
      }
    }

    // Handles the OXIDIZER and COMBUSTIBLE condition
    // (i.e. Can't have OXI -> COM) 
    else if(currentCar->getCargo() == OXIDIZER)
    {
      // Builds the second cargo pointer
      secondCar = currentCar->getNext();
      
      // Determines if second cargo is COMBUSTIBLE
      if(secondCar->getCargo() == COMBUSTIBLE)
      {
	result = false;
      }
    }
    
    // Handles BIOLOGICAL 5x condition
    // (i.e. Can't have BIO -> BIO -> BIO -> BIO -> BIO)
    else if(currentCar->getCargo() == BIOLOGICAL)
    {
      // Builds second cargo pointer
      secondCar = currentCar->getNext();
      
      // Builds third cargo pointer
      if(secondCar->getNext() != NULL)
      {
	thirdCar = secondCar->getNext();
      
	// Compares the values of the second and third cargo pointer
	if((secondCar->getCargo() == BIOLOGICAL) && (thirdCar->getCargo() == BIOLOGICAL))
	{
	  // Builds the fourth cargo pointer
	  if(thirdCar->getNext() != NULL)
	  {
	    fourthCar = thirdCar->getNext();

	    // Builds the fifth cargo pointer
	    if(fourthCar ->getNext() != NULL)

	       fifthCar = fourthCar->getNext();
	 
	    // Compares the fourth and fifth cargo pointers
	    if((fourthCar->getCargo() == BIOLOGICAL) && (fifthCar->getCargo() == BIOLOGICAL))
	    {
	      result = false;
	    }
	  }
	}
      }
    }

    // Handles RADIOACTIVE condition
    // (i.e. Can't have RAD -> BIO -> RAD)
    else if(currentCar->getCargo() == RADIOACTIVE)
    {
      // Builds the second cargo pointer
      secondCar = currentCar->getNext();
      
      // Builds the third cargo pointer
      if(secondCar->getNext() != NULL)
      {
	thirdCar = secondCar->getNext();

	// Compares the second and third cargo pointers
	if((secondCar->getCargo() == BIOLOGICAL) && (thirdCar->getCargo() == RADIOACTIVE))
	{
	  result = false;
	}
      }
    }
   
  // Grabs next cargo for cargo pattern analysis
  currentCar = currentCar->getNext();

  //Resets variables for next iteration
  secondCar = NULL;
  thirdCar = NULL;
  fourthCar = NULL;
  fifthCar = NULL;
   
 }
  return result;
}


int Train::addCar(const CARGO_TYPE& cargo, int index)
{
  Car *newCar = new Car(cargo);    // Creates a cargo pointer
  Car *tempCar;                    // Creates a traversal pointer
  int i = 0;                       // Index counter 

  // Establishes first node
  newCar->setCargo(cargo);
  newCar->setNext(NULL);

  // Handles the case where linked list is empty
  if(index == 0)
    m_head = newCar;
  
  else
  {
    // Points to first node head
    tempCar = m_head;
    
    // Traverses through linked list until it reaches index
    while((i<index)&&(tempCar ->getNext() != NULL))
    {
      tempCar = tempCar -> getNext();
      i++;
    }
    
     // Links last node to cargo pointer
     tempCar->setNext(newCar);
  
   m_len++;

   // Deletes cargo once last cargo train is passed in 
   if((cargo == CABOOSE)&&(tempCar->getNext() == NULL))
   {
     delete newCar;
     newCar = NULL;

     delete tempCar;
     tempCar = NULL;
    }
  }
   return 1;
}


int Train::removeCar(int index)
{
  Car *currentCar = m_head;  // Starting point of linked list
  Car *tempCar = NULL;       // Deletion pointer
  int tempIndex = 0;         // Index tracking varaible
 
  // Loops through and grabs current car's (index - 1)th place
  for(tempIndex = 0; tempIndex <= index-2; tempIndex++)
  {
    currentCar = currentCar ->getNext();
  }
    // Sets temp to the nth node (i.e. the index we want to delete)
    tempCar = currentCar ->getNext();

    // Sets current car's placement to (index + 1)th place 
    // (i.e. the node after the deleted node)
    currentCar->setNext(tempCar->getNext());
   
    // Gets rid of specified placement and decreases length of cargo train
    delete tempCar;
    m_len--;
  
  return 1;
}

int Train::removeCar(CARGO_TYPE cargo)
{
  Car *currentCar = m_head; // Starting point of linked list
  int index = 0;            // Index tracking variable
  
  // Traverses through entire linked list
  while(currentCar != NULL)
  {
    if(currentCar->getCargo() == cargo)
    {
      // Removes found cargo at specified index
      removeCar(index);
      
      // Resets varaibles for next iteration
      index = 0;
      currentCar = m_head;
    }

    // Grabs next current cargo and grabs the next cargo's index
    currentCar = currentCar->getNext();
    index++;
    
  }
  return 1;

}

int Train::getLength() const
{
  return m_len;
}

int Train::getNumber() const
{

  return m_number;

}

void Train::setNumber(int trainNumber)
{

  m_number = trainNumber;

}

ostream &operator<< (ostream &stream, const Train& train)
{

  // Calls the display function
  train.display(stream);

  return stream;

}
