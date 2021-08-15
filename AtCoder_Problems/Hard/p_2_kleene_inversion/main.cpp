#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    vector<ll> count_inversion(N, 0);
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if (A.at(i) > A.at(j)) {
                count_inversion.at(i)++;
            }
        }
    }

    vector<ll> last_count(N, 0);
    for (ll i = 0; i < N; i++) {
        for (ll j = i; j < N; j++) {
            if (A.at(i) > A.at(j)) {
                last_count.at(i)++;
            }
        }
    }

    ll count = 0;
    ll tmp = pow(10, 9) + 7;
    for (ll i = 0; i < N; i++) {
        count += (count_inversion.at(i) % tmp) * ((K * (K - 1)) / 2 % tmp) +
                 last_count.at(i) * (K % tmp);
    }

    ll ans = count % tmp;
    cout << ans << endl;

    return 0;
}
