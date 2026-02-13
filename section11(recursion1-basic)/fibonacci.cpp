#include<iostream>
using namespace std;

int fib(int n){
    for(int i=0;i<n;i++){
        if(n==0) return 0;
        if(n==1) return 1;

        int a = 0, b=1, c;

        for(int i=2;i<=n;i++){
            c= a+b;
            a = b;
            b = c;
        }
        return b;
    }
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    
    
    cout<<"Fibonacci of "<<n<<" is: "<<fib(n)<<endl;
    return 0;
}
