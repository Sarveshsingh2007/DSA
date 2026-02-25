#include<iostream>
using namespace std;

void removeA(char a[]){
    if(a[0] == '\0') return;
    if(a[0] != 'a'){
        removeA(a + 1);
    }else{
        for(int i=0;a[i]!='\0';i++){
            a[i] = a[i+1];
        }
        removeA(a);
    }
}

int main(){
    char a[] = "abmacd";
    cout<<"Original: "<<a<<endl;
    removeA(a);
    cout<<"After removing a: "<<a<<endl;
    return 0;
}