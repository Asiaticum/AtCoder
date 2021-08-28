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

    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p.at(i);
    }

    int M = *max_element(p.begin(), p.end());
    int max_score = M * N + 1;

    vector<vector<bool>> dp(N + 1, vector<bool>(max_score, false));
    dp.at(0).at(0) = true;
    for (int i = 0; i < N; i++) {
        dp.at(i + 1).at(0) = true;
        for (int j = 0; j < max_score; j++) {
            if ((j - p.at(i) >= 0 && dp.at(i).at(j - p.at(i))) == true || dp.at(i).at(j) == true) {
                dp.at(i + 1).at(j) = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < max_score; i++) {
        if (dp.at(N).at(i)) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
