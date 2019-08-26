#indef DEVELOPER_H
#include DEVELOPER_H

#include "Emp.h"
#include "Manager.h"
using namesapce std;

class Developer::Employee{

 public:
  void raiseSalary();
  void showDesignation();

 protected:
  string name;
  int age;
  int salary;
}
