#include "main.hpp"
class User{
    int id;
    char name[255];
    char email[255];
public:
    void registerUser();
    void verifyDetails();
    bool writeToFile();
    void setId(int idIn){
        id = idIn;
    }
    void setName(char *nameIn){
        strcpy(name, nameIn);
    }
    void setEmail(char *emailIn){
        strcpy(email, emailIn);
    }
    int getId(){
        return id;
    }
    char* getName(){
        return name;
    }
    char* getEmail(){
        return email;
    }
};

void User::registerUser(){
    cout<<"\nEnter the Details:\n";
    cout<<"\nID: ";
    cin>>id;
    fflush(stdin);
    cout<<"\nName: ";
    gets(name);    
    cout<<"\nEmail id: ";
    fflush(stdin);
    gets(email);
    verifyDetails();
}
void User::verifyDetails(){
    cout<<"\nDetails entered:\n";
    cout<<"\nName: "<<this->name<<endl;
    cout<<"\nID: "<<this->id<<endl;
    cout<<"\nEmail id: "<<this->email<<endl;
    cout<<"\n";
    char confirmation;
    cout<<"\nPlease verify the details and enter y(yes)/n(no).";
    cin>>confirmation;
    if(confirmation == 'y' || confirmation == 'Y'){
        if(writeToFile()){
            cout<<"\nYou are registered successfully!";
        }
        else{
            cout<<"\nThere is some internal issue! Couldn't register!";
        }
    }
    else if(confirmation == 'n' || confirmation == 'N'){
        cout<<"\nCancelled successfully!";
    }
}
bool User::writeToFile(){
    ofstream fout;
    User user;
    user.id = this->id;
    strcpy(user.name, this->name);
    strcpy(user.email, this->email);
    fout.open("users.dat", ios::binary | ios::app);
    if(fout){
        fout.write((char *)&user, sizeof(user));
        fout.close();
        return true;
    }
    return false;
}

int main(){
    User user;
    user.registerUser();
    return 0;
}


// typedef struct USER{
//     int id;
//     char name[255];
//     char email[255];
// } User;
