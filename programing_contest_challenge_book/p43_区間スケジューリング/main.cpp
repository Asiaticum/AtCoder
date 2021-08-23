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

/*
https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> P(N);
    for (int i = 0; i < N; i++) {
        int center, len;
        cin >> center >> len;
        P.at(i).first = center + len;
        P.at(i).second = center - len;
    }

    sort(P.begin(), P.end());
    int end = -INF;
    int counter = 0;
    for (auto p : P) {
        if (p.second >= end) {
            end = p.first;
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}
