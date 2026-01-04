#include<iostream>
#include<cstring>
using namespace std;

void printallprefixes(char str[]){
    for (int i=0;i<strlen(str);i++){
        for (int j=0; j<=i; j++){
            cout<<str[j];
        }
        cout<<endl;
    }
}

int main(){
    char str[] = "abcd";
    printallprefixes(str);

    return 0;
}