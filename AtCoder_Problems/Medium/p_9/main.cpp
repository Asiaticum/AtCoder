#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    string res = "NO";
    for (int i = 1; i < B + 1; i++) {
        if (A * i % B == C) {
            res = "YES";
            break;
        }
    }

    cout << res << endl;

    return 0;
}
