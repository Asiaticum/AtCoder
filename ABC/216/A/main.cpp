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

    string S;
    cin >> S;

    string y = S.substr(S.length() - 1);
    if (y == "0" || y == "1" || y == "2") {
        cout << S.substr(0, S.length() - 2) << "-" << endl;
    } else if (y == "7" || y == "8" || y == "9") {
        cout << S.substr(0, S.length() - 2) << "+" << endl;
    } else {
        cout << S.substr(0, S.length() - 2) << endl;
    }

    return 0;
}
