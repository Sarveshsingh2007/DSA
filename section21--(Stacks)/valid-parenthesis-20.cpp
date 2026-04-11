#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string A) {
        stack<char> s;
        for(int i = 0; i < A.size(); i++){
            if(A[i] == '(' || A[i] == '{' || A[i] == '['){
                s.push(A[i]);
            }else{
                if(s.empty()) return false;

                if(A[i] == ')'){
                    if(s.top() == '(') s.pop();
                    else return false;
                }
                else if(A[i] == '}'){
                    if(s.top() == '{') s.pop();
                    else return false;
                }
                else if(A[i] == ']'){
                    if(s.top() == '[') s.pop();
                    else return false;
                }
            }
        }
        return s.empty();
    }
};

int main() {
    Solution obj;

    string str;
    cout << "Enter string: ";
    cin >> str;

    if(obj.isValid(str)){
        cout << "Valid Parentheses" << endl;
    } else {
        cout << "Invalid Parentheses" << endl;
    }

    return 0;
}