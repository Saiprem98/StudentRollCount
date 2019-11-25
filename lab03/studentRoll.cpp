#include <string>
#include <iostream>
#include "studentRoll.h"
//using namespace std;

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {

 
  // int perm1 = s.getPerm();
  // const char *name1 = s.getName();
  // Student *s1 = nullptr;
  // s1->setName(name1);
  // s1->setPerm(perm1);
  Node* add = new Node;
  add->s = new Student(s);
  
   // Node *last = new Node;
   // last-> s= s1;
   if(head == 0){
    head = add;
    tail = add;
    //head->s = s1;
    add->next = 0;
   }
   else{

  tail->next = add;
  // tail = tail->next;
  tail = add;
  tail->next= 0;
  // tail = last; 
  // last -> next = NULL;
}
 
}

std::string StudentRoll::toString() const {
  std:: string result;

  Node *temp = this->head;
  result += "[";
  while(temp != NULL){
    result += temp->s->toString();
    if(temp->next != NULL){
      result += ",";
    }
    temp = temp->next;
  } 
  result += "]";
   return result ;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  // STUB
  
  Node* current = orig.head;
  // if(current == NULL){
  //   head = new Node;
  //   x1->s=current->s;
  //   x1->next = 0;
  // }
  this->head = NULL;
  this->tail = NULL;
  while(current != NULL){
    this->insertAtTail(*current->s);
    // x1->s = current->s;
    // if(current->next != NULL){
    //   x1->next = new Node;
    //   x1 = x1->next;
    // }

    current = current->next;
  }

 
}

StudentRoll::~StudentRoll() {
  // STUB
  Node* current = this->head;
  while(current != NULL){
    current = head->next;
    delete head->s;
    delete head;
    head = current;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);


  // TODO... Here is where there is code missing that you need to 
  // fill in...
  Node* first = right.head;
  // while(first){
  //   Node* skip = first->next;
  //   delete first;
  //   first = skip;
  // }

  //this->head=NULL;
  //first = right.head;
  while(first){
    this->insertAtTail(*first->s);
    first = first->next;
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





