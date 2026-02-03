#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> *vp = new vector<int>(); // dynamic
    vector<int> v; // static 

    // initializing the value of vector
    vector<int> v2(10, -2);
    for ( int i=0;i<v2.size();i++){
        cout<<v2[i]<<endl;
    }
    sort(v2.begin(), v2.end());

    for(int i=0;i<100;i++){
        cout<<"capacity is: "<<v.capacity()<<endl;
        cout<<"size is: "<<v.size()<<endl;
        v.push_back(i+1);
    }
    // printing
    for(int i=0;i<v.size();i++){
        cout<<"element at index "<<i<<" is: "<<v[i]<<endl;
    }

    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);

    // v[0] = 100;

    // // v[3] = 40;  wrong way to assign value
    // // v[4] = 50;

    // v.push_back(40);
    // v.push_back(60);

    // // cout<<"value at 3  "<<v.at(3)<<endl;

    // // cout<<v[0]<<endl;
    // // cout<<v[1]<<endl;
    // // cout<<v[2]<<endl;
    // // cout<<v[3]<<endl;
    // // cout<<v[4]<<endl;

    // for(int i=0;i<v.size();i++){
    //     cout<<v.at(i)<<endl;
    // }

    // cout<<"---------POP BACK-----------"<<endl;
    // // pop back
    // v.pop_back();
    // for(int i=0;i<v.size();i++){
    //     cout<<v.at(i)<<endl;
    // }

    return 0;

}