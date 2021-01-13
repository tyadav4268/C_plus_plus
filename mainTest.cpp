#include<iostream>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<string>
using namespace std;

void showAllBooks();
void addBook();
void removeBook();

int main(){
  // showAllBooks();
  removeBook();
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
