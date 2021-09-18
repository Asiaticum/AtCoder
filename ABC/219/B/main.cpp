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

    string S1, S2, S3, T;
    cin >> S1;
    cin >> S2;
    cin >> S3;
    cin >> T;

    string ans;

    for (char t : T) {
        if (t == '1') {
            ans += S1;
        } else if (t == '2') {
            ans += S2;
        } else {
            ans += S3;
        }
    }

    cout << ans << endl;

    return 0;
}
