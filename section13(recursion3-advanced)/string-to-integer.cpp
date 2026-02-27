#include<iostream>
#include<cstring>
using namespace std;

int convertStrtoInt(char a[], int n){
    if(n==0) return 0;

    int smallAns = convertStrtoInt(a, n-1);
    int lastDigit = a[n-1] - '0';
    return (smallAns * 10) + lastDigit;
}

int main(){
    char a[] = "12345";
    int n = strlen(a);
    cout<<convertStrtoInt(a,n)<<endl;
    return 0;
}