#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
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

    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S.at(i);
    }

    vector<vector<int>> dp(101, vector<int>(101, INF));
    dp.at(0).at(0) = 0;
    if (S.at(0).at(0) == '#') {
        dp.at(0).at(0) = 1;
    }


    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (y + 1 < H) {
                if (S.at(y).at(x) == '.' && S.at(y + 1).at(x) == '#') {
                    chmin(dp.at(y + 1).at(x), dp.at(y).at(x) + 1);
                } else {
                    chmin(dp.at(y + 1).at(x), dp.at(y).at(x));
                }
            }
            if (x + 1 < W) {
                if (S.at(y).at(x) == '.' && S.at(y).at(x + 1) == '#') {
                    chmin(dp.at(y).at(x + 1), dp.at(y).at(x) + 1);
                } else {
                    chmin(dp.at(y).at(x + 1), dp.at(y).at(x));
                }
            }
        }
    }

    cout << dp.at(H - 1).at(W - 1) << endl;


    return 0;
}
