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

    int N;
    cin >> N;

    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L.at(i);
    }

    sort(L.begin(), L.end());

    int cost = 0;
    while (L.size() > 1) {
        cost += accumulate(L.begin(), L.end(), 0);
        L.pop_back();
    }
    cout << cost << endl;

    return 0;
}
