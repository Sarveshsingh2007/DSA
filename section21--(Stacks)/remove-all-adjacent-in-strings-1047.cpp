#include <iostream>
#include <stack>
#include <string>
#include <algorithm> // for reverse
using namespace std;

class Solution {
public:
    string removeDuplicates(string A) {
        stack<char> s;
        for(int i = 0; i < A.size(); i++){
            if(s.empty() || A[i] != s.top()){
                s.push(A[i]);
            }else{
                s.pop();
            }
        }

        string ans = "";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution obj;

    string str;
    cout << "Enter string: ";
    cin >> str;

    string result = obj.removeDuplicates(str);
    cout << "Result: " << result << endl;

    return 0;
}