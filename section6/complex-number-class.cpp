#include <iostream>
using namespace std;

class ComplexNumbers {
private:
    double real;
    double imaginary;

public:
    // Constructor
    ComplexNumbers(double r, double i) {
        real = r;
        imaginary = i;
    }

    // Addition
    void add(ComplexNumbers c2) {
        real = real + c2.real;
        imaginary = imaginary + c2.imaginary;
    }

    // Subtraction
    void subtract(ComplexNumbers c2) {
        real = real - c2.real;
        imaginary = imaginary - c2.imaginary;
    }

    // Multiplication
    void multiply(ComplexNumbers c2) {
        double newReal = real * c2.real - imaginary * c2.imaginary;
        double newImaginary = real * c2.imaginary + imaginary * c2.real;

        real = newReal;
        imaginary = newImaginary;
    }

    // Division
    void divide(ComplexNumbers c2) {
        double denominator = c2.real * c2.real + c2.imaginary * c2.imaginary;

        if (denominator == 0) {
            cout << "Division not possible (denominator is zero)" << endl;
            return;
        }

        double newReal =
            (real * c2.real + imaginary * c2.imaginary) / denominator;

        double newImaginary =
            (imaginary * c2.real - real * c2.imaginary) / denominator;

        real = newReal;
        imaginary = newImaginary;
    }

    // Print complex number
    void print() {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int main() {
    double real1, imaginary1, real2, imaginary2;

    cout << "value of real 1 and imaginary 1: ";
    cin >> real1 >> imaginary1;

    cout << "value of real 2 and imaginary 2: ";
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cout << "Enter choice:\n";
    cout << "1. Addition\n";
    cout << "2. Multiplication\n";
    cout << "3. Subtraction\n";
    cout << "4. Division\n";
    cin >> choice;

    if (choice == 1) {
        c1.add(c2);
        c1.print();
    }
    else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else if (choice == 3) {
        c1.subtract(c2);
        c1.print();
    }
    else if (choice == 4) {
        c1.divide(c2);
        c1.print();
    }
    else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}
