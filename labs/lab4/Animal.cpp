#include "Animal.h"

void Animal::setMakeSound(string sound){

  m_makeSound = sound;

}

void Animal::setName(string name){

  m_name = name;

}

string Animal::getMakeSound(){

  return m_makeSound;
}

string Animal::getName(){

  return m_name;

}

void Animal::WhoAmI(){

  if (m_name == "")
    cout << "I do not have a name" << endl;
  else if (m_makeSound == "")
    cout << "I do not make a sound" << endl;

  else{
    cout << endl;
    cout <<" My name is " << m_name << " and I say " << m_makeSound << endl;
  }
}
