class NewUser{
  int roll_number;
  char name[255];
  char email[255];
public:
  NewUser(){}
  NewUser(int rno, char *nm, char *eml, char *oB);
  bool writeToFile();
  void getDetails();
  void registerUser();
  void verifyDetails();
  void readFromFile();

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

NewUser::registerUser(int rno, char *nm, char *eml, char *oB){
  roll_number = rno;
  strcpy(name, nm);
  strcpy(email, eml);
  strcpy(orderedBook, oB);
}

void NewUser::verifyDetails(){
  cout<<"\nDetails entered:\n";
  cout<<"\nName: "<<this->name<<endl;
  cout<<"\nRoll Number: "<<this->roll_number<<endl;
  cout<<"\nEmail id: "<<this->email<<endl;
  cout<<"\nBook to be Ordered: "<<this->orderedBook<<endl;
  cout<<"\n";
}
void NewUser::setDetails(){
  cout<<"Enter the Details:\n";
  fflush(stdin);
  cout<<"\nName: ";
  gets(name);
  cout<<"\nRoll Number: ";
  fflush(stdin);
  cin>>roll_number;
  cout<<"\nEmail id: ";
  fflush(stdin);
  gets(email);
  cout<<"\nBook to be Ordered: ";
  fflush(stdin);
  gets(orderedBook);
}
