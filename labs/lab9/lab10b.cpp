#include <iostream>
using namespace std;



//Use this to implement the templated class calculator
//The constructor should take in two "numbers" and then call displayResult
//displayResult should add, subtract, divide, and multiply each pair of numbers
//Implement the class calculator here:

template <class T>
class Calculator{

private: 
  T m_numOne;
  T m_numTwo;

public:
  void displayResult();
  Calculator(T, T);

};

template <class T>
Calculator<T>::Calculator(T numOne, T numTwo)
{
  m_numOne = numOne;
  m_numTwo = numTwo;

} 

template <class T>
void Calculator<T>::displayResult()
{
  cout <<"Numbers are: " << m_numOne << " and " << m_numTwo << endl;
  cout <<"Addition: " << m_numOne + m_numTwo << endl;
  cout <<"Subtraction: " << m_numOne - m_numTwo << endl;
  cout <<"Product: " << m_numOne * m_numTwo << endl;
  cout <<"Division: " << m_numOne / m_numTwo << endl;

}

int main()
{
  Calculator<int> intCalc(2, 1);
  Calculator<float> floatCalc(2.4, 1.2);
  
  cout << "Int results:" << endl;
  intCalc.displayResult();
  
  cout << endl << "Float results:" << endl;
  floatCalc.displayResult();
  
  return 0;
}







