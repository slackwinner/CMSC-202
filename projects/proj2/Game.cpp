/****************************************************************
File: Game.cpp
Project: CMSC 202 Project 2, Spring 2018
Author: Dane Magbuhos
Date: 3/20/18
E-mail: mag4@umbc.edu

Description: 
This file contains the search, hatch, display, attack
and quit dragon functions for the user. Each function is executed 
based upon the user's numeric choice input.  
****************************************************************/
#include "Game.h"
#include "Dragon.h"
#include <ctime> 
using namespace std;

const int PERCENT = 100;     // Represents the percentage
const int PERCENT_CALC = 99; // Part of probability calculations
const int ELEMENT_SHIFT = 1; // Used to increment/decrement values
const int LOWER_BOUND = 1;   // Represents lower value within any range
const int DEFAULT = 0;       // Represents first goto value

Game::Game()
{
  
  cout << "Welcome to Dragon Wars" << endl;
  cout << "What is your name" << endl;
  getline(cin, m_name);

  // Imports dragon file into m_dragon vector
  LoadDragons(); 
}

void Game::LoadDragons()
{
  ifstream dragonInfo;    // input and output stream of textfile
  string endOfFile;       // NULL value of text file
  string name;            // Dragon's name
  string type;            // Type of special attack
  string size;            // Dragon's maximum growth  (string version)
  string rareness;        // Dragon's rareness factor (string version)
  int maxSize;            // Dragon's maximum growth  (integer version)
  int rarity;             // Dragon's rareness factor (integer version)
  bool isHatched = false; // Sets default value for if the dragon is hatched
  
  // Opens textfile
  dragonInfo.open(PROJ2_DRAGONS.c_str());
  
  // Traverses through textfile and reads in the name, type, maxSize,and rarity data
  while(getline(dragonInfo,name,','))
   {
      getline(dragonInfo,type,',');
      getline(dragonInfo,size,',');
      getline(dragonInfo,rareness);

      // Converts maxSize string into integer
      maxSize = atoi(size.c_str());

      // Converts rarity string into integer
      rarity = atoi(rareness.c_str());
      
      // Invokes dragon constructor 
      Dragon d(name,type,isHatched,tiny,huge,rarity);

      d.SetName(name);
      d.SetType(type);
      d.SetCurSize(tiny);
      d.SetMaxSize(maxSize);
      d.SetRarity(rarity);

      // Adds dragon data into m_dragons vector
      m_dragons.push_back(d);
   }
    dragonInfo.close();

    // Function called to ensure text file content was read in properly
    // DisplayAllDragons();

}

void Game::SearchEgg()
{
  int rareInput;       // User's rarity input
  int rareCalc;        // Determines rare boundaries 
  int rareBase = 9;    // Part of rare calculation
  int rareResult;      // Random chosen number 
  int upperBound = 10; // Upper boundary of rarity
  int count = 0;       // Loop control variable
  int maxDragon = 1;   // Sets amount of dragon eggs the user can get
  int chosenDragon;    // Used to pick out random dragon within rarity class
  unsigned int i = 0;  // Loop variable

  //Grabs and validates user input
  do{
     cout << "What rarity egg would you like to search for?" << endl;
     cout << "Enter a rarity (1 = very common and 10 = very rare)" << endl;
     cin >> rareInput;

  }while((rareInput < LOWER_BOUND)||(rareInput > upperBound));

  // Calculates percentage range for upper and lower bounds
  rareCalc = PERCENT - (rareInput * rareBase);

  // Ensures randomnization is unique after each program execution
  srand(time(DEFAULT));

  // Randomly picks out a number between 1 - 100
  rareResult = rand() % PERCENT_CALC + ELEMENT_SHIFT;

  // Selects random dragon from dragon vector
  chosenDragon = rand() % m_dragons.size();

  // Adds dragon within rarity boundary if rare result is within range of rareCalc
 if(rareResult <= rareCalc)
 {
  while(count != maxDragon)
  {
    // Adds random dragon to user's dragon vector and deletes chosen dragon from main dragon vector 
    if(m_dragons[chosenDragon].GetRarity() == rareInput)
    {
      m_myDragons.push_back(m_dragons[chosenDragon]);

      cout <<"You found a " << m_dragons[chosenDragon].GetName() << " egg" << endl;

      m_dragons.erase(m_dragons.begin()+i);

      count++;
    }
    // Picks out another dragon only if dragon's rareness does not equal rare input
    chosenDragon = rand() % m_dragons.size();
  }
 }
 else
   // Only outputs statement if rare result is not within rarity boundary
    cout << "Sorry, you did not find a dragon of that rarity." << endl;
}

