#include <iostream>
#include<conio.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
using namespace std;


int main(){
  int choice;
  LibClub libclub;
  cout<<"\t\t Welcome to The LibClub\n";
  cout<<"\n1. New User";
  cout<<"\n2. Already a member";
  cout<<"\n3. Admin";
  cout<<"\n4. Exit";
  cout<<"Enter your choice: ";
  while(true){
  cin>>choice;
    switch(choice){
      case 1:
        libclub.newUser();
        break;
      case 2:
        libclub.memberLogin();
        break;
      case 3:
        libclub.adminLogin();
        break;
      case 4:
        exit(0);
      default:
        cout<<"Invalid choice !";
    }
  }
  return 0;
}
