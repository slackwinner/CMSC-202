#include <iostream>
#include <string>
using namespace std;

const int START = 0;
const int END = 10;

struct Node {
  int num;
  Node * next;
};

class LinkedList{
public:
  LinkedList(){m_head = NULL;}
  ~LinkedList(){
    Node * ptrNode = m_head;    
    while(ptrNode != NULL){
      ptrNode = m_head->next;
      delete m_head;
      m_head = ptrNode;
    }
  }
  void insert(int value){
    //If the linked list is empty
    if (m_head == NULL) {
      m_head = new Node();
      m_head->num = value;
      m_head->next = NULL;
      return;
    }
    //insert at the beginning
    Node *curr = new Node();
    curr->num = value;
    curr->next = m_head;
    m_head = curr;
  }

  void displayRec(){
    //Step 1: call helper function and print the list in reverse

    displayRecHelper(m_head);
    cout << "END" << endl;
  }


  //Iterates through linked list and displays
  void display(){
    Node * ptrNode = m_head;
    while(ptrNode){
      cout << ptrNode->num << "-->";
      ptrNode = ptrNode->next;
    }
    cout << "END" << endl;
  }

private:
  Node* m_head;
  void displayRecHelper(Node *currNode){
    //**RECURSIVE**
    //Step 2: Code the recursive function for printing the list

    if(currNode->next == NULL)
      cout << currNode->num << "-->";
    else{
      displayRecHelper(currNode->next);
      cout << currNode->num << "-->";
    }
  }

};

//Creates linked list and inserts 0-9 then displays
int main (){
  LinkedList ll;
  for(int i = START; i < END;i++){
    ll.insert(i);
  }
  ll.display();
  ll.displayRec();
  return 0;
}
