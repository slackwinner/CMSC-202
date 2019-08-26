#include <iostream>
#include "Manager.h"

using namespace std;

Manager::Manager(string name, int age, int salary){

  m_name = name;
  m_age = age;
  m_salary = salary;

}


void Manager::showDesgnation(){

  cout << "I am a manager" << endl;




}

void Manager::printSalary(){

  cout << "My salary is: " << m_salary << endl;


}
