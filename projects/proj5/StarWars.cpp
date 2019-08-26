/*******************************************************
File: StarWars.cpp
Project: CMSC 202 Project 5, Spring 2018
Author: Dane Magbuhos
Date: 5/6/18
E-mail: mag4@umbc.edu

Description: This contains the function implementations
for the StarWars.h file. This file controls the battle 
simulation.
******************************************************/

#include <iostream>
#include <fstream>
#include "StarWars.h"

const int DEFAULT = 2; // Chosen goto value for randomnization

StarWars::StarWars(){
  // empty body constructor

}

StarWars::~StarWars(){

  // Clears out the rebel and imperial vectors

  for(unsigned int i = 0; i < m_rebelShips.size(); i++)
    delete m_rebelShips[i];

  for(unsigned int j = 0; j < m_imperialShips.size(); j++)
    delete m_imperialShips[j];

}
bool StarWars::loadShips(char *files[]){

  ifstream inputStream; // Input value stream variable
  string shipName;      // Ship's name
  string shipType;      // Ship's type
  string attackS;       // Ship's attack value (string verison)
  string defenseS;      // Ship's defense value (stirng verison)

  int attack;           // Ship's attack value (integer version)
  int defense;          // Ship's defense value (integer version)
  int numOfFiles = 2;   // Number of files in file array
  int imperialFile = 0; // Imperial's file index
  int rebelFile = 1;    // Rebel's file index

  Ship *imperialShip;  // Imperial's ship
  Ship *rebelShip;     // Rebel's ship
  
   for(int i = 0; i < numOfFiles; i++){

     // Opens specified file
    inputStream.open(files[i]);

    // Loops through textfile and extracts text file contents
    while(getline(inputStream,shipName,',')){
      getline(inputStream,shipType,',');
      getline(inputStream,attackS,',');
      getline(inputStream,defenseS);

      attack = atoi(attackS.c_str());
      defense = atoi(defenseS.c_str());

      // Creates and stores imperial ships
      if(i == imperialFile){
	imperialShip = new Imperial(shipName, shipType, attack, defense);
	m_imperialShips.push_back(imperialShip);
      }
      
      // Creates and stores rebel ships
      else if(i == rebelFile){
	rebelShip = new Rebel(shipName, shipType, attack, defense);
	m_rebelShips.push_back(rebelShip);
      }
    }
 
    inputStream.close();
   }
  return 1;
}

void StarWars::Start(char *files[]){

  bool loadSuccess;    // Did the ships load properly?
  
  int numShips;        // Number of ships per side
  int lowerBound = 0;  // Represents lowest bound for input

  cout << "Welcome To Star Wars" << endl;

  loadSuccess = loadShips(files);

  if(loadSuccess == true){
    cout << "Ships Loaded" <<endl;
    do{
      cout << "How many ships would you like on a team" << endl;
      cin >>numShips;
      cin.ignore();
      
    }while(numShips <= lowerBound);

    // Creates the teams
    createTeams(numShips);
 
    // Invokes battle simulation
    battle();

  }
  
 }

void StarWars::createTeams(int numShips){

  int rebelIndex;      // Rebel's vector index
  int imperialIndex;   // Imperial's vector index
  int shipCount = 0;   // Current count of amount of populated ships

  // Ensures chosen ships are unique
  srand(time(0));

  // Populates Rebel and Imperial Tqueues
  while(shipCount != numShips){

    // Pick out a random ship from rebel and imperial vector
    rebelIndex = rand() % m_rebelShips.size();
    imperialIndex = rand() % m_imperialShips.size();
    
    // Adds ships to rebel and imperial ship's queue 
    m_myShips.enqueue(m_rebelShips[rebelIndex]);
    m_enemyShips.enqueue(m_imperialShips[imperialIndex]);

    shipCount++;
  }

  // Used to output all the ships that are present in space battle
  // Uncomment to see which ships were populated in array

  /*   for(int i = 0; i < numShips; i++)
    cout << "Rebel: " << m_myShips[i]->getName() <<endl;
    

  for(int j = 0; j < numShips; j++)
  cout << "Empire: " << m_enemyShips[j]->getName() << endl;*/
}

void StarWars::battle(){

  int noShips = 1;       // Empty ship queue ship
  int rebel = 1;         // Rebel side 
  int empire = 0;        // Imperial side
  int shipIndex = 0;     // Index of ship in queue
  int startBattle;       // The side that will attack first  
  int nextBattle = -1;   // The side that will attack next

  bool result;            // Battle outcome
  bool destroyedShip = 1; // Destroyed ship value
  bool damagedShip = 0;   // Damaged ship value

 
  cout << "The Battle Begins..." <<endl;

  // Ensures there's a unique chosen value
  srand(time(0));

  // Determines which side will begin the attack
  startBattle = rand() % DEFAULT;

  // Rebel and Imperial ships fight until no more ships are avaliable on one side
  while((m_myShips.isEmpty() != noShips) && (m_enemyShips.isEmpty() != noShips)){
 
    // Rebels attacks Imperial
    if(startBattle == rebel){
      cout << *m_myShips[shipIndex] << " attacks " << "Imperial's " << m_enemyShips[shipIndex]->getName() << endl;
      cout << endl;

      // Determines the fate of the Imperial ship
      result = m_myShips[shipIndex]->attack(m_enemyShips[shipIndex]);

      // Removes destroyed Imperial ship from battle
      if(result == destroyedShip){
	m_enemyShips.dequeue();
	startBattle = nextBattle;
      }
      // Enemy ship retaliates
      else if(result == damagedShip)
	startBattle = empire;
    }

      // Imperial attacks Rebel
    else if(startBattle == empire){
      cout << *m_enemyShips[shipIndex] << " attacks " << "Rebel's " << m_myShips[shipIndex]->getName() << endl;
      cout << endl;

      // Determines the fate of the Rebel ship
      result = m_enemyShips[shipIndex]->attack(m_myShips[shipIndex]);

      // Removes destroyed Rebel ship
      if(result == destroyedShip){
	m_myShips.dequeue();
	startBattle = nextBattle;
      }

      // Rebel ships retaliate
      else if(result == damagedShip)
	startBattle = rebel;
    }

    // Randomly decides which side is going to attack next
    if(startBattle == nextBattle)
      startBattle = rand() % DEFAULT;


  }

  // Outputs battle result
  if(m_myShips.isEmpty() == noShips)
    cout << "The Imperial Navy decimated your ships! You lost the battle!" << endl;
  
  else if(m_enemyShips.isEmpty() == noShips)
    cout << "The Imperial Navy is defeated! You won the battle!!!" << endl;
}

