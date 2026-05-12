#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"------UNORDERD MAP------"<<endl;
    unordered_map<string, int> myMap;
    myMap["abc"] = 1;
    myMap["bcd"] = 2;
    myMap["cde"] = 3;
    myMap["def"] = 4;
    myMap["efg"] = 5;
    myMap["ghi"] = 6;

    for(unordered_map<string, int>:: iterator it = myMap.begin();it!=myMap.end();it++){
        cout<<"Key: "<<it->first<<" value: "<<it->second<<endl;
    }
    
    cout<<"------MAP------"<<endl;
    map<string, int> myMap1;
    myMap1["abc"] = 1;
    myMap1["bcd"] = 2;
    myMap1["cde"] = 3;
    myMap1["def"] = 4;
    myMap1["efg"] = 5;
    myMap1["ghi"] = 6;

    for(auto it = myMap1.begin();it!=myMap1.end();it++){
        cout<<"Key: "<<it->first<<" value: "<<it->second<<endl;
    }

    cout<<"------VECTOR------"<<endl;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(4);
    v.push_back(6);

    for(auto it = v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }

    cout<<"------FINDING AN ELEMENT------"<<endl;
    if(myMap.find("abc") == myMap.end()){
        cout<<"Not Present."<<endl;
    }else{
        cout<<"Present."<<endl;
    }

    cout<<"------DELETE------"<<endl;
    myMap.erase(myMap.begin(), myMap.end());
    cout<<"myMap is empty."<<endl;

    cout<<"------Size-----"<<endl;
    cout<<"myMap size is: "<<myMap.size()<<endl;

    auto a = 10;
    auto b = "abc";
    cout<<a<<" "<<b<<endl;

    return 0;
}


/* 
------UNORDERD MAP------
Key: efg value: 5
Key: abc value: 1
Key: bcd value: 2
Key: ghi value: 6
Key: def value: 4
Key: cde value: 3
------MAP------
Key: abc value: 1
Key: bcd value: 2
Key: cde value: 3
Key: def value: 4
Key: efg value: 5
Key: ghi value: 6
------VECTOR------
1
2
3
5
4
6
------FINDING AN ELEMENT------
Present.
------DELETE------
myMap is empty.
------Size-----
myMap size is: 0
10 abc
*/