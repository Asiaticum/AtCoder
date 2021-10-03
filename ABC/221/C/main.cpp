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

    string N;
    cin >> N;
    sort(N.begin(), N.end(), greater<int>());

    ll ans = 0;

    if (N.size() == 1) {
        cout << N << endl;
        return 0;
    }

    // for (int i = 0; i < N.size() / 2; i++) {
    //     string a, b;
    //     a = N.substr(0, i + 1);
    //     b = N.substr(i + 1);

    //     int A, B;
    //     A = atoi(a.c_str());
    //     B = atoi(b.c_str());

    //     ll m = A * B;
    //     if (m > ans) {
    //         ans = m;
    //     }
    // }


    for (int bit = 0; bit < (1 << N.size()); bit++) {
        vector<int> S;
        for (int i = 0; i < N.size(); i++) {
            if (bit & (1 << i)) {
                S.push_back(i);
            }
        }

        string a = "", b = "";
        b = N;
        for (int i = 0; i < (int)S.size(); ++i) {
            a += N.at(S.at(i));
            b = b.erase(S.at(i) - i, 1);
        }

        int A, B;
        A = atoi(a.c_str());
        B = atoi(b.c_str());

        if (A * B > ans) {
            ans = A * B;
        }

        // cout << "end" << endl;
        // cout << 'a' << a << endl;
        // cout << 'b' << b << endl;
    }

    cout << ans << endl;

    return 0;
}
