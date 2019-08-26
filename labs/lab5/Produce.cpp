#include "Produce.h"
using namespace std;

Produce::Produce() {
  m_ProduceName = "Pineapple";
  m_Price = 1.29;
  m_Barcode = 12345;
}

Produce::Produce(string produceName, double price, int barcode){
  m_ProduceName = produceName;
  m_Price = price;
  m_Barcode = barcode;
}

string Produce::GetProduceName(){
  return m_ProduceName;
}
double Produce::GetPrice(){
  return m_Price;
}
int Produce::GetBarcode(){
  return m_Barcode;
}

void Produce::SetProduceName(string produceName){
  m_ProduceName = produceName;
}
void Produce::SetPrice(double price){
  m_Price = price;
}
void Produce::SetBarcode(int barcode){
  m_Barcode = barcode;
}

