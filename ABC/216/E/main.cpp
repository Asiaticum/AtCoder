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

    ll N, K;
    cin >> N >> K;

    vector<ll> A(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    sort(A.begin(), A.end(), greater<ll>());

    ll count = 0;
    ll last = A.at(0);
    ll index = 0;
    ll j = 0;
    for (int i = 0; i < N; i++) {
        if (count + (A.at(i) - A.at(i + 1)) * (i + 1) <= K) {
            count += (A.at(i) - A.at(i + 1)) * (i + 1);
            last = A.at(i + 1);
            j++;
            if (count == K) {
                break;
            }
        } else {
            last = A.at(i) - (K - count) / (i + 1);
            index = i - (K - count) % (i + 1);
            j++;
            break;
        }
    }

    ll res = 0;
    for (int i = 0; i < j; i++) {
        if (last == A.at(1)) {
            ll n = A.at(i) - last;
            ll a = last + 1;
            res += n * (2 * a + (n - 1)) / 2;
        } else if (i < index + 1) {
            ll n = A.at(i) - last + 1;
            ll a = last;
            res += n * (2 * a + (n - 1)) / 2;
        } else {
            ll n = A.at(i) - last;
            ll a = last + 1;
            res += n * (2 * a + (n - 1)) / 2;
        }
    }

    cout << res << endl;

    return 0;
}
