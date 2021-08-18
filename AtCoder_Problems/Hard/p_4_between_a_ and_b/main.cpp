#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
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

ll round_up(ll a, ll x) { return (a + x - 1) / x; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, x;
    cin >> a >> b >> x;

    ll diff;

    ll ans = b / x - round_up(a, x) + 1;

    cout << ans << endl;

    return 0;
}
