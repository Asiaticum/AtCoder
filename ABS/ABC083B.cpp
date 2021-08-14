#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int s = 0;
    for (int i = 1; i < N + 1; i++) {
        int a, b, c, d, e;
        a = i / 10000;
        b = i % 10000 / 1000;
        c = i % 1000 / 100;
        d = i % 100 / 10;
        e = i % 10;
        if (a + b + c + d + e >= A && a + b + c + d + e <= B) {
            s += i;
        }
    }
    cout << s << endl;

    return 0;
}
