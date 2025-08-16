/**
 * You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
 */



int maximum69Number (int num) {
    string s = to_string(num);
    for (char &c : s) {
        if (c == '6') {
            c = '9';
            break;
        }
    }
    return stoi(s);
}
// Example usage
#include <iostream>
using namespace std;

int main() {
    int num = 9669;
    int maxNum = maximum69Number(num);
    cout << "Maximum number after changing 6 to 9: " << maxNum << endl;
    return 0;
}