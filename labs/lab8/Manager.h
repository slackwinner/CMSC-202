#ifndef MANAGER_H
#define MANAGER_H

#include<iostream>
#include<string>

class Manager{

 public:

  Manager(string name, int age, int salary);
  void showDesignation();
  void printSalary();
  
 protected:

  string m_name;
  int m_age;
  int m_salary;


}
#endif



