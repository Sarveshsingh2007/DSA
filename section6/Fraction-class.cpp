#include<iostream>
using namespace std;

class Fraction{
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int n, int d){
            numerator = n;
            denominator = d;
        }

        void display(){
            cout<<numerator<<"/"<<denominator<<endl;
        }
        
        void addFraction(Fraction const &f2){
            int lcm = denominator * f2.denominator;

            // numerators
            int x = lcm/denominator;
            int y = lcm/ f2.denominator;

            numerator = x*numerator + y*f2.numerator;
            denominator = lcm;

            simplify();
        }

        void simplify(){
            int gcd = 1;
            int j = min(abs(numerator), abs(denominator));

            for(int i=1;i<=j;i++){
                if(numerator % i == 0 && denominator % i == 0){
                    gcd = i;
                }
            }
            numerator /= gcd;
            denominator /= gcd;
        }
};

int main(){
    Fraction f1(10,2);
    Fraction f2(5,4);
    cout<<"Fraction 1: ";
    f1.display();
    cout<<"Fraction 2: ";
    f2.display();
    f1.addFraction(f2);
    cout<<"After Addition: ";
    f1.display();
    return 0;
}