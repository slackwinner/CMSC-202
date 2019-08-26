/********************************************************************************************************
File: main.cpp
Project: CMSC 202 Project 3, Spring 2018
Author: Dane Magbuhos
Date: 4/9/18
E-mail: mag4@umbc.edu

Description:
This file contains the main driver for Project 3.This program reads in a train file, builds individual
cargos, and links them togther using linked lists. From there the newly built train undergos a pattern
analysis to determine if pattern type is valid or invalid based on a set of established conditions.

*********************************************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "Car.h"
#include "Train.h"

using namespace std;

// All possible cargo types (or car types)
const string CARGO_ONE = "BIOLOGICAL";
const string CARGO_TWO = "POISONOUS";
const string CARGO_THREE = "COMBUSTIBLE";
const string CARGO_FOUR = "OXIDIZER";
const string CARGO_FIVE = "RADIOACTIVE";
const string CARGO_SIX = "LOCOMOTIVE";
const string CARGO_SEVEN = "CABOOSE";

// Add and remove action indicators
const string ADD = "add";
const string REMOVE = "remove";

// Used to invoke new train construction
int PREVIOUS_NUMBER = 0;

int main(int argc, char* argv[])
{    
  string trainNumber;              // Specific train with unique cargo pattern (string version)
  string action;                   // Specifies what to do with imported content
  string cargo;                    // Unique cargo type (string version) 
  int trainNum;                    // Specific train with unique cargo pattern (integer version)
  int carType;                     // Index of cargo/cargo types
  int index = 0;                   // Index of linked list
  int setCount = 0;                // Used to store previous train number
  unsigned int i = 0;              // Looping variable for train vector
  bool valid;                      // Is train cargo pattern valid?
  CARGO_TYPE car;                  // Unique cargo type (enumerated value)
  vector <Train*> t;               // Stores train pointers
  Train *firstTrain = new Train(); // Creates first train object
  

  // Adds first train to pointer vector
  t.push_back(firstTrain);

  // Utilizes the "make run" command to execute program
  if(argc != 2)
    cout << "File not found" << argv[0] << endl;
  else
  {
    if(argv[1] > 0)
    {
      ifstream file(argv[1]);

      // Reads in the data from chosen text file
      while(getline(file,trainNumber,','))
      {
	getline(file,action,',');
	getline(file,cargo);

	// Converts trainNumber into an integer 
	trainNum = atoi(trainNumber.c_str());
     
	// Converts cargo into its corresponding enum version
	if(cargo == CARGO_ONE)
	   carType = BIOLOGICAL;

	else if(cargo == CARGO_TWO)
	   carType = POISONOUS;
    
	else if(cargo == CARGO_THREE)
	   carType = COMBUSTIBLE;

	else if(cargo == CARGO_FOUR)
	  carType = OXIDIZER;

	else if(cargo == CARGO_FIVE)
	  carType = RADIOACTIVE;

	else if(cargo == CARGO_SIX)
	  carType = LOCOMOTIVE;
    
	else if(cargo == CARGO_SEVEN)
	  carType = CABOOSE;

	car = CARGO_TYPE(carType);

	// Prevents invocation of train construction until current train is built
	if(car == CABOOSE)
	{
	  PREVIOUS_NUMBER = trainNum;
	  setCount++;
	} 
	// Invokes the construction of a new train 
	if((PREVIOUS_NUMBER != trainNum) && (setCount > 0))
	{
	  // Creates new train object
	  Train *newTrain = new Train(trainNum);
	  
	  // Resets the variables for next build iteration
	  index = 0;
	  setCount = 0;
	  PREVIOUS_NUMBER = trainNum;

	  //Adds new train to vector
	  t.push_back(newTrain);

	  // Redirects read in data to build new train 
	  i++;
       
	}

	// Builds a train based on read in data
	t[i]->setNumber(trainNum);

	// Builds up train with similiar train number cargos
	if(t[i]->getNumber() == trainNum)
	{
	  // Creates individual cargo and populates train
	  if(action == ADD)
	  {
	    t[i]->addCar(car, index);
	    index++;
	  }

	  // Removes specified cargo
	  else if(action == REMOVE)
	    t[i]->removeCar(car);
	}
      }
      // Closes text file
      file.close();
    }
  }
	          
  //Outputs cargo train and deallocates vector
   for(unsigned int j = 0; j < t.size();j++)
   {
     cout << "Train " << t[j]->getNumber() << ": " << *t[j] << endl;
     
     // Evaluates if train cargo pattern is valid
     valid = t[j]->isValid();
     if(valid == true)
       cout << "(VALID)" << endl;
     else
       cout << "(INVALID)" << endl;

     delete t[j];
   }
  
	  
   return 0;
}

