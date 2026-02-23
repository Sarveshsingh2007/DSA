#include<iostream>
using namespace std;

bool checkPalindrome(int a[], int s, int e){
    if(s>=e) return true;
    if(a[s] != a[e]) return false;

    return checkPalindrome(a, s+1, e-1);
}

int main(){
    int a[] = {1,2,3,3,2,1};
    int n = sizeof(a)/sizeof(a[0]);
    if(checkPalindrome(a, 0, n-1))
        cout << "Array is Palindrome";
    else
        cout << "Array is Not Palindrome";

    return 0;
}