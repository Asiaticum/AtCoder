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

    int N, weight;
    vector<int> V, W;
    vector<vector<int>> dp(101, vector<int>(10001, 0));

    cin >> N >> weight;
    V.resize(N + 1);
    W.resize(weight + 1);

    for (int i = 0; i < N; i++) {
        cin >> V.at(i) >> W.at(i);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < weight + 1; j++) {
            if (j - W.at(i) >= 0) {
                dp.at(i + 1).at(j) = max(dp.at(i).at(j - W.at(i)) + V.at(i), dp.at(i).at(j));
            } else {
                dp.at(i + 1).at(j) = dp.at(i).at(j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < weight + 1; i++) {
        ans = max(ans, dp.at(N).at(i));
    }

    cout << ans << endl;

    return 0;
}
