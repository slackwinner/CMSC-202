#ifndef PRODUCE_H
#define PRODUCE_H

#include <iostream>
#include <string>
using namespace std;

class Produce {
 public:
  //Default Constructor
  Produce();
  //Overload Constructor
  Produce(string produceName, double price, int barcode);

  string GetProduceName();
  double GetPrice();
  int GetBarcode();

  void SetProduceName(string produceName);
  void SetPrice(double price);
  void SetBarcode(int barcode);

 private:
  string m_ProduceName;
  double m_Price;
  int m_Barcode;
};

#endif
