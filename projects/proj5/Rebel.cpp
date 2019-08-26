/*******************************************************
File : Rebel.cpp
Project: CMSC 202 Project 5, Spring 2018
Author: Dane Magbuhos
Date: 5/6/18
E-mail: mag4@umbc.edu

Description: This contains the prototype implementations
for the Rebel.h file. In addition, this file serves as a 
child class for the Ship file.

********************************************************/
#include <iostream>
#include "Rebel.h"

bool Rebel::attack(Ship* enemy){

  bool battleResult;      // What was the ending result?
  bool damagedShip = 0;   // Damaged ship boolean value
  bool destroyedShip = 1; // Destroyed ship boolean value 

  int damage = 0;         // Damage points on the empire's ships
  
  // Handles the destroyed ship case
  if(getAttack() >= enemy->getDefense()){

    // Outputs destroyed result
    cout << "The Imperial's " << enemy->getName() << " " << enemy-> getType() << " was destroyed" <<endl;
    cout << endl;

    battleResult = destroyedShip;
  }

  // Handles the damaged ship case
  else if(getAttack() < enemy-> getDefense()){

    // Calculates how much damage the rebel ship inflicts on Imperial ship
    damage = enemy->getDefense() - getAttack();
    
    // Sets the new defense points
    enemy->setDefense(damage);

    // Outputs damage results
    cout <<"The Imperial's " << enemy->getName() << " " << enemy->getType() << " was damaged" << endl;
    cout << endl;

    battleResult = damagedShip;

  }

  return battleResult;

}

ostream& Rebel::toString(ostream& os){

  os << "The Rebel " <<  getName();

  return os;


}
