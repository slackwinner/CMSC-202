#include <iostream>
using namespace std;

int main(void){

  int arr1[] = {1,2,3,4,5};
  int arr2[] = {6,7,8};
  int i;

  for (i = 0; i < 5; i++){
    cout << arr1[i] << " ";
  }
  cout << endl;
  arr2 = arr1;
  for(i=0; i<3;i++){
    cout << arr2[i]<< " "; 
  }

  return 0;

}
