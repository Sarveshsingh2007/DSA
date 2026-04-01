#include <iostream>
#include<vector>
using namespace std;

int josephusRec(vector<int> person, int k, int index){
    if (person.size() == 1) { ;
        return person[0];
    }
    index = ((index + k) % person.size());
    person.erase(person.begin() + index);
    return josephusRec(person, k, index);
}

int josephus(int n,int k){
    int index= 0; 
    vector<int> person;
    for (int i = 1; i <= n; i++) {
        person.push_back(i);
    }
    return josephusRec(person,k,index);
}

int main(){
    int n = 7; 
    int k = 3;
    k--;
    cout<<josephus(n, k)<<endl;
}