#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

//This code is supposed to randomly generate two integers.
//Then it is supposed to print out the integers
//Then it is supposed to print out the pointers to the integers
//Then it passes the pointers to the function.
//The function prints out the average of the integers

//There are three errors - one is a runtime that causes a segmentation fault
//The other two are logical errors. Find them using gdb.

//****************************
// TO GET POINTS FOR THIS LAB
// YOU MUST FIND THE ERRORS USING GDB
//***************************

double findAverage(double, double, double); //Function Prototype

int main () {
  cout << "Welcome to Lab 8" << endl;
 
  double a;  //New number
  double b; //New number
  double c = 2.0; // Denominator
  double *ptrA = &a;  //New pointer to num
  double *ptrB = &b;
  double *ptrC = &c;
  
  srand(time(NULL)); //Seeds the random number generator

  // Gets random number
  a = static_cast<double>(rand())*100 / static_cast<double>(RAND_MAX) ;
  b = static_cast<double>(rand())*100 / static_cast<double>(RAND_MAX) ;

  // Prints numbers
  cout << "This are our numbers: a = " << a << " b = " << b <<" c = " << c << endl;
  
  //Prints the dereferenced pointer nums
  cout << "This are our dereferenced pointers: a = " << *ptrA <<" b = " << *ptrB << " c = " << *ptrC<< endl; 
 
  //Passing dereferenced pointers to findAverage()
  cout << "Average: " << findAverage(*ptrB, *ptrA, *ptrC)<< endl; 

  return 0;
}

double findAverage(double num1, double num2, double num3){
  
  return (num1 + num2) / num3;

}
