#include <bits/stdc++.h>
using namespace std;

void is_odd(int a, int b) {
    if (a * b % 2 == 0) {
        cout << "Even" << endl;
    } else {
        cout << "Odd" << endl;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    is_odd(a, b);

    return 0;
}
