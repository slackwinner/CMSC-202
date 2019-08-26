/**************************************************************
File: proj2.cpp
Project: CMSC 202 Project 2, Spring 2018
Author: Dane Magbuhos
Date: 3/20/18
E-mail: mag4@umbc.edu

Description: 
This file contains the main driver for Project 2.
This program boots up the Dragon game by loading in 
the dragon files and uses the file contents to create
a dragon based game. The user can search, collect, and hatch
dragon eggs as well as level up their dragons by battling 
against other dragon proponents.   
***************************************************************/

#include "Dragon.h"
#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int main() 
{

  Game newGame; // Invokes Game Class
  
  // Invokes start game function
  newGame.StartGame();

  return 0;
}
