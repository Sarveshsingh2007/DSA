#include<iostream>
#include<vector>
using namespace std;

void printSubs(string input, string output, vector<string>& v){
    if(input.length() == '\0') {
        v.push_back(output);
        return;
    }
    printSubs(input.substr(1), output + input[0], v);  //include
    printSubs(input.substr(1), output, v); // exclude
}

int main(){
    string input;
    cin>>input;
    string output = "";

    vector<string> v;
    printSubs(input, output, v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}