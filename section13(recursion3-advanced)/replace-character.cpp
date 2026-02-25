#include<iostream>
using namespace std;

void replaceChar(char input[]){
    if(input[0] == '\0') return;

    if(input[0] == 'a'){
        input[0] = 'x';
    }

    replaceChar(input + 1);
}

int main(){
    char input[100];

    cout<<"Enter characters: ";
    cin>>input;

    cout<<"Original array: "<<input<<endl;

    replaceChar(input);   

    cout<<"After replacing a with x: "<<input<<endl;

    return 0;
}