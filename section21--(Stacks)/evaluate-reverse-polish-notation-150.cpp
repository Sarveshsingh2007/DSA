#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& token) {
        stack<int> st;
        for(int i = 0; i < token.size(); i++){
            if(token[i] == "+" || token[i] == "-" || token[i] == "*" || token[i] == "/"){
                int v1 = st.top(); st.pop();
                int v2 = st.top(); st.pop();

                if(token[i] == "+"){
                    st.push(v2 + v1);
                }else if(token[i] == "-"){
                    st.push(v2 - v1);
                }else if(token[i] == "*"){
                    st.push(v2 * v1);
                }else if(token[i] == "/"){
                    st.push(v2 / v1);
                }
            }else{
                st.push(stoi(token[i]));
            }
        }
        return st.top();
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of tokens: ";
    cin >> n;

    vector<string> tokens(n);
    cout << "Enter tokens (space separated): ";
    for(int i = 0; i < n; i++){
        cin >> tokens[i];
    }

    int result = obj.evalRPN(tokens);
    cout << "Result: " << result << endl;

    return 0;
}