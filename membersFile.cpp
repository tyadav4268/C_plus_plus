void LibClub::readFromFile(){
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

bool LibClub::writeToFile(){
  ofstream fout;
  Student student;
  student.roll_number = this->roll_number;
  strcpy(student.name, this->name);
  strcpy(student.email, this->email);
  strcpy(student.orderedBook, this->orderedBook);
  fout.open("orders.dat", ios::binary | ios::app);
  if(fout){
    fout.write((char *)&student, sizeof(student));
    fout.close();
    return true;
  }
  return false;
}
