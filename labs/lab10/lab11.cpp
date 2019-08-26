#include "Registration.h"

//using namespace std;
Registration copyConstructorDemo(Registration tempReg) {
  cout << "Copy Constructor called twice." << endl;
  cout << "Once for the formal parameter being passed by value" << endl;
  cout << "Once for the return value." << endl;
  return tempReg;
}

int main() {
  Registration reg1; //Constructor Called (overloaded constructor with default values)

  reg1.insert("Math"); //Adds Math to the Registration
  reg1.insert("Chemistry"); //Adds Chemistry to the Registration
  reg1.insert("Biology"); //Adds Biology to the Registration
  reg1.insert("English"); //Adds English to the Registration
  reg1.insert("French"); //Adds French to the Registration
  
  cout << reg1 << endl; //Calls the overloaded << operator to output the registration
  
  Registration reg2("Jane Doe",4); //Constructor called (uses overloaded constructor)
  
  reg2.insert("Physics"); //Adds Physics to the Registration 2
  
  cout << endl << "**Pass by Value/Return by Value Example**" << endl;
  copyConstructorDemo(reg2); //Calls the copy constructor as part of pass by value
  cout << "**End of Pass by Value/Return by Value Example**" << endl << endl;

  //Copy constructor invoked
  Registration reg3 = reg2;
  
  //Overloaded assignment operator invoked
  reg2 = reg1;
  
  cout << "reg2: " << reg2 << endl;//Calls overloaded << operator outputs registration
  cout << "reg1: " << reg1 << endl;//Calls overloaded << operator outputs registration
  cout << "reg3: " << reg3 << endl;//Calls overloaded << operator outputs registration
  
}
