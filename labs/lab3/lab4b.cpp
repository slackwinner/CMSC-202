/*

Dane Magbuhos
lab4b

*/

#include <iostream>
using namespace std;

void swapNum2 (int *x, int *y);


int main(){

  int a;
  int b;

  int *x = &a;
  int *y = &b;

  // *x = &a;
  // *y = &b;

  cout << "Value of x: " <<endl;
  cin >> a;


  cout <<"Value of y: " <<endl;
  cin >> b;

  swapNum2 (x, y);

  cout <<" x is " << a << endl;
  cout <<" y is " << b << endl; 

}


void swapNum2 (int *x, int *y){

  int tempX = *x;
  int tempY = *y;

 *x = tempY;
 *y = tempX;
 
  /*  tempY = *x;
  tempX = *y;
  */
}
