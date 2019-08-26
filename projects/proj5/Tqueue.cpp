
/*****************************************************************                                                                                                               
File: Tqueue.cpp                                                                                                                                                                  
Project: CMSC 202 Project 5, Spring 2018                                                                                                                                         
Author: Dane Magbuhos                                                                                                                                                             
Date: 5/6/18                                                                                                                                                                      
E-mail: mag4@umbc.edu                                                                                                                                                                                                                                                                                                                                          
Description: This project contains the Tqueue driver for project 5.                                                                                                               
This program dynamically expands and shrinks an array.                                                                                                                                                   ******************************************** **********************/                                                                                                                                                                                                                                                                                         
#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor

  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T>& x ); //Copy Constructor

  //Name: Destructor
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor

  //Name: enqueue
  //Precondition: Existing Tqueue
  //Postcondition: Adds item to back of queue.
  //If queue is at capacity, doubles size and copies everything starting at 0
  void enqueue(T data); //Adds item to queue (to back)

  //Name: dequeue
  //Precondition: Existing Tqueue
  //Postcondition: Removes item from front of queue
  //If queue is less than half capacity, halves capacity
  //and copies everything starting at 0
   void dequeue(); //Removes item from queue (from front)

  //Name: queueFront
  //Precondition: Existing Tqueue
  //Postcondition: Returns front item in queue (does not remove it)
  T& queueFront();    // Retrieve front (does not remove it)

  //Name: getBack()
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve int of m_back
  int getBack();

  //Name: getFront()
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve int of m_front
  int getFront();

  //Name: isEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int isEmpty(); //Returns 1 if queue is empty else 0

  //Name: size
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue (not capacity but m_back - m_front)
  int size(); //Returns size of queue

  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T>& operator=( const Tqueue<T> &y); //Overloaded assignment operator for queue

  //Name: Overloaded [] operator
  //Precondition: Existing Tqueue
  //Postcondition: Returns object from Tqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from queue

  //Name: displayTqueue (Test function)
  //Precondition: Existing Tqueue
  //Postcondition: Used to display all members in the Tqueue
  void displayTqueue();

private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
  int m_capacity; //Capacity of the queue
};

template <class T>
Tqueue<T>::Tqueue()
{
  m_capacity = 1;
  m_back = 0;
  m_front = 0;
  m_data = new T[m_capacity];
}


template <class T>
Tqueue<T>::Tqueue(const Tqueue<T>& x): m_front(x.m_front), m_back(x.m_back), m_capacity(x.m_capacity)
{

    m_data = new T[x.m_capacity];
    
    // Traverses through array 
    for(int j = 0; j < m_capacity; j++)
      m_data[j] = x.m_data[j]; 
}

template <class T>
Tqueue<T>::~Tqueue()
{
  delete [] m_data;
  m_data = NULL;

}

template <class T>
void Tqueue<T>:: enqueue(T data)
{
  // Adds items to m_data array
  m_data[m_back] = data;

  // Increases index of array
    m_back = getBack() + 1;

  // Checks to see if index matches capacity
  // Creates new array if true
  if(m_back == m_capacity){

    int tempCap = m_capacity * 2;   // Doubles the capacity for new array
    T* tempArray = new T [tempCap]; // Creates the doubled version of original array

    // Copies items from old contents to new array
    for(int i = 0; i < m_capacity; i++)
      tempArray[i] = m_data[i];
    
    // Increases capacity by two
    m_capacity = tempCap;
    
    // Deletes old array
    delete [] m_data;
 
    // Links temporary array to main array
    m_data = tempArray;
  }

}

