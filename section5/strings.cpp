#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(){
    string s = "abc";
    cout<<"value inside the s is: "<<s<<endl;

    // Dynamically
    string *sp = new string;
    *sp = "mno";
    cout<<"Address of sp is: "<<sp<<endl;
    cout<<"Value of sp is: "<<*sp<<endl;

    // store multiple strings
    vector <string> v;
    v.push_back(s);
    v.push_back("hello");
    v.push_back("world");
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    // // Taking input
    // string s1;
    // cout<<"Enter the value of s1: ";
    // cin>>s1;
    // cout<<"value of s1: "<<s1<<endl; // it will show only the word before the space _

    // // solving the space problem
    // // in char we use getline 
    // // now for string

    // string s2;
    // cout<<"Enter the value of s2: ";
    // cin.ignore();
    // getline(cin,s2);
    // cout<<"value of s2: "<<s2<<endl;
    
    // accessing element
    string s3 = "abcabc";
    cout<<s3[1]<<endl;

    //change value
    s3[0] = 'd';
    cout<<s3<<endl;

    // concatination adding two strings
    string s4 =  s + s3 + "hello sarvesh";
    cout<<s4<<endl;


    // length / size

    cout<< s4.size()<<endl;
    cout<< s4.length()<<endl;


    // substring()

    cout<<s4.substr(3)<<endl;
    cout<< s4.substr(11, 11)<<endl;

    // find value 
    
    string word = "defabcabcabc";
    cout<<word.find("abc")<<endl;

    // To string

    int a = 123;
    string st = to_string(a);
    cout<<st<<endl;

    // atoi()

    a = atoi(st.c_str());
    cout<<a<<endl;

    // push_back()

    st.push_back('5');
    cout<<st<<endl;

    return 0;
}