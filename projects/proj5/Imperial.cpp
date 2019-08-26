/************************************************************
File: Imperial.cpp
Project: CMSC 202 Project 5, Spring 2018
Author: Dane Magbuhos
Date: 5/6/18
E-mail: mag4@umbc.edu

Description: This file contains the prototype implementations
for the Imperial.h file. This file also serves as a child class
for the ship file.
*************************************************************/

#include <iostream>
#include "Imperial.h"


bool Imperial::attack(Ship *enemy){

  bool battleResult;      // What was the ending result?
  bool damagedShip = 0;   // Damaged ship boolean value
  bool destroyedShip = 1; // Destroyed ship boolean value

  int damage = 0;         // Damage points on the rebel ships



  // Handles the destroyed ship case
  if(getAttack() >= enemy->getDefense()){

    // Outputs destroyed result
    cout << "The Rebel's " << enemy->getName() << " " << enemy->getType() << " was destroyed" << endl;
    cout << endl;

    battleResult = destroyedShip;
  }

  // Handles the damaged ship case
  else if(getAttack() < enemy->getDefense()){
    
    // Calculates how much damage the Imperial ship inflicts on rebel ship 
    damage = enemy->getDefense() - getAttack();

    // Sets the new defnse points for enemy
    enemy->setDefense(damage);

    // Outputs damage results
    cout << "The Rebel's " << enemy->getName() << " " << enemy->getType() << " was damaged"<< endl;
    cout << endl;

    battleResult = damagedShip;
  }

  return battleResult;

}


ostream& Imperial::toString(ostream& os){

  os << "The Imperial " << getName();

  return os;

} 