template <class T>
void Tqueue<T>::dequeue()
{
  int capacityCheck = m_capacity / 2; // Calculates current half capacity

  // Prevents array from surpassing default array
  if(m_capacity == 1)
  {
    m_back = 0;
    m_front = 0;
    m_data[m_back] = NULL;
  }
  else{
 
    // Shifts the indices
    for(int i = 0; i < size(); i++)
        m_data[i] = m_data[i+1];

    m_back = getBack() - 1;

    // Checks to see if index is half of maximum capacity
    if(size() < capacityCheck){
      T* tempArray = new T [capacityCheck];
    
     // Copies contents from original array to new array
      for(int k = 0; k < capacityCheck; k++)
	 tempArray[k] = m_data[k];

     // Sets the new maximum capacity
     m_capacity = capacityCheck;

     // Deletes the original array
     delete [] m_data;
	
     // Links the temp array to main array
     m_data = tempArray;
	
     // Resets index positions of array
     m_front = 0;
     m_back = size();
    }
      
  }
}

template <class T>
T& Tqueue<T>::queueFront()
{

 return  m_data[m_front];

}

template <class T>
int Tqueue<T>::getBack()
{

  return m_back;

}

template <class T>
int Tqueue<T>::getFront()
{

  return m_front;
}

template <class T>
int Tqueue<T>::isEmpty()
{
  int result = 0;

  if(m_back - m_front == 0)
    result = 1;

  return result;


}

template <class T>
int Tqueue<T>::size()
{
  return m_back - m_front;

}

template <class T>
Tqueue<T>& Tqueue<T>:: operator= (const Tqueue<T> &y)
{
  // Checks to see if object is itself
   if(this != &y){

     // Creates a deep copy of object
     m_front = y.m_front;
     m_back = y.m_back;
     m_capacity = y.m_capacity;

     T* temp = new T[m_capacity];

     // Traverses through array and copies array contents
     for(int i = 0; i < m_capacity; i++)
       temp[i] = y.m_data[i];
     
     delete [] m_data;

     m_data = temp;

   }
  
   return *this;

}


template <class T>
T& Tqueue<T>:: operator[] (int x)
{

  return m_data[x];

}

template <class T>
void Tqueue<T>::displayTqueue()
{

  // Outputs array contents
  for(int i = 0; i < size(); i++){
    cout << m_data[i] << " ";

  }
   cout << endl;
}

// This is the type of code you should test your Tqueue with
// Once you have coded all of the functions, compile just Tqueue and test it

/*int main () {
  cout << "newQ" << endl;
  Tqueue<int> newQ;
  newQ.displayTqueue();
  cout <<"After 1st display " << endl;
  newQ.enqueue(10);
  newQ.displayTqueue();
  newQ.enqueue(20);
  newQ.displayTqueue();
  newQ.enqueue(30);
  newQ.displayTqueue();
  newQ.enqueue(40);
  newQ.displayTqueue();
  newQ.enqueue(50);
  newQ.displayTqueue();
  
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.enqueue(40);
  newQ.displayTqueue();
  
  newQ.enqueue(40);
  newQ.enqueue(50);
  newQ.displayTqueue();

  cout << "newQ2 using assignment operator" << endl;
  Tqueue<int> newQ2;
  newQ2 = newQ;
  newQ2.displayTqueue();

  cout << "newQ3 using copy constructor" << endl;
  Tqueue<int> newQ3(newQ2);
  newQ3.displayTqueue();
  cout << endl << "newQ after two dequeue" << endl;
  newQ.dequeue();
  newQ.dequeue();
  newQ.displayTqueue();
  cout << endl;

  cout << "newQ4 using copy with deletes" << endl;
  Tqueue<int> newQ4(newQ);
  newQ4.dequeue();
  cout << "After 1st deq" << endl;
  newQ4.dequeue();
  cout << "After 2nd deq" << endl;
  newQ4.dequeue();
  cout << "After 3rd deq" << endl;
  newQ4.dequeue();
  cout << "After 4th deq" << endl;
  newQ4.displayTqueue();
  newQ3 = newQ4;
  newQ3.displayTqueue();

  Tqueue<int> newQ5;
  for(int i = 0;i<400;i++){
      newQ5.enqueue(i);
  }
  cout <<"size()= " << newQ5.size() << endl;
  newQ5.displayTqueue();
 
  return 0;
  }*/
#endif
