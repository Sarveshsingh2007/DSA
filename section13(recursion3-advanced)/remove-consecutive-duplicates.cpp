#include<iostream>
using namespace std;

void removeconsecutiveduplicates(char a[]){
    if(a[0] == '\0') return;

    if(a[0] == a[1]){
        for(int i = 0; a[i] != '\0'; i++){
            a[i] = a[i+1];
        }
        removeconsecutiveduplicates(a);
    }
    else{
        removeconsecutiveduplicates(a + 1);
    }
}

int main(){
    char a[] = "aabccdds";
    cout<<"Original: "<<a<<endl;
    removeconsecutiveduplicates(a);
    cout<<"After removing consecutive duplicates: "<<a<<endl;
    return 0;
}