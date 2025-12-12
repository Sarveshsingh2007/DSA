// #include<iostream>
// #include<cstring>
// using namespace std;

// void reverseString(char input[]){
//     int n = strlen(input); //length of string
//     for (int i=n-1;i>=0;i--){
//         cout<<input[i];
//     }
// }

// int main(){

//     char name[100];
//     cout<<"Enter your name: ";
//     cin.getline(name, 100);
//     cout<<"name is: "<<name<<endl;;
//     cout<<"reversed name is: ";
//     reverseString(name);

//     return 0;
// }

#include<iostream>
using namespace std;

int length (char input[]){
    int count = 0;
    for (int i=0; input[i]!= '\0'; i++){
        count++;
    }
    return count;
}

void reverse(char input[]){
    int s = 0;
    int e = length(input) - 1;

    while (s<e){
        swap(input[s], input[e]);
        s++;
        e--;
    }
}

int main(){
    char name[100];
    cout<<"enter name: ";
    cin.getline(name, 100);
    cout<<"name is: "<<name<<endl;

    reverse(name);
    cout<<"reversed name is: "<<name<<endl;
    
    return 0;
}