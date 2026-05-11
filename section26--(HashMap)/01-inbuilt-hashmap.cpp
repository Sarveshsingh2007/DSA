#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    unordered_map<string, int> myMap;

    // insert

    pair<string, int> p("abc", 1);
    myMap.insert(p);
    myMap["bcd"] = 2;

    // access

    cout<<myMap["abc"]<<endl;
    cout<<myMap.at("bcd")<<endl;

    cout<<myMap["cde"]<<endl; // it will push the key and return 0

    // search for a key

    if(myMap.count("cde") > 0){
        cout<<"cde is present"<<endl;
    }else{
        cout<<"cde is not present"<<endl;
    }

    // updation

    myMap["abc"]  = 20;
    cout<<"after updating the value of 'abc' becomes: "<<myMap["abc"]<<endl;
    
    // size

    cout<<"size of hashmap: "<<myMap.size()<<endl;

    // delete

    myMap.erase("cde");
    cout<<"cde is erased."<<endl;

    if(myMap.count("cde") > 0){
        cout<<"cde is present"<<endl;
    }else{
        cout<<"cde is not present"<<endl;
    }

    cout<<"after deletion of 'cde' size of hashmap becomes: "<<myMap.size()<<endl;

    return 0;
}
