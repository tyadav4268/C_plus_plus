class Member{
private:
  char email[255];
  char password[255];
public:
  bool verifyMember();
  void loginMember();
};

bool Member::verifyMember(char *eml, char *pass){
  Member member;
  ifstream fin;
  fin.open("member.dat" | ios::binary);
  while(fin.read((char *)&member, sizeof(member))){
    if(strcmp(member.email,eml) && strcmp(member.password,pass)){
      return true;
    }
  }
  return false;
}

void Member::loginMember(){
  int choice;
  cout<<"\n\tWelcome to The LibClub";
  cout<<"\n1. Show all books";
  cout<<"\n2. Order a book";
  cout<<"\n3. Exit";
  cout<<"Enter your choice: ";
  while(true){
  cin>>choice;
    switch(choice){
      case 1:
        libclub.showAllBooks();
        break;
      case 2:
        libclub.placeOrder();
        break;
      case 3:
        exit(0);
      default:
        cout<<"Invalid choice !";
    }
  }
}

void Member::placeOrder(){
  cout<<"\nAre you sure to place the order? Y/N: ";
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
