#include <iostream>
#include <cstring>
using namespace std;

// Function to print reverse suffixes
void printReverseSuffixes(char str[]) {
    int len = strlen(str);

    for (int i = len - 1; i >= 0; i--) {
        for (int j = i; j < len; j++) {
            cout << str[j];
        }
        cout << endl;
    }
}

int main() {
    char str[] = "abcd";
    printReverseSuffixes(str);
    return 0;
}
