#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int num = 1;
    for (int i = 0; i < S.size(); i++) {
        if (i % 2 == 1) {
            if (S.at(i) == '+') {
                num += 1;
            } else {
                num -= 1;
            }
        }
    }
    cout << num << endl;
}
