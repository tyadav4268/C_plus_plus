#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

int menu(){
    int choice;
    cout<<"\n\t\t Welcome to The LibClub\n";
    cout<<"\n1. New User";
    cout<<"\n2. Already a member";
    cout<<"\n3. Admin";
    cout<<"\n4. Exit";
    cout<<"\nEnter your choice: ";
    cin>>choice;
    return choice;
}

int main(){
    // LibClub libclub;
    while(true && !cin.fail()){
        switch(menu()){
            case 1:
            cout<<"New User.";
            // libclub.newUser();
            break;
            case 2:
            cout<<"member.";
            // libclub.memberLogin();
            break;
            case 3:
            cout<<"admin.";
            // libclub.adminLogin();
            break;
            case 4:
            exit(0);
            default:
            cout<<"Invalid choice !";
        }
    }
    return 0;
}
