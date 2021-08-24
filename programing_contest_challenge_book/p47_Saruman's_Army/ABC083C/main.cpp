#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e8;
const int MOD = 1e9 + 7;
const ll LINF = 1e17;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll X, Y;
    cin >> X >> Y;

    ll start = X;
    ll count = 0;

    while (true) {
        count++;
        if (start * 2 > Y) {
            break;
        } else {
            start *= 2;
        }
    }

    cout << count << endl;

    return 0;
}