void Game::HatchEgg()
{
  int upperBound = m_myDragons.size();  // Highest range within user's vector
  int noDragons = 0;                    // Represents empty vector
  int hatchInput;                       // User's input
  string currentStatus;                 // Status value for dragon
  bool hatched = true;                  // Is the egg hatched or unhatched?

  // Handles the case where the user's dragon vector is not populated
  if(upperBound == noDragons)
    cout << "No dragon eggs found! " << endl;
  else
  {
    // Showcases all user's dragons
    DisplayMyDragons();

    // Prompts user to choose which egg to hatch from their set
    do{
      cout << "Which dragon would you like to try and hatch?" << endl;
      cin >> hatchInput;
    }while((hatchInput < LOWER_BOUND)||(hatchInput > upperBound));
  
    // Handles the case where user chose an element that is hatched already
    if(m_myDragons[hatchInput - ELEMENT_SHIFT].GetIsHatched() == hatched)
      cout << "Your " << m_myDragons[hatchInput - ELEMENT_SHIFT].GetName() << " has already hatched!" << endl;
    else
    {
     // Determines if user's chosen egg will hatch
     m_myDragons[hatchInput - ELEMENT_SHIFT].HatchDragon();

     // Outputs appropriate message based on hatch result and keeps count of all hatched eggs
     if(m_myDragons[hatchInput - ELEMENT_SHIFT].GetIsHatched() == hatched)
     {
        cout << "Your " << m_myDragons[hatchInput - ELEMENT_SHIFT].GetName() << " egg hatches into a dragon!" << endl;
        m_countHatchedDragons++;
     }
     else
        cout <<"Your chosen dragon did not hatch" << endl;
    }
 }

}
void Game::StartGame()
{
  int choice;      // User's game option 
  int endGame = 5; // Terminal value to end game

  // Calls main menu to receive input response from user
  choice = MainMenu();

  // Executes one of the user's chosen option 
  while (choice != endGame)
  {
    switch(choice)
    {
     case 1:
       SearchEgg();
       break;

     case 2:
       HatchEgg();
       break;
    
     case 3:
       DisplayMyDragons();
       break;
  
     case 4:
       cout << "Attack! " << endl;
       Attack();
       break;

     default:
       cout << "An error has occured" << endl;
    }
    // Displays main menu until terminal value is entered
    choice = MainMenu();
  }

  cout << "Thanks for playing Dragon Wars! " <<endl;
}

void Game::DisplayMyDragons()
{

  int count = 1;                        // Dragon number
  int upperBound = m_myDragons.size();  // Highest range of user's vector
  int noDragons = 0;                    // Represents empty vector
  string currentStatus;                 // Status value for dragon
  bool hatched = true;                  // Is the egg hatched or unhatched?

  // Handles the case where there's no dragons in user's vector
  if(upperBound == noDragons)
    cout << "No dragons were found" << endl;
  else
  {
    cout << "**************************************************************************" << endl;
    cout << m_name << "'s Dragons" << endl;
    cout << setw(30) <<"Name "<< setw(10) << "Type "<< setw(6) << "Egg/Dragon " << setw(6) << "Current Size   " << setw(3) << "Max Size" << endl; 

    // Traverses through user's vector and output all dragons and eggs within their set
    for(vector<Dragon>::iterator it = m_myDragons.begin(); it != m_myDragons.end();it++)
    {
      // Sets current status of the user's dragon based on the hatch status
      if(it->GetIsHatched() == hatched)
	currentStatus = "dragon";
      else
	currentStatus = "egg";
    
      cout << setw(2) << count <<"." << setw(26) << it->GetName() << setw(10) <<it->GetType() << setw(11) << currentStatus << setw(13);
      cout << it->GetCurSize() + ELEMENT_SHIFT << setw(11) << it->GetMaxSize() + ELEMENT_SHIFT << endl;

      count++;
    }
  }
}

