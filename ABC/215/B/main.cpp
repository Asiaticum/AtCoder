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

    ll N;
    cin >> N;

    ll k = 1;
    while (true) {
        ll pow_2 = pow(2, k);
        if (pow_2 > N) {
            cout << --k << endl;
            break;
        }
        k++;
    }

    return 0;
}
