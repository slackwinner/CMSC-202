/* Dane Magbuhos
   lab3.cpp
*/

#include <iostream>
using namespace std;

const int NUM_OF_ELEMENTS = 25;

void reverse(int data[], int dataLen);

int main(){

  int arr[NUM_OF_ELEMENTS] = {0};
  int numElements = 0;
  int inputValue;
  int j;
  int i;

  cout <<"Enter a number (-1 when done): ";
  cin >> inputValue;

  while((inputValue != -1)){
    
    arr[numElements] = inputValue;
    numElements++;
    
    cout << "Enter a number (-1 when done): ";
    cin >> inputValue;
    
  }

  cout <<"Contents of Array: "<<endl;
  
  for (j = 0; j < numElements; j++){
    cout << arr[j] << ", ";

  }
  
  cout <<endl;

  reverse(arr, numElements);
 
  cout << "Reversed Array: " <<endl;

  for (i = 0; i < numElements; i++){
    cout << arr[i] << ", ";
    
  }

  cout <<endl;

}

void reverse(int data[], int dataLen){

  int i = 0;
  int j = dataLen - 1;
  int temp;

  /* for (i = dataLen - 1; i < j; --i){
     temp = data[j];
     data[j] = data[i];
     data[i] = temp;
     j++;
     }*/
    while (i < j){
      temp = data[i];
      data[i] = data[j];
      data[j] = temp;
      ++i;
      --j;
    } 



}
