#include "Employee.h"
#include "Manager.h"

#include <iostream>
#include <string>

using namespace std;


int main(){

  Employee *emp;
  Manager mng("John",34,20000);
  //  Developer dev("Patrick",23,10000);
  mng.showDesignation();
  mng.printSalary();
  // dev.showDesignation();
  // dev.printSalary();

  /* cout<<endl<<"Following Prints are done using Pointer of SuperClass" << endl;

  emp = &mng;
  emp->raiseSalary();
  emp->showDesignation();
  emp->printSalary();

  */




}
