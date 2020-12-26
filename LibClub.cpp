#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
using namespace std;

class Student{
  int roll_number;
  char name[255];
  char email[255];
  char orderedBook[255];
public:
  Student(){}
  Student(int rno, char *nm, char *eml, char *oB);
  bool writeToFile();
  void getDetails();
  void setDetails();

  void setRollNumber(int rno){
    roll_number = rno;
  }
  void setName(char *n){
    strcpy(name, n);
  }
  void setEmail(char *eml){
    strcpy(email, eml);
  }
  void setOrderedBook(char *oB){
    strcpy(orderedBook, oB);
  }
};


int main(){
  cout<<"\t\tBooks Order Manager\n";
  Student student;
  student.setDetails();
  student.getDetails();
  return 0;
}

Student::Student(int rno, char *nm, char *eml, char *oB){
  roll_number = rno;
  strcpy(name, nm);
  strcpy(email, eml);
  strcpy(orderedBook, oB);
}

void Student::getDetails(){
  ifstream fin;
  Student student;
  fin.open("orders.dat", ios::binary);
  if(!fin){
    cout<<"\n Error in opening file !";
  }
  else{
    while(fin.read((char *)&student, sizeof(student))){
      cout<<"\nData in the file:\n";
      cout<<"\nName: "<<student.name<<endl;
      cout<<"\nRoll Number: "<<student.roll_number<<endl;
      cout<<"\nEmail id: "<<student.email<<endl;
      cout<<"\nBook to be Ordered: "<<student.orderedBook<<endl;
      cout<<"\n";
    }
  }
  fin.close();
}

void Student::setDetails(){
  cout<<"Enter the Details:\n";
  fflush(stdin);
  cout<<"\nName: ";
  gets(name);
  cout<<"\nRoll Number: ";
  fflush(stdin);
  cin>>roll_number;
  cout<<"\nEmail id: ";
  fflush(stdin);
  cin>>email;
  cout<<"\nBook to be Ordered: ";
  fflush(stdin);
  gets(orderedBook);
  cout<<"\nAre you sure to Proceed?Y/N: ";
  char yn;
  while(true){
    cin>>yn;
    if(yn == 'Y' || yn =='y'){
      if(writeToFile()){
        cout<<"\n\tSuccessful !";
        break;
      }
      else{
        cout<<"Task Failed, Error in writing to File !"<<endl;
      }
    }
    else if(yn == 'N' || yn =='n'){
      cout<<"\n\tCancelled Successfully!";
      break;
    }
    else{
      cout<<"Please choose Y/N or y/n :";
    }
  }
}

bool Student::writeToFile(){
  ofstream fout;
  Student student;
  student.roll_number = this->roll_number;
  strcpy(student.name, this->name);
  strcpy(student.email, this->email);
  strcpy(student.orderedBook, this->orderedBook);
  fout.open("orders.dat", ios::binary);
  if(fout){
    fout.write((char *)&student, sizeof(student));
    fout.close();
    return true;
  }
  return false;
}
