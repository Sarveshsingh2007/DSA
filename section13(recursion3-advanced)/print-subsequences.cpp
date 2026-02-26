#include<iostream>
using namespace std;

// USING STRING 
void printSubs(string input, string output){         
    if(input.length() == 0){    
        cout << output << endl;
        return;
    } 
    printSubs(input.substr(1), output); 
    printSubs(input.substr(1), output + input[0]);
}

// USING CHARACTER ARRAY
void printSubs2(char input[], char output[], int i){
 
    if(input[0] == '\0'){
        output[i] = '\0';   
        cout << output << endl;
        return;
    }
 
    output[i] = input[0];
    printSubs2(input + 1, output, i + 1);
    printSubs2(input + 1, output, i);
}

int main(){

    //   STRING VERSION
    /*
    string input;
    cin >> input;
    string output = "";
    printSubs(input, output);
    */

    //   CHARACTER ARRAY VERSION
    char input[100];          
    cin >> input;

    char output[100];          
    printSubs2(input, output, 0);    

    return 0;
}