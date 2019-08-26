/********************************************
File: proj1.cpp
Project: CMSC 202 Project 1, Spring 2018
Author: Dane Magbuhos
Date: 2/9/18
E-mail: mag4@umbc.edu

Description:
This file contains the main driver for Project 1. 
This program reads in the specified Urban Heat Islands
text file, uses the file contents to calculate the 
model temperatures and displays the calculated results
in a two dimension array format. 

******************************************* */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// 2D Array Dimensions
const int ROW = 6;               
const int COLUMN = 5;            

// Temperature Boundaries
const double lowerTemp = -130;   
const double upperTemp = 134;    

// Area multipliers for different areas
const double RURAL = 1.01;       
const double SUB_RES = 1.03;     
const double COMMERCIAL = 1.05;  
const double URBAN_RES = 1.04;   
const double DOWNTOWN = 1.09;    
const double PARK = 1.02;        
const double RURAL_F = 1.00;    

// Name: mainMenu
// PreCondition: There are no pre-conditions (Outputs menu choices) 
// PostCondition: Returns the user's validated choice number for further execution
int mainMenu();

// Name: fileValidator
// PreCondition: String input contains a valid text file name
// PostCondition:  Returns boolean result based on how valid the input is
bool fileValidator(string inputFile);

// Name: tempValidator
// PreCondition: Base temperature input is in between the lower and upper temperature ranges
// PostCondition: Returns boolean based on the user's input
bool tempValidator(double baseTemp);

// Name: printGrid
// PreCondition: There are no pre-conditions (Only serves as an output function)
// PostCondition: Outputs contents in 2D array format
void printGrid(string array[][COLUMN], const int ROW);

// Name: modelTemp
// PreCondition: The string array is populated and baseTemp has a valid number
// PostCondition: Outputs the calculated results in 2D array format
void modelTemp(string landArray[][COLUMN], const int ROW, double baseTemp);

// Name: getCoverFile
// PreCondition: The file name and option are valid
// PostCondition: Files are read in and one of the two options are executed (Outputs read in contents or executes model temp protocol)
void getCoverFile(string fileInput, int option);

int main()
{

  
  int choice;                  // options for user
  int exitChoice = 3;          // exit value for program
  bool result;                 // is input value valid?
  string inputFile;            // name of user's text file input
  string validatedFile = " ";  // name of validated file
 
  cout << "Welcome to the Urban Island Model" << endl;

  // Provides user main menu options
  choice = mainMenu();

  // Only exits while loop if user chooses "EXIT" option
  while (choice != exitChoice)
  {
    
    switch (choice)
    {
    // Handles user's first user option
    case 1:
      // Prompts user to enter file name input
      cout << "What is the name of the file to import?" << endl;
      getline(cin, inputFile);

      // Validates string input
      result = fileValidator(inputFile);

      if (result == true)

        // Imports user's desired file
        getCoverFile(inputFile, choice);

      else	
	// Displays file input error
	cout << "The file " << inputFile << " was not opened" << endl;

      break;
    
     // Handles the second user option
    case 2:
   
      // Validates user's file input
      result = fileValidator(inputFile);

      if (result == true)

	// Imports user's desired file and grabs 2D array temperatures
	getCoverFile(validatedFile, choice);

      else

	// Handles no file import case
	cout << "No file was imported" << endl;

      break;

    default:
      cout << "An error has occured" << endl;
   }
    
    // Stores validated input for second option usage
    validatedFile = inputFile;

    // Resets boolean variable
    result = false;
    
    // Provides user main menu options
    choice = mainMenu();
  }
 
   cout << "Thank you for using the Urban Heat Island Model" << endl;
 
   return 0;

}

int mainMenu()
{

  int choice;          // user's desired option 
  int lowerBound = 1;  // lowest option choice
  int upperBound = 3;  // highest option choice

  do
  {
    // Outputs user's options and validates user's input
     cout << " " << endl;
     cout << "What would you like to do?:" << endl;
     cout << "1) Load Land Cover File" << endl;
     cout << "2) Model Temperatures Based on Land Cover" << endl;
     cout << "3) Exit" << endl;
     cout << " " << endl;
     cin >> choice;
     cin.ignore();
  
  } while ((choice < lowerBound) || (choice > upperBound));

  return choice;
 
}

bool fileValidator (string fileInput)
{

  ifstream inputStream; // fstream open and close variable
  bool result = true;   // is fileInput valid?

  // Opens specified file
  inputStream.open(fileInput.c_str());
  
  // Only returns false if text file does not exists
  if (inputStream.fail())
    result = false;
  
  return result;

}

