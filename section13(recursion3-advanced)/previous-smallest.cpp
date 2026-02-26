#include<iostream>
#include<stack>
using namespace std;

int main(){
    int a[] = {4,7,1,3,5,2,6};
    int n = sizeof(a)/sizeof(a[0]);

    stack<int> s;

    for(int i = 0; i < n; i++){

        while(!s.empty() && s.top() >= a[i]){
            s.pop();
        }

        if(s.empty()){
            cout << -1 << " ";
        } else {
            cout << s.top() << " ";
        }

        s.push(a[i]);
    }

    return 0;
}