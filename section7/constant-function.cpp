#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    // Helper function to find GCD (used internally)
    int gcd(int a, int b) const {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

public:
    // Default constructor
    Fraction() {
        numerator = 0;
        denominator = 1;
    }

    // Parameterized constructor
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }

    // Getter functions (const because they don't modify data)
    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    // Setter functions
    void setNumerator(int n) {
        numerator = n;
    }

    void setDenominator(int d) {
        if (d != 0)
            denominator = d;
    }

    // Simplify function
    void simplify() {
        int hcf = gcd(abs(numerator), abs(denominator));
        numerator /= hcf;
        denominator /= hcf;

        // Keep denominator positive
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Add two fractions (const function)
    Fraction add(const Fraction& f) const {
        int n = numerator * f.denominator + f.numerator * denominator;
        int d = denominator * f.denominator;

        Fraction result(n, d);
        result.simplify();
        return result;
    }

    // Multiply two fractions (const function)
    Fraction multiply(const Fraction& f) const {
        Fraction result(numerator * f.numerator,
                        denominator * f.denominator);
        result.simplify();
        return result;
    }

    // Display fraction (const function)
    void display() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f1(2, 4);
    Fraction f2(3, 6);

    cout << "Fraction 1: ";
    f1.display();

    cout << "Fraction 2: ";
    f2.display();

    Fraction sum = f1.add(f2);
    cout << "Sum: ";
    sum.display();

    Fraction product = f1.multiply(f2);
    cout << "Product: ";
    product.display();

    return 0;
}
