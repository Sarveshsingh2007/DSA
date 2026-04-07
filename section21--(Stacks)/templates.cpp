#include<iostream>
using namespace std;

template<typename T, typename V>
class Pair{
    T x;
    V y;

    public:
        void setX(T x){
            this->x = x;
        }
        T getX(){
            return x;
        }

        void setY(V y){
            this->y = y;
        }
        V getY(){
            return y;
        }
};  

int main(){
    Pair<int, double> p1;
    p1.setX(1.5);
    p1.setY(2.54);
    cout<<"Integer values: "<<"x = "<<p1.getX()<<" "<<"y = "<<p1.getY()<<endl;

    Pair<double, char> p2;
    p2.setX(1.23);
    p2.setY('S');
    cout<<"Double values: "<<"x = "<<p2.getX()<<" "<<"y = "<<p2.getY();
}