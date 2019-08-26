#include "Animal.h"
#include <iostream>
using namespace std;

int main(){

  Animal a;

  string animalOne = "Molly";
  string animalTwo = "Billy";
  string altName = "Kitty";

  string soundOne = "Bow Bow";
  string soundTwo = "Meow Meow";

  a.setName(animalOne);
  cout << "Animal1's name is: " << a.getName() << endl;

  a.setMakeSound(soundOne);
  cout <<"Animal1 makes sound: " << a.getMakeSound() << endl;

  a.WhoAmI();
  cout << endl;

  a.setName(animalTwo);
  cout << "Animal2's name is: " << a.getName() << endl;

  a.setMakeSound(soundTwo);
  cout<< "Animal2 makes sound: " << a.getMakeSound() <<endl;

  a.setName(altName);
  cout <<"Animal2's name changed to: " << a.getName();

  a.WhoAmI();

  return 0;

 }
