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

    ll count_inversion = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A.at(i) > A.at(j)) {
                count_inversion++;
            }
        }
    }

    ll last_count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (A.at(i) > A.at(j)) {
                last_count++;
            }
        }
    }


    ll count = 0;
    ll tmp = pow(10, 9) + 7;
    cout << count_inversion << endl;
    count += (count_inversion % tmp) * (((K * (K - 1)) / 2) % tmp) + last_count * (K % tmp);


    cout << count << endl;
    ll ans = count % tmp;
    cout << ans << endl;

    return 0;
}
