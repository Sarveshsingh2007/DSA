#include<iostream>
using namespace std;

int length(char input[]) {
    if (input[0] == '\0') {
        return 0;   // Base case
    }
    return 1 + length(input + 1);   // Recursive case
}

int main() {
    char input[100];

    cout << "Enter a string: ";
    cin.getline(input, 100);   // Takes full line including spaces

    int l = length(input);
    cout << "Length of string = " << l << endl;

    return 0;
}