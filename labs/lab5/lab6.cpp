#include "Produce.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// fill vector - fills produce info
// vector<Produce>& - produce in your grocery list
void fillVector(vector<Produce>&);

// printVectorWithIterator - prints the information 
// of all produce using unsigned int
void printVectorWithIterator(vector<Produce>&);

// printVectorWithoutIterator - prints the information 
// of all produce using the ::iterator
void printVectorWithoutIterator(vector<Produce>&);

int main () {
  //Creates a new vector of produce for your grocery list
  vector<Produce> myGroceryList;

  //Populates the vector
  fillVector(myGroceryList);

  cout << "Grocery List using unsigned int: " << endl;
  // Prints the contents of the vector using unsigned int
    printVectorWithoutIterator(myGroceryList);  

  cout << "\n";
  cout  << "Grocery List using the ::iterator:" << endl;
  // Prints the contents of the vector using ::iterator 
   printVectorWithIterator(myGroceryList);
  
  return 0;
}

void fillVector(vector<Produce>& newGroceryList) {

  //Write this function
  //Needs to ask how many items/produce
  //Gets produce name, price, and barcode of the item
  
  //Needs to add produce to the vector

  int itemAmount;
  int count = 1;
  string name;
  double price;
  int barcode;

  cout << "How many items in your grocery list?: " << endl;
  cin >> itemAmount;

  while (count <= itemAmount){
    Produce p;
    cout << "Produce " << count << " name: ";
    cin >> name;
    cout << endl;
   
    cout << "Produce " << count << " price: ";
    cin >> price;
    cout << endl;

    cout << "Produce " << count << " barcode: ";
    cin >> barcode;
    cout << endl;

    p.SetProduceName(name);
    p.SetPrice(price);
    p.SetBarcode(barcode);

    newGroceryList.push_back(p);
    // newGroceryList.push_back(p.GetPrice());
    // newGroceryList.push_back(p.GetBarcode());

    /* cout << p.GetProduceName() << endl;
    cout << p.GetPrice() << endl;
    cout << p.GetBarcode() << endl;*/

    count++;
    
  }

}

void printVectorWithoutIterator(vector<Produce>& newGroceryList){
  // Print out the vector using unsigned int

   for (unsigned int i = 0; i < newGroceryList.size(); i++){
     cout << newGroceryList[i].GetProduceName() << " ";
     cout << newGroceryList[i].GetPrice() << " ";
     cout << newGroceryList[i].GetBarcode() << endl;

    }

}
void printVectorWithIterator(vector<Produce>& newGroceryList){
  // Print out the vector using ::iterator
  // cout << "Did we get here?" << endl;
  for (vector<Produce>::iterator it = newGroceryList.begin(); it != newGroceryList.end();++it){
    cout << " " << it->GetPrice() << " ";
    cout << " " << it->GetBarcode() << " ";
    cout << " " << it->GetProduceName() << endl;

    //*(it.GetPrice())
}
  
  
}
