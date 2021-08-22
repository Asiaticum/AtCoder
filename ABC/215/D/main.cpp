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
Ref. https://atcoder.jp/contests/abc215/submissions/25244813
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int maxA = 100000;

    int N, M;
    cin >> N >> M;

    vector<bool> k(maxA + 1, true);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a != 1) {
            k.at(a) = false;
        }
    }

    vector<bool> isprime(maxA + 1, true);
    vector<int> prime;
    for (int i = 2; i < maxA + 1; i++) {
        if (!isprime.at(i)) {
            continue;
        }
        for (int j = i + i; j < maxA + 1; j += i) {
            isprime.at(j) = false;
            k.at(i) = k.at(i) & k.at(j);
        }
        if (!k.at(i)) {
            prime.push_back(i);
        }
    }

    for (int p : prime) {
        for (int j = p + p; j < M + 1; j += p) {
            k.at(j) = k.at(j) & k.at(p);
        }
    }

    vector<int> ans;
    for (int i = 1; i < M + 1; i++) {
        if (k.at(i)) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans.at(i) << endl;
    }

    return 0;
}