int Game::MainMenu()
{

  int option;         // User's input value
  int upperBound = 5; // Highest bound of choice range

  // Outputs blank space for spacing purposes in output
  cout << endl;

  //Displays the main menu options for user
  do{
    cout << "What would you like to do?" << endl;
    cout << "1. Search for an egg" << endl;
    cout << "2. Try to hatch egg" << endl;
    cout << "3. Display all dragons and eggs " << endl;
    cout << "4. Attack!" << endl;
    cout << "5. Quit" << endl;
    cout << endl;
    cin >> option;
    cin.ignore();

  }while((option < LOWER_BOUND) || (option > upperBound));

  return option; 
}
void Game::Attack()
{
  int playerTotal;            // Total amount of eggs/dragons in user's vector
  int enemyDragon;            // Index of random chosen dragon
  int enemyDragonSize;        // Size value of chosen enemy dragon
  int dragonChoice;           // User's chosen dragon 
  int lowestRoster = 0;       // Lowest value user's vector
  dragonSize maxSize;         // Maximum size dragon can grow
  dragonSize curSize;         // Current size of dragon
  dragonSize increment;       // Upscales user's dragon by one size
  dragonSize enemySize;       // Random size of enemy dragon
  string ally;                // Name of user's chosen dragon
  string type;                // Name of special attack chosen dragon has
  string enemy;               // Name of random chosen dragon
  string attackCommand;       // User's way of commencing attack on random dragon
  string yes = "y";           // String command to attack enemy dragon 
  string special = "success"; // Default string value for successful breath attack
  string primaryMove;         // Was the breath attack a success?
  bool success = true;        // Default value when execution is completed properly
  bool growthResult;          // Did the dragon grow? 
  bool attackSuccess;         // Did the user's dragon win the fight?
 
  playerTotal = m_myDragons.size();
  enemyDragon = rand() % m_dragons.size();
  enemy = m_dragons[enemyDragon].GetName();

  // Handles the case where no dragons are present within player's vector
  if (m_countHatchedDragons == DEFAULT)
    cout << "No dragons are avaliable to choose from" << endl;
  else
  {
    // Ensures randomnization is unique after each program execution
    srand(time(DEFAULT));

    cout << "You found a " << enemy << " to fight!" << endl;
 
    // Prompts player to either go into the battle or back out of fight
    cout << "Do you want to fight it? (y/n) " << endl;
    cin >> attackCommand;

    // Handles the "yes" case of attack command
    if(attackCommand == yes)
    {
      // Sets the range of size values for the random function 
      if(m_dragons[enemyDragon].GetMaxSize() == DEFAULT)
	enemyDragonSize = m_dragons[enemyDragon].GetMaxSize();
      else
	enemyDragonSize = rand() % m_dragons[enemyDragon].GetMaxSize();

      // Sets enemy dragon's size to chosen random size
      enemySize = dragonSize(int(enemyDragonSize) + ELEMENT_SHIFT);
      m_dragons[enemyDragon].SetCurSize(enemySize);

      // Showcases player's avaliable dragons
      DisplayMyDragons();
    
      // Prompts user to choose a dragon from their roster
      do{
	cout << "Which dragon would you like to fight with?" << endl;
	cin >> dragonChoice;
	
	// Reprompts user to choose another hatched egg
	while(m_myDragons[dragonChoice - ELEMENT_SHIFT].GetIsHatched() != success)
	{
	  cout <<"Please choose a dragon that's hatched and is part of your dragon roster." << endl;
	  cin >> dragonChoice;
	}

      }while((dragonChoice <= lowestRoster) || (dragonChoice > playerTotal));
    
      // Grabs the name of the player's dragon
      ally = m_myDragons[dragonChoice - ELEMENT_SHIFT].GetName();

      // Executes both special and regular attack between the player's dragon and enemy dragon
      primaryMove = m_myDragons[dragonChoice - ELEMENT_SHIFT].BreathAttack(m_myDragons[dragonChoice - ELEMENT_SHIFT]);
      attackSuccess =  m_myDragons.at(dragonChoice - ELEMENT_SHIFT).AttackDragon(m_dragons[enemyDragon]);

      // Handles the case where the player's dragon wins the battle
      if((primaryMove == special) || (attackSuccess == success))
      {
	 // Grabs the current/max size of player's dragon
	 curSize = m_myDragons[dragonChoice - ELEMENT_SHIFT].GetCurSize();
	 maxSize = m_myDragons[dragonChoice - ELEMENT_SHIFT].GetMaxSize();

	 // Outputs appropriate result of the battle 
	 if(curSize == enemyDragonSize)
	   cout << "The battle ends in a draw" << endl;
	 else
	   cout << "Your " << ally << " defeats the " << enemy << "!" << endl;
      
	 // Attempts to increase the chosen dragon's size
	 growthResult = m_myDragons[dragonChoice-ELEMENT_SHIFT].AttemptGrow();

	 // Increases current size by one and/or outputs appropriate response
	 if((growthResult == success) && (curSize < maxSize))
	 {
	   increment = dragonSize(int(curSize) + ELEMENT_SHIFT);
	   m_myDragons[dragonChoice - ELEMENT_SHIFT].SetCurSize(increment);
	   cout << "Your dragon grew larger." << endl;
	 }
	 // Handles the case where chosen dragons is at its max size 
         else if(curSize == maxSize)
	   cout << "Your dragon is at its maximum size" << endl;
	 else
	   cout << "Your dragon did not grow larger" << endl;
      }
      
      // Handles the case where the player's dragon loses the battle
      else if(attackSuccess != success)
      {
	// Outputs defeat message and removes deceased dragon from player's roster
	cout << "The enemy " << enemy << " defeats your " << ally << "!" << endl;
	m_myDragons.erase(m_myDragons.begin() + dragonChoice - ELEMENT_SHIFT);
	m_countHatchedDragons--;

	// Resets enemy dragon to default current size for next program execution
	m_dragons[enemyDragon].SetCurSize(tiny);
      }

    }
  }
} 
void Game::DisplayAllDragons()
{
  // Traverses through vector to ensure files were imported successfully
  for(vector<Dragon>::iterator it = m_dragons.begin(); it!= m_dragons.end();it++)
  {
    cout << it->GetName() << " " << it->GetType() << " " << it->GetMaxSize() << " " << it->GetRarity() << endl; 
  }

}
