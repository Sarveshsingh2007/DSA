#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int a[n];
    cout << "Enter array elements:\n";

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Elements are: ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";   // space printed only here
    }
    cout << endl;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    cout << "Sum of the array is: " << sum << endl;

    return 0;
}