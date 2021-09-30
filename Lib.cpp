class LibClub{
public:
  void newUser();
  void memberLogin();
  void adminLogin();
  void showAllBooks();
};

void LibClub::newUser(){
  cout<<"\n\tWelcome to The LibClub";
  NewUser newUser;
  newUser.setDetails();
  newUser.verifyDetails();
  newUser.writeToFile();
  memberLogin();
}

void LibClub::memberLogin(){
  Member member;
  while(1){
    clrscr();
    cout<<"Enter email id: ";
    cin>>member.email;
    cout<<"Enter Password: ";
    cin>>member.password;
    if(member.verifyMember(email, password)){
      member.loginMember();
      break;
    }
    else {
      cout<<"Wrong Credentials !";
    }
    getch();
  }
}

void LibClub::adminLogin(){
  int code;
  while(1){
    clrscr();
    cout<<"Enter code";
    cin>>code;
    if(code == 4268){
      break;
    }
    else {
      cout<<"Wrong Credentials ! Press any key to try again !";
    }
    getch();
  }
  clrscr();
  while(1){
    switch(menu()){
      case 1:
        showAllBooks();
        break;
      case 2:
        addBook();
        break;
      case 3:
        removeBook();
        break;
      case 4:
        showAllUsers();
        break;
      case 5:
        deleteUser();
        break;
      case 6:
        modifyUser();
        break;
      case 7:
        exit(0);
        break;
      default:
        cout<<"Invalid input !"
    }
  }
}
int menu(){
  int choice;
  cout<<"\n1. Show All Books";
  cout<<"\n2. Add a Book";
  cout<<"\n3. Remove a Book";
  cout<<"\n4. Show All Users";
  cout<<"\n5. Delete an User";
  cout<<"\n6. Modify an User's Details";
  cout<<"\n7. Exit";
  cout<<"Enter Your Choice: ";
  
  do      
  {
    cin>>choice;
    if((choice<1) || (choice>7)){
      cout<<"Invalid input! Please try again. \nEnter Your Choice: ";
    }
  }while((choice<1) || (choice>7));
  
  return choice;
}



removeBook();

showAllUsers();

deleteUser();

modifyUser();
