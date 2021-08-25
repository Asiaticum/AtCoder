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

int N, weight;
vector<int> V(101), W(10001);
vector<vector<int>> dp(101, vector<int>(10001, -1));

int rec(int i, int j) {
    if (dp.at(i).at(j) >= 0) {
        return dp.at(i).at(j);
    }
    int res;
    if (i == N) {
        res = 0;
    } else if (j < W.at(i)) {
        res = rec(i + 1, j);
    } else {
        res = max(rec(i + 1, j), rec(i + 1, j - W.at(i)) + V.at(i));
    }
    dp.at(i).at(j) = res;
    return dp.at(i).at(j);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> weight;

    for (int i = 0; i < N; i++) {
        cin >> V.at(i) >> W.at(i);
    }

    cout << rec(0, weight) << endl;

    return 0;
}
