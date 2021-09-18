#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
using ll = long long;
const int INF = 1e8;
const ll MOD = 1e9 + 7;
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

    int X;
    cin >> X;

    if (X < 40) {
        cout << 40 - X << endl;
    } else if (X < 70) {
        cout << 70 - X << endl;
    } else if (X < 90) {
        cout << 90 - X << endl;
    } else {
        cout << "expert" << endl;
    }


    return 0;
}
