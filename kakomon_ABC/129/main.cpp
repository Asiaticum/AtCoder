#include <bits/stdc++.h>
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

    int N, M;
    cin >> N >> M;

    vector<int> a(M);
    for (int i = 0; i < M; i++) {
        cin >> a.at(i);
    }

    vector<ll> dp(N + 1, -1);
    for (int a : a) {
        dp.at(a) = 0;
    }

    for (int i = 0; i < N + 1; i++) {
        if (i == 0) {
            dp.at(0) = 1;
        } else if (i == 1 && dp.at(1) != 0) {
            dp.at(1) = 1;
        } else if (dp.at(i) != 0) {
            dp.at(i) = dp.at(i - 1) % MOD + dp.at(i - 2) % MOD;
        }
    }

    cout << dp.at(N) % MOD << endl;

    return 0;
}
