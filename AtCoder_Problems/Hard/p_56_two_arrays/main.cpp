#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<ll>> A(2, vector<ll>(N));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.at(0).size(); j++) {
            cin >> A.at(i).at(j);
        }
    }

    ll can_add_a = 0;
    ll can_add_b = 0;
    for (int i = 0; i < N; i++) {
        ll a = A.at(0).at(i);
        ll b = A.at(1).at(i);
        if (b > a) {
            can_add_a += (b - a) / 2;
        } else {
            can_add_b += a - b;
        }
    }

    if (can_add_b <= can_add_a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
