#include "Gemstone.h"

using namespace std;


Gemstone::Gemstone(){

  int count = 1;
  int i = 0;
  string gemType;
  
  cout <<"Enter the amount of Gemstones in your collection: ";
  cin >> m_num;

  m_ptr = new string[m_num];

  while(count <= m_num){
    cout <<"Gemstone name " << count <<": ";
    cin >> gemType;

    m_ptr[i] = gemType;
    
    count++;
    i++;
  }
}


Gemstone::~Gemstone(){

  delete[] m_ptr;

}

void Gemstone::Display(){

  cout <<"Displaying Gemstone names."<<endl;
  for(int i = 0; i < m_num; i++){
    cout<< "Gemstone name " << i+1 << ": " << m_ptr[i] << endl;
  }
}
