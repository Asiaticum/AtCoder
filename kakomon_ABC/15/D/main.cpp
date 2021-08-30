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

    int W, N, K;
    cin >> W;
    cin >> N >> K;

    vector<int> A(N + 1), B(N + 1);
    for (int i = 1; i < N + 1; i++) {
        cin >> A.at(i) >> B.at(i);
    }

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(W + 1, vector<int>(K + 1, 0)));
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            for (int k = 1; k < K + 1; k++) {
                if (j >= A.at(i) && k >= 1) {
                    dp.at(i).at(j).at(k) = max(dp.at(i - 1).at(j).at(k),
                                               dp.at(i - 1).at(j - A.at(i)).at(k - 1) + B.at(i));
                } else {
                    dp.at(i).at(j).at(k) = dp.at(i - 1).at(j).at(k);
                }
            }
        }
    }

    cout << dp.at(N).at(W).at(K) << endl;

    return 0;
}
