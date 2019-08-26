/* 

Name: Dane Magbuhos
Lab #: 02

*/

#include <iostream>
#include <string>
using namespace std;

string getName();
int getAge();
void printLetter(int age); //void does not return any value


int main(){
  
  string name = "";
  int age = 0;
  
  name = getName();
  age = getAge();
  cout << name; 
  printLetter(age);

  return 0;
}

string getName(){
  
  string name = "";

  cout << "Enter your name" << endl;
  getline(cin, name);

  while((name.length() < 2) || (name.length() > 15)){
      cout << "Invalid name length"<<endl;
      cout<< "Enter your name"<<endl;
      getline(cin, name);
   }

  return name;

}

int getAge(){

  int age = -1;

  cout << "Enter your age" << endl;
  cin >> age;

  while(age < 0){

     cout << "Invalid age" << endl;
     cout << "Enter in a valid age" << endl;
     cin >> age;
    }
  
  return age;
}

void printLetter(int age){

  switch(age){

  case 0 ... 34:
    cout <<  " is in the millennial generation " << endl;
    break;

  case 35 ... 50:
    cout << " is in the Gen X generation " << endl;
    break;

  case 51 ... 69:
    cout << " is in the Boomer generation " << endl;
    break;

  case 70 ... 87:
    cout << " is in the Silent generation " << endl;
    break;
      
  default:
    cout << " is in the greatest generation " << endl;
      
  }

}