bool tempValidator (double baseTemp)
{

  bool result = true; // is temperature input valid?

  // Checks the bounds of the user temperature input
  if ((baseTemp < lowerTemp) || (baseTemp > upperTemp))
    result = false;

  return result;
}

void printGrid(string array[][COLUMN], const int ROW)
{

  int currentRow;    // current 2D array row
  int currentCol;    // current 2D array column

  // Traverses through 2D array and outputs the contents
  for (currentRow = 0; currentRow < ROW; currentRow++)
  {
    for (currentCol = 0; currentCol < COLUMN; currentCol++)
    {
      cout << setw(5) << array[currentRow][currentCol] << setw(5);
    }
    // Outputs a newline for next row iteration
    cout << endl;
  }

}

void modelTemp (string landArray[][COLUMN], const int ROW, double baseTemp)
{

  int currentRow;                 // current text file row
  int currentCol;                 // current text file column
  double tempArray[ROW][COLUMN];  // stores temperature values into 2D array
  string rural = "R";             // rural character
  string sub_res = "S";           // suburban character
  string commercial = "C";        // commercial character
  string urban_res = "U";         // urban character
  string downtown = "D";          // downtown character
  string park = "P";              // park character
  string farm = "F";              // rural farmland character
  
  // Traverses through landArray 
  for (currentRow = 0; currentRow < ROW; currentRow++)
  {
    for (currentCol = 0; currentCol < COLUMN; currentCol++)
    {
      // Based on character value, multipies base temperature by corresponding multiplier
      if (landArray[currentRow][currentCol] == rural)
	tempArray[currentRow][currentCol] = RURAL * baseTemp;
        
      else if (landArray[currentRow][currentCol] == sub_res)
	tempArray[currentRow][currentCol] = SUB_RES * baseTemp;
	
      else if (landArray[currentRow][currentCol] == commercial)
	tempArray[currentRow][currentCol] = COMMERCIAL * baseTemp;

      else if (landArray[currentRow][currentCol] == urban_res)
	tempArray[currentRow][currentCol] = URBAN_RES * baseTemp;

      else if (landArray[currentRow][currentCol] == downtown)
	tempArray[currentRow][currentCol] = DOWNTOWN * baseTemp;

      else if (landArray[currentRow][currentCol] == park)
	tempArray[currentRow][currentCol] = PARK * baseTemp;

      else if (landArray[currentRow][currentCol] == farm)
	tempArray[currentRow][currentCol] = RURAL_F * baseTemp;

      // Sets temperature value to round to the nearest tenth place
      cout.setf(ios::fixed);
      cout.setf(ios::showpoint);
      cout.precision(1);
     
      // Outputs calculated temperature in 2D array format 
      cout << setw(8) << tempArray[currentRow][currentCol] << setw(8);

    }  

    // Outputs new line for next row iteration
    cout << endl;
  }
}

void getCoverFile(string fileInput, int option)
{

  ifstream variable;                // name of file text
  int currentRow;                   // current text file row
  int currentCol;                   // current text file column
  int optionA = 1;                  // output file option
  int optionB = 2;                  // model temp option
  string landArray[ROW][COLUMN];    // used to store land values into 2D array
  double baseTemp;                  // user's temperature input
  bool result;                      // is base temp input valid?

  // Opens input file prior to traversing through file
  variable.open(fileInput.c_str());

  // Traverses through 2D array text file 
  for(currentRow = 0; currentRow < ROW; currentRow++)
  {
    for(currentCol = 0; currentCol < COLUMN; currentCol++)
    {
      // Imports text file contents into landArray and contentArray
      variable >> landArray[currentRow][currentCol];
    }
      
  }
  
  // Closes text file
  variable.close();

  // Option A: Output file contents in 2D array format
  if (option == optionA)
  {
    cout << "File successfully loaded" << endl;

    // Displays the text file contents
    printGrid(landArray, ROW);

  }
  // Option B: Calculates model temperatures
  else if (option == optionB)
  {
    // Exits while loop when baseTemp is equal or within range of lower/upper bounds
    while (result == false)
    {
      // Prompts user to enter in base temperature input
      cout << "What is the base temperature?" << endl;
      cin >> baseTemp;

      // Validates baseTemp input
      result = tempValidator (baseTemp);

    }

    // Calls modelTemp function and displays calculated results
    modelTemp(landArray, ROW, baseTemp);
  }

}
