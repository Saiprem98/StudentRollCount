#include "student.h"
#include <string>
#include <sstream>
#include <cstring>

Student::Student(const char * const name, int perm) {
  this->name = NULL;
  this->setName(name);
  this->setPerm(perm);
}

int Student::getPerm() const {
  return this->perm;
}

const char * const Student::getName() const {
  return this->name;
}

void Student::setPerm(const int permNumber) {
  this->perm = permNumber;
}

void Student::setName(const char * const name) {
  if(this->name){
    delete [] this->name;
  }
  this->name = new char[strlen(name)+1];
  strcpy(this->name,name);
}


Student::Student(const Student &orig) {
  this->name = NULL;
  this->setName(orig.name);
  this->setPerm(orig.perm);
}

Student::~Student() {
 
   delete [] this->name;
   // 

}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);
  

  this->setPerm(right.getPerm());
  this->setName(right.getName());
  // char* s1 =const_cast<char *>(right.getName());
  // this->name = s1; 
  // TODO... Here is where there is code missing that you need to 
  // fill in...


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
  std::ostringstream oss;
  oss << "[" ;
      oss << this->getName() << "," ;
      oss << this->getPerm() << "]";
  return oss.str();
}

