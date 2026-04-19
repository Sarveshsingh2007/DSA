#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;

    vector<int> v2(10, -2);
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<endl;
    }

    sort(v2.begin(), b2.end()); // sort

    // push_back
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);
    v.push_back(400);

    // modify
    v[2] = 500;

    // pop_back
    v.pop_back();

    // push using loop
    for(int i = 1000; i < 1050; i++){
        v.push_back(i + 1);
        cout << "Size is: " << v.size() << endl;
        cout << "Capacity is: " << v.capacity() << endl;
    }

    // correct printing
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }

    return 0;
}