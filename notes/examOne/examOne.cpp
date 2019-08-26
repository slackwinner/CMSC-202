# include <iostream>
using namespace std;

const int NUM_SCORES = 3;


void absoluteValue(int &input);

int main(){

  // int numScores = 3;
  double total = 185.45;
  cout << "Num Scores: " << total/ NUM_SCORES  << endl;

  cout << endl;

  /////////////////////////////////////////////////////////////////
  /*  int x = 0;

  if ((x != 0) || (3/x > 1))
    cout << "It works" <<endl;
  else
  cout << "0 case failed" << endl;*/

  ////////////////////////////////////////////////////////////////

  int input;
  // int *inputPTR = &input;

  cout << "Input a integer" << endl;
  cin >> input;

  absoluteValue(input);
  
  cout << input << endl;

}

void absoluteValue(int &input){

  int counter = 0;
  int absoluteValue;

  if (input >= 0)
    input = input;
  else{
    
    while (counter >= input){

      if (counter == input)
	input = absoluteValue;
      else
	absoluteValue++;
	 counter--;
  
    }
  }
}
