#include<iostream>
using namespace std;

int length(char input[]){
    int count = 0;
    for (int i=0;input[i] !='\0';i++){
        count++;
    }
    return count;
}

int main(){
    char name[100];
    char petname[100];
    cout<<"Enter your name: ";
    cin.getline(name, 100);
    cout<<"Your name is: "<<name<<endl;
    cout<<"Length is: "<<length(name)<<endl;

    
    cout<<"\nEnter your petname: ";
    cin.getline(petname, 100,  'o');
    cout<<"Your petname will print upto o: "<<petname<<endl;
    cout<<"Length is: "<<length(petname)<<endl;
    return 0;
}

