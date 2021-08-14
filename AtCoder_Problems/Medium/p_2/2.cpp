#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    long long counter = 0;
    long long j = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == 'W') {
            counter += i - j;
            j++;
        }
    }

    cout << counter << endl;

    return 0;
}
