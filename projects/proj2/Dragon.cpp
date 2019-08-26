/*********************************************************
File: Dragon.cpp
Project: CMSC 202 Project 2, Spring 2018
Author: Dane Magbuhos
Date: 3/18/18
E-mail: mag4@umbc.edu

Description:
This file contains functions and constructors that sets and
stores all dragon attributes. In addition, this also contains 
functions that determine if eggs hatch, if certain attacks was
a success during a battle, and if the user's dragon levels up. 
**********************************************************/
#include "Dragon.h"
#include <ctime>

const int DEFAULT = 0;           // Represents first goto value
const int PERCENT_CALC = 2;      // Part of probability calculations
const int PERCENT_CALC_TWO = 99; // Part of second probability calculations 
const int ELEMENT_SHIFT = 1;     // Used to increment/decrement values

Dragon::Dragon(string name, string type, bool isHatched, dragonSize curSize, dragonSize maxSize, int rarity)
{
  m_name = name;
  m_type = type;
  m_isHatched = isHatched;
  m_curSize = curSize;
  m_maxSize = maxSize;
  m_rarity = rarity;
}

string Dragon::GetName() { return m_name; }

void Dragon::SetName(string name)
{

  m_name = name;

}

string Dragon::GetType()
{
 
  return m_type;

}

void Dragon::SetType(string Type)
{

  m_type = Type;

}

bool Dragon::GetIsHatched()
{

  return m_isHatched;

}

void Dragon::HatchDragon()
{

  int hatchResult;    // Random number chosen (i.e possible outcome: 0 or 1)
  int hatchBound = 0; // Represents the probability of egg being hatched 

  // Ensures that randomnizaiton is unique in each program execution
  srand(time(DEFAULT));
  hatchResult = rand() % PERCENT_CALC;

  // Sets m_isHatched to appropraite value based on hatch result 
  if(hatchResult == hatchBound)
     m_isHatched = true;
  else
    m_isHatched = false;
  
}

dragonSize Dragon::GetCurSize()
{
  return m_curSize;

}

void Dragon::SetCurSize(dragonSize curSize)
{

  m_curSize = curSize;

}

dragonSize Dragon::GetMaxSize()
{
  return m_maxSize;

}

void Dragon::SetMaxSize(int maxSize)
{
  int tinyInt = 1;   // represents tiny value
  int smallInt = 2;  // represents small value
  int mediumInt = 3; // represents medium value
  int largeInt = 4;  // represents large value

  // Sets the max vlue to the appropriate enum value equivalent
  if (maxSize == tinyInt)
    m_maxSize = tiny;

  else if(maxSize == smallInt)
    m_maxSize = small;

  else if(maxSize == mediumInt)
    m_maxSize = medium;

  else if(maxSize == largeInt)
    m_maxSize = large;
  else
    m_maxSize = huge;
}

int Dragon::GetRarity()
{
  return m_rarity;
}

void Dragon::SetRarity(int rarity)
{
  m_rarity = rarity;
}

bool Dragon::AttemptGrow()
{
  int upgrade;       // Represents 50/50 chance of successful growth
  int growth = 0;    // Successful growth value  
  bool growthResult; // Did the dragon grow larger?

  // Ensures randomnization is unique in each program's execution
  srand(time(0));
  upgrade = rand() % PERCENT_CALC;

  // Determines if dragon does or does not grow
  if(upgrade == growth)
    growthResult = true;
  else 
    growthResult = false;

  return growthResult;

}

bool Dragon::AttackDragon(Dragon& d)
{
  bool result; // Was the attack a success?

  // Determines if player's dragon lives or dies based on current size comparison
  if((m_curSize + ELEMENT_SHIFT > d.GetCurSize()) || (m_curSize + ELEMENT_SHIFT == d.GetCurSize()))
     result = true;
  else
    result = false;  

   return result;

}

string Dragon::BreathAttack(Dragon& a)
{
 int breathAttack;          // Value for executing special attack
 int lowerBound = 1;        // Lowest range for breath attack probability
 int upperBound = 5;        // Highest range for breath attack probability
 string result = "Failed";  // Default result value for breath attack

 // Ensures randomnization is unique after each program execution
 srand(time(DEFAULT));
 
 // Picks out random value between 1 - 100
 breathAttack = rand() % PERCENT_CALC_TWO + ELEMENT_SHIFT;

 // Only changes result if breath attack was within the probablity range of success
 if((breathAttack >= lowerBound) && (breathAttack <= upperBound))
 {
   cout << "Your " << a.GetName() << " used its " << a.GetType() << " breath attack! " << endl;
   result = "Success";
 }

  return result;
}

