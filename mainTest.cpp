#include <string>
#include<dirent.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;


void showAllBooks();
void addBook();
void removeBook();
void showAllUsers();
void searchUser();
void deleteUser();
void modifyUser();

int main(){
    showAllUsers();
    return 0;
}
void showAllBooks(){
    struct dirent *dirent;
    DIR *dir;
    dir = opendir("./resources");
    if(!dir){
        cout<<"Error in opening folder!";
    }
    else{
        int i = 1;
        for(dirent = readdir(dir); dirent != NULL; dirent = readdir(dir)){
            if(strlen(dirent->d_name) > 3){
                cout<<i<<". ";
                cout<<dirent->d_name<<endl;
                cout<<"\n";
                i++;
            }
        }
    }
    closedir(dir);
}

void addBook(){
    //working on Windows for sure
    //Unsure for linux so that part of code is commented out
    //tried but file system brings issue

    // int os = 0;
    // label: cout<<"Choose your operating system: "<<endl;
    // cout<<"1. Linux"<<endl;
    // cout<<"2. Windows"<<endl;
    // cin>>os;
    // char cpywin[10] =  "copy ";
    // char cpyLinux[10] =  "cp ";
    // char cpy[100];
    // if (os == 1){
    //     strcpy(cpy, cpyLinux);
    // }
    // else if(os == 2){
    //     strcpy(cpy, cpywin);
    // }
    // else{
    //   goto label;
    // }
    char loc[100];
    cout<<"Enter complete location of the book: ";
    fflush(stdin);
    //gets(loc) would not require to remove the newline character;
    fgets(loc, 255, stdin);
    int i = 0;
    while(loc[i] != '\n'){
        loc[i] = loc[i];
        i++;
    }
    loc[i] = '\0';
    char cpy[10] =  "copy ";
    char *cmd = strcat(cpy,loc);
    char dest[100] = " \".\\Resources\"";
    char *finalcmd = strcat(cmd, dest);
    cout<<"Executing command: "<<finalcmd<<endl;
    system(finalcmd);

}

void removeBook(){
    showAllBooks();
    char name[255];
    cout<<"Enter the book name from the above list: ";
    cin>>name;
    char del[255] = "del Resources\\";
    char *cmd = strcat(del, name);
    cout<<"Executing command: "<<cmd<<"\n";
    if(system(cmd)){
        cout<<"\nUnsuccessful!";
    }
    else{
        cout<<"\nSuccessfull";
    }
}

typedef struct USER{
    int id;
    char name[255];
    char email[255];
} User;

void showAllUsers(){
    ifstream fin;
    User user;
    fin.open("users.dat", ios::binary);
    if(!fin){
        cout<<"\n Error in opening file !";
    }
    else{
        cout<<left<<setw(7)<<"ID"<<left<<setw(20)<<"Name"<<left<<setw(30)<<"Email Id"<<endl;
        while(fin.read((char *)&user, sizeof(user))){
            cout<<left<<setw(7)<<user.id<<left<<setw(20)<<user.name<<left<<setw(30)<<user.email;
            cout<<"\n";
        }
    }
    fin.close();
}

void searchUser(){
    int choice;
    int id;
    char name[255];

    Label:
    cout<<"Search by:\n1.ID\n2.Name\n";
    cin>>choice;
    if(choice == 1){
        cout<<"Enter Id:";
        cin>>id;
        strcpy(name, "-1");
    }
    else if(choice == 2){
        cout<<"Enter name:";
        fflush(stdin);
        gets(name);
        id = -1;
    }
    else{
        cout<<"Invalid choice!\n";
        goto Label;
    }
    ifstream fin("users.dat", ios::binary);
    User user;
    if(fin){
        int flag = 0;
        while(fin.read((char *)&user, sizeof(user))){
            if(user.id == id || strcmp(user.name, name) == 0){
                cout<<"\nData in the file:\n";
                cout<<"\nID: "<<user.id<<endl;
                cout<<"\nName: "<<user.name<<endl;
                cout<<"\nEmail id: "<<user.email<<endl;
                cout<<"\n";
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout<<"\nNo such record found!";
        }
        fin.close();
    }
    else{
        cout<<"Error in opening file User.dat";
    }
}

void modifyUser(){
    fstream file("users.dat", ios::binary | ios::in | ios::out);
    if(file){
        int id, flag = 0;
        User user;
        cout<<"Enter ID of the user to be modified: ";
        cin>>id;
        while(file.read((char *)&user, sizeof(user))){
            if(user.id == id){
                flag = 1;
                cout<<"Previous Details are: \n";
                cout<<"ID: "<<user.id<<endl;
                cout<<"Name: "<<user.name<<endl;
                cout<<"Email Id: "<<user.email<<endl;
                cout<<"\nEnter New Details:\n";
                cout<<"\nID: ";
                cin>>user.id;
                fflush(stdin);
                cout<<"\nName: ";
                gets(user.name);
                cout<<"\nEmail id: ";
                fflush(stdin);
                gets(user.email);
                // cout<<user.id<<user.name<<user.email<<endl;

                // cout<<file.tellp()<<endl;
                int s = sizeof(user);
                // cout<<s<<endl;
                file.seekp(-s, ios::cur);
                // cout<<file.tellp()<<endl;
                // file.read((char *)&user, sizeof(user));
                // cout<<"Next Details are: \n";
                // cout<<"ID: "<<user.id<<endl;
                // cout<<"Name: "<<user.name<<endl;
                // cout<<"Email Id: "<<user.email<<endl;
                file.write((char *)&user, s);
                break;
            }
        }
        if (flag == 1){
            cout<<"User Details Updated.\n";
        }
        else{
            cout<<"No such Record Found!\n";
        }
    }
    else{
        cout<<"Error in opening file!";
    }

}

void deleteUser(){
    fstream file("users.dat", ios::binary | ios::in);
    ofstream fout("temp.dat", ios::binary| ios::out);
    User user;
    if(file && fout){
        file.seekg(0);
        int id, flag = 0;
        cout<<"Enter ID of the User to be removed:";
        cin>>id;
        while(file.read((char *)&user, sizeof(user))){
            if(user.id == id){
                cout<<"\nData in the file:\n";
                cout<<"\nID: "<<user.id<<endl;
                cout<<"\nName: "<<user.name<<endl;
                cout<<"\nEmail id: "<<user.email<<endl;
                cout<<"\n";
                flag = 1;
            }
            if(user.id != id){
                fout.write((char *)&user, sizeof(user));
            }
        }
        file.close();
        fout.close();
        remove("users.dat");
        rename("temp.dat", "users.dat");
        if(flag == 1){
            cout<<"\nUser removed successfully.\n";
        }
        else{
            cout<<"\nThere is no such record!\n";
        }
    }
    else{
        cout<<"Error in opening file User.dat";
    }
}
