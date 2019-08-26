#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<string>
using namespace std;

class Employee{

 public:

  virtual void raiseSalary() = 0;
  virtual void showDesignation() = 0;

 protected:
  string m_name;
  int m_age;
  int m_salary;
  
}

#endif
