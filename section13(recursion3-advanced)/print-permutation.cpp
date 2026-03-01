#include<iostream>
using namespace std;

void printPermutation(char a[], int i = 0){
// base case 
    if(a[i] == '\0'){
        cout << a << endl;
        return;
    }
 
    for(int j = i; a[j] != '\0'; j++){
        swap(a[i], a[j]);             
        printPermutation(a, i + 1);    
        swap(a[i], a[j]);              
    }
}

int main(){
    char a[] = "ABC";
    printPermutation(a);
    return 0;
}